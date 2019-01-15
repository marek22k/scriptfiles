# Author: m.k[aet]mk16[dot].de
# Free download from test.mk16.de/scriptFiles

print "Number: "
num = gets.to_i;
puts

x = num;
y = 1;
until x%10 == 0
    puts "Step: #{y}; #{x}%10 = #{x%10}"
    if y >= 6
        x -= 1;
    else
      x += 1;
    end
    y += 1;
end

puts "Step: #{y}; #{x}%10 = #{x%10}"
puts
puts "Result: #{x}"