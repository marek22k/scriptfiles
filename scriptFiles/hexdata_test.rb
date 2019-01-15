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
require "hexdata"

class HexDataTest < Test::Unit::TestCase
    
    def setup
        @hd1 = HexData.new [":0C00000048656C6C6F20576F726C6421B7", ":00000001FF"]
        @hd2 = HexData.new
    end
    
    def test_basic1
        @hd1.interpret
        assert_equal @hd1.ascii, "Hello World!"
        assert_equal @hd1.checksum?, 183
        assert_equal @hd1.checksum?(1), 255
        assert_equal @hd1.push_address, 16
        assert_equal @hd1.enddef, ":00000001FF"
        assert_equal @hd1.max_index?, 2
        assert_equal @hd1.data_end?, 1
    end
    
    def test_basic2
        @hd2.interpret
        assert_equal @hd2.ascii, ""
        assert_equal @hd2.push_address, 16
        assert_equal @hd2.enddef, ":00000001FF"
        assert_equal @hd2.max_index?, 0
        assert_equal @hd2.data_end?, 0...0
    end
    
    def test_work1
        @hd1.delete_data! 0
        @hd1.interpret
        
        assert_equal @hd1.max_index?, 1
        assert_equal @hd1.data_end?, 0
        
        assert_equal @hd1.ascii, ""
    end
    
    def test_work2
        @hd2.push "Test"
        @hd2.push_user ":0C00000048656C6C6F20576F726C6421B7"
        @hd2.push_end
        @hd2.interpret
        
        assert_equal @hd2.ascii, "TestHello World!"
        assert_equal @hd2.checksum?, 76
        assert_equal @hd2.checksum?(1), 183
        assert_equal @hd2.checksum?(2), 255
    end
    
    def test_edit1
        @hd1.reset_address!
        assert_equal @hd1.push_address, 16
    end
    
    def test_edit2
        @hd1.enddef = ":0C00000048656C6C6F20576F726C6421B7"
        assert_equal @hd1.data_end?, 0
    end
    
    def test_work3
        @hd1.push_address = 123
        @hd1.clear!
        @hd1.interpret
        
        assert_equal @hd1.max_index?, 0
        assert_equal @hd1.data_end?, 0...0
        assert_equal @hd1.push_address, 16
        assert_equal @hd1.ascii, ""
    end
    
    def test_work4
        @hd2.enddef = ":0C00000148656C6C6F20576F726C6421B6"
        @hd2.push "Test"
        @hd2.push_end
        @hd2.interpret
        
        assert_equal @hd2.max_index?, 2
        assert_equal @hd2.data_end?, 1
        assert_equal @hd2.ascii, "Test"
        assert_equal @hd2.checksum?, 76
        assert_equal @hd2.checksum?(1), 182
        assert_equal @hd2.push_address, 17
    end
end