def setzen(grose)
	File.open("data.txt", "w") { |f|
		f << "#{grose}\n#{grose}"
		f.close
	}
end

def messen(anzahl)
	ergebnis = 0.0
	anzahl.times {
		ergebnis += `neighbor_letters < data.txt`.match(/([0-9]+) adjacent letters were found\./)[1].to_f
	}
	return ergebnis/anzahl.to_f
end

Genauigkeit = 100

for i in 0..20
setzen(i)
puts "Bei i=#{i} ist r=#{messen(Genauigkeit)}"
end