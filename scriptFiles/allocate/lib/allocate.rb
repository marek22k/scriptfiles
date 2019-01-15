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

# @version 2.0

# Requests memory by means of the C function malloc and can release it with the C function free.
# @author Marek K. <mailto:m.k@mk16.de, http://mk16.de>
# example
# @note It is recommended to use the class AMemoryAllocator instead of the class Allocate.
class Allocate
  # The version, allocate from the Gem
  VERSION = "2.0"
  
  # Initializes an allocate object
  # @return [Allocate] self
  def initialize ; end
  
  # Checks if the requested storage space is ready for use.
  # @return [TrueClass, FalseClass] Returns true if the space is ready, false otherwise.
  def good? ; end
  
  # Releases the requested memory area.
  # @return [Allocate] self
  # @note If there is no memory space to release, the funkton does nothing.
  def free ; end
  
  # Returns the number of requested spaces.
  # @return [Integer] Number of requested storage areas. If no memory has been requested or already released, the function returns 0.
  # @note The maximum index can be calculated accordingly by subtracting the return value by one. If no memory has been requested or has already been released, the function returns 0, since the index can not be calculated accordingly, since there can be none.
  def max? ; end
  
  # Allocates any 1-byte number of memory.
  # @param size [Integer] The number of times 1-byte memory should be allocated.
  # @return [Allocate] self
  # @note It allocates [PARAMETER] * 1, so [PARAMETER] times the memory requirement of a byte (character).
  # @raise [ArgumentError] Raises a runtime error if memory could not be requested.
  # @raise [ArgumentError] Raises a argument error when trying to allocate a negative number from memory.
  def alloc size ; end
  
  # Reads a memory area.
  # @param index [Integer] The key (index) of the memory area
  # @return [Allocate] self
  # @raise [RuntimeError] Raises a runtime error if the key (index) is outside the requested scope.
  # @raise [RuntimeError] Raises a runtime error when no memory has been requested.
  def get index ; end
  
  # Writes to a memory area.
  # @param index [Integer] The key (index) of the memory area
  # @param size [Integer] The value to be written to the memory area.
  # @return [Allocate] self
  # @note Only a value from 0 to 255 can be set since only 1 byte is assigned to a memory area.
  # @raise [RuntimeError] Raises a runtime error if the key (index) is outside the requested scope.
  # @raise [RuntimeError] Raises a runtime error when no memory has been requested.
  def set index, size ; end
end

# Requests memory by means of the C function malloc and can release it with the C function free.
# @author Marek K. <mailto:m.k@mk16.de, http://mk16.de>
# example
# @note This class has AMemoryAlloocator different from the allocate class in that it has a buffer function, more error handling, and some other useful functions.
# @since 2.0
class AMemoryAllocator < Allocate

  # Sets the total requested memory to 0 (integer).
  # @return [AMemoryAllocator] self
  # @raise [RuntimeError] Triggers a runtime error if no memory has been requested to be set.
  def setzero!
    self.initmemory! 0
  end
  
  # Sets all memory to a value.
  # @param val [Integer] The value to set the memory to.
  # @return [AMemoryAllocator] self
  # @raise [RuntimeError] Triggers a runtime error if no memory has been requested to set a value.
  def initmemory! val
    raise RuntimeError, "No buffer was created!" unless self.good?
  
    self.max?.times { |x|
      self.set x, val
    }
    
    self
  end
  
  # Requests memory for a buffer and releases the memory, if any, which has not yet been released.
  # @return [AMemoryAllocator] self
  # @raise [RuntimeError] Raises a runtime error if memory could not be requested.
  def makebuffer!
    self.free
    self.alloc 1
  end
  
  # Sets the value of the buffer
  # @param val [Integer] The value to which the buffer should be set.
  # @return [AMemoryAllocator] self
  # @note Only a value from 0 to 255 can be set, as only 1 byte is allocated for a buffer.
  # @raise [RuntimeError] Raises a runtime error if no buffer has been created.
  def setbuffer val
    raise RuntimeError, "No buffer was created!" unless self.good?
    self.set 0, val
  end
  
  # Reads the value of a buffer
  # @return The value of the current buffer
  # @raise [RuntimeError] Raises a runtime error if no buffer has been created.
  def getbuffer
    raise RuntimeError, "No buffer was created!" unless self.good?
    self.get 0
  end
  
  # Gives the memory of a buffer.
  # @return [AMemoryAllocator] self
  def deletebuffer
    self.free
  end
  
  # Reads a memory area.
  # @param key [Integer] The key (index) of the memory area
  # @raise [RuntimeError] Raises a runtime error if the key (index) is outside the requested scope.
  # @raise [RuntimeError] Raises a runtime error when no memory has been requested.
  def get key
    raise RuntimeError, "The memory to be read is outside the requested range." if key >= self.max?
    super key
  end
  
  # Writes to a memory area.
  # @param key [Integer] The key (index) of the memory area
  # @param val [Integer] The value to be written to the memory area.
  # @return [AMemoryAllocator] self
  # @note Only a value from 0 to 255 can be set since only 1 byte is assigned to a memory area.
  # @raise [RuntimeError] Raises a runtime error if the key (index) is outside the requested scope.
  # @raise [RuntimeError] Raises a runtime error when no memory has been requested.
  def set key, val
    raise RuntimeError, "The memory to be write is outside the requested range." if key >= self.max?
    super key, val
  end
  
  # See get
  # @see get
  def [] key
    self.get key
  end
  
  # See set
  # @see set
  def []= key, val
    self.set key, val
  end
end

require "allocate/allocate"