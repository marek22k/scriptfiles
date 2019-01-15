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

#include "dat.h"

dat::dat(int dataX)  // Start funktion fur x
{
    x = dataX;
}

dat::dat(int dataX, int dataY)  // Start funktion fur x und y
{
    x = dataX;
    y = dataY;
}

dat::dat(int dataX, int dataY, int dataZ)  // Start funktion fur x, y und z
{
    x = dataX;
    y = dataY;
    z = dataZ;
}

int dat::getX()  // Gebe x zuruck
{
    return x;
}

int dat::getY()  // Gebe y zuruck
{
    return y;
}

int dat::getZ()  // Gebe z zuruck
{
    return z;
}

void dat::operator=(int client)  // x = client
{
    x = client;
}

void dat::operator=(int client[])  // x, y, z = client[0], client[1], client[2]
{
    try
    {
        x = client[0];
        y = client[1];
        z = client[2];
    }catch(const std::exception e){}
}

void dat::operator=(dat client)
{
    x = client.getX();
    y = client.getY();
    z = client.getZ();
}

void dat::operator&=(int client)  // y &= client
{
    y = client;
}

void dat::operator|=(int client)  // z |= client
{
    z = client;
}

int dat::operator+(dat &client)  // obj1 + obj2
{
    x += client.getX();
    y += client.getY();
    z += client.getZ();
    client = x;
    client &= y;
    client |= z;
    return x;
}

int dat::operator-(dat &client)  // obj1 - obj2
{
    x -= client.getX();
    y -= client.getY();
    z -= client.getZ();
    client = x;
    client &= y;
    client |= z;
    return x;
}

int dat::operator*(dat &client)  // obj1 * obj2
{
    x *= client.getX();
    y *= client.getY();
    z *= client.getZ();
    client = x;
    client &= y;
    client |= z;
    return x;
}

int dat::operator/(dat &client)  // obj1 / obj2
{
    x /= client.getX();
    y /= client.getY();
    z /= client.getZ();
    client = x;
    client &= y;
    client |= z;
    return x;
}

int dat::operator%(dat &client)  // obj1 % obj2
{
    x %= client.getX();
    y %= client.getY();
    z %= client.getZ();
    client = x;
    client &= y;
    client |= z;
    return x;
}

bool dat::operator==(dat client)  // x, y, z == clientX, clientY, clientZ
{
    if(x == client.getX() && y == client.getY() && z == client.getZ())
    return true;
    return false;
}

bool dat::operator!=(dat client)  // x, y, z != clientX, clientY, clientZ
{
    if(x != client.getX() && y != client.getY() && z != client.getZ())
    return true;
    return false;
}

bool dat::operator<=(dat client)  // x, y, z <= clientX, clientY, clientZ
{
    if(x <= client.getX() && y <= client.getY() && z <= client.getZ())
    return true;
    return false;
}

bool dat::operator>=(dat client)  // x, y, z >= clientX, clientY, clientZ
{
    if(x >= client.getX() && y >= client.getY() && z >= client.getZ())
    return true;
    return false;
}

int dat::operator+(int client)  // x + client
{
    x += client;
    return x;
}

int dat::operator-(int client)  // x - client
{
    x -= client;
    return x;
}

int dat::operator*(int client)  // x * client
{
    x *= client;
    return x;
}

int dat::operator/(int client)  // x /client
{
    x /= client;
    return x;
}

int dat::operator%(int client)  // x % client
{
    x %= client;
    return x;
}

bool dat::operator==(int client)  // x == client
{
    if(x == client)
    return true;
    return false;
}

bool dat::operator!=(int client)  // x != client
{
    if(x != client)
    return true;
    return false;
}

bool dat::operator<=(int client)  // x <= client
{
    if(x <= client)
    return true;
    return false;
}

bool dat::operator>=(int client)  // x >= client
{
    if(x >= client)
    return true;
    return false;
}

bool dat::operator<(dat client)  // x < client
{
    if(x < client.getX() && y < client.getY() && z < client.getZ())
    return true;
    return false;
}

bool dat::operator>(dat client)  // x > client
{
    if(x > client.getX() && y > client.getY() && z > client.getZ())
    return true;
    return false;
}

bool dat::operator<(int client)  // x, y, z < clientX, clientY, clientZ
{
    if(x < client)
    return true;
    return false;
}

bool dat::operator>(int client)  // x, y, z > clientX, clientY, clientZ
{
    if(x > client)
    return true;
    return false;
}
