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

// aml soll fur "Arbeiten mit Lua" stehen
// und testprog fur ein Programm, welches einen Test durchfuhrt

#define CONFIG_FILE "config.lua"
// CONFIG_FILE enthaelt den namen der Config-Datei
#define CONFIG_LUA  "menu = {\"Test\", \"Exit\"}     -- Menu options\n" \
"input_text = \"Option: \"     -- Text at the prompt\n" \
"success_text = \"Success!\"   -- Text if the test function returns true\n" \
"failed_text = \"Failed!\"     -- Text if the test function returns false\n" \
"\n"\
"function test(obj)          -- The test function called in a test that returns\n" \
"                            -- a boolean and requests an argument. The argument\n" \
"                            -- is usually nil.\n" \
"    if os.execute(obj) then return true else return false end\n" \
"                            -- It returns true if the terminal responds\n" \
"                            -- otherwise false.\n" \
"end"
// CONFIG_LUA enthaelt den Inhalt der Config-Datei.
// LUA, weil es sich um Lua-Code handelt

#include <iostream>
#include <exception>
#include <stdexcept>
#include <fstream>

#include <cstdlib>
#include <cstddef>

#include <lua.hpp>

int main()
{
    lua_State * Lua = lua_open();
    luaL_openlibs(Lua);
    
    try
    {
        std::ifstream f1(CONFIG_FILE);
        if(! f1)  // Erstelle ein Config-Datei, wenn keine vorhanden ist
        {
            std::ofstream f2(CONFIG_FILE);
            
            if(! f2.good())
                throw std::runtime_error("Can not open file to write " CONFIG_FILE);
            
            f2 << CONFIG_LUA;
            
            f2.close();
        }
        f1.close();
        
        if(luaL_dofile(Lua, CONFIG_FILE))  // Lasse die Config-Datei von Lua lesen( und interpretieren)
            throw std::runtime_error( "reading " CONFIG_FILE );
        
        lua_getglobal(Lua, "menu");  // Lade die Variable menu, in dieser ist die Beschriftung des Menus enthalten
        // Durch das aendern der Config-Datei kann das Menu auch auf Deutsch sein
        
        size_t siz = luaL_getn(Lua, 1);  // Lade die grosze des Menus und gebe dieses aus
        
        const char * str;
        for(size_t i = 1; i <= siz; i++)  // Ausgabe des Menus
        {
            luaL_checktype(Lua, 1, LUA_TTABLE);
            lua_rawgeti(Lua, 1, i);
            
            luaL_checktype(Lua, 2, LUA_TSTRING);
            str = lua_tostring(Lua, 2);
            std::cout << i << " - " << str << std::endl;
            lua_pop(Lua, 1);
        }
        
        lua_pop(Lua, 1);
        
        std::cout << std::endl;
        
        lua_getglobal(Lua, "input_text");  // Aufforderung zur Eingabe der gewunschten Option
        luaL_checktype(Lua, 1, LUA_TSTRING);
        str = lua_tostring(Lua, 1);
        std::cout << str << std::flush;
        
        unsigned short option = static_cast<unsigned short>(-1);
        std::cin >> option;
        
        if(std::cin.fail() || option > siz)
            throw std::runtime_error("Invalid option!");
        
        lua_pop(Lua, 1);
        
        if(option == 1)  // Wenn der Test durchgefuhrt werden soll(Option 1)
                         // sonst gehe weiter(do nothing und beende das Programm)
        {
            std::cout << std::endl;
            lua_getglobal(Lua, "test");  // Laden der Funktion
            lua_pushnil(Lua);
            
            if(lua_pcall(Lua, 1, 1, 0))  // Ausfuhren der Funktion
                throw std::runtime_error("Can not call function test!");
            
            luaL_checktype(Lua, -1, LUA_TBOOLEAN);  // Ruckgabetyp auf Typ richtigkeit uberprupfen
            int r = lua_toboolean(Lua, -1);
            lua_pop(Lua, 1);
            
            if(r)  // Uberprupfen ob der Test erfolgreich ist/war und
                   // dementsprechende Variable laden
                lua_getglobal(Lua, "success_text");
            else
                lua_getglobal(Lua, "failed_text");
            
            luaL_checktype(Lua, 1, LUA_TSTRING);
            str = lua_tostring(Lua, 1);
            std::cout << "Test status: " << str << std::endl;  // Resultat ausgeben
            
            lua_pop(Lua, 1);
        }
    }
    catch(std::exception & e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        abort();
    }
    
    lua_close(Lua);
    return EXIT_SUCCESS;
}