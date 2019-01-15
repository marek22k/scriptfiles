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

#include <iostream>

#if __cplusplus >= 201103L
    #define PUTNUMS_NOEXC noexcept
#else
    #define PUTNUMS_NOEXC 
#endif
#ifdef DEBUG
    #define PUTNUMS_BEG os << "Start function PutNums\n";
    #define PUTNUMS_END os << "End function PutNums\n";
#else
  #define PUTNUMS_BEG 
  #define PUTNUMS_END 
#endif
template <class T>
void PutNums(const int f, const int t, T &os = std::cout) PUTNUMS_NOEXC
{
    PUTNUMS_BEG
    for(int i = f; i <= t; i++)
    {
        for(int j = f; j <= i; j++)
            os << j << (j==i?"":" ");
        os << "\n";
    }
    PUTNUMS_END
}
#undef PUTNUMS_NOEXC
#undef PUTNUMS_BEG
#undef PUTNUMS_END

int main()
{
    PutNums(5, 10, std::cout);
    return 0;
}
