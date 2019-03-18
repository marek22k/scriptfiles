require "chunky_png"


arr = ARGV[1].chomp.bytes

while arr.size%3 != 0
	arr << 0
end

p arr

png = ChunkyPNG::Image.new(arr.size / 3 + 1, 1, ChunkyPNG::Color::TRANSPARENT)

for i in (0...arr.size).step 3
	png[i / 3, 0] = ChunkyPNG::Color.rgb(arr[i].to_i, arr[i + 1].to_i, arr[i + 2].to_i)
end


png.save(ARGV[0])