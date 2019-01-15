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

require "mysql2"

print "Host: "
host = gets.chomp
print "Username: "
username = gets.chomp
print "Password: "
passowrd = gets.chomp
client = Mysql2::Client.new(:host => "hundert-prozent.net", :username => "d02c4c38", :password => "fbbot4mvBTbf94Re")

loop do
  begin
    print "SQL: "
    $sql = gets.chomp
    break if $sql == "exit"
    result = client.query($sql)
    result.each { |row|
      row.each { |data|
       print "#{data[0]}: #{data[1]} - "
      }
      puts
    } if result != nil
  rescue Exception => e
    puts e
  end
end

client.close