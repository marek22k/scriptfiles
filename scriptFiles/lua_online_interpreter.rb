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

    Dieses Programm ist Freie Software: Sie koennen es unter den Bedingungen
    der GNU General Public License, wie von der Free Software Foundation,
    Version 3 der Lizenz oder (nach Ihrer Wahl) jeder neueren
    veroeffentlichten Version, weiter verteilen und/oder modifizieren.

    Dieses Programm wird in der Hoffnung bereitgestellt, dass es nuetzlich sein wird, jedoch
    OHNE JEDE GEWAEHR,; sogar ohne die implizite
    Gewaehr der MARKTFAEHIGKEIT oder EIGNUNG FUER EINEN BESTIMMTEN ZWECK.
    Siehe die GNU General Public License fuer weitere Einzelheiten.

    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
    Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.
  
=end

require "net/http"
require "uri"

def InterpretLua par
  uri = URI("https://www.lua.org/cgi-bin/demo")
  https = Net::HTTP.new(uri.host, uri.port)
  https.use_ssl = true
  
  req = Net::HTTP::Post.new(uri.path)
  req.body = "input=" + URI::encode(par) 
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
    return nil unless r
    return r[1]
  else
    $stderr.puts "Unfortunately, the server is currently not working!"
    f = File.new "error.html", "w"
    f << res.body
    f.close
    exit!
  end
end

if ARGV[0] == "-v"
  puts InterpretLua 'print(_VERSION)'
  exit
elsif ARGV[0] == "-o"
  par = File.read(ARGV[2])
  f = File.new ARGV[1], "w"
  f << InterpretLua(par)
  f.close()
else
  print InterpretLua File.read(ARGV[0])
end
