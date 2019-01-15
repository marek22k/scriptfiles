require "tk"

def pressbutton obj1, obj2, obj3
  x = obj1.get("0.0", "end").to_i
  y = obj2.get("0.0", "end").to_i
  z = x + y
  obj3.insert 0, "#{x}+#{y}=#{z}"
end

r=TkRoot.new do
  title "Addition"
  minsize 300, 300
  maxsize 300, 300
  background "#99ff66"
  iconbitmap "logo.ico"
end

tb1=TkText.new r do
  height "1"
  width "10"
  background "#2a8000"
  foreground "white"
end

tb2=TkText.new r do
  height "1"
  width "10"
  background "#2a8000"
  foreground "white"
end

la1=TkLabel.new r do
  text "+"
  background "#99ff66"
end

lb1=TkListbox.new r do
  height "7"
  background "#d3d3d3"
end

bu1=TkButton.new r do
  text "="
  command proc {pressbutton tb1, tb2, lb1}
end

tb1.pack "pady"=>"10"
la1.pack
tb2.pack "pady"=>"10"
bu1.pack "pady"=>"10"
lb1.pack

r.mainloop