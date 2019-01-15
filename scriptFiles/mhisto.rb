#!/usr/bin/ruby

# mhisto written by Marek K.

=begin

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Dieses Programm ist Freie Software: Sie koennen es unter den Bedingungen
    der GNU General Public License, wie von der Free Software Foundation,
    Version 3 der Lizenz oder (nach Ihrer Wahl) jeder neueren
    veroeffentlichten Version, weiter verteilen und/oder modifizieren.

    Dieses Programm wird in der Hoffnung bereitgestellt, dass es nuetzlich sein wird, jedoch
    OHNE JEDE GEWAEHR,; sogar ohne die implizite
    Gewaehr der MARKTFAEHIGKEIT oder EIGNUNG FUER EINEN BESTIMMTEN ZWECK.
    Siehe die GNU General Public License fuer weitere Einzelheiten.

    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
    Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.

=end

require "json"

$ErrLogFile = "errlog.json"

def ErrLog e
  puts "Error: #{e.message};"
  begin
    fil = File.new($ErrLogFile, "r")
    ary = JSON.parse(fil.read())
  fil.close
  rescue Errno::ENOENT => e
  rescue
    ary = nil
  end
  fil = File.new($ErrLogFile, "w")
  ary = Array.new unless ary
  ary << [e.message, e.backtrace, Time.new.to_s]
  JSON.dump(ary, fil)
  fil.close
  exit!
end

def Arymax ary
  m = 0
  ary.each { |x| m = x.to_i if x.to_i > m }
  return m
end

def DrawHistogram g
  begin
    for i in 0...g.length
      g[i] = g[i].to_i
    end
  
    g.sort!

    i = 0
    until i == g.length
      c = g.count(g[i])
      Arymax(g).to_s.length.times { print " " }
      print "|  "
      c.times { print "_" }
      print "\n#{g[i]}"
      (Arymax(g).to_s.length-g[i].to_s.length).times { print " " }
      print "| |"
      c.times { print "_" }
      print "|\n"
      i += c
    end
  rescue Exception => e
    ErrLog(e)
  end
  return g
end

def NewHistogram
  begin
  print "Data: "
  g = gets.chomp.split " "
  rescue Exception => e
    ErrLog(e)
  end
  return DrawHistogram(g)
end

def OpenHistogram filename
  begin
    fil = File.new(filename, "r")
    g = JSON.parse(fil.read())
    fil.close
    DrawHistogram g
  rescue Exception => e
    ErrLog(e)
  end
end

def SaveHistogram g, filename
  begin
    fil = File.new(filename, "w")
    JSON.dump(g, fil)
    fil.close
  rescue Exception => e
    ErrLog(e)
  end
end

def ReadErrLog
    fil = File.new($ErrLogFile, "r")
    begin
      ary = JSON.parse(fil.read())
    rescue JSON::ParserError => e
      puts "No erros; errlog.json is empty;"
      exit!
    end
    fil.close
    ary.each { |x|
      puts "Errormessage: #{x[0]}"
      puts "Errorbacktrace: #{x[1]}"
      puts "Date and time: #{x[2]}"
      puts
    }
end

begin
  puts "1 - New Histogram"
  puts "2 - Open Histogram"
  puts "3 - Read ErrLog(errlog.json)"
  puts "4 - Clear ErrLog(errlog.json)"
  puts "5 - Version"
  print "\nOption: "
  sel = gets.to_i
rescue Exception => e
  ErrLog(e)
end

case sel
  when 1
    print "\nFilename: "
    filename = gets.chomp
    SaveHistogram NewHistogram(), filename
  when 2
    print "\nFilename: "
    filename = gets.chomp
    OpenHistogram filename
  when 3
    ReadErrLog()
  when 4
    begin
      File.delete($ErrLogFile, "w")
    rescue Errno::ENOENT => e
    end
  when 5
    puts "\n#{DATA.read()}"
end

__END__
English:

mhisto
======

mhisto was written on 18/05/2018 by Marek K. in the programming language Ruby.
mhisto sets, saves, opens histograms.

Create a new histogram(Option 1):
1. In the main menu, select the first option(Option 1)
2. Next, enter the file name from the file in which the histogram is to be saved.
3. Next enter the histogram data(eg 1 1 5 6 9 90 80 80 4 5 5 80 7 4 7)
The histogram is automatically saved when viewing the histogram in the file.

Open a histogram(Option 2):
1. In the main menu, select the second option (Option 2)
2. After that, enter the filename from the file where the histogram is stored

Option 3: View the ErrLog(errlog.json)
Option 4: Clear or clear the ErrLog(errlog.json)
Option 5: Display this message

The filenames you specify should have the file extension .json because the data is saved in JSON format.


German:

mhisto
======

mhisto wurde am 18.05.2018 von Marek K. in der Programmiersprache Ruby geschrieben.
mhisto setzt, speichert, oeffnet Histogramme.

Erstellen Sie ein neues Histogramm(Option 1):
1. Waehlen Sie im Hauptmenue die erste Option(Option 1)
2. Als naechstes geben sie den Dateinamen, von der Datei in der das Histogramm gespeichert werden soll, ein.
3. Als naechstes geben Sie die Histogrammdaten ein (z. B. 1 1 5 6 9 90 80 80 4 5 5 80 7 4 7)
Das Histogramm wird automatisch beim anzeigen des Histogramms in der Datei gespeichert.

oeffnen eines Histogramms(Option 2):
1. Waehlen Sie im Hauptmenue die zweite option(Option 2)
2. Danach, geben Sie den Dateinamen, von der Datei in der das Histogramm gespeichert ist, ein

Option 3: Anzeigen des ErrLog(errlog.json)
Option 4: Loeschen bzw. leeren des ErrLog(errlog.json)
Option 5: Anzeigen dieser Meldung

Die Dateinamen, die Sie angeben, sollten die Dateiendung .json haben, weil die Daten im JSON format gespeichert werden.