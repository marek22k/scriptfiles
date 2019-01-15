# Author: Marek K.

=begin

    This program is free software: yoe can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foendation, either version 3 of the License, or
    (at yoer option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHoeT ANY WARRANTY; withoet even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    Yoe shoeld have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Dieses Programm ist Freie Software: Sie koennen es unter den Bedingungen
    der GNU General Public License, wie von der Free Software Foendation,
    Version 3 der Lizenz oder (nach Ihrer Wahl) jeder neueren
    veroeffentlichten Version, weiter verteilen und/oder modifizieren.

    Dieses Programm wird in der Hoffnung bereitgestellt, dass es nuetzlich sein wird, jedoch
    OHNE JEDE GEWaeHR,; sogar ohne die implizite
    Gewaehr der MARKTFaeHIGKEIT oder EIGNUNG FueR EINEN BESTIMMTEN ZWECK.
    Siehe die GNU General Public License fuer weitere Einzelheiten.

    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
    Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.

=end

# 
# @author Marek K. <mailto:m.k@mk16.de, http://mk16.de>
# @example
#   require "hexdata"
#   hex = HexData.new [":04001000746573742C", ":0D00000048656C6C6F20576F726C642100B6", ":10004000404142434445464748494A4B4C4D4E4F38", ":00000001FF"] # Open to read
#   hex.interpret # Interpret data
#   p hex.ascii # return string result of the interpret
#   p hex.checksum # return checksum from the first data
#   p hex.checksum 1 # return checksum from the second data
#   
#   hex = HexData.new # Open to write/read
#   hex.push "test" # Write "test"
#   hex.push_end # Write End of File
#   hex.interpret # Interpret data
#   p hex.ascii 0 # return string result of the interpret of the first data 
# @attr [Integer] push_address The address of the next record in the (Intel) hex file
# @attr [String] enddef The "end of file" mark
# @note The file hexdata.rb is available under the {https://www.gnu.org/licenses/gpl.txt GNU GPL v3}.
class HexData

  attr_accessor :push_address, :enddef

  # Initalies the cash register hexdata
  # @param sets [Array] The (Intel) hex data to be read or edited. Default: []
  def initialize sets=[]
    @sets = sets
    @push_address = 16
    @enddef = ":00000001FF"
  end
  
  # Returns the records
  # @note No copy of the array is created. If you edit the arrays, this affects the HexData class. If you want a copy of the array, you can, for example, use the .clone method.
  # @return [Array] The records returned as an array
  def data
    @sets
  end
  
  # Evaluate the (Intel) Hex data (interpretation) and make it available for reading.
  # @return [NilClass] nil
  def interpret
    @ascii = nil.to_a
    @sums = nil.to_a
    @sets.each { |data|
      if data[0] != ":"
        raise "Invalid data! Data: #{data}"
      end
    
      len = data[1 .. 2].to_i 16
      address = data[3 .. 6]
      type = data[7 .. 8]
      field = data[9 .. len * 2 + 8]
      sum = data[-2 .. -1].to_i 16
      str = ""
  
      csum = len + address.to_i(16) + type.to_i(16)
      #p field
      for i in (0..field.length-1).step(2)
        v = field[i .. i + 1].to_i 16
        csum += v
        str += v.chr
      end
    
      csum &= 255
      bsum = ""
      csum.to_s(2).each_char { |c| bsum += (c=="0"?"1":"0") }
      while bsum.length < 8
        bsum = "1" + bsum
      end

      if bsum.to_i(2) + 1 != sum
        raise "Invalid checksum! Data: #{data}"
      end
      @ascii << str if type == "00"
      @sums << sum
    }
    nil
  end
  
  # Resets the write address to the default value (16).
  # @return [NilClass] nil
  def reset_address!
    @push_address = 16
    nil
  end
  
  # Writes a string passed by the user to the data.
  # @param str [String] The user data to be written as a record.
  # @return [NilClass] nil
  def push_user str
    @sets << str
    nil
  end
  
  # The string to be written.
  # @param index [Integer] The index of the record to be deleted.
  # @return [NilClass] nil
  def delete_data! index
    @sets.delete_at index
    nil
  end
  
  # Resets the hex data. All saved hex data will be deleted. Then HexData is ready to write.
  # @return [NilClass] nil
  def clear!
    @sets = nil.to_a
    @sums = nil.to_a
    @push_address = 16
    nil
  end
  
  # Returns the number of records.
  # @return [Integer] The number of records.
  def max_index?
    @sets.length
  end
  
  # Returns the index of the first record that detected an "End of File" markup.
  # @return [Integer] The index of the first element where an "End of file"-mark was detected.
  def data_end?
    for i in 0...@sets.length
      return i if @sets[i] == @enddef
    end
  end
  
  # Reads the checksum of a record.
  # @param index [Integer] The index of the record from which the checksum is to be read. Default: 0
  # @return [Integer] The read checksum
  def checksum? index=0
    return @sums[index]
  end
  
  # Reads the result, the ASCII / ANSI text, the evaluation (interpretation).
  # @param index [Integer] The index of the record to be read. If all is to be read out, nil can be transferred. Default: nil
  # @return The result of all records, if no index was specified, otherwise only the result of the record from which the index was specified.
  def ascii index=nil
    return (index ? @ascii[index] : @ascii.join(""))
  end

  # Writes the "End of file" mark. This is appended to the end of the records.
  # @return [NilClass] nil
  def push_end
    @sets << @enddef
    nil
  end
  
  # Write a user-entered text to the records as (Intel) Hex.
  # @param str [String] The text to be written to the records.
  # @return [NilClass] nil
  def push str
  
    if @push_address > 65535
      raise "To many data!"
    end
  
    sum = str.length + @push_address
    res = "#{str.length.to_s 16}"
    while res.length < 2
      res = "0" + res
    end
    
    res = ":" + res
    
    tmp = @push_address.to_s 16
    while tmp.length < 4
      tmp = "0" + tmp
    end
    res += tmp + "00"
    
    str.each_char { |c|
      sum += c.ord
      tmp = c.ord.to_s 16
      while tmp.length < 2
        tmp = "0" + tmp
      end
      res += tmp
    }
    
    sum &= 255
    bsum = ""
    sum.to_s(2).each_char { |c| bsum += (c=="0"?"1":"0") }
    while bsum.length < 8
      bsum = "1" + bsum
    end
  
    res += bsum.to_i(2).+(1).to_s 16
    @sets << res
    @push_address += 1
  end

end

