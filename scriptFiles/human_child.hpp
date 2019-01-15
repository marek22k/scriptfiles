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

#ifndef HUMAN_CHILD_HPP
#define HUMAN_CHILD_HPP

#define HUMAN_CHILD_DEBUG 0

#if __cplusplus >= 201103L
    #define HUMAN_CHILD_NOEXC noexcept
#else
    #define HUMAN_CHILD_NOEXC
#endif

class human
{
    friend unsigned GetNumsOfHumans(human & n) HUMAN_CHILD_NOEXC;
    friend unsigned GetNumsOfHumans(human * n) HUMAN_CHILD_NOEXC;

    public:
        human() HUMAN_CHILD_NOEXC;
        human(std::string name, unsigned height) HUMAN_CHILD_NOEXC;
        virtual std::string GetName() const HUMAN_CHILD_NOEXC = 0;
        virtual unsigned GetHeight() const HUMAN_CHILD_NOEXC = 0;

    protected:
        static unsigned NumOfHumans;
        std::string name;
        unsigned height;  // in cm
};

class Child : public human
{
    friend void operator<<(std::ostream & out, Child & c);
    friend void operator<<(std::ostream & out, Child * c);

    public:
        Child(std::string name) HUMAN_CHILD_NOEXC;
        #if HUMAN_CHILD_DEBUG
            ~Child();
        #endif
        std::string GetName() const HUMAN_CHILD_NOEXC;
        unsigned GetHeight() const HUMAN_CHILD_NOEXC;
        void LevelUp();

        enum status_e {Baby = 0, Junior, Teenager};

    private:
        status_e stat;
};

#endif // HUMAN_CHILD_HPP
