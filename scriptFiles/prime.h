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
#include <fstream>
namespace prime {
    using namespace std;

    /** \brief Checks whether it is a prime number
     *
     * \param num int The number to be checked
     * \return bool Specifies in a boolean whether it is a prime
     *
     */
    bool isPrime(int num)
    {
        bool res = true;
        for(int n = 2; n < num; n++)
        {
            int i = num%n;
            if(i == 0)
                res = false;
        }
        return res;
    }

    /** \brief Collects in a Dynamic Array Primes
     *
     * \param to int To the number on is checked
     * \param from=1 int Up to the number is checked
     * \return vector<int> Returns a dynamic array with prime numbers
     *
     */
    vector<int> GetPrims(int to, int from=1)
    {
        vector<int> v;
        for(int n = from; n < (to+1); n++)
        {
            if(isPrime(n) == true)
                v.push_back(n);
        }
        return v;
    }

    /** \brief Writes the primes into a file
     *
     * \param v vector<int> Primes in a Dynamic Array
     * \param filename string Filename from the file to which is written
     * \return void No return value
     *
     */
    void WritePrimsInFile(vector<int> v, string filename)
    {
        fstream f;
        f.open(filename, ios::out);
        for(int n = 0; n < v.size(); n++)
        {
            f << v[n];
            if((v.size()-1) != n)
                f << ", ";
            if(n%9 == 0 && n != 0)
                f << "\n";
        }
    }

    /** \brief Returns a set of prime numbers
     *
     * \param v vector<int> The primes printed in a dynamic array
     * \return void No return value
     *
     */
    void OutputPrims(vector<int> v)
    {
        for(int n = 0; n < v.size(); n++)
        {
            cout << v[n];
            if((v.size()-1) != n)
                cout << ", ";
            if(n%9 == 0 && n != 0)
                cout << endl;
        }
    }
}
