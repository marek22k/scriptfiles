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

#include "exceptionhelper.hpp"
#include <iostream>
#include <new>
#include <cstdlib>
#include <cstring>

// INIT

ExceptionHelper::ExceptionHelper(void (* func)(void)) :
    abr(func),
    status(EXIT_SUCCESS),
    met(1)
{
    errmsg = new char[255];
    errmsg[0] = static_cast<char>(0);
}

ExceptionHelper::ExceptionHelper() :
    abr(abort),
    status(EXIT_SUCCESS),
    met(1)
{
    errmsg = new char[255];
    errmsg[0] = static_cast<char>(0);
}

ExceptionHelper::~ExceptionHelper()
{
    delete [] errmsg;
}

// FUNCTION

int ExceptionHelper::operator()(unsigned line, char * file, short m)
{
    status = EXIT_FAILURE;
    std::cerr << "\n\r\tError!" << std::endl
              << std::endl
              << "\tReport" << std::endl
              << "\tMessage: " << (met==1?std::string(errmsg):exc->what()) << std::endl
              //<< "\t " << exc.what() << std::endl
              << "\tLine: " << line << std::endl
              << "\tFile: " << file << std::endl;
    if(m == 0) abr();
    else std::clog << "Program continue to run..." << std::endl;

    return status;
}

void ExceptionHelper::operator=(char * msg)
{
    strcpy(errmsg, msg);
    met = 1;
}

void ExceptionHelper::operator=(std::string msg)
{
    strcpy(errmsg, msg.c_str());
    met = 1;
}

void ExceptionHelper::operator=(std::exception * e)
{
    exc = e;
    met = 2;
}

int ExceptionHelper::reset()
{
    status = EXIT_SUCCESS;
    return status;
}

int ExceptionHelper::getstatus() const
{
    return status;
}

// FRIENDS

std::string to_string(ExceptionHelper & eh)
{
    return std::string(eh.errmsg);
}
