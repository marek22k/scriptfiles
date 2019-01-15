// This program was written by Marek K.

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

using namespace std;

void printga(const int ga[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << "|";
            switch(ga[i][j])
            {
                case 0:
                    cout << " ";
                    break;
                case 1:
                    cout << "X";
                    break;
                case 2:
                    cout << "O";
                    break;
            }
        }
        cout << "|" << endl;
    }
}

bool checkWin(const int ga[3][3], const int player)
{
    for(int i = 0; i < 3; i++)
    {
        if(ga[i][0] == player && ga[i][1] == player && ga[i][2] == player) return true;
        if(ga[0][i] == player && ga[1][i] == player && ga[2][i] == player) return true;
    }
    if(ga[0][0] == player && ga[1][1] == player && ga[2][2] == player) return true;
    if(ga[0][2] == player && ga[1][1] == player && ga[2][0] == player) return true;
    return false;
}

bool checkFull(const int ga[3][3])
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(ga[i][j] == 0) return false;
    return true;
}

int main()
{
    try
    {
        cout << "This program was written by Marek K." << endl;
        int ga[3][3] = { {0, 0, 0},  // ga = Gamearea
                         {0, 0, 0},
                         {0, 0, 0}
                    }, player = 1;

        bool p1, p2;
        while(!(p1=checkWin(ga, 1)) && !(p2=checkWin(ga, 2)) && !checkFull(ga))
        {
            cout << endl;
            printga(ga);
            int a1, a2;
            cout << "Player " << player << "(row column): ";
            cin >> a1 >> a2;
            if(a1 >= 4 || a1-- <= 0)
                throw 0x0001;
            if(a2 >= 4 || a2-- <= 0)
                throw 0x0002;
            if(ga[a1][a2] == 0)
                ga[a1][a2] = player;
            else
                continue;
            if(player == 1) player = 2;
            else player = 1;
        }

        cout << endl;
        if(p1)
            cout << "Player 1 wins" << endl;
        else if(p2)
            cout << "Player 2 wins" << endl;
        else
            cout << "Draw" << endl;
    }
    catch(const int ex)
    {
        cerr << "Errorcode: " << ex << endl;
    }

    return 0;
}
