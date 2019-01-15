# Author: Marek K.

=head1 NAME

colorize

=head1 DESCRIPTION

colorize can change the text color and the background color of the console.

=head1 AUTHOR

Marek K.

=head1 EXAMPLE

use Colorize;

Colorize->setColor($Colorize::Colors{"yellow"}, $Colorize::Colors{"red"});
print Colorize->VERSION();
Colorize->resetColor();

=head1 LICENSE

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

package Colorize;

use strict;
use warnings;

our @EXPORT_OK = ("setColor", "resetColor");
our $VERSION = 1.01;

our %Colors = (
    "none"    => 0,
    "black"   => 30,
    "red"     => 31,
    "green"   => 32,
    "yellow"  => 33,
    "blue"    => 34,
    "magenta" => 35,
    "cyan"    => 36,
    "white"   => 37
);

sub setColor {
    print STDOUT chr(27) . "[" . $_[1] . (defined $_[2]?";" . ($_[2]+10):"") . "m";
}

sub resetColor {
    print STDOUT chr(27) . "[0m";
}