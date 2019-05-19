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

MStruct = Object.new
MStruct.define_singleton_method(:method_missing) do |name|
  obj = Object.new
  obj.define_singleton_method(:method_missing) do |name, *args, &block|
    sym = "@#{name.to_s}".to_sym
    if instance_variables.include? sym
      instance_variable_get sym
    elsif name.to_s[-1] == "="
      sym = "@#{name.to_s[0...-1]}".to_sym
      
      instance_variable_set sym, args[0] if args.length == 1
      instance_variable_set sym, args.to_a if args.length > 1
    elsif block != nil
      args.unshift name
      block.call args
    elsif args != []
      args.each { |x|
        x.call name if x.kind_of? Proc
      }
      name
    else
      name
    end
  end
  return obj
end

#s1 = MStruct.copy
#s2 = MStruct.new_struct
#s1.xy = 1, 2
#p s1.xy