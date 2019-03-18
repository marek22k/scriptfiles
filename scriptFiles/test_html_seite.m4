divert(-1)

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

define(`COUNT', 0)
define(`C', `define(`COUNT', eval(COUNT `+ 1'))'`<$2>COUNT - $1</$2>')
define(HTML5, `<!DOCTYPE html>')
define(HTML4_STRICT, `<!DOCTYPE HTML "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">')
define(HTML4_TRANSITIONAL, `<!DOCTYPE HTML "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">')
define(BEGIN, `<html><head>')
define(TITLE, `<title>$1</title>')
define(ICON, `<link rel="icon" type="$2" href="$1"ifelse($3, `0', , ` /')>'
`<link rel="shortcut icon" type="$2" href="$1"ifelse($3, `0', , ` /')>')
define(CSS, `<link rel="stylesheet" type="text/css" href="$1"ifelse($2, `0', , ` /')>')
define(META, `<meta name="$1" content="$2"ifelse($3, `0', , ` /')>')
define(CHARSET, `<meta http-equiv="Content-Type" content="text/html; charset=$1">')
define(CHARSET5, `<meta charset="$1">')
define(MIDDLE, `</head><body>')
define(END, `</body></html>')
define(H1, `<h1>$1</h1>')
define(H2, `<h2>$1</h2>')
define(H3, `<h3>$1</h3>')
define(H4, `<h4>$1</h4>')
define(H5, `<h5>$1</h5>')
define(H6, `<h6>$1</h6>')
define(NEWLINE, `<br ifelse($1, `0', , /)>')
define(LINK, `<a href="$1">$2</a>')
define(LINKT, `<a href="$1" target="$3">$2</a>')
define(BACKGROUND, `<div style="background-color:$1;">$2</div>')
define(STYLE, `<div style="$1">$2</div>')
define(ID, `<div id="$1">$2</div>')
divert(0)
HTML5
BEGIN
TITLE(Test Seite)
CHARSET5(UTF-8)
META(author, Marek K., 0)
ICON(http://mk16.de/Images/Logo.png, image/png, 0)
CSS(http://mk16.de/System/csslib.css, 0)
MIDDLE

H1(Willkommen auf dieser Test Seite)
H2(Dies Seite benutzt die ``CSS'' Library von mk16.de)

ID(content)
BACKGROUND(white,
H3(Warum sollte ich mk16.de benutzen und-oder besuchen)
C(Es gibt auf mk16.de tolle Artikel, span)
NEWLINE(0)
C(Es gibt Anleitungen auf mk16.de, span)
NEWLINE(0)
LINK(http://mk16.de, zu mk16.de)
NEWLINE(0)
LINKT(http://mk16.de/, zu mk16.de (Neues Fenster), _blank)
)
END