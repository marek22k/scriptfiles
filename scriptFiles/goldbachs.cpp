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

#include <iostream>  /* cout, cin */
#include <ostream>  /* endl */
#include <vector>  /* vector */
#include <utility>  /* pair */

#include <cstdlib>  /* exit, abort, EXIT_SUCCESS */
#include <cstddef>  /* size_t */

using namespace std;

vector<pair<long unsigned, long unsigned>> GetGoldbachs(long unsigned);

int main()
{
    long unsigned n = static_cast<long unsigned>(-1);

    cout << "Number: ";
    cin >> n;
    if(cin.fail() || n == static_cast<long unsigned>(-1)) abort();

    if(n%2 != 0 || n <= 2)
    {
        cout << "Incorrect input! Proceed anyway? (Y/N)" << endl;
        char x = static_cast<char>(0);
        cin >> x;
        if(cin.fail() || x == static_cast<char>(0)) abort();
        if(x != 'Y') exit(1);
    }

    cout << endl << "Working..." << endl;
    vector<pair<long unsigned, long unsigned>> res = GetGoldbachs(n);
    cout << endl;
    for(size_t i = 0; i < res.size(); i++)
        cout << res[i].first << " + " << res[i].second << " = " << res[i].first + res[i].second << endl;

    return EXIT_SUCCESS;
}

vector<pair<long unsigned, long unsigned>> GetGoldbachs(long unsigned n)
{
    vector<long unsigned> primes;
    bool isPrime;
    for(long unsigned i = 2; i < n; i++)
    {
        isPrime = true;
        for(long unsigned j = 2; j < i; j++)
        {
            if(i%j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if(isPrime) primes.push_back(i);
    }

    vector<pair<long unsigned, long unsigned>> res;
    long x = primes.size()/2-1;
    for(size_t i = 0; i < primes.size(); i++)
    {
        for(long j = primes.size()-1; j >= x; j--)
        {
            if(primes[i] + primes[j] == n)
            {
                res.push_back(make_pair(primes[i], primes[j]));
            }
        }
    }

    if(res.size() > 1 && res[res.size()-1].first == res[0].second && res[res.size()-1].second == res[0].first) res.pop_back();
    if(res.size() > 2 && res[res.size()-1].first == res[res.size()-2].second && res[res.size()-1].second == res[res.size()-2].first) res.pop_back();

    return res;
}
