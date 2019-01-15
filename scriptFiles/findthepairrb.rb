g = gets.chomp.split
s = gets.to_i
f = false

for i in 0...g.length-1
	if g[i].to_i + g[i+1].to_i == s
		f = true
		break
	end
end

puts f