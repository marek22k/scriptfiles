/**
 * \author Marek K.
 * \copyright GNU GPL v3
 */

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

#ifndef COLORIZE_HPP
#define COLORIZE_HPP

#include <ostream>  /* ostream */

/**
 * \enum colorize_color
 * \brief Enumerator which stores the possible colors for the text coloring
 *
 * A color is addressed with COLORIZE_COLOR.
 * If no color is to be specified COLORIZE_NONE can be used.
 */
enum colorize_color { COLORIZE_NONE, COLORIZE_BLACK = 30, COLORIZE_RED, COLORIZE_GREEN,
                      COLORIZE_YELLOW, COLORIZE_BLUE, COLORIZE_MAGENTA, COLORIZE_CYAN,
                      COLORIZE_WHITE };

/**
 * \fn std::ostream & colorize(std::ostream &, colorize_color = COLORIZE_NONE, colorize_color =
 *                             COLORIZE_NONE);
 * \brief Colors text
 * \param  std::ostream & The output stream from which the text should be colored.
 * \param COLORIZE_NONE colorize_color font Color
 * \param COLORIZE_NONE colorize_color Background color
 * \return std::ostream & The output stream that has been colored.
 *
 * If the coloring is to be reset, colorize can only be called with the first argument:
 * Code: colorize(cout);
 * In this example, the default output stream is reset.
 *
 * If only the background color is to be changed, the second argument
 * COLORIZE_NONE can be specified.
 * Code: colorize(cout, COLORIZE_NONE, COLORIZE_BLUE);
 * In this case, the background color of the text output with the Standerd output stream
 * is set toblue, and the text color is reset.
 *
 * Hint: Sometimes it can be useful to create two global variables
 * that store the current text and the current background color.
 *
 * Hint: It is before the program is terminated to undo the coloring, because sometimes
 * even after completion of the program the setting color is maintained.
 */
std::ostream & colorize(std::ostream &, colorize_color = COLORIZE_NONE, colorize_color =
                        COLORIZE_NONE);

#endif  // COLORIZE_HPP