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

require "resolv"
require "net/http"

site = "tmp.mk16.de"

print "Check DNS entries... "

if Resolv::DNS.open.getresources(site, Resolv::DNS::Resource::IN::TXT)[0].strings[0] == site
  puts "OK"
else
  exit!
end


def GetWebsiteContent address, schema = "https"
  uri = URI "#{schema}://#{address}"
  begin
    return res = Net::HTTP.start(uri.host, uri.port, :use_ssl => uri.scheme == "https") { |http|
      request = Net::HTTP::Get.new uri
     
      http.request request
    }
    rescue OpenSSL::SSL::SSLError => e
      return GetWebsiteContent address, "http"
    rescue Exception => e
      print "ERROR"
      exit!
    end
end

print "Connection to #{site}... "
res = GetWebsiteContent site + "/data/?C=M"
puts "OK"

print "Read data... "
if res.code == "200" && res.message == "OK"
  puts "OK\n\n"
  puts "Data: "
  res.body.scan(/<td><a href="(.*)\.tmp">.*\.tmp<\/a>/).each { |x|
    puts x[0]
  }
else
  puts "ERROR"
end