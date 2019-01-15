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

print "Number: "
n = gets.chomp.to_i
print "Array(num1 num2 num3 numN): "
ary = gets.chomp.split.map { |x| x.to_i }

min = -> (ary, s) {
  z = 0
  ary.each { |x|
    if s-z > s-x && s > x
      z = x
    end
  }
  return z
}

sum = min[ary, n]
last = sum
res = Array.new
res << sum
i = 0

while sum < n && i < ary.size
  last = min[ary, last]
  sum += last
  if sum > n
    sum -= last
    last = min[ary, last]
    sum += last
  end
  res << last
  i += 1
end

if sum == n
  puts "Guitar subset: #{res.join(" + ")} = #{sum}"
else
  puts "No guitar subset found"
end