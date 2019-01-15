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

#include <iostream>  /* cout, cerr, endl */
#include <random>  /* mt19937, uniform_int_distribution */
#include <array>  /* array */
#include <memory>  /* shared_ptr */
#include <chrono>  /* system_clock */
#include <algorithm>  /* max_element, min_element */
#include <new>  /* bad_alloc */

#include <cstddef>  /* size_t */
#include <cstdlib>  /* abort, EXIT_SUCCESS */

using namespace std;

template <typename T, size_t SIZ = 100u>
shared_ptr<array<T, SIZ>> CreateRandomArray(T min = 0, T max = 100)
{
    shared_ptr<array<T, SIZ>> arr = make_shared<array<T, SIZ>>();
    mt19937 mt(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<T> dis(min, max);

    for(size_t i = 0; i < SIZ; i++)
        arr->at(i) = short(dis(mt));

    return arr;
}

int main()
{
    shared_ptr<array<short, 100u>> arr1, arr2;

    try
    {
        arr1 = CreateRandomArray<short>(1);
        arr2 = CreateRandomArray<short>(-100, -1);
    }
    catch(const bad_alloc & e)
    {
        cerr << "Error: " << e.what() << endl;
        abort();
    }

    short max1 = *min_element(arr1->begin(), arr1->end()),
    max2 = *max_element(arr2->begin(), arr2->end());

    cout << "Numbers: " << endl;

    for(short i : *arr1)
        cout << i  << ", ";

    for(short i : *arr2)
        cout << i << ", ";

    cout << endl << endl << "Result: ";

    if(max1 == -max2)
        cout << max1 << " and " << max2;
    else
        if(max1 < -max2)
            cout << max1;
        else
            cout << max2;

    cout << endl;

    return EXIT_SUCCESS;
}
