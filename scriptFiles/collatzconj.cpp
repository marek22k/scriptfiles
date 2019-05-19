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
#include <vector>
#include <utility>

#include <cstdlib>
#include <cstddef>

using namespace std;

pair<size_t, vector<unsigned>> collatzconj(unsigned);

int main()
{
    try
    {
        unsigned n;
        
        cout << "Please enter a number: " << flush;
        cin >> n;
        
        if(cin.fail())
            throw runtime_error("Invalid input!");
        
        pair<size_t, vector<unsigned>> res = collatzconj(n);
    
        cout << "To achieve the Collatz sequence, " << res.first << " steps were needed." << endl
            << "Sequence: ";
    
        for(unsigned x : res.second)
            cout << x << ", ";
    
        cout << endl;
    }
    catch(const exception & e)
    {
        cerr << "Error: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
    
    return EXIT_SUCCESS;
}

pair<size_t, vector<unsigned>> collatzconj(unsigned n)
{
    if(n == 0)
        throw invalid_argument("n > 0");
    
    size_t i = 0;
    vector<unsigned> vec;
    
    for(i = 0;
            vec.size() < 3 || vec[vec.size() - 1 ] != 1 || vec[vec.size() - 2 ] != 2 || vec[vec.size() - 3 ] != 4;
            i++)
        vec.push_back(n),
        n = n % 2 == 0 ? n / 2 : 3 * n + 1;
    
    return make_pair(i, vec);
}
