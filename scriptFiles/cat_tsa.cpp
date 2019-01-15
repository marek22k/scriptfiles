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

#include <iostream>  /* cout, endl, flush */
#include <vector>  /* vector */
#include <string>  /* string, stoll */

using namespace std;

template <typename C>
C cat_two_sorted_arrays(C, C, bool = false);

int main()
{
    vector<long long> vec1, vec2;
    string nums1, nums2, buf;
    
    cout << "Please enter the first sorted number series(number1 number2 numberN): " << flush;
    getline(cin, nums1);
    
    cout << "Please enter the second sorted number series(number1 number2 numberN): " << flush;
    getline(cin, nums2);
    
    nums1 += " ",
    nums2 += " ";
    
    for(auto i = nums1.begin(); i != nums1.end(); i++)
        if(*i == ' ')
            vec1.push_back(stoll(buf)),
            buf = "";
        else
            buf += *i;

    for(auto i = nums2.begin(); i != nums2.end(); i++)
        if(*i == ' ')
            vec2.push_back(stoll(buf)),
            buf = "";
        else
            buf += *i;

    for(long long lv : cat_two_sorted_arrays(vec1, vec2))
        cout << lv << ", ";

    return 0;
}

template <typename C>
inline C cat_two_sorted_arrays(C vec1, C vec2, bool op)
{
    /* register */ size_t sres, be, en;
    
    for(auto i = vec2.begin(); i != vec2.end(); i++)
    {
        sres = 0;
        be = 0;
        en = vec1.end() - vec1.begin();
        
        while((sres=be+1) != en)
            if(vec1[sres=(be + en) / 2] > *i)
                en = sres;
            else if(vec1[sres] < *i)
                be = sres;
            else
                break;

        if(be == 0 && *i == 1) sres--;
        if(op) cout << "Insert " << *i << " on position " << sres << "!" << endl;
        
        vec1.insert(vec1.begin() + sres, *i);
    }
    
    return vec1;
}