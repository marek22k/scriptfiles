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

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Person
{
    public class Person
    {

        /*
            Class: Person
            Class from: m.k@mk16.de
            Download class: http://test.mk16.de/scriptFiles/
        */

        // New String for name and language
        // New status for type
        // New int for age
        private string firstname = "";
        private string lastname = "";
        private int age = 0;
        private Status type = Status.life;
        private String language = "";

        // Set enum status [life,dead]
        protected enum Status
        {
            life, dead
        }

        // Public Person methods
        public Person(string name, int NewAge)
        {
            SetName(name);
            age = NewAge;
        }

        public Person(string name)
        {
            SetName(name);
        }

        public Person()
        {
            SetName("Mark Mustermann");
        }

        // Set/Get name
        public void SetName(string name)
        {
            string[] names = name.Split(' ');
            firstname = names[0];
            lastname = names[1];
        }

        public string GetName()
        {
            return firstname + " " + lastname;
        }

        // Set/Get age
        public void SetNewAge(int NewAge)
        {
            age = NewAge;
        }

        public int GetAge()
        {
            return age;
        }

        // Age += +1
        public void Birthday()
        {
            SetNewAge(GetAge() + 1);
        }

        // Status = dead
        public void Dead()
        {
            type = Status.dead;
            Console.WriteLine(GetName() + " died with the age of " + GetAge() + "!");
        }

        // If life
        public bool IsLife()
        {
            if (type == Status.life)
                return true;
            else
                return false;
        }

        // Set/Get language
        public void SetLanguage(string lang)
        {
            language = lang;
        }

        public string GetLanguage()
        {
            return language;
        }
    }
}
