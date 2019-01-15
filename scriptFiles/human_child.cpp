// human_child.hpp and human_child.cpp written by Marek K.

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
#include "human_child.hpp"

human::human() HUMAN_CHILD_NOEXC
{
    NumOfHumans++;
}

human::human(std::string name, unsigned height) HUMAN_CHILD_NOEXC : name(name), height(height)
{
    NumOfHumans++;
}

inline unsigned GetNumsOfHumans(human & n) HUMAN_CHILD_NOEXC
{
    return n.NumOfHumans;
}

inline unsigned GetNumsOfHumans(human * n) HUMAN_CHILD_NOEXC
{
    return n->NumOfHumans;
}

unsigned human::NumOfHumans = 0;

Child::Child(std::string name) HUMAN_CHILD_NOEXC : human(name, 30), stat(Child::Baby) {
#if HUMAN_CHILD_DEBUG
std::cout << "Create Child(name: " << name << ")" << std::endl;
#endif // DEBUG
}

#if HUMAN_CHILD_DEBUG
Child::~Child()
{
    std::cout << "Delete Child(name: " << this->name << ")" << std::endl;
}
#endif // HUMAN_CHILD_DEBUG

inline std::string Child::GetName() const HUMAN_CHILD_NOEXC
{
    return "Junior " + this->name;
}

inline unsigned Child::GetHeight() const HUMAN_CHILD_NOEXC
{
    return this->height;
}

void Child::LevelUp()
{
    if(stat < Child::Teenager)
    {
        this->height += 25;
        switch(this->stat)
        {
            case Child::Baby: this->stat = Child::Junior;
            break;
            case Child::Junior: this->stat = Child::Teenager;
            default:;
        }
    }
    else
    {
        std::cout << this->name << " win!" << std::endl;
    }
}

void operator<<(std::ostream & out, Child & c)
{
    out << "Junior " << c.name << std::endl;
    out << "Height: " << c.height << std::endl;
    out << "Level: " << static_cast<int>(c.stat) + 1;
}

inline void operator<<(std::ostream & out, Child * c)
{
    operator<<(out, *c);
}
