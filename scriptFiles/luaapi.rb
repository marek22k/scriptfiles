# Author: Marek K.

=begin

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Dieses Programm ist Freie Software: Sie können es unter den Bedingungen
    der GNU General Public License, wie von der Free Software Foundation,
    Version 3 der Lizenz oder (nach Ihrer Wahl) jeder neueren
    veröffentlichten Version, weiter verteilen und/oder modifizieren.

    Dieses Programm wird in der Hoffnung bereitgestellt, dass es nützlich sein wird, jedoch
    OHNE JEDE GEWÄHR,; sogar ohne die implizite
    Gewähr der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
    Siehe die GNU General Public License für weitere Einzelheiten.

    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
    Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.

=end

class LuaApi
  require "net/http"
  require "uri"
  
  attr_accessor :type
  
  def initialize
    begin
      File.open "./lua_api-in.txt", "w" do |f|
        f.write "print(_VERSION)"
        f.close
      end
      
      IO.popen "lua ./lua_api-in.txt" do |p|
        @version = p.gets
        p.close
      end
      
      @type = 0
    rescue Errno::ENOENT => e
      @type = 1
      uri = URI("https://www.lua.org/cgi-bin/demo")
      https = Net::HTTP.new(uri.host, uri.port)
      https.use_ssl = true
      req = Net::HTTP::Post.new(uri.path)
      req.body = "input=" + URI::encode("print(_VERSION)") 
      res = https.request(req)
      if res.code == "200"
        @version = res.body.match(/<H2>Output<\/H2>\n<TEXTAREA ROWS="8" COLS="80">\n(.*)\n<\/TEXTAREA><P><IMG SRC="images\/ok.png" ALIGN="absbottom">\nYour program ran successfully\./m)[1]
      else
        @type = 2
        raise RuntimeError, "No interpreter found!"
      end
    end
  end
  
  def version?
    return @version
  end
  
  def good?
    true unless @type == 2
  end
  
  def interpret code
    case @type
      when 0
        File.open "./lua_api-in.txt", "w" do |f|
          f.write code
          f.close
        end
      
        begin
          IO.popen "lua ./lua_api-in.txt" do |p|
            @result = p.gets
            p.close
          end
        rescue Errno::ENOENT => e
          raise RuntimeError, "No interpreter found!"
        end
      when 1
        uri = URI("https://www.lua.org/cgi-bin/demo")
        https = Net::HTTP.new(uri.host, uri.port)
        https.use_ssl = true
  
        req = Net::HTTP::Post.new(uri.path)
        req.body = "input=" + URI::encode(code) 
        res = https.request(req)
  
        if res.code == "200"
          r = res.body.match(/<H2>Output<\/H2>\n<TEXTAREA ROWS="8" COLS="80">\n(.*)\n<\/TEXTAREA><P><IMG SRC="images\/ok.png" ALIGN="absbottom">\nYour program ran successfully\./m)
          unless r
            r = res.body.match(/<H2>Output<\/H2>\n<TEXTAREA ROWS="8" COLS="80">\n(.*)<\/TEXTAREA><P><IMG SRC="images\/alert.png" ALIGN="absbottom">\nYour program failed to compile\./m)
          end
          unless r
            r = res.body.match(/<H2>Output<\/H2>\n<TEXTAREA ROWS="8" COLS="80">\n(.*)<\/TEXTAREA><P><IMG SRC="images\/alert.png" ALIGN="absbottom">\nYour program failed to run\./m)
          end
          unless r
            r = res.body.match(/<H2>Output<\/H2>\n<TEXTAREA ROWS="8" COLS="80">\n(.*)<\/TEXTAREA><P><IMG SRC="images\/alert.png" ALIGN="absbottom">\nYour program was aborted\./m)
          end
          @result = nil unless r
          @result = r[1]
        else
          raise RuntimeError, "Online Interpreter not available!"
        end
      when 2
        raise RuntimeError, "No interpreter found!"
    end
    return @result
  end
  
  def result
    @result
  end
  
  def close
    File.delete "./lua_api-in.txt" if File.exist? "./lua_api-in.txt"
    @type = 2
  end
  
end