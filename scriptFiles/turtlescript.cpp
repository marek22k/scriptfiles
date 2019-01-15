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

#include "turtlescript.hpp"

namespace turtlescript
{
    /* turtlescript variable stack */
    TUR_STACK variables;
    
    int eval(std::string code)
    {
        auto iter = code.begin();
        decltype(iter) it;
        std::string codbuf, buf, name, value;
        size_t tmp, i;
        size_t track = 1;
        
        while(iter <= code.end())
        {
            if(*iter == ';')
            {
                for(it = codbuf.begin(); *it == ' ' || *it == '\n' || *it == '\t'; it++);
                codbuf.erase(codbuf.begin(), it);
                
                if(codbuf[0] == '#');
                else if((tmp = (buf = codbuf.substr(0, 9)).find("@")) != std::string::npos)
                {
                    buf = buf.substr(0, tmp);
                    for(i = tmp; codbuf[i] != '=' && codbuf[i] != ' '; i++);
                    
                    name = codbuf.substr(tmp + 1, i - tmp - 1);
                    for(i += 2; codbuf[i] == ' ' || codbuf[i] == '\n' || codbuf[i] == '\t'; i++);
                    for(tmp = i; codbuf[tmp] != ' ' && codbuf[tmp] != '\n' && codbuf[tmp] != '\t'
                    && tmp + 1 < codbuf.length(); tmp++);
                    if(tmp > codbuf.length())
                        throw TUR_EXCEPTION("Invalid value!", track);
                    if(tmp + 1 == i)
                        throw TUR_EXCEPTION("No value!", track);

                    value = context(codbuf.substr(i, tmp - i + 1), track);
                    
                    if(name == "")
                        throw TUR_EXCEPTION("No variable name!", track);

                    if(buf == "integer")
                        editvar(name, static_cast<TUR_INTEGER>(stoi(value)), 1);
                    else if(buf == "boolean")
                    {
                        if(value != "true" && value != "false")
                            throw TUR_EXCEPTION("No logic value!", track);

                        editvar(name, static_cast<TUR_BOOLEAN>(value=="true"?1:0), 2);
                    }
                    else if(buf == "string")
                    {
                        for(i += 1; codbuf[i] != '"'; i++);
                        for(tmp = i + 1; codbuf[tmp] != '"' ; tmp++);
                        
                        editvar(name, static_cast<TUR_STRING>(value.substr(1,
                        value.length() - 2)), 3);
                    }
                    else if(buf == "bignum")
                        editvar(name, static_cast<TUR_BIGNUM>(stoll(value)), 4);
                    else if(buf == "byte")
                        editvar(name, static_cast<TUR_BYTE>(stoi(value)), 5);
                    else if(buf == "float")
                        editvar(name, static_cast<TUR_FLOAT>(value), 6);
                    else
                        throw TUR_EXCEPTION("No valid type!", track);
                }
                else
                    throw TUR_EXCEPTION("Invalid command!", track);

                codbuf = "";
            }
            else
            {
                codbuf += *iter;
                if(*iter == '\n')
                    track++;
            }
            iter++;
        }
        
        return 1;
    }
    
    void editvar(std::string name, boost::any value, int type)
    {
        auto iter = std::find(variables.name.begin(), variables.name.end(), name);
        if(iter == variables.name.end())
        {
            variables.name.push_back(name);
            variables.value.push_back(value);
            variables.type.push_back(type);
        }
        else
        {
            variables.value[iter - variables.name.begin()] = value;
            variables.type[iter - variables.name.begin()] = type;
        }
    }
    
    std::string context(std::string code, unsigned line)
    {
        if(code.find("$") != std::string::npos)
        {
            code.erase(0, 1);
            for(size_t i = 0; i < variables.name.size(); i++)
            {
                if(code == variables.name[i])
                {
                    switch(variables.type[i])
                    {
                        case 1: return std::to_string(boost::any_cast<TUR_INTEGER>
                                (variables.value[i]));
                        case 2: return (boost::any_cast<TUR_INTEGER>(variables.value[i])==1?
                                "true":"false");
                        case 4: return std::to_string(boost::any_cast<TUR_BIGNUM>
                                (variables.value[i]));
                        case 5: return std::to_string(boost::any_cast<TUR_BYTE>
                                (variables.value[i]));
                        case 3: case 6: return boost::any_cast<TUR_STRING>(variables.value[i]);
                        default: throw TUR_EXCEPTION("Type Casting!", line);
                    }
                    return "";
                }
            }
        }
        return code;
    }
    
    int clear()
    {
        variables.name.clear();
        variables.value.clear();
        variables.type.clear();
        return 1;
    }
    
    TUR_STACK * stack()
    {
        return &variables;
    }
    
    TUR_INTEGER getinteger(std::string var)
    {
        for(size_t i = 0; i < variables.name.size(); i++)
            if(var == variables.name[i])
                return boost::any_cast<TUR_INTEGER>(variables.value[i]);

        return static_cast<TUR_INTEGER>(NULL);
    }
    
    TUR_BOOLEAN getboolean(std::string var)
    {
        for(size_t i = 0; i < variables.name.size(); i++)
            if(var == variables.name[i])
                return boost::any_cast<TUR_BOOLEAN>(variables.value[i]);

        return static_cast<TUR_BOOLEAN>(NULL);
    }
    
    TUR_STRING getstring(std::string var)
    {
        for(size_t i = 0; i < variables.name.size(); i++)
            if(var == variables.name[i])
                return boost::any_cast<TUR_STRING>(variables.value[i]);

        return static_cast<TUR_STRING>(NULL);
    }
    
    TUR_BIGNUM getbignum(std::string var)
    {
        for(size_t i = 0; i < variables.name.size(); i++)
            if(var == variables.name[i])
                return boost::any_cast<TUR_BIGNUM>(variables.value[i]);

        return static_cast<TUR_BIGNUM>(NULL);
    }
    
    TUR_BYTE getbyte(std::string var)
    {
        for(size_t i = 0; i < variables.name.size(); i++)
            if(var == variables.name[i])
                return boost::any_cast<TUR_BYTE>(variables.value[i]);

        return static_cast<TUR_BYTE>(NULL);
    }
    
    TUR_FLOAT getfloat(std::string var)
    {
        for(size_t i = 0; i < variables.name.size(); i++)
            if(var == variables.name[i])
                return boost::any_cast<TUR_FLOAT>(variables.value[i]);

        return static_cast<TUR_FLOAT>(NULL);
    }

}