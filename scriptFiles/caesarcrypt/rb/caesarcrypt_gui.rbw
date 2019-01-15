require 'tk'

def crypt key, txt, str = "encrypt"
  text1, text2, last, res = Array.new, Array.new, 0, ""
  
  for i in 0...26
    text1 << (97 + i).chr
  end
  
  for i in 0...26
    t = 97 + i + key
    if t > 122
       last = i
       break
    else
       text2 << t.chr
    end
  end
  
  for i in last...26
    text2 << (97 + i - last).chr
  end
  
  for i in 0...txt.length
    a = txt[i]
    for j in 0...26
      if str == "encrypt"
        if a == text1[j]
          res += text2[j]
        end
      elsif
        if a == text2[j]
          res += text1[j]
        end
      end
    end
  end
  
  return res
end

def press_encryptButton object1, object2
  text = object2.get("0.0", "end")
  for i in 0...26
    object1.insert 0, "Key: #{i}; Result: #{crypt(i, text, "encrypt")}"
  end
end

def press_decryptButton object1, object2
  text = object2.get("0.0", "end")
  for i in 0...26
    object1.insert 0, "Key: #{i}; Result: #{crypt(i, text, "decrypt")}"
  end
end

def draw  r

  r.title = "caesarcrypt"
  r.maxsize 1000, 1000
  r.minsize = 800, 500
  
  resultList = TkListbox.new r do
    height "26"
    
    pack "fill" => "x"
  end
  
  textBox = TkText.new r do
    height "1"
    
    pack "side" => "left"
  end
  
  decryptButton = TkButton.new r do
    command proc {press_decryptButton resultList, textBox}
    text "Decrypt"
    
    pack "side" => "right", "padx" => "5"
  end
  
  encryptButton = TkButton.new r do
    command proc {press_encryptButton resultList, textBox}
    text "Encrypt"
    
    pack "side" => "right", "padx" => "5"
  end
  
  return r
end

r = TkRoot.new
r = draw r
r.mainloop