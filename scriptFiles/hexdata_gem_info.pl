#!/usr/bin/perl

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
=cut

use warnings;
use Tkx;

my $r = Tkx::widget->new(".");
$r->g_wm_title("hexdata Gem");
$r->g_wm_minsize(600, 650);
#$r->g_wm_maxsize(600, 650);

my $labelframe1 = $r->new_ttk__labelframe(
	-text => "Gem",
	-borderwidth => "5"
);

my $labelframe2 = $r->new_ttk__labelframe(
	-text => "Description",
	-borderwidth => "5"
);

my $labelframe3 = $r->new_ttk__labelframe(
	-text => "Install",
	-borderwidth => "5"
);

my $labelframe4 = $r->new_ttk__labelframe(
	-text => "Links",
	-borderwidth => "5"
);

my $label1 = $labelframe1->new_label(
	-text => <<"END"
With hexdata you can create and read (Intel) hex data.
hexdata also calculates the checksum and calls an exception if it gets wrong.
hexdata is available under the GNU GPL v3.0.
END
);

my $label2 = $labelframe2->new_label(
	-text => <<"END"
With hexdata you can write or read (Intel) Hex data.
If you want to read data with hexdata, you can pass an array as an argument when creating the class.
Each element of the array should contain an (Intel) hex code.
So if you want to read a file you can use File.read("filename").split("\\n") as code.
If you pass this code as an argument, it will generate the array that will be passed.
First the file is read, then each line of the file becomes an element of the array.
If you want to write (Intel) hex data, you can either pass nothing as an argument or you pass an empty array.
An evaluation of the data can be achieved by calling the class method .interpret.
This does not demand arguments.
If you want to write data now you can use the class method .push.
At this one gives as argument the text to be written (actually ASCII, it goes however also ANSI signs).
At the end of the writing, you should call the class method .push_end.
This demands nothing as an argument. The class method inserts the data for the end of a file, that is, the
total amount of data.

hexdata Gem is available under the GNU General Public License v3.0
License: test.mk16.de/scriptFiles/COPYING, www.gnu.org/licenses/"
END
);

my $label3 = $labelframe3->new_label(
	-text => "Install from rubygems.mk16.de (SSL): "
);

my $label4 = $labelframe3->new_label(
	-text => "Install from rubygems.mk16.de: "
);

my $label5 = $labelframe3->new_label(
	-text => "Install from rubygems.org: "
);

my $label6 = $labelframe4->new_label(
	-text => <<"END"
Author: Marek K. <m.k\@mk16.de>
Reference: http://test.mk16.de/projects/hexdata-gem
Gem (rubygems.mk16.de): http://rubygems.mk16.de/?gem=hexdata
Gem (rubygems.org): https://rubygems.org/gems/hexdata
END
);

my $textbox1 = $labelframe3->new_tk__entry( -width => 60 );
my $textbox2 = $labelframe3->new_tk__entry( -width => 60 );
my $textbox3 = $labelframe3->new_tk__entry( -width => 60 );

$textbox1->insert("end", "gem install hexdata --source https://rubygems.mk16.de/");
$textbox2->insert("end", "gem install hexdata --source http://rubygems.mk16.de/");
$textbox3->insert("end", "gem install hexdata");

$label1->g_pack(-fill => "x");
$label2->g_pack(-fill => "x");
$label6->g_pack(-fill => "x");

$label3->g_pack(-fill => "x");
$textbox1->g_pack(-fill => "x");
$label4->g_pack(-fill => "x");
$textbox2->g_pack(-fill => "x");
$label5->g_pack(-fill => "x");
$textbox3->g_pack(-fill => "x");

$labelframe1->g_pack(-fill => "x");
$labelframe2->g_pack(-fill => "x");
$labelframe3->g_pack(-fill => "x");
$labelframe4->g_pack(-fill => "x");

Tkx::MainLoop();