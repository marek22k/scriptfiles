#include <iostream>
#include <fstream>

#include <cstdlib>
#include <cstring>

#include "mminilang.hpp"

int main(int argc, char * argv[])
{
    if(argc < 2)
    {
        std::cerr << "Error: " << "Invalid arguments! mminilang filename.mml argument1 argument2 argumentn" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    if(strcmp(argv[1], "-v") == 0)
    {
        std::cout << "mminilang v1.0" << std::endl <<
        "mminilang was written by Marek K. on 18/01/2019 in the C++ programming language."
                << std::endl <<
        "mminilang uses GNU Bison." << std::endl << std::endl <<
        "Option -l for license, option -ia for interactive mode." << std::endl;
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
        "For version information, see the -v option for help with the -h option." << std::endl;
        exit(EXIT_SUCCESS);
    }
    
    std::vector<double> args;
    for(size_t i = 2; i < static_cast<size_t>(argc); i++)
        args.push_back(stod(std::string(argv[i])));
    
    if(strcmp(argv[1], "-ia") == 0)
    {
        std::cout << "mminilang Interactive mode" << std::endl << std::endl;
        yyparse(std::cin, std::cout, args);
    }
    else
    {
        std::ifstream in(std::string(argv[1]), std::ifstream::in | std::ifstream::binary);
        yyparse(in, std::cout, args);
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