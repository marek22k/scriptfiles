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
    File: test.lua

function main()
	return "1,2,3,4"
end

*/

/*
    File: test.rb

if ARGV[1] != 1
	puts "Error"
else
	puts ARGV[0].split ","
end

*/

/*
    This program needs the liblua.dll (or liblua.so).
    This program uses mruby and the Lua C API.
*/

extern "C"
{
    #include <mruby.h>
    #include <mruby/compile.h>
    #include <mruby/array.h>
}

#include "lua.hpp"

#include <iostream>
#include <fstream>
#include <string>

#include <cstdlib>
#include <cstring>

int main(int argc, char * argv[])
{
    mrb_state * mrb = mrb_open();
    lua_State * Lua = lua_open();
  
    if(strcmp(argv[1], "-v") == 0)
    {
        std::cout << "mluarubyccombiner" << std::endl <<
                     "=================" << std::endl <<
                     "" << std::endl <<
                     "mluarubycombiner was written by Marek K. on 11/16/2018 in the programming language C++." << std::endl <<
                     "mluarubycombiner uses mruby(mruby.org) and the Lua C API(lua.org)." << std::endl <<
                     "" << std::endl <<
                     "Argument 1: Lua script" << std::endl <<
                     "Argument 2: Ruby file" << std::endl <<
                     "" << std::endl <<
                     "Example:" << std::endl <<
                     "mluarubycombiner test.lua test.rb" << std::endl <<
                     "" << std::endl <<
                     "In Ruby:" << std::endl <<
                     "ARGV[0]: Output of the Lua function with the name \"main\"" << std::endl <<
                     "ARGV[1]: fault condition" << std::endl <<
                     "fault conditions:" << std::endl <<
                     "1: Success" << std::endl <<
                     "2: Lua call error" << std::endl <<
                     "3: The return value of the Lua function main is not a string" << std::endl <<
                     "4: Lua read error" << std::endl <<
                     "" << std::endl <<
                     "This program is free software: you can redistribute it and/or modify" << std::endl <<
                     "it under the terms of the GNU General Public License as published by" << std::endl <<
                     "the Free Software Foundation, either version 3 of the License, or" << std::endl <<
                     "(at your option) any later version." << std::endl <<
                     "" << std::endl <<
                     "This program is distributed in the hope that it will be useful," << std::endl <<
                     "but WITHOUT ANY WARRANTY; without even the implied warranty of" << std::endl <<
                     "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the" << std::endl <<
                     "GNU General Public License for more details." << std::endl <<
                     "You should have received a copy of the GNU General Public License" << std::endl <<
                     "along with this program.  If not, see <http://www.gnu.org/licenses/>."
                ;
                goto EXIT;
    }
    
    try
    {
        if(argc < 2)
        {
            throw std::runtime_error("Argument error!");
        }
        
        luaL_openlibs(Lua);
        
        if(! mrb)
            throw std::runtime_error("Error open mrb!");
      
        int rs = 1;  // rs = run success
        
        char * str = nullptr;
        size_t str_len;
        
        if(luaL_dofile(Lua, argv[1]))
        {
            rs = 4;
        }
        
        if(rs != 4)
        {
            lua_getglobal(Lua, "main");
            lua_pushstring(Lua, "");
    
        
            if(lua_pcall(Lua, 1, 1, 0))
            {
                rs = 2;
            }
    
            if(! lua_isstring(Lua, -1))
            {
                rs = 3;
            }
            str_len = strlen(lua_tostring(Lua, -1));
            str = new char[str_len + 1];
            strcpy(str, lua_tostring(Lua, -1));
            lua_pop(Lua, -1);
        }
    
        
        mrb_value ARGV = mrb_ary_new_capa(mrb, 2);
        if(rs == 3)
            mrb_ary_push(mrb, ARGV, mrb_str_new(mrb, "Result is not a number!", 24));
        else if(rs == 4)
            mrb_ary_push(mrb, ARGV, mrb_str_new(mrb, "Error read file!", 16));
        else
        {
            if(str != nullptr)
            {
                mrb_ary_push(mrb, ARGV, mrb_str_new(mrb, str, str_len));
                delete [] str;
                str = nullptr;
            }
            else
            {
                mrb_ary_push(mrb, ARGV, mrb_str_new(mrb, "Error copying the result!", 25));
            }
        }
        mrb_ary_push(mrb, ARGV, mrb_fixnum_value(rs) );
        mrb_define_global_const(mrb, "ARGV", ARGV);
        
        std::ifstream f(argv[2]);
        std::string pardata, buf;  // pardata = parse data
        
        while( std::getline(f, buf) )
            pardata += buf + "\n";
        
        mrb_load_string(mrb, pardata.c_str());
        
    }
    catch(const std::runtime_error & e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
  
    EXIT:
    mrb_close(mrb);
    lua_close(Lua);
    
    return 0;
}
