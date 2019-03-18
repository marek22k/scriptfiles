require "chunky_png"

png = ChunkyPNG::Image.from_file(ARGV[0])

for i in (0...png.width).step 1
	for j in (0...png.height).step 1
		png[i, j] = ChunkyPNG::Color.rgb((ChunkyPNG::Color.r(png[i, j])*2)%256 , (ChunkyPNG::Color.g(png[i, j])*2)%256, (ChunkyPNG::Color.b(png[i, j])*2)%256)
	end
end


png.save(ARGV[1])