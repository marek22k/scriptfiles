print "Please enter a number: "
n = gets.to_i
puts "\nFloyd's triangle:"

num = 1

for i in 1..n
  for j in 0...i
    print "#{num} "
    num += 1
  end
  puts
end