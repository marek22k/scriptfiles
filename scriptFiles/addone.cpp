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

#include <iostream>  /* cerr, endl, cout, flush, cin */
#include <stdexcept>  /* runtime_error */
#include <exception>  /* exception, terminate_handler, set_terminate, terminate */
#include <functional>  /* bind, plus, placeholders */
#include <string>  /* string, to_string */
#include <vector>  /* vector */
#include <optional>  /* optional */

#include <cstdlib>  /* exit, EXIT_SUCCESS, EXIT_FAILURE */
#include <climits>  /* UINT_MAX */
#include <csignal>  /* signal, SIGILL, SIGINT, SIGSEGV, SIGTERM */

using namespace std;

class invalid_input : public exception
{
    public:
        [[noreturn]] invalid_input(string msg) noexcept : _msg(msg) { }
        invalid_input(const char * msg) noexcept : _msg(msg) { }

        virtual const char * what() const noexcept override
        {
            return _msg.c_str();
        }

        virtual string what() noexcept
        {
            return _msg;
        }

    protected:
        string _msg;
};

void signalHandler(int sig)
{
    cerr << "\tThe program was unfortunately canceled!" << endl;
    cerr << "\tCancel code: " << sig << endl;
    terminate();
}

vector<optional<string>> menu = { "addone",
                        "======",
                        {},
                        "1st step:\n\r\tEnter the number to be added by one.",
                        "2nd step:\n\r\tConfirm the entry with the Enter key.",
                        {},
                        "Note:\n\r\tZero, numbers greater than " + to_string(UINT_MAX) + " and negative numbers as input are invalid.",
                        {},
                        "Author:\n\r\tMarek K. (mk16.de)",
                        {}};

vector<optional<string>> license = {  "This program is free software: you can redistribute it and/or modify",
                            "it under the terms of the GNU General Public License as published by",
                            "the Free Software Foundation, either version 3 of the License, or",
                            "(at your option) any later version.",
                            {},
                            "This program is distributed in the hope that it will be useful,",
                            "but WITHOUT ANY WARRANTY; without even the implied warranty of",
                            "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the",
                            "GNU General Public License for more details.",
                            "You should have received a copy of the GNU General Public License",
                            "along with this program.  If not, see <http://www.gnu.org/licenses/>.",
                            {}};

int main()
{
    signal(SIGILL, signalHandler);
    signal(SIGINT, signalHandler);
    signal(SIGSEGV, signalHandler);
    signal(SIGTERM, signalHandler);

    terminate_handler termhandler = [] () noexcept -> void {cerr << "\tProgram terminate!" << endl; exit(EXIT_FAILURE); };
    set_terminate(termhandler);

    try
    {
        unsigned x = 0;
        auto addone = bind(plus<decltype(x)>(), placeholders::_1, 1u);

        for(optional<string> line : menu)
            cout << line.value_or("") << endl;

        cout << "License: " << endl;
        for(optional<string> line : license)
            cout << "\t" << line.value_or("") << endl;


        cout << "Please input a number: " << flush;
        cin >> x;

        if(cin.fail()) throw runtime_error("Input failed!");
        if(x == 0) throw invalid_input("Input is 0!");

        x = addone(x);

        cout << "Result: " << x << endl;
    }
    catch(invalid_input & e)
    {
        cerr << "Invalid input: " << e.what() << endl;
        terminate();
    }
    catch(exception & e)
    {
        cout << e.what() << endl;
        terminate();
    }

    return EXIT_SUCCESS;
}
