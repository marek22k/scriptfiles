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

    Dieses Programm ist Freie Software: Sie können es unter den Bedingungen
    der GNU General Public License, wie von der Free Software Foundation,
    Version 3 der Lizenz oder (nach Ihrer Wahl) jeder neueren
    veröffentlichten Version, weiter verteilen und/oder modifizieren.

    Dieses Programm wird in der Hoffnung bereitgestellt, dass es nützlich sein wird, jedoch
    OHNE JEDE GEWÄHR,; sogar ohne die implizite
    Gewähr der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
    Siehe die GNU General Public License für weitere Einzelheiten.

    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
    Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.

=end


require "net/http"
require "json"
require "tk"

$error = ""

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
      puts e
      print "ERROR"
      exit!
    end
end

def IsOnline

  response = GetWebsiteContent("api.freenom.com/v2/service/ping")
  if response.code == "200"
    h = JSON.parse response.body
    if h["status"] == "OK" && h["result"] == "PING REPLY"
      return h["timestamp"]
    end
  end
  return false
  
end

def SearchDomain domain

  response = GetWebsiteContent("api.freenom.com/v2/domain/search?domainname=#{domain}&domaintype=FREE&email=#{$textbox2.get}&password=#{$textbox3.get}")
  h = JSON.parse response.body
  if response.code == "200"
    if h["status"] == "OK"
      return h["result"] == "DOMAIN AVAILABLE"
    end
  else
    if h["status"] == "error"
      $error = h["error"]
    end
  end
  return false
  
end

window_x = 500
window_y = 500
bgcolor = "#00ccff"

$r = TkRoot.new do
  title "Freedom"
  minsize window_x, window_y
  maxsize window_x, window_y
  background bgcolor
end

$label1 = TkLabel.new $r do
  text "Status: Loading..."
  background bgcolor
  font TkFont.new("Palatino 11")
end

Thread.new {
  loop do
    $label1["text"] = "Status: #{IsOnline()}"
    sleep 2
  end
}

label2 = TkLabel.new $r do
  text "Domain: "
  background bgcolor
  font TkFont.new("Palatino 11")
end

$label3 = TkLabel.new $r do
  text ""
  background bgcolor
  font TkFont.new("Palatino 13")
end

label4 = TkLabel.new $r do
  text "Username: "
  background bgcolor
  font TkFont.new("Palatino 13")
end

label5 = TkLabel.new $r do
  text "Password: "
  background bgcolor
  font TkFont.new("Palatino 13")
end

label6 = TkLabel.new $r do
  text "URL: "
  background bgcolor
  font TkFont.new("Palatino 11")
end

$textbox1 = TkEntry.new $r do
  width 20
end

$textbox2 = TkEntry.new $r do
  width 20
end

$textbox3 = TkEntry.new $r do
  width 20
  show "*"
end

button1 = TkButton.new $main do
  text "Check"
  background bgcolor
  font TkFont.new("Palatino 11")
  command proc {
    Thread.new {
    arr = [".tk", ".ml", ".ga", ".cf", ".gq"]
    $label3["text"] = ""
    
    arr.each { |x|
      $error = ""
      if SearchDomain $textbox1.get + x
      #DOMAIN AVAILABLE
        $label3["text"] += "#{$textbox1.get}#{x}: DOMAIN AVAILABLE\n"
      else
        if $error == ""
        $label3["text"] += "#{$textbox1.get}#{x}: DOMAIN NOT AVAILABLE\n"
        else
          $label3["text"] += "#{$error}\n"
        end
      end
    }
    }
  }
end

$label1.place "x" => 250, "y" => 10
x = 10
y = 70
label2.place "x" => x, "y" => y
$textbox1.place "x" => x+60, "y" => y
button1.place "x" => x+190, "y" => y-10
$label3.place "x" => x+10, "y" => y+50
label4.place "x" => x+10, "y" => y+200
$textbox2.place "x" => x+100, "y" => y+200
label5.place "x" => x+10, "y" => y+225
$textbox3.place "x" => x+100, "y" => y+225

$r.mainloop