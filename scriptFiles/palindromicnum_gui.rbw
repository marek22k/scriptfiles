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

def algol196 x, n = 0
  return x if x.to_s.reverse == x.to_s
  return -1 if n == 56
  $listbox1.insert 0, "#{n+1}: #{x} + #{x.to_s.reverse.to_i} = #{x + x.to_s.reverse.to_i}"
  return algol196(x + x.to_s.reverse.to_i, n + 1)
end

$window_x = 500
$window_y = 550

$bgcolor = "#ff9933"

$r = TkRoot.new do
  title "Palindromic number - 196-Algorithm"
  minsize $window_x, $window_y
  maxsize $window_x, $window_y
  background $bgcolor
end

$label1 = TkLabel.new $r do
  text "Palindromic number"
  font TkFont.new("Linotype 20")
  background $bgcolor
end

$label2 = TkLabel.new $r do
  text "Number: "
  font TkFont.new("Linotype 12")
  background $bgcolor
end

$label3 = TkLabel.new $r do
  text "Number: "
  font TkFont.new("Linotype 12")
  background $bgcolor
end

$label4 = TkLabel.new $r do
  text "196-Algorithm"
  font TkFont.new("Linotype 20")
  background $bgcolor
end

$entry1 = TkEntry.new $r do
  font TkFont.new("Linotype 12")
  width 10
end

$entry2 = TkEntry.new $r do
  font TkFont.new("Linotype 12")
  width 10
end

$button1 = TkButton.new $r do
  text "Check"
  font TkFont.new("Linotype 11")
  borderwidth 2
  background $bgcolor
  foreground "black"
  command Proc.new {
    Tk.messageBox( "type" => "ok", "icon" => "info", "title" => "Result", "message" =>
    "#{$entry1.value} is #{if $entry1.value.to_i != $entry1.value.reverse.to_i then 'not ' end}a palindromic number!" )
  }
end

$button2 = TkButton.new $r do
  text "Check"
  font TkFont.new("Linotype 11")
  borderwidth 2
  background $bgcolor
  foreground "black"
  command Proc.new {
    $listbox1.delete 0, "end"
    x = algol196 $entry2.value.to_i
    Tk.messageBox( "type" => "ok", "icon" => "info", "title" => "Result", "message" =>
    if x != -1 then "#{$entry2.value.to_i} is a Anti-Lychrel number; The Palindrome is #{x} :-)" else
    "#{$entry2.value.to_i} is a Lychrel number :-(" end )
  }
end

$listbox1 = TkListbox.new $r do
  height 15
  width 60
  background $bgcolor
  borderwidth 2
  yscrollcommand Proc.new { |*args| $scrollbar1.set(*args) }
  xscrollcommand Proc.new { |*args| $scrollbar2.set(*args) }
end

$scrollbar1 = TkScrollbar.new $r do
  orient "vertical"
  command Proc.new { |*args| $listbox1.yview(*args) }
  borderwidth 2
end

$scrollbar2 = TkScrollbar.new $r do
  orient "horizontal"
  command Proc.new { |*args| $listbox1.xview(*args) }
end

$label1.place "x" => 106, "y" => 5
$label4.place "x" => 106, "y" => 130

begin_input1 = 130
$entry1.place "x" => begin_input1+65, "y" => 60
$label2.place "x" => begin_input1, "y" => 60
$button1.place "x" => begin_input1+170, "y" => 60

begin_input2 = 130
$entry2.place "x" => begin_input2+65, "y" => 185
$label3.place "x" => begin_input2, "y" => 185
$button2.place "x" => begin_input2+170, "y" => 185

$listbox1.place "x" => 70, "y" => 225
$scrollbar1.place "x" => 440, "y" => 225, "height" => 250
$scrollbar2.place "x" => 70, "y" => 475, "width" => 370

$r.mainloop