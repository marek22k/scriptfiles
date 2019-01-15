x = gets.chomp

def isDisarium x
  sum = 0

  for i in 0...x.length
    sum += x[i].to_i ** (i + 1)
  end
    
  return sum == x.to_i
end

if (! x.include? " ")
  if isDisarium x
    puts "#{x} is a disarium number :-)"
  else
    puts "#{x} is not a disarium number :-("
  end
else
  a = x.split(" ")
  b = a[1]
  a = a[0]
    
  for i in a..b
    puts "#{i} is a disarium number :-)" if isDisarium i
  end
end