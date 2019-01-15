-- Author: Marek K.

--[[

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
  
--]]

md5 = require "md5"

if arg[1] == "sum" then
    print("Open file to write ...")
    f = assert(io.open(arg[3], "wb"), "Can not open file to write")

    print("Create MD5 and write ...")
    f:write(md5.sum(arg[2]))

    print("Close file ...")
    f:close()
elseif arg[1] == "eql" then
    print("Open first file to read ...")
    f = assert(io.open(arg[2], "rb"))
    s1 = f:read()
    print("Close first file ...")
    f:close()

    print("Open second file to read ...")
    f = assert(io.open(arg[3], "rb"))
    s2 = f:read()
    print("Close second file ...")
    f:close()

    if s1 == s2 then
        print("Result: True")
    else
        print("Result: False")
    end
else
    print("Invalid input!")
    print("sum [text] [file]")
    print("Retrieves the MD5 value of [text] and saves it in [file].")
    print("eql [file 1] [file 2]")
    print("Compares the values of [file 1] and [file 2]. If they are equal then the result is True, otherwise False.")
end