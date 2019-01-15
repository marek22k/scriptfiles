require "tk"
puts "13%"

root = TkRoot.new
puts "25%"
root.title "Modulus Calculator"
root.geometry "500x300"
root.cursor "circle"

textfield1 = TkEntry.new root
puts "38%"
textfield1.insert 0, "0"

textfield2 = TkEntry.new root
puts "50%"
textfield2.insert 0, "1"

textfield3 = TkEntry.new root
puts "63%"
textfield3.insert 0, "0"

def button1_click textfield1, textfield2, textfield3
    textfield3.delete 0, "end"
    result = textfield1.get.to_i % textfield2.get.to_i
    textfield3.insert 0, result
end

button1 = TkButton.new root
puts "75%"
button1.text "Get modulus"
button1.command {button1_click textfield1, textfield2, textfield3}
button1.background "yellow"
button1.foreground "blue"
button1.activebackground "blue"
button1.activeforeground "yellow"
button1.font TkFont.new("arial 9")
button1.borderwidth 3
button1.cursor "X_cursor"
puts "88%"

textfield1.pack
textfield2.pack
textfield3.pack "pady" => "10"
button1.pack "side" => "right" , "padx" => "26"
puts "100%"

root.mainloop