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

def interpretJSON str
  s = str.delete "\n"
  s = s[1...s.length-1]
  s += ","
  
  hh = Hash.new
  
  a = 0
  b = s[a..s.length].index ","
  while b != nil
    b += a
    e = s[a..b]
    
    if(e.index("{") != nil)
      n = 0
      while e.index("}") == nil || n != 0
        b += 1
        e = s[a..b]
        n += 1 if e[e.length-1] == "{"
        n -= 1 if e[e.length-1] == "}"
        #puts "e == #{e} && n == #{n} && c == #{e[e.length-1]}"
      end
      b += 2
      e = s[a..b]
      
      name = e[0...e.index(":")].match(/\"(.*)\"/).to_a[1]
      value = e[e.index(":")+1...e.length-1]
      hh[name] = interpretJSON value
    else
      name = e[0...e.index(":")].match(/\"(.*)\"/).to_a[1]
      if name == nil then name = e[0...e.index(":")-1] end
      value = eval(e[e.index(":")+1...e.length-1].delete "}")
      hh[name] = value
    end
    a = b+1
    while a > s.length; a -= 1 end
    b = s[a..s.length].index(",")
  end
  
  return hh
end

def compareHash h1, h2
  h1.each { |k, v|
    if v.class == Hash && h2[k].class == Hash
      compareHash v, h2[k]
    else
      if v != h2[k]
        puts "Variable #{k}: JSON 1 => #{v}; JSON 2 => #{h2[k]}"
      end
    end
  }
end

h1 = interpretJSON gets.chomp
h2 = interpretJSON gets.chomp

compareHash h1, h2