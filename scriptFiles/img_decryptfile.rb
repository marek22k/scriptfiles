require "chunky_png"

png = ChunkyPNG::Image.from_file(ARGV[0])

arr = Array.new

for i in 0...png.width-1
	arr << ChunkyPNG::Color.r(png[i, 0]) << ChunkyPNG::Color.g(png[i, 0]) << ChunkyPNG::Color.b(png[i, 0])
end

p arr
File.open(ARGV[1], "w") { |f|
	arr.each { |x|
		f << x.chr
	}
	f.close
}