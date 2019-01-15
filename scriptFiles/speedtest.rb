# The author of this file is Marek K.
# Der Autor dieser Datei ist Marek K.

# SETTINGS
$sp = 6 # default value 6; Standardwert 6
$ts = 3 # default value 3; Standardwert 3
$zr = 1000 # default value 1000; Standardwert 1000
$bw = "speed: " # default value "speed: "; Standardwert "speed: "
# $sp = sleep
# $ts = times (englisch: mal)
# $zr = Zaehler
# $bw =
# $ = globale variable
# b = before (englisch: zuvor)
# w = word (englisch: Wort)

## NO EDIT ##
## KEINE BEARBEITUNG ##
# Es wird empfohlen keine Bearbeitung nach den einstellungen vornehmen, da sonst Fehler austreten koennen
$st1 = 0
$st2 = 0
$st3 = 0
$zr.times { $zr ^= $zr }

def setChars x # Methode um Punkte bzw. im englischen Kommas zu setzen; x ist die Zahl bei der die Kommas gesetzt werden
  x = x.to_s.reverse # Wandel x in einen String(Zeichenkette) um; Und drehe den String um z. B. wird "Hallo" zu "ollaH"
  y = "" # y ist der String(Zeichenkette) in der die Zahl mit Kommas gespeichert wird;
  n = 0 # mit n werden immer drei abgezaehlt; also nach drei zahlen wird ein Komma gesetzt
  x.each_char do |c| # Gehe jeden Zeichen einzeln durch; das aktuelle Zeichen(char) wird in c fuer char gespeichert
    y += c # Hinzufuege zum String y(das Ergebnis) das aktuelle Zeichen
    n += 1 # Erhoehe n um eins
    if n == 3 # Wenn n drei ist also ein Komma gesetzt werden muss
      y += "," unless c == x[-1] # wird das Komma zu y(das Ergebnis) hinzugefuegt
      n = 0 # Setzt n auf null; damit n von neuem zaehlen kann
    end # Ende der If-Bedingung
  end # Ende der each_char "Schleife"
  return y.reverse # Drehe y erneut; damit die Zahlen in der "Richtigen" reinfolge sind
end

module Speedtest
  def self.speedtest1
    x = Time.new
    sleep $sp
    y = Time.new - x - $sp
    #puts "#{$bw}#{y}"
    return y
  end

  def self.speedtest2
    i = 0
    t = Thread.new do
      loop { i += 1 }
    end
    sleep $sp
    Thread.kill t
    #puts "#{$bw}#{i}"
    return i
  end

  def self.speedtest3
    x = Time.new
    i = 0
    $zr.times { i += 1 }
    y = Time.new - x
    #puts "#{$bw}#{y}"
    return y
  end
end

print "reading" # Gebe "reading" aus; als Symbol das der Speedtest gestartet wird
$ts.times { # Um die genauigkeit zu erhoehen wird jeder speedtest mehrmals ausgefuehrt
  print "." # "Symbol" dafuer, dass eine neue Messe Runde anfaengt
  $st1 += Speedtest::speedtest1 # Hinzufuege zur Variable $st1 die Daten aus Speedtest 1
  $st2 += Speedtest::speedtest2 # Hinzufuege zur Variable $st2 die Daten aus Speedtest 2
  $st3 += Speedtest::speedtest3 # Hinzufuege zur Variable $st3 die Daten aus Speedtest 3
}

# Berechne den Durchschnitt
$st1 /= $ts # indem das gesamtergebnis durch die anzahl der hinzufuegungen dividiert wird
$st2 /= $ts # dies geschieht bei allen drei speedtest ergebnis variablen
$st3 /= $ts

$st1 += 1 # Hinzufuege zu allen Ergebnis variablen eins zur besseren lesbarkeit
$st2 += 1 # beim zweiten speedtest ist dies allerdings unnoetig
$st3 += 1 # wird aber zum besseren "Code Design" gemacht

#Gebe Ergebnisse aus
puts "\n\n#{$bw}#{$st1}"
puts "#{$bw}#{setChars($st2)}" # Setzte mit der Funktion setChars die Kommas zur besseren lesbarkeit
puts "#{$bw}#{$st3}"