require "chunky_png"

png = ChunkyPNG::Image.from_file(ARGV[0])

for i in 0...png.width
	for j in 0...png.height
		png[i, j] = ChunkyPNG::Color.rgb(255 - ChunkyPNG::Color.r(png[i, j]), 255 - ChunkyPNG::Color.g(png[i, j]), 255 - ChunkyPNG::Color.b(png[i, j]))
	end
end


png.save(ARGV[1])