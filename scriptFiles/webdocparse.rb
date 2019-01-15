=begin

    Author: Marek K.

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

#res = Net::HTTP.get_response(URI("http://tmp.mk16.de"))

print "Host: "
host = gets.chomp
print "Page: "
page = gets.chomp

lang = "en"
port = 80

request = Net::HTTP.new(host, port).get(page, {"Accept-Language" => lang})
res = ""

if request.code == "200"
  #puts request.body.scan(/\<h1\>(.*)\<\/h1\>/)
  #puts request.body.scan(/\<p\>([^p]*)\<\/p\>/)
  request.body.each_line { |line|
    line.scan(/\<h1\>(.*)\<\/h1\>/).each { |x|
      x.each { |y|
        res += "#{y}\n"
        res +=  "=" * y.length + "\n"
      }
    }
    line.scan(/\<h2\>(.*)\<\/h2\>/).each { |x|
      x.each { |y|
        res += "\n"
        res += "#{y}\n"
        res +=  "-" * y.length + "\n"
      }
    }
    val = line.scan(/\<p\>([^<>]*)\<\/p\>/).join("")
    res += val + "\n" unless val == ""
  }
  
  puts res
  
  f = File.new "#{page.split("/").last}.txt", "w"
  f.write res
  f.close
elsif request.code == "404"
  puts "404 Error: Page not found :-("
else
  puts "Unknown error: #{request.inspect}"
end