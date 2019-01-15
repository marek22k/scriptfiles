x = gets.chomp.to_i

puts "#{x} is #{unless x**2 == (x.to_s.reverse.to_i**2).to_s.reverse.to_i then 'not 'end}a Adam number!"