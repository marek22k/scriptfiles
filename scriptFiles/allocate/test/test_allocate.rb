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

require "test/unit"
require "allocate"

class AllocateTest < Test::Unit::TestCase
  
  def setup
    @a = Allocate.new
  end
  
  def test_test
    @a.alloc 4
	
    assert_equal @a.good?, true
	
    @a.set 0, 3
    @a.set 1, 6
    @a.set 2, 9
    @a.set 3, 12
	
    assert_equal @a.get(0), 3
    assert_equal @a.get(1), 6
    assert_equal @a.get(2), 9
    assert_equal @a.get(3), 12
    assert_equal @a.max?, 4
	
    @a.free
    assert_equal @a.good?, false
  end
end
