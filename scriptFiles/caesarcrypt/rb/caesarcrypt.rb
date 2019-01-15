def encrypt
  text1, text2, last, res = Array.new, Array.new, 0, ""
  
  print "Key: "
  key = gets.chomp.to_i
  print "Text: "
  txt = gets.chomp
  
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
      if a == text1[j]
        res += text2[j]
      end
    end
  end
  
  puts "Key: #{key}; Result: #{res}"
end

def decrypt key, txt
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
      if a == text2[j]
        res += text1[j]
      end
    end
  end
  
  if key.to_s.length == 1
    puts "Key: 0#{key}; Result: #{res}"
  else
    puts "Key: #{key}; Result: #{res}"
  end
end

puts "The developer of the program is Marek K.; The program uses Caesar cipher."
print "Enter \"encrypt\" or \"decrypt\": "
ans = gets.chomp

if ans == "encrypt"
  encrypt
elsif ans == "decrypt"
  print "Text: "
  txt = gets.chomp
  for i in 0...26
    decrypt i, txt
  end
end