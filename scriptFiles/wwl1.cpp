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
along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

#define CONFIG_FILE "config.lua"

#define CONFIG_VALUE ""\
"menu = {\"Test\", \"License\", \"Exit\"}\n"\
"menu_items = 3\n"\
"\n"\
"input_text = \"\\nOption: \"\n"\
"\n"\
"license = [==[\n"\
"\n"\
"This program is free software: you can redistribute it and/or modify\n"\
"it under the terms of the GNU General Public License as published by\n"\
"the Free Software Foundation, either version 3 of the License, or\n"\
"(at your option) any later version.\n"\
"\n"\
"This program is distributed in the hope that it will be useful,\n"\
"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"\
"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"\
"GNU General Public License for more details.\n"\
"\n"\
"You should have received a copy of the GNU General Public License\n"\
"along with this program.  If not, see <https://www.gnu.org/licenses/>.]==]\n"\
"\n"\
"function Test()\n"\
"  if isHere() == 0.0 and TestMemory() then\n"\
"    return false\n"\
"  else\n"\
"    return true\n"\
"  end\n"\
"end\n"\
"\n"\
"success_text = \"\\nStatus: Success :-)\"\n"\
"failure_text = \"\\nStatus: Failed :-(\"\n"\

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <fstream>

#include <cstdlib>
#include <cstddef>


// include lua.h lualib.h luaxlib.h
#include <lua.hpp>

// Lua functions
int isHere(lua_State * Lua) noexcept
{
    lua_pushnumber(Lua, system(NULL));
    return 1;
}

int TestMemory(lua_State * Lua) noexcept
{
    char * ptr = (char *) malloc(sizeof(char));
    if(ptr == NULL)
        lua_pushboolean(Lua, 0);
    else
        lua_pushboolean(Lua, 1);
    free(ptr);
    return 1;
}

// Functions
void Test(lua_State * Lua)
{
    lua_getglobal(Lua, "Test");
    if(lua_pcall(Lua, 0, 1, 0))
        throw std::runtime_error("Can not call function Test!");
    
    if(! lua_isboolean(Lua, -1))
        throw std::runtime_error("Return value is not a boolean!");
    
    if(lua_toboolean(Lua, -1))
        lua_getglobal(Lua, "success_text");
    else
        lua_getglobal(Lua, "failure_text");
    
    if(! lua_isstring(Lua, -1))
        throw std::runtime_error("success_text or failure_text are not strings!");
    
    std::cout << lua_tostring(Lua, -1) << std::endl;
}

void License(lua_State * Lua)
{
    lua_getglobal(Lua, "license");
    if(! lua_isstring(Lua, -1))
        throw std::runtime_error("license is not a string!");
    
    std::cout << lua_tostring(Lua, -1) << std::endl;
}

int main()
{
    try
    {
        lua_State * Lua = luaL_newstate();
        
        if(Lua == nullptr || Lua == NULL)
            throw std::runtime_error("Can not open Lua state!");
        
        luaL_openlibs(Lua);
        
        lua_pushcfunction(Lua, isHere);
        lua_setglobal(Lua, "isHere");
        
        lua_pushcfunction(Lua, TestMemory);
        lua_setglobal(Lua, "TestMemory");
        
        std::ifstream check_file(CONFIG_FILE);
        if(! check_file)
        {
            std::ofstream fil(CONFIG_FILE);
            
            if(! fil.good())
                throw std::runtime_error("Can not write to file " CONFIG_FILE "!");
            
            fil << CONFIG_VALUE;
            
            fil.close();
        }
        check_file.close();
        
        if(luaL_dofile(Lua, CONFIG_FILE))
            throw std::runtime_error("Can not read " CONFIG_FILE "!");
        
        lua_getglobal(Lua, "menu_items");
        if(! lua_isnumber(Lua, -1))
            throw std::runtime_error("menu_itens is not a number!");
        
        size_t menu_items = (size_t) lua_tonumber(Lua, -1);
        
        lua_getglobal(Lua, "menu");
        if(! lua_istable(Lua, -1))
            throw std::runtime_error("menu is not a table!");
        
        for(size_t i = 0; i < menu_items; i++)
        {
            lua_rawgeti(Lua, -1, i + 1);
            
            if(! lua_isstring(Lua, -1))
                throw std::runtime_error("menu value is not a string!");
            
            std::cout << i + 1 << " - " << lua_tostring(Lua, -1) << std::endl;
            lua_pop(Lua, 1);
        }
        
        lua_getglobal(Lua, "input_text");
        if(! lua_isstring(Lua, -1))
            throw std::runtime_error("input_text is not a string");
        
        std::cout << lua_tostring(Lua, -1);
        
        lua_settop(Lua, 0);
        
        unsigned short option;
        std::cin >> option;
        
        if(std::cin.fail() || option == 0 || option > 3)
            throw std::runtime_error("Invalid input!");
        
        switch(option)
        {
            case 1: Test(Lua); break;
            case 2: License(Lua); break;
            case 3: exit(EXIT_SUCCESS);
        }
        
        lua_settop(Lua, 0);
    }
    catch(std::exception & e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    
    return EXIT_SUCCESS;
}