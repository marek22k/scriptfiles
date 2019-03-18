/*
    Author: Marek K.

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

    Dieses Programm ist Freie Software: Sie können es unter den Bedingungen
    der GNU General Public License, wie von der Free Software Foundation,
    Version 3 der Lizenz oder (nach Ihrer Wahl) jeder neueren
    veröffentlichten Version, weiter verteilen und/oder modifizieren.

    Dieses Programm wird in der Hoffnung bereitgestellt, dass es nutzlich sein wird, jedoch
    OHNE JEDE GEWAHR,; sogar ohne die implizite
    Gewahr der MARKTFAHIGKEIT oder EIGNUNG FUR EINEN BESTIMMTEN ZWECK.
    Siehe die GNU General Public License fur weitere Einzelheiten.

    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
    Programm erhalten haben. Wenn nicht, siehe <https://www.gnu.org/licenses/>. 
*/

/* IP address of the server where the request for the grep.geek website should be sent.
Default value: "161.97.219.84" */
#define GREPGEEK_IP "161.97.219.84"
/* URL parameter containing the keyword(Call: grep.geek/?[QUERY_PAR]=keyword ; In this case:
grep.geek/?q=keyword). Default value: "q" */
#define QUERY_PAR "q"
/* Regular expression that extracts the search results. In this case, the first group should be
the number of the result, the second group the URL to the website and the third group the title
of the website (Title) (In case of deviations, the program can be adapted accordingly).
Default value: "<DT>([0-9]+)\\.\n *<a href=\"(.*)\">\n *(.*)\n *</a>" */
#define REGEXP_SEARCH "<DT>([0-9]+)\\.\n *<a href=\"(.*)\">\n *(.*)\n *</a>"
/* Regular expression after everything in the title is modified accordingly. The first and only
group should be what stays. Used here to remove the HTML code the keyword highlights. Default value: */
#define REGEXP_REPLACE "<span style=\"font-weight: bold;\">(.*)</span>"
/* Characters with which, when requesting grep.geek, the spaces are replaced. Default value: "+" */
#define BLACK_SPACE "+"
/* Regular expression of the character with the request to grep.geek, the spaces are replaced.
This regular expression is used to replace the characters with a space when the keyword is output.
Default value: "\\+" */
#define BLACK_SPACE_RE "\\+"

/*
for my windows pc: long: g++ mgrepgeek.cpp mgghttpclient.cpp -save-temps -O3 -std=c++17 -Wall
                         -Wextra -Wpedantic -lws2_32 -IE:\boost_1_69_0 -m32 -o mgrepgeek.exe
                   short: g++ mgrepgeek.cpp mgghttpclient.cpp -O3 -std=c++17 -lws2_32
                          -IE:\boost_1_69_0 -o mgrepgeek.exe
-IE:\boost_1_69_0\ is my C++ Boost library path
-std=c++17 mean that I use C++17
and -lws2_32 link thw WinSocket (need for Boost Asio)
*/

#include <iostream>
#include <stdexcept>
#include <exception>
#include <string>
#include <regex>

#include <cstdlib>
#include <cstddef>

#include <boost/asio.hpp>

#include "mgghttpclient.hpp"

using namespace std;

int main(int argc, char * argv[])
{
    try
    {
        std::string keyword;
        if(argc < 2)
            keyword = "OpenNIC";
        else
            for(int i = 1; i < argc; i++)
            {
                if(i > 1)
                    keyword += BLACK_SPACE;
                keyword += std::string(argv[i]);
            }
        
        boost::asio::io_service ios;
        HTTPClient htc(&ios);
        boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string(GREPGEEK_IP), 80);
        htc.get(ep, "grep.geek", std::string("/?" QUERY_PAR "=") + keyword);
        
        if(htc.status() != 200)
            throw runtime_error("The server returned an error:" + htc.result());
        
        
        
        regex reg(REGEXP_SEARCH);
        smatch sm;
        std::string str = htc.body();
        
        cout << "What is mgrepgeek?\n"
                "mgrepgeek is a program written by Marek K. on 18/03/2018 in the programming language C++,\n"
                "which uses the grep.geek search to search the internet for a keyword. The search results\n"
                "are shown below. The program uses the C ++ Boost Library.\n"
                "The program is available under the GNU GPL v3 license." << endl <<
                "How do I use mgrepgeek?\n"
                "Enter the program name of mgrepgeek into the terminal (possibly with a ./ in front of the program name)\n"
                "and search for the keyword as the first argument (the argument is often given after the program name,\n"
                "separated by a space)." <<
                endl << endl << "Search results for " << regex_replace(keyword, regex(BLACK_SPACE_RE), " ") << ":" << endl;
        
        size_t count = 0;
        while(regex_search(str, sm, reg))
        {
            count++;
            if(sm.size() > 1)
            {
                /*for(size_t i = 0; i < sm.size(); i++)
                    cout << "Res: " << sm.str(i) << endl;*/
                
                cout << sm.str(1) << ". " << regex_replace(sm.str(3), regex(REGEXP_REPLACE), "$1") << " <" << sm.str(2) << ">" << endl;
            }
            else
                break;
            
            str = sm.suffix().str();
        }
        
        cout << endl;
        if(count == 0)
            cout << "No result found for your search." << endl;
        else
            cout << count << " results found for your search." << endl;
    }
    catch(const exception & e)
    {
        cerr << "Error: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
    catch(const boost::system::error_code & berror)
    {
        cerr << "Error: " << berror.message() << endl;
        exit(EXIT_FAILURE);
    }
    catch(...)
    {
        cerr << "Unknown error" << endl;
        exit(EXIT_FAILURE);
    }
    
    return EXIT_SUCCESS;
}
