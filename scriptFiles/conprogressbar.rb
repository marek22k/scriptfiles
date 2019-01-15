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

# @author Marek K. <mailto:m.k@mk16.de, http://mk16.de>
# @example
#   puts "Build ..."
#   pb = ConProgressBar.new
#   100.times { |x|
#     pb.up!
#     sleep 0.01
#   }
#   pb.delete
#   puts "Complete."
# @example
#   require "conprogressbar"
#   puts "Catch ..."
#   pb = ConProgressBar.new 0, ".", ">", "<", ",", STDERR
#   100.times { |x|
#     pb.update pb.percent + 1
#     sleep 0.01
#   }
#   pb.update 0
#   puts
# @note The file conprogessbar.rb is available under the {https://www.gnu.org/licenses/gpl.txt GNU GPL v3}.
class ConProgressBar

  # Initializes the class ConProgressBar and thus a new progressbar on the console.
  # @note There should be no other issues in the same stream as long as the ProgressBar is used.
  # @note The arguments symbol, beg, en and space must have a length of one.
  # @param percent [Integer] The percentage with which the progressbar should be initialized.
  # @param symbol [String] The symbol which draws the already loaded area on the Progressbar.
  # @param beg [String] The symbol for the introduction of the Progressbar.
  # @param en [String] The symbol that initiates the end of the progressbar.
  # @param space [String] The symbol that fills the not yet loaded part of the progress bar.
  # @param stream [IO] The stream to which the progressbar should be written.
  # @raise [ArgumentError] Dispatched when one of the arguments has not been specified correctly.
  def initialize percent=0, symbol="=", beg="<", en=">", space=" ", stream=STDOUT
    raise ArgumentError, "Argument 1" if percent < 0 || percent > 100
    raise ArgumentError, "Argument 2" if symbol.length != 1
    raise ArgumentError, "Argument 3" if beg.length != 1
    raise ArgumentError, "Argument 4" if en.length != 1
    raise ArgumentError, "Argument 5" if space.length != 1
    
    @percent = percent
    @symbol = symbol
    @beg = beg
    @en = en
    @space = space
    @stream = stream
    
    print @beg
    percent.times {
      @stream.print @symbol
    }
    (100-percent).times {
      @stream.print @space
    }
    out = percent.to_s
    while out.length < 3
      out = "0" + out
    end
    @stream.print "#{@en} #{out}%"
    @stream.flush
  end
  
  # Returns the current percentage
  # @return [Integer] The current percentage of the progressbar
  def percent
    @percent
  end
  
  # Increases the percentage of progressbar by one and updates the prompts bar.
  # @return [NilClass] nil
  # @raise [RuntimeError] Is triggered when the percentage can not be increased, because the maximum has already been reached.
  def up!
    raise RuntimeError, "Down" if @percent == 100
    @percent += 1
    self.update
  end
  
  # Decreases the percentage of progressbar by one and updates the prompts bar.
  # @return [NilClass] nil
  # @raise [RuntimeError] Will be triggered when the percentage can not be lowered, because the minimum has already been reached.
  def down!
    raise RuntimeError, "Down" if @percent == 0
    @percent -= 1
    self.update
  end
  
  # Updates the progressbar.
  # It is possible to specify a percentage that should be set.
  # @param percent [Integer, NilClass] The percentage to which the progressbar should be updated. Without specification (nil) the progress bar is updated to the already defined number.
  # @return [NilClass] nil
  # @raise [ArgumentError] Dispatched when the percent argument is less than 0 or greater than 100.
  def update percent=nil
    if percent == nil
      percent = @percent
    else
      raise ArgumentError, "Argument 1" if percent < 0 || percent > 100
      @percent = percent
    end
    
    (106).times {
      @stream.print "\b"
    }
    
    percent.times {
      @stream.print @symbol
    }
    (100-percent).times {
      @stream.print @space
    }
    out = percent.to_s
    while out.length < 3
      out = "0" + out
    end
    @stream.print "#{@en} #{out}%"
    @stream.flush
    nil
  end
  
  # Deletes the progressbar from the stream
  # @return [NilClass] nil
  def delete
    107.times { @stream.print "\b" }
    107.times { @stream.print "\0" }
    107.times { @stream.print "\b" }
    @stream.flush
  end
end