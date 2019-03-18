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
#include <vector>
#include <exception>
#include <stdexcept>
#include <algorithm>

#include <cstdlib>

#define SUM(vec, var) {var = 0; for(int i : vec) var += static_cast<long>(i);}

using namespace std;

int main()
{
    try
    {
        size_t size;
        cout << "Please enter the size of the vector: " << flush;
        cin >> size;
        if(cin.fail())
            throw runtime_error("Invalid input!");
        
        vector<int> vec;
        vec.resize(size);
        
        cout << "Please enter the values of the vector: " << flush;
        for(size_t i = 0; i < size; i++)
        {
            cin >> vec[i];
            if(cin.fail())
                throw runtime_error("Invalid input!");
        }
        
        vector<int> svec1, svec2;
        
        vector<int>::iterator it;
        long sum1, sum2;
        
        while(vec.size() != 0)
        {
            SUM(svec1, sum1);
            SUM(svec2, sum2);
            
            if(sum1 > sum2)
            {
                it = max_element(vec.begin(), vec.end());
                svec2.push_back(*it);
                vec.erase(it);
            }
            else
            {
                it = max_element(vec.begin(), vec.end());
                svec1.push_back(*it);
                vec.erase(it);
            }
            
        }
        
        SUM(svec1, sum1);
        SUM(svec2, sum2);
        
        cout << endl << "Subvector 1: ";
        for(int i : svec1)
            cout << i << " ";
        
        cout << "; SUM: " << sum1 << endl << "Subvector 2: ";
        for(int i : svec2)
            cout << i << " ";
        
        cout << "; SUM: " << sum2 << endl;
        
        cout << "Difference of the two sums: " << sum1 - sum2 << endl;
    }
    catch(exception & e)
    {
        cerr << "Error: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}
