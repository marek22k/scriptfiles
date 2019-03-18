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
#include <exception>
#include <stdexcept>

#include <cstdlib>
#include <ctime>

#include "mmatrix.hpp"

using namespace std;

int main()
{
    try
    {
        srand( time(0) );
        
        size_t sx = static_cast<size_t>(-1), sy = sx;
        
        cout << "Please enter the width of the matrix: " << flush;
        cin >> sx;
        if(cin.fail() || sx == static_cast<size_t>(-1))
            throw runtime_error("Invalid input!");
        
        cout << "Please enter the height of the matrix: " << flush;
        cin >> sy;
        if(cin.fail() || sy == static_cast<size_t>(-1))
            throw runtime_error("Invalid input!");
        
        cout << endl;
        
        mmatrix<char> mat(sx, sy);
        mat.fill('\0');
        mat.fill([](size_t, size_t) -> char {
            return static_cast<char>(rand()%26 + 'A');
        });
        
        cout << "A " << sx << 'x' << sy << " matrix with random letters:" << endl;
        mat.output();
        
        size_t founds = 0;
        
        mat.each([&founds, &mat](size_t x, size_t y, char * val) {
            // eins nach unten und eins nach rechts
            if(x + 1 < mat.sx && y + 1 < mat.sy)
                if(mat.mat.at(y + 1).at(x + 1) == *val)
                {
                    cout << "Found " << *val << " at x=" << x + 1 << ", y=" << y + 1 <<
                            " and x=" << x << ", y=" << y << "." << endl;
                    founds++;
                }
            
            // eins nach unten
            if(y + 1 < mat.sy)
                if(mat.mat.at(y + 1).at(x) == *val)
                {
                    cout << "Found " << *val << " at x=" << x << ", y=" << y + 1 <<
                            " and x=" << x << ", y=" << y << "." << endl;
                    founds++;
                }
                
            // eins nach rechts
            if(x + 1 < mat.sx)
                if(mat.mat.at(y).at(x + 1) == *val)
                {
                    cout << "Found " << *val << " at x=" << x + 1 << ", y=" << y <<
                            " and x=" << x << ", y=" << y << "." << endl;
                    founds++;
                }
            
            // eins nach unten und eins nach links
            if(static_cast<long>(x) - 1 >= 0 && y + 1 < mat.sy)
                if(mat.mat.at(y + 1).at(x - 1) == *val)
                {
                    cout << "Found " << *val << " at x=" << x - 1 << ", y=" << y + 1 <<
                            " and x=" << x << ", y=" << y << "." << endl;
                    founds++;
                }
        });
        
        cout << founds << " adjacent letters were found." << endl;
    }
    catch(exception & e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}
