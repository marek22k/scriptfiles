require "tk"

root = TkRoot.new {
    title "Sqrt GUI"
    geometry "465x150"
    background "gray"
}

textfield1 = TkEntry.new(root) {
    insert 0, "2"
    background "royalblue"
    foreground "#00FF00"
    borderwidth 4
}

textfield2 = TkEntry.new(root) {
    insert 0, "1.4142135623730951"
    background "red"
    foreground "yellow"
    borderwidth 4
}

label1 = TkLabel.new(root) {
    text "Sqrt:"
    background "gray"
}

label2 = TkLabel.new(root) {
    text "           Result:"
    background "gray"
}

button1 = TkButton.new(root) {
    text "Get sqrt"
    command {
        textfield2.delete 0, "end"
        textfield2.insert 0, Math.sqrt(textfield1.get.to_f)
    }
    background "black"
    foreground "white"
    activebackground "black"
    activeforeground "gray"
    borderwidth 5
    cursor "circle"
}

label1.pack "side" => "left"
textfield1.pack "side" => "left"
label2.pack "side" => "left"
textfield2.pack "pady" => 6, "side" => "left"
button1.pack "padx" => 15, "side" => "bottom"

root.mainloop