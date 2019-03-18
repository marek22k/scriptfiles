// Author: Marek K.

/*

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
    
*/

#ifndef MMINILANG_HPP
#define MMINILANG_HPP

#include <istream>
#include <ostream>
#include <vector>
#include <exception>
#include <stdexcept>

#include <cstddef>
#include <cmath>

#define YP_ARG_1 std::istream &
#define YP_ARG_2 std::ostream &
#define YP_ARG_3 std::istream &
#define YP_ARG_4 std::vector<double> &

/* decs */
int yyparse(YP_ARG_1, YP_ARG_2, YP_ARG_3, YP_ARG_4);
unsigned gcd(unsigned, unsigned);
unsigned lcm(unsigned, unsigned);
unsigned fact(unsigned);

void mml_error(std::exception);
void mml_error(std::invalid_argument);
void mml_error(std::runtime_error);
#if 0
void mml_error(std::logic_error);
void mml_error(std::domain_error);
void mml_error(std::out_of_range);
void mml_error(std::range_error);
void mml_error(std::overflow_error);
void mml_error(std::underflow_error);
#endif

#endif
