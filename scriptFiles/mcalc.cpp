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

#include <cstdlib>
#include <cstring>

int yyparse();

int main(int argc, char * argv[])
{
    if(argc >= 2)
    {
        if(strcmp(argv[1], "-v") == 0)
        {
            std::cout << "mcalc v1.0" << std::endl <<
            "mcalc was written by Marek K. on 09/01/2019 in the C++ programming language."
                    << std::endl <<
            "mcalc uses GNU Bison." << std::endl << std::endl <<
            "Option -h for Help; Option -l for license." << std::endl;
            exit(EXIT_SUCCESS);
        }
        else if(strcmp(argv[1], "-h") == 0)
        {
            std::cout << "After launching mcalc, an interactive console opens." << std::endl <<
            "In this, the computing tasks such. For example, enter \"1 + 1\"." << std::endl <<
            "This is also possible with comma numbers." << std::endl <<
            "You can omit the 0 at 0.: z. B. 0.5 can also be written as .5." << std::endl <<
            "If the module operator \"%\" is used, the decimal places are cut off."
                    << std::endl <<
            "To quit the Interactive Console, you can use \"!\" enter." << std::endl <<
            "To negate a number you can specify a \"-\" (NEG)." << std::endl <<
            "Operators:" << std::endl <<
            "Addition (plus): +" << std::endl <<
            "Subtraction (minus): -" << std::endl <<
            "Multiplication (times): *" << std::endl <<
            "Divion: /" << std::endl <<
            "Modules: %" << std::endl <<
            "Potency: ^" << std::endl <<
            "The operators have the following order:" << std::endl <<
            "^" << std::endl <<
            "NEG" << std::endl <<
            "* / %" << std::endl <<
            "+ -" << std::endl <<
            "A bracketing is also possible." << std::endl << std::endl <<
            "Option -v for Version; Option -l for license." << std::endl;
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
    }
    
    yyparse();
    
    return EXIT_SUCCESS;
}
