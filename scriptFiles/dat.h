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

#include <iostream>  // Importiere iostream
#ifndef DAT_H  // Initialisiere dat class
#define DAT_H

class dat
{
    private:  // Erstelle die Variablen x, y, z
        int x = 0;
        int y = 0;
        int z = 0;

    public: // Initialisiere funktionen (siehe dat.cpp)
        dat();
        dat(int dataX);
        dat(int dataX, int dataY);
        dat(int dataX, int dataY, int dataZ);
        int getX();
        int getY();
        int getZ();
        void edit(int data);
        void operator=(int client);
        void operator=(dat client);
        void operator=(int client[]);
        void operator&=(int client);
        void operator|=(int client);
        int operator+(dat &client);
        int operator+(int client);
        int operator-(dat &client);
        int operator-(int client);
        int operator*(dat &client);
        int operator*(int client);
        int operator/(dat &client);
        int operator/(int client);
        int operator%(dat &client);
        int operator%(int client);
        bool operator==(int client);
        bool operator==(dat client);
        bool operator!=(int client);
        bool operator!=(dat client);
        bool operator<=(int client);
        bool operator>=(int client);
        bool operator<=(dat client);
        bool operator>=(dat client);
        bool operator<(int client);
        bool operator<(dat client);
        bool operator>(int client);
        bool operator>(dat client);
};

#endif
