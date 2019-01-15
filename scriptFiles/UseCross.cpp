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
#include "cross.h"

#define LANGUAGE DE

using namespace std;

int main()
{
    cout << "Bitte gebe eine Zahl ein: ";
    int num;
    cin >> num;
    cout << endl << "Berechne..." << endl;
    int n1 = cross::GetCrossSum(num);
    int n2 = cross::GetCrossProduct(num);
    int n3 = cross::GetIteratedCrossProduct(num);
    int n4 = cross::GetLastPersistence();
    int n5 = cross::GetAlternatingCrossSum(num);
    string log = cross::GetLog();
    cout << "Berechnungen abgeschlossen!" << endl << endl;
    cout << "Die Quersumme von " << num << " ist " << n1 << endl;
    cout << "Die Querprodukt von " << num << " ist " << n2 << endl;
    cout << "Die Iteriertes Querprodukt von " << num << " ist " << n3 << endl;
    cout << "Die Beharrlichkeit von " << num << " ist " << n4 << endl;
    cout << "Die Abwechselnde Quersumme von " << num << " ist " << n5 << endl << endl << "Protokoll:" << endl << log << endl;
    cin >> num;
    return 0;
}
