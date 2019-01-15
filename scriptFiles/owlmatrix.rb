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


ary = Array.new
input = Array.new

input = gets.chomp.split
w = input.size
h = 0

if w%2 == 1
  puts "Error"
  exit!
end

while input.size == w && input.size > 0
  ary << input
  h += 1
  input = gets.chomp.split
end

x = w/2
y = h/2
block1 = Array.new

for i in 0...y
  block1 << ary[i][0...x]
end

block2 = Array.new
for i in 0...y
  block2 << ary[i][x...w]
end

block3 = Array.new
for i in y...h
  block3 << ary[i][0...x]
end

block4 = Array.new
for i in y...h
  block4 << ary[i][x...w]
end

for i in 0...block2.size
  block2[i].reverse!
end

for i in 0...block4.size
  block4[i].reverse!
end

block3.reverse!
block4.reverse!

if block1 == block2 && block2 == block3 && block3 == block4
  puts "The Matrix is a Owl Matrix :-)"
else
  puts "The Matric is not a Owl Matrix :-("
end