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
#include <fstream>
#include <exception>
#include <stdexcept>
#include "turtlescript.hpp"

int main(int argc, char * argv[])
{
    try
    {
        if(argc < 2)
        {
            throw std::runtime_error("Invalid command line argument!");
        }
        
        std::string buf = std::string(argv[1]), res;
        std::ifstream f(buf);
        
        if(! f.is_open())
            throw std::runtime_error("Can not open file!");
        
        while(std::getline(f, buf))
            res += buf + "\n";
        
        f.close();
        turtlescript::eval(res);
        
        for(unsigned i = 0; i < turtlescript::stack()->name.size(); i++)
        {
            std::cout << turtlescript::stack()->name[i] << "\t--- ";
            switch(turtlescript::stack()->type[i])
            {
                case 1: std::cout << "INTEGER"; break;
                case 2: std::cout << "BOOLEAN"; break;
                case 3: std::cout << "STRING"; break;
                case 4: std::cout << "BIGNUM"; break;
                case 5: std::cout << "BYTE"; break;
                case 6: std::cout << "FLOAT"; break;
            }
            std::cout << "\t--- " << turtlescript::context("$" + turtlescript::stack()->name[i]) << std::endl;
        }
        turtlescript::clear();
    }
    catch(TUR_EXCEPTION & e)
    {
        std::cerr << e.what() << " on line " << e.line() << std::endl;
        std::terminate();
    }
    catch(boost::bad_any_cast & e)
    {
        std::cerr << "Type casting error: " << e.what() << std::endl;
        std::terminate();
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << std::endl;
        std::terminate();
    }
    
    return 0;
}