#!/usr/bin/ruby

# The author of this program is Marek Küthe
# Website: mk16.de
# E-Mail: m.k@mk16.de

puts "Hello User! Enter a number:"
num = gets.to_i

if num < 0
	puts "The number ist crazy!"
elsif num%2 == 0
	puts "The number is good!"
else
	puts "The number is bad!"
end