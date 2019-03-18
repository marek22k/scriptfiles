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

#include <cstdlib>
#include <cstddef>

namespace passwd {
    struct passwd_security {
        bool min,
             max,
             sc,
             valid,
             num,
             upper,
             lower;
    };

    size_t count_security(passwd_security);
    passwd_security get_security(const std::string, const size_t, const size_t);
}

using namespace std;

constexpr static size_t min_len = 8;
constexpr static size_t max_len = 256;

int main()
{
    string pass;
    
    cout << "Password: " << flush;
    getline(cin, pass);
    if(cin.fail())
    {
        cerr << "Invalid input!" << endl;
        exit(EXIT_FAILURE);
    }
    
    passwd::passwd_security sec = passwd::get_security(pass, min_len, max_len);
    
    cout << endl << "Min(" << min_len << "): " << sec.min << endl;
    cout << "Max(" << max_len << "): " << sec.max << endl;
    cout << "Special character: " << sec.sc << endl;
    cout << "Valid: " << sec.valid << endl;
    cout << "Number: " << sec.num << endl;
    cout << "Upper: " << sec.upper << endl;
    cout << "Lower: " << sec.lower << endl;
    cout << "The password \"" << pass << "\" satisfies " << passwd::count_security(sec) << " of 7 criteria." << endl;
    
    return EXIT_SUCCESS;
}

namespace passwd {
    size_t count_security(passwd_security sec)
    {
        return static_cast<size_t>(sec.min) +
               static_cast<size_t>(sec.max) +
               static_cast<size_t>(sec.sc) +
               static_cast<size_t>(sec.valid) +
               static_cast<size_t>(sec.num) +
               static_cast<size_t>(sec.upper) +
               static_cast<size_t>(sec.lower);
    }
    
    passwd_security get_security(const std::string passwd, const size_t min, const size_t max)
    {
        passwd::passwd_security sec;
        
        sec.max = (passwd.length() > max?false:true);
        sec.min = (passwd.length() < min?false:true);
        sec.valid = (passwd.find(' ') == std::string::npos?true:false);
        
        sec.num = false;
        for(char c = '0'; c <= '9'; c++)
            if(passwd.find(c) != std::string::npos)
            {
                sec.num = true;
                break;
            }
        
        sec.lower = false;
        for(char c = 'a'; c <= 'z'; c++)
            if(passwd.find(c) != std::string::npos)
            {
                sec.lower = true;
                break;
            }
        
        sec.upper = false;
        for(char c = 'A'; c <= 'Z'; c++)
            if(passwd.find(c) != std::string::npos)
            {
                sec.upper = true;
                break;
            }
        
        sec.sc = false;
        for(char c = '!'; c <= '~'; c++)
            if(passwd.find(c) != std::string::npos)
            {
                sec.sc = true;
                break;
            }
            else if(c == '/')
                c = ':';
            else if(c == '@')
                c = '[';
            else if(c == '`')
                c = '{';
        
        return sec;
    }
}
