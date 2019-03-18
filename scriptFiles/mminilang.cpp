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
#include <fstream>
#include <sstream>

#include <cstdlib>
#include <cstring>

#include "mminilang.hpp"

int main(int argc, char * argv[])
{
    if(argc < 2)
    {
        mml_error(std::invalid_argument("Invalid arguments! mminilang filename.mml argument1 argument2 argumentn"));
        exit(EXIT_FAILURE);
    }
    
    if(strcmp(argv[1], "-v") == 0)
    {
        std::cout << "mminilang v2.0" << std::endl <<
        "mminilang was written by Marek K. on 18/01/2019 in the C++ programming language."
                << std::endl <<
        "mminilang uses GNU Bison." << std::endl << std::endl <<
        "update v2.0: 25/01/2018" << std::endl <<
        std::endl << "Option -l for license, option -ia for interactive mode." << std::endl;
        exit(EXIT_SUCCESS);
    }
    else if(strcmp(argv[1], "-l") == 0)
    {
        std::cout << "This program is free software: you can redistribute it and/or modify" <<
                std::endl <<
        "it under the terms of the GNU General Public License as published by" << std::endl <<
        "the Free Software Foundation, either version 3 of the License, or" << std::endl <<
        "(at your option) any later version." << std::endl <<
        std::endl <<
        "This program is distributed in the hope that it will be useful," << std::endl <<
        "but WITHOUT ANY WARRANTY; without even the implied warranty of" << std::endl <<
        "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the" << std::endl <<
        "GNU General Public License for more details." << std::endl <<
        std::endl <<
        "You should have received a copy of the GNU General Public License" << std::endl <<
        "along with this program.  If not, see <http://www.gnu.org/licenses/>." << std::endl
                << std::endl <<
        "Dieses Programm ist Freie Software: Sie koennen es unter den Bedingungen" <<
                std::endl <<
        "der GNU General Public License, wie von der Free Software Foundation," << std::endl
                <<
        "Version 3 der Lizenz oder (nach Ihrer Wahl) jeder neueren" << std::endl <<
        "veroeffentlichten Version, weiter verteilen und/oder modifizieren." << std::endl <<
        std::endl <<
        "Dieses Programm wird in der Hoffnung bereitgestellt, dass es nuetzlich sein wird, "
                "jedoch" << std::endl <<
        "OHNE JEDE GEWAEHR,; sogar ohne die implizite" << std::endl << 
        "Gewaehr der MARKTFAEHIGKEIT oder EIGNUNG FUER EINEN BESTIMMTEN ZWECK." << std::endl
                <<
        "Siehe die GNU General Public License fuer weitere Einzelheiten." << std::endl << 
        std::endl << 
        "Sie sollten eine Kopie der GNU General Public License zusammen mit diesem"
                << std::endl <<
        "Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>." <<
                std::endl << std::endl <<
        "For version information, see the -v option for interactive mode with the -ia option." << std::endl;
        exit(EXIT_SUCCESS);
    }
    
    std::vector<double> args;
    for(size_t i = 2; i < static_cast<size_t>(argc); i++)
        args.push_back(stod(std::string(argv[i])));
    
    if(strcmp(argv[1], "-ia") == 0)
    {
        std::cout << "mminilang Interactive mode" << std::endl << std::endl;
        yyparse(std::cin, std::cout, std::cin, args);
    }
    else
    {
        std::ifstream in(std::string(argv[1]), std::ifstream::in);
        if(! in)
            mml_error(std::runtime_error("Can not open file!"));
        std::stringstream s;
        s << in.rdbuf() << '\n';
        yyparse(s, std::cout, std::cin, args);
        in.close();
    }
    
    return EXIT_SUCCESS;
}

unsigned gcd(unsigned a, unsigned b)
{
    while(a != b)
        if(a > b)
            a -= b;
        else
            b -= a;
    
    return a;
}

unsigned lcm(unsigned a, unsigned b)
{
    return abs(a * b)/gcd(a, b);
}

unsigned fact(unsigned a)
{
    if(a == 0)
        return 0;
    
    unsigned res = 1;
    for(unsigned i = 2; i <= a; i++)
        res *= i;
    
    return res;
}

void mml_error(std::exception exc)
{
    std::cerr << "Error: " << exc.what() << std::endl;
    exit(EXIT_FAILURE);
}

void mml_error(std::invalid_argument exc)
{
    std::cerr << "Invalid argument: " << exc.what() << std::endl;
    exit(EXIT_FAILURE);
}

void mml_error(std::runtime_error exc)
{
    std::cerr << "Runtime error: " << exc.what() << std::endl;
    exit(EXIT_FAILURE);
}

#if 0
void mml_error(std::logic_error exc)
{
    std::cerr << "Logic error: " << exc.what() << std::endl;
    exit(EXIT_FAILURE);
}

void mml_error(std::domain_error exc)
{
    std::cerr << "Domain error: " << exc.what() << std::endl;
    exit(EXIT_FAILURE);
}

void mml_error(std::out_of_range exc)
{
    std::cerr << "Out-of-range error: " << exc.what() << std::endl;
    exit(EXIT_FAILURE);
}

void mml_error(std::range_error exc)
{
    std::cerr << "Range error: " << exc.what() << std::endl;
    exit(EXIT_FAILURE);
}

void mml_error(std::overflow_error exc)
{
    std::cerr << "Overflow error: " << exc.what() << std::endl;
    exit(EXIT_FAILURE);
}

void mml_error(std::underflow_error exc)
{
    std::cerr << "Underflow error: " << exc.what() << std::endl;
    exit(EXIT_FAILURE);
}
#endif
