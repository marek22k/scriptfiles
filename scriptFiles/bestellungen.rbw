# Author: Marek K.

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

require "net/http"
require "tk"
require "yaml"

puts "Lade Konfigurations Einstellungen..."

#conf

$span_class = "milestone-primaryMessage beta"

#conf end

puts "Lade Funktionen..."

def GetWebsiteContent address, schema = "https"
  uri = URI "#{schema}://#{address}"
  begin
    return res = Net::HTTP.start(uri.host, uri.port, :use_ssl => uri.scheme == "https") { |http|
      request = Net::HTTP::Get.new uri
     
      http.request request
    }
    rescue OpenSSL::SSL::SSLError => e
      return GetWebsiteContent address, "http"
    rescue Exception => e
      Tk.messageBox("type" => "ok", "icon" => "error", "title" => "Fehler", "message" => "Fehler beim Verbindungsaufbau!")
      exit!
    end
end

def show_window url, name = "No Name"

  res = GetWebsiteContent url
  data = res.body.scan(/<span class="#{$span_class}">\n(.*)\n[ ]*<\/span>/)
  
  if data.length < 4
    Tk.messageBox("type" => "ok", "icon" => "error", "title" => "Fehler", "message" => "Daten konnten nicht gelesen werden!")
    exit!
  end

  bestellt_am = data[0][0].match(/<span class=\".*\">(.*)<\/span>/)[1]
  versandt = data[1][0].match(/<span class=\".*\">(.*)<\/span>/)
  versandt = versandt[1] if versandt != nil
  versandt = "" if versandt == nil

  in_zustellung = data[2][0].match(/<span class=\".*\">(.*)<\/span>/)
  in_zustellung = in_zustellung[1] if in_zustellung != nil
  in_zustellung = "" if in_zustellung == nil

  zustellung = data[3][0].match(/<span class=\".*\">(.*)<\/span>/)[1]

  window_x = 500
  window_y = 400

  bgcolor = "orange"
  msg_begin_x = 15
  msg_begin_y = 30

  r = TkToplevel.new $main do
    title "Bestellung vom #{bestellt_am} - #{name[0..10]}..."
    minsize window_x, window_y
    background bgcolor
  end

  label1 = TkLabel.new r do
    text "Versandt: #{versandt==""?"Noch nicht versendet":versandt}"
    background bgcolor
    font TkFont.new("Palatino 13#{versandt!=""?" bold":""}")
  end

  label2 = TkLabel.new r do
    text "In Zustellung: #{in_zustellung==""?"Noch nicht in Zustellung":in_zustellung}"
    background bgcolor
    font TkFont.new("Palatino 13#{in_zustellung!=""?" bold":""}")
  end

  label3 = TkLabel.new r do
    text "Voraussichtliche Zustellung: #{zustellung}"
    background bgcolor
    font TkFont.new("Palatino 13 bold")
  end

  val = 0
  val += 25 if bestellt_am != ""
  val += 25 if versandt != ""
  val += 25 if in_zustellung != ""
  val += 25 if zustellung != ""

  pb = Tk::Tile::Progressbar.new r do
    value val
    orient "horizontal"
    length 500-msg_begin_x*2
  end

  label1.place "x" => msg_begin_x, "y" => msg_begin_y
  label2.place "x" => msg_begin_x, "y" => msg_begin_y + 30
  label3.place "x" => 500-msg_begin_x-320, "y" => msg_begin_y + 165
  pb.place "x" => msg_begin_x, "y" => msg_begin_y + 200
  
  return r

end

def main_window bestellungen

  mw_x = 500
  mw_y = 500
  
  bgcolor = "#80aaff"
  
  $list = TkVariable.new(bestellungen.keys)
  
  $main = TkRoot.new do
    title "Bestellungen Lieferverfolgung"
    minsize mw_x, mw_y
    maxsize mw_x, mw_y
    background bgcolor
  end
  
  $listbox1 = TkListbox.new $main do
    listvariable $list
    width 60
    height 20
  end
  
  button1 = TkButton.new $main do
    text "Details"
    background bgcolor
    foreground "black"
    font TkFont.new("Palatino 11")
    command proc {
      if $listbox1.curselection == []
        Tk.messageBox("type" => "ok", "icon" => "error", "title" => "Fehler", "message" => "Fehler: Es wurde keine Bestellung ausgewaehlt.", "detail" => "Binding: #{binding.local_variables}\nBestellungen: #{bestellungen}")
      else
        show_window bestellungen.values[$listbox1.curselection[0]], bestellungen.keys[$listbox1.curselection[0]]
      end
    }
  end
  
  button2 = TkButton.new $main do
    text "Hinzufuegen"
    background bgcolor
    foreground "black"
    font TkFont.new("Palatino 11")
    command proc {
      if $textbox1.get.length < 10
        Tk.messageBox("type" => "ok", "icon" => "error", "title" => "Fehler", "message" => "Der Eingegebene Name ist zu kurz!", "detail" => "Er muss mindestens 10 Zeichen haben.")
      else
        bestellungen[$textbox1.get] = $textbox2.get
        $list = TkVariable.new(bestellungen.keys)
        $listbox1["listvariable"] = $list
      end
    }
  end
  
  button3 = TkButton.new $main do
    text "Loeschen"
    background bgcolor
    foreground "black"
    font TkFont.new("Palatino 11")
    command proc {
      if $listbox1.curselection == []
        Tk.messageBox("type" => "ok", "icon" => "error", "title" => "Fehler", "message" => "Fehler: Es wurde keine Bestellung ausgewaehlt.", "detail" => "Binding: #{binding.local_variables}\nBestellungen: #{bestellungen}")
      else
        bestellungen.delete bestellungen.keys[$listbox1.curselection[0]]
        $list = TkVariable.new(bestellungen.keys)
        $listbox1["listvariable"] = $list
      end
    }
  end
  
  button4 = TkButton.new $main do
    text "Speichern"
    background bgcolor
    foreground "black"
    font TkFont.new("Palatino 11")
    command proc {
      File.open($file, "w") { |f|
        f.write YAML.dump(bestellungen)
        f.close
      }
      Tk.messageBox("type" => "ok", "icon" => "info", "title" => "Speicherung", "message" => "Die Datei wurde gespeichert.", "detail" => "File: #{$file}")
    }
  end
  
  label1 = TkLabel.new $main do
     text "Name:"
     background bgcolor
    font TkFont.new("Palatino 11")
  end
  
  label2 = TkLabel.new $main do
    text "Addresse:"
     background bgcolor
    font TkFont.new("Palatino 11")
  end
  
  label3 = TkLabel.new $main do
    text "(ohne http(s)://)"
     background bgcolor
    font TkFont.new("Palatino 10")
  end
  
  $textbox1 = TkEntry.new $main
  $textbox2 = TkEntry.new $main
  
  $listbox1.place "x" => 10, "y" => 10
  
  button1.place "x" => 380, "y" => 304
  button4.place "x" => 380, "y" => 450
  
  button3.place "x" => 380, "y" => 355
  button2.place "x" => 380, "y" => 390
  
  $textbox1.place "height" => 25, "width" => 280, "x" => 92, "y" => 350
  $textbox2.place "height" => 25, "width" => 280, "x" => 92, "y" => 390
  
  label1.place "x" => 10, "y" => 350
  label2.place "x" => 10, "y" => 390
  label3.place "x" => 10, "y" => 420
  
  $main.mainloop
end

puts "Start..."

Tk.messageBox("type" => "ok", "icon" => "info", "title" => "License/Lizenz", "message" => DATA.read)

$file = Tk.getSaveFile "filetypes" => [["YAML(*.yaml)", "*.yaml"]], "title" => "Bestellungen oeffnen/speichern"

unless File.exist? $file
  File.open($file, "w") { |f|
    f.write YAML.dump(Hash.new)
    f.close
  }
end
bestellungen = YAML.load_file($file)

main_window bestellungen

__END__
Author: Marek K.
    
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