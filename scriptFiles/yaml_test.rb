require "yaml"

p YAML.load([[5, 6, 7], 8].to_yaml)
p YAML.load(YAML.dump([7, 8, 9]))
p YAML.dump_stream("hallo", "welt")

File.open("test.yml", "w") do |out|
	YAML.dump( [[0, 1], [2, 3, 4, 5, 6, 7], [8, 9], ["A", "B", "C", "D", "E", "F"]], out )
end

p YAML.load_file("test.yml")