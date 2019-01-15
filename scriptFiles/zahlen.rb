# Dateiname: zahlen.rb

# Erstellt am: 04.06.2017

# Erstellt von: m[dot]k[aet]mk16[dot]de
# [dot] = .    ( Anti-Bots )
# [aet] = @

# Im Web unter der Adresse: http://test.mk16.de/scriptFiles/zahlen.rb

# Ausgefuhrt in: ca. 0.11 Sekunden

# Beschreibung: 
# Nummern von null 0 bis zwolf 12.
# Ausgabe der Nummern mit zahlen.select und dann werden die Zahlen mit puts ausgegeben.

zahlen = Hash.new

zahlen = {
    "null  " => "0" ,
    "eins"   => "1" ,
    "zwei"   => "3" ,
    "vier"   => "4" ,
    "funf"   => "5" ,
    "sechs"  => "6" ,
    "sieben" => "7" ,
    "acht"   => "8" ,
    "neun"   => "9" ,
    "zehn"   => "10",
    "elf"    => "11",
    "zwolf"  => "12"
}

zahlen.select do |k,v| puts "#{k} = #{v}" end