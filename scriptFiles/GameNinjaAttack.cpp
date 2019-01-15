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
#include <string>
using namespace std;

// Game: NinjaAttack
// Free download from test.mk16.de/scriptFiles
class Attack
{
protected: int AttackPower = 40;
		   int Schild = 60;

public: Attack(int AttackPower = 40, int Schild = 60)
{
	SetAttackPower(AttackPower);
	SetSchild(Schild);
}
		void SetAttackPower(int AttackPower = 40)
		{
			this->AttackPower = AttackPower;
		}
		void SetSchild(int Schild = 60)
		{
			this->Schild = Schild;
		}
		int NowAttack(Attack client)
		{
			int my = Schild;
			int you = client.AttackPower;
			if (my < you) {
				return 0;
			}
			else if (my > you) {
				return 1;
			}
			return 3;
		}
		Attack GetAttack() {
			Attack a(AttackPower, Schild);
			return a;
		}
};

class Card : protected Attack {
public: string CardName = "";
		Card(string CardName, int AttackPower, int Schild)
		{
			SetAttackPower(AttackPower);
			SetCardName(CardName);
			SetSchild(Schild);
		}
		void SetCardName(string CardName)
		{
			this->CardName = CardName;
		}
		void AttackOnClient(Card Client)
		{
			int w = this->NowAttack(Client.GetAttack());
			if (w == 0) {
				cout << Client.CardName + " vs " + CardName + "; Won: " + Client.CardName << endl;
			}
			else if (w == 1) {
				cout << Client.CardName + " vs " + CardName + "; Won: " + CardName << endl;
			}
			else if (w == 3) {
				cout << "The fight was undecided." << endl;
			}
		}
		Card operator+(Card plus)
		{
			string name = this->CardName + plus.CardName;
			int a = this->AttackPower + plus.AttackPower;
			int s = this->AttackPower + plus.AttackPower;
			Card big(name, a, s);
			return big;
		}
		Card operator*(Card plus)
		{
			string name = "Big" + this->CardName + plus.CardName;
			int a = this->AttackPower * 2 + plus.AttackPower;
			int s = this->AttackPower + plus.AttackPower * 2;
			Card big(name, a, s);
			return big;
		}
};