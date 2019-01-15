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

site = ARGV[0]
host = ARGV[1]
path = ARGV[2]

ip1 = Resolv::DNS.open.getresources(site, Resolv::DNS::Resource::IN::A)[0].address.to_s
ip2 = Resolv::DNS.open.getresources(host, Resolv::DNS::Resource::IN::A)[0].address.to_s
txt = Resolv::DNS.open.getresources(host, Resolv::DNS::Resource::IN::TXT)[0].strings[0]

if ip1 != ip2 || txt != host
  puts "Error"
  exit!
end

$data = Array.new

def scan ip, host, path = "/"

  response = Net::HTTP.new(ip, "80").send_request "GET", path, nil, {
    "Host" => host,
    "User-Agent" => "Bot",
    "Referer" => host,
    "Accept" => "application/xhtml+xml"
  }

  response.body.scan(/<td><a href="(.*)">.*<\/a>/).each { |x|
    puts "#{path}#{x[0]}" if x[0] != "/"
    tmp = ["#{path}#{x[0]}"]
    if x[0].include?("/") && x[0] != "/"
      scan ip, host, path + x[0]
    end
    response = Net::HTTP.new(ip, "80").send_request "GET", path + x[0], nil, {
      "Host" => host,
      "User-Agent" => "Bot",
      "Referer" => host,
      "Accept" => "application/xhtml+xml"
    }
    tmp << response.body.inspect
    $data << tmp
  }

end

scan ip1, host, path

File.open("archive.txt", "w") { |f|
  f.write($data.inspect)
  f.close
}