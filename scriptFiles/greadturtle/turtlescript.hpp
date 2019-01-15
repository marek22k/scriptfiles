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

/*
 Example:

int main()
{
    try
    {
        eval(" integer@x = 256 ;\nstring@str=\"test\";\ninteger@y = $x;");
        std::cout << getvar<TUR_INTEGER>("y") << std::endl;
    }
    catch(TUR_EXCEPTION ture)
    {
        std::cerr << ture.what() << " on line " << ture.line() << std::endl;
    }
    return 0;
}
*/

#ifndef TURTLESCRIPT_H
#define TURTLESCRIPT_H

#include <string>  /* string */
#include <vector>  /* vector */
#include <array>  /* array */

#include <cstddef>  /* size_t */

/* Need C++ Boost */
#include <boost/any.hpp>  /* any, any_cast */

/* turtlescript exception class */
class TUR_EXCEPTION
{
    protected:
        const char * msg;
        unsigned lin;

    public:
        explicit TUR_EXCEPTION(const char * msg, unsigned lin) : msg(msg), lin(lin)
        {}
        virtual const char * what() const
        {
            return msg;
        }
        virtual unsigned line() const
        {
            return lin;
        }
};

/* turtlescript variable stack */
typedef struct
{
    std::vector<std::string> name;
    std::vector<boost::any> value;
    std::vector<int> type;
} TUR_STACK;

/*
    TYPE         ID
    integer    = 1
    boolean    = 2
    string     = 3
    bignum     = 4
    byte       = 5
    float      = 6
*/

/* Turtlescript data types */
typedef int             TUR_INTEGER;
typedef int             TUR_BOOLEAN;
typedef std::string     TUR_STRING;
typedef long long       TUR_BIGNUM;
typedef unsigned char   TUR_BYTE;
typedef std::string     TUR_FLOAT;

namespace turtlescript
{
    /* Edit and set variables */
    void editvar(std::string, boost::any, int);
    
    /* Execute turtlescript code */
    int eval(std::string);
    
    /* Execute turtlescript context */
    std::string context(std::string, unsigned = 0);
    
    /* clear the variable stack */
    int clear();
    
    TUR_STACK * stack();
    
    /* Return a variable */
    TUR_INTEGER getinteger(std::string);
    TUR_BOOLEAN getboolean(std::string var);
    TUR_STRING getstring(std::string var);
    TUR_BIGNUM getbignum(std::string var);
    TUR_BYTE getbyte(std::string var);
    TUR_FLOAT getfloat(std::string var);

}

#endif