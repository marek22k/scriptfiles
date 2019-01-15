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
    File: fg_conf.lua

-- fg_conf.lua

function add(x, y)
    return x + y
end

function sub(x, y)
    return x - y
end

function mul(x, y)
    return x * y
end

function div(x, y)
    return x / y
end

function mod(x, y)
    return x % y
end

*/

// This program uses the Lua C API
// This program needs the liblua.dll file

#include <iostream>
#include <string>
#include <stdexcept>

#include <cstring>
#include <cstdlib>

#include "lua.hpp"

using namespace std;

double CallNumFunc(lua_State *, string, double, double);

int main()
{
    lua_State * L = lua_open();
    
    try
    {
        luaL_openlibs(L);

        if(luaL_dofile(L, "fg_conf.lua"))
            throw runtime_error("Error(load file fg_conf.lua)");
        
        double num1, num2;
        
        cout << "Number 1: " << flush;
        cin >> num1;
        
        if(cin.fail())
            throw runtime_error("Invalid input!");
        
        cout << "Number 2: " << flush;
        cin >> num2;
        
        if(cin.fail())
            throw runtime_error("Invalid input!");
        
        cout << endl;
        
        cout << num1 << " + " << num2 << " = " << CallNumFunc(L, "add", num1, num2) << endl;
        cout << num1 << " - " << num2 << " = " << CallNumFunc(L, "sub", num1, num2) << endl;
        cout << num1 << " * " << num2 << " = " << CallNumFunc(L, "mul", num1, num2) << endl;
        cout << num1 << " / " << num2 << " = " << CallNumFunc(L, "div", num1, num2) << endl;
        cout << num1 << " % " << num2 << " = " << CallNumFunc(L, "mod", num1, num2) << endl;
    }
    catch(const runtime_error & e)
    {
        if(strcmp(lua_tostring(L, -1), "") == 0)
            cerr << "Error: " << e.what() << endl;
        else
            cerr << "Error: " << e.what() << ": " << lua_tostring(L, -1) << endl;
        
        lua_close(L);
        abort();
    }

    lua_close(L);
    return 0;
}

double CallNumFunc(lua_State * L, string func_name, double arg1, double arg2)
{    
    lua_getglobal(L, func_name.c_str());
    lua_pushnumber(L, arg1);
    lua_pushnumber(L, arg2);
    
    if(lua_pcall(L, 2, 1, 0) != 0)
        throw runtime_error("Error(pcall)");
    
    if(! lua_isnumber(L, -1))
        throw runtime_error("Result is not a number!");
    
    arg1 = lua_tonumber(L, -1);
    lua_pop(L, -1);
    
    return arg1;
}