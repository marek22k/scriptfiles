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
  
=end

require "tk"

def CreatePassword
  srand Random.new_seed
  res = ""
  
  for i in 1..$entry3.value.to_i
    res += $entry2.value[rand(0...$entry2.value.length)]
  end
  
  $entry1.value = res
end

bg = "orange"

$r = TkRoot.new do
  title "Random Password"
  minsize 400, 300
  maxsize 400, 300
  background bg
  iconbitmap "random_password_ico.ico"
end

$photoimage1 = TkPhotoImage.new :file => "./random_password_gif.gif"

$label1 = TkLabel.new $r do
  text "Password: "
  font TkFont.new("size" => 12, "family" => "Courier New")
  background bg
end

$label2 = TkLabel.new $r do
  text "Symbols: "
  font TkFont.new("size" => 12, "family" => "Courier New")
  background bg
end

$label3 = TkLabel.new $r do
  text "Length: "
  font TkFont.new("size" => 6, "family" => "Courier New")
  background bg
end

$label4 = TkLabel.new $r do
  image $photoimage1
  height 200
  width 350
  borderwidth 0
end

$button1 = TkButton.new $r do
  text "New password"
  font TkFont.new("size" => 12, "family" => "Courier New")
  borderwidth 0
  foreground "darkorange"
  background "gray"
  activebackground "blue"
  activeforeground "white"
  command Proc.new { CreatePassword() }
end

$entry1 = TkEntry.new $r do
  font TkFont.new("size" => 12, "family" => "Courier New")
  width 20
end

$entry2 = TkEntry.new $r do
  font TkFont.new("size" => 12, "family" => "Courier New")
  width 20
end

$entry3 = TkEntry.new $r do
  font TkFont.new("size" => 12, "family" => "Courier New")
  width 2
end

$label1.grid "row" => 0, "column" => 0
$entry1.grid "row" => 0, "column" => 1
$label3.grid "row" => 0, "column" => 2
$entry3.grid "row" => 0, "column" => 3

$label2.grid "row" => 1, "column" => 0
$entry2.grid "row" => 1, "column" => 1

$button1.grid "row" => 2, "column" => 1

$label4.place "x" => 25, "y" => 86

$entry2.value = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopstuvwxyz!$%&()=?{[]}\*+~#-_.:,;<>|"
$entry3.value = "7"
CreatePassword()

$r.mainloop