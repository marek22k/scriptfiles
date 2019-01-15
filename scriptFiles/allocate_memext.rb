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

# This is a small extension of the RubyGem allocate

gem "allocate"
require "allocate"

class MemoryAllocater < Allocate
	def setzero!
		self.initmemory! 0
	end

	def initmemory! val
		for i in 0...self.max?
			self.set i, val
		end
		return self
	end

	def makebuffer!
		self.free
		self.alloc 1
		return self
	end

	def setbuffer val
		unless self.good?
			self.makebuffer!
		end
		self.set 0, val
		return self
	end

	def getbuffer
		self.get 0
	end

	def deletebuffer
		self.free
	end

	def [] ind
		self.get ind
	end

	def []= ind, val
		self.set ind, val
	end
end

class MemoryArray
	include Enumerable

	def initialize
		@allocs = Array.new
	end

	def push ind
		@allocs.push MemoryAllocater.new
		@allocs.last.alloc ind
	end

	def pop ind
		@allocs[ind].free
		@allocs.delete_at ind
	end

	def [] ind
		@allocs[ind]
	end

	def size
		@allocs.size
	end

	def shift
		@allocs.shift
	end

	def insert ind1, ind2
		@allocs.insert ind1, MemoryAllocater.new
		@allocs[ind1].alloc ind2
	end

	def delete_at ind
		@allocs.delete_at ind
	end

	def clear
		@allocs.each { |x| x.free }
		@allocs.clear
	end

	def at ind
		self.[] ind
	end

	def each
		raise "No block given!" unless block_given?
		@allocs.each { |x| yield x }
	end

	def first
		@allocs[0]
	end

	def last
		@allocs[-1]
	end
end

=begin
Example:
a = MemoryAllocater.new

a.alloc 256
a.setzero!
p a[123]
a[123] = 123
p a.get 123
a.free

a.makebuffer!
a.setbuffer 2
p a.getbuffer
a.deletebuffer

arr = MemoryArray.new
arr.push 1
arr.push 2
arr.delete_at 0
arr.shift
arr.insert 0, 4
arr.at(0).alloc 5
arr[0][0] = 4;
p arr[0][0]

arr.each { |x| puts x }

arr.clear
=end
