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
#include <ostream>
#include <vector>

using namespace std;

static long money = 0;
static long unsigned cid = 0;

class CandyRobot
{
    public:
        CandyRobot(unsigned, unsigned, unsigned);
        unsigned GetCandies();

    private:
        unsigned p, e, c, h;
        long unsigned robotid;
};

CandyRobot::CandyRobot(unsigned p, unsigned e, unsigned c) : p(p), e(e), c(c), h(0), robotid(++cid) {}
unsigned CandyRobot::GetCandies()
{
    if(money - ((long)c) < 0)return 0;
    money -= c;

    cout << "Robot: " << robotid << "; Money: " << money << "; Candies: " << (h++<e?p:1) << endl;
    return (h-1<e?p:1);
}

int main()
{
    money = 1500;
    unsigned rn = 5, candies = 0, temp, a, b, c;

    cout << "Format: [MONEY] [NUMBER OF ROBOTS] [CANDIES PER ROBOT PER HOUR] [ENERGIE OF ROBOT IN HOUR] [MONEY PER ROBOT PER HOUR]" << endl;
    cin >> money >> rn >> a >> b >> c;
    //double r =  int((b*a+(double(money)/double(rn)/double(c)-double(b)))*double(rn));
    double r = int(a*b*rn-b*rn+double(money)/double(c));
    cout << endl << "Estimated candies: " << r << endl;
    vector<CandyRobot> robots;
    for(unsigned i = 0; i < rn; i++) robots.push_back(CandyRobot(a, b, c));

    cout << endl;

    while(temp != 0)
        for(unsigned i = 0; i < rn; i++)
        {
            temp = robots[i].GetCandies();
            if(temp == 0) break;
            candies += temp;
        }

    cout << endl << "--------------------------------" << endl;
    cout << "Money: " << money << "; Candies: " << candies << endl;
    return 0;
}
