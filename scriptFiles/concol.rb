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

# concol = console color

class String
    def colorize(color = 37, background = 40)
        return "\e[#{color};#{background}m#{self}\e[0m"
    end
end

Colorize_color = {
    "black" => 30,
    "red" => 31,
    "green" => 32,
    "yellow" => 33,
    "blue" => 34,
    "magenta" => 35,
    "cyan" => 36,
    "white" => 37
}

Colorize_background = {
    "black" => 40,
    "red" => 41,
    "green" => 42,
    "yellow" => 43,
    "blue" => 44,
    "magenta" => 45,
    "cyan" => 46,
    "white" => 47
}

Colorize_color.values.each { |v|
    Colorize_background.values.each { |vv|
        puts "test".colorize v, vv
    }
}