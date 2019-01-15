/*
    mc1interpreter written by Marek K.
    mc1interpreter = M Custom 1 Interpreter
*/

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
#include <fstream>
#include <vector>
#include <array>
#include <string>
#include <ostream>
#include <new>

#include <cstdlib>
#include <cstring>
#include <cstddef>
#include <ctime>

using namespace std;

static vector<array<string, 2>> vars;
static vector<array<string, 2>> packs;
static vector<string> log;

string from_cp_to_str(char * c);
string GetInput(string filename);
vector<string> split(string &str, char c);
string GetVarVal(string var);
void PutVar(string var, string val);
void EditVar(string var, string val);
long long ret(string args);
void RunCode(string com);
bool IfStat(vector<string> v);
void Parse(string);
void exit_script();
bool RunPack(string);

int main(int argc, char * argv[])
{
    try
    {
        atexit(exit_script);

        if(argc < 2)
            throw string("No filename :-(");

        string fn;
        fn = from_cp_to_str(argv[1]);
        string in = GetInput(fn);
        vector<string> commands;
        commands = split(in, ';');

        PutVar("__FILENAME__", fn);
        PutVar("__MVERSION__", "mc1");
        PutVar("__FOR__", "0");
        PutVar("__LOG__", "");
        PutVar("__LOGGERLIMIT__", "0");
        PutVar("__EXITOK__", to_string(EXIT_SUCCESS));
        PutVar("__EXITABORT__", to_string(EXIT_FAILURE));
        char date[] = __DATE__, time[] = __TIME__;
        PutVar("__CVERSION__", from_cp_to_str(time) + " " + from_cp_to_str(date));

        for(unsigned i = 0; i < commands.size(); i++)
            Parse(commands[i]);
    }
    catch(string str)
    {
        cerr << "Error: " << str;
        exit(EXIT_FAILURE);
    }
    catch(...)
    {
        cerr << "Unknown error :-(";
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}

string from_cp_to_str(char * c)
{
    string res;

    if(c == NULL) throw string("Argument is a NULL-Pointer :-(");

    unsigned len = strlen(c);

    for(unsigned i = 0; i < len; i++)
        res += c[i];

    return res;
}

string GetInput(string filename)
{
    ifstream f;
    string res, line;

    f.open(filename);
    if(f.is_open())
    {
        while( getline(f, line) )
            res += line;

        f.close();
    }
    else throw string("Unable to open file[err1] :-(");

    return res;
}

vector<string> split(string &str, char c)
{
    string tmp("");
    vector<string> res;

    for(unsigned i = 0; i < str.length(); i++)
    {
        if(str[i] == c && str[i-1] != '\\')
        {
           res.push_back(tmp);
           tmp = "";
        }
        else tmp += str[i];
    }

    return res;
}

string GetVarVal(string var)
{
    for(unsigned i = 0; i < vars.size(); i++)
        if(vars[i][0] == var) return vars[i][1];

    return "[err]";
}

void PutVar(string var, string val)
{
    array<string, 2> tmp = {var, val};
    vars.push_back(tmp);
}

void EditVar(string var, string val)
{
    for(unsigned i = 0; i < vars.size(); i++)
        if(vars[i][0] == var) vars[i][1] = val;
}

long long ret(string args)
{
    long long lng = 0;
    string tmp("");
    vector<string> res;
    vector<char> op;
    for(unsigned i = 0; i < args.length(); i++)
    {
        if(args[i] == '+' || args[i] == '-' || args[i] == '*' || args[i] == '/' || args[i] == '%')
        {
            res.push_back(tmp);
            tmp = "";
            op.push_back(args[i]);
        }
        else tmp += args[i];
    }
    res.push_back(tmp);
    if((tmp=GetVarVal(res[0])) != "[err]")
        lng = stoi(GetVarVal(res[0]));
    else
    {
        try
        {
            lng = stoi(res[0]);
        }
        catch(...)
        {
                string str("Var not found: ");
                str += res[0];
                str += ";";
                throw str;
        }
    }
    for(unsigned i = 1, j = 0; i < res.size(); i++)
    {
        if((tmp=GetVarVal(res[i])) != "[err]")
        {
            if(tmp[0] == '"') throw string("Math error :-(");
            if(op[j] == '+') lng += stoi(tmp);
            if(op[j] == '-') lng -= stoi(tmp);
            if(op[j] == '*') lng *= stoi(tmp);
            if(op[j] == '/') lng /= stoi(tmp);
            if(op[j] == '%') lng %= stoi(tmp);
            j++;
        }
        else
        {
            try
            {
                if(op[j] == '+') lng += stoi(res[i]);
                if(op[j] == '-') lng -= stoi(res[i]);
                if(op[j] == '*') lng *= stoi(res[i]);
                if(op[j] == '/') lng /= stoi(res[i]);
                if(op[j] == '%') lng %= stoi(res[i]);
                j++;
            }
            catch(...)
            {
                string str("Var not found: ");
                str += res[i];
                str += ";";
                throw str;
            }
        }
    }
    return lng;
}

void RunCode(string com)
{
        string str(""), na("");
        str = com.substr(com.find("{"), com.length());
        na = "";
        for(unsigned i = 0; i < str.length(); i++)
        {
            if(str[i] == '}' && str[i-1] != '!')
            {
                Parse(na);
                na = "";
            }
            else if((str[i] == '{' && str[i+1] != '!') || (str[i] == '!' && str[i+1] == '}') || (str[i] == '!' && str[i-1] == '{'));
            else na += str[i];
        }
}

bool IfStat(vector<string> v)
{
    bool b = 0;
    string vs2("");
    string vs1("");

    if((vs1 = GetVarVal(v[1])) != "[err]")
        ;
    else if(v[1][0] == '"')
        vs1 = v[1];
    else
        vs1 = to_string(ret(v[1]));

    if((vs2 = GetVarVal(v[3])) != "[err]")
        ;
    else if(v[3][0] == '"')
        vs2 = v[3];
    else
        vs2 = to_string(ret(v[3]));

    if(v[2] == "==") if(vs1 == vs2) b = 1;
    if(v[2] == "!=") if(vs1 != vs2) b = 1;
    if(v[2] == "<") if(stoi(vs1) < stoi(vs2)) b = 1;
    if(v[2] == "<=") if(stoi(vs1) <= stoi(vs2)) b = 1;
    if(v[2] == ">") if(stoi(vs1) > stoi(vs2)) b = 1;
    if(v[2] == ">") if(stoi(vs1) >= stoi(vs2)) b = 1;
    return b;
}

void Parse(string com)
{
    string sc;
    string args;
    bool c = 0;
    for(unsigned i = 0; i < com.length(); i++)
        if(com[i] == ' ') c = 1; else if(c) args += com[i]; else sc += com[i];
    if(com[0] == '$');
    else if(com[0] == '#')
    {
        string str = com.substr(1, com.length()-1);
        log.push_back(str);
        EditVar("__LOG__", str);
        EditVar("__LOGGERLIMIT__", to_string(log.size()));
    }
    else if(sc == "errmsg")
    {
        string val;
        if((val=GetVarVal(args)) != "[err]") cerr << val;
        else throw string("Var not found");
    }
    else if(sc == "errmsgln")
    {
        string val;
        if((val=GetVarVal(args)) != "[err]") cerr << val << endl;
        else throw string("Var not found");
    }
    else if(sc == "package")
    {
        vector<string> v;
        v = split(com, ' ');

        array<string, 2> a = {v[1], com};
        packs.push_back(a);
    }
    else if(sc == "()" || sc == "run")
    {
        if(!RunPack(args)) throw string("Package not found");
    }
    else if(sc == "logger")
    {
        string x;
        try
        {
            int acc;
            if((x=GetVarVal(args)) != "[err]")
                acc = stoi(x);
            else
                acc = stoi(args);
            if(unsigned(acc) >= log.size())
                acc = 0;
            cout << (log.size()>0?log[acc]:"") << endl;
        }
        catch(...)
        {
            throw string("logger error");
        }
    }
    else if(sc == "exit")
        exit((int) ret(args));
    else if(sc == "sys")
    {
        args = com.substr(4, com.length()-4);
        //char str[args.length()+1];
        char * str = new char[args.length()+1];
        if(str == nullptr || str == NULL) abort();
        for(unsigned i = 0; i < args.length(); i++)
            str[i] = args[i];
        str[args.length()] = (char) 0;

        system(str);
        delete [] str;
    }
    else if(sc == "ok")
    {
        if(GetVarVal(args) != "[err]")
        {
            if(system(NULL)) EditVar(args, "1");
            else EditVar(args, "0");
        } else throw string("var not found");
    }
    else if(sc == "bool")
    {
        vector<string> v;
        string str("");
        com += " ";
        v = split(com, ' ');
        if(v.size() < 2) throw string("bool");

        if(v[1] == "NOT")
            if((str=GetVarVal(v[2])) != "[err]") EditVar(v[2], to_string(! stoi(str)));
            else throw string("var not found");
        else if(v[1] == "AND")
            if((str=GetVarVal(v[2])) != "[err]") EditVar(v[2], to_string(stoi(str) && stoi(GetVarVal(v[3]))));
            else throw string("var not found");
        else if(v[1] == "OR")
            if((str=GetVarVal(v[2])) != "[err]") EditVar(v[2], to_string(stoi(str) || stoi(GetVarVal(v[3]))));
            else throw string("var not found");
        else if(v[1] == "XOR")
            if((str=GetVarVal(v[2])) != "[err]") EditVar(v[2], to_string(stoi(str) ^ stoi(GetVarVal(v[3]))));
            else throw string("var not found");


        else if(v[1] == "NAND")
            if((str=GetVarVal(v[2])) != "[err]") EditVar(v[2], to_string(!(stoi(str) && stoi(GetVarVal(v[3])))));
            else throw string("var not found");
        else if(v[1] == "NOR")
            if((str=GetVarVal(v[2])) != "[err]") EditVar(v[2], to_string(!(stoi(str) || stoi(GetVarVal(v[3])))));
            else throw string("var not found");
        else if(v[1] == "NXOR")
            if((str=GetVarVal(v[2])) != "[err]") EditVar(v[2], to_string(!(stoi(str) ^ stoi(GetVarVal(v[3])))));
            else throw string("var not found");

        else throw string("bool: operator not found");
    }
    else if(sc == "while")
    {
        vector<string> v;
        v = split(com, ' ');
        if(v.size() <  3) throw string("if: if [var1] [compare] [var2] {command1}{commandn}");

        while(IfStat(v))
            RunCode(com);
    }
    else if(sc == "dowhile")
    {
        vector<string> v;
        v = split(com, ' ');
        if(v.size() <  3) throw string("if: if [var1] [compare] [var2] {command1}{commandn}");

        do
        {
            RunCode(com);
        } while(IfStat(v));
    }
    else if(sc == "scan")
    {
        if(GetVarVal(args) != "[err]")
        {
            string tmp("");
            cin >> tmp;
            EditVar(args, tmp);
        }
        else
        {
            string str("Not found var: ");
            str += args,
            str += ";";
            throw str;
        }

    }
    else if(sc == "scanln")
    {
        if(GetVarVal(args) != "[err]")
        {
            string tmp("");
            getline(cin, tmp);
            EditVar(args, tmp);
        }
        else
        {
            string str("Not found var: ");
            str += args,
            str += ";";
            throw str;
        }

    }
    else if(sc == "strscan")
    {
        if(GetVarVal(args) != "[err]")
        {
            string tmp("");
            cin >> tmp;
            tmp += "\"";
            EditVar(args, "\"" + tmp);
        }
        else
        {
            string str("Not found var: ");
            str += args,
            str += ";";
            throw str;
        }

    }
    else if(sc == "strscanln")
    {
        if(GetVarVal(args) != "[err]")
        {
            string tmp("");
            getline(cin, tmp);
            tmp += "\"";
            EditVar(args, "\"" + tmp);
        }
        else
        {
            string str("Not found var: ");
            str += args,
            str += ";";
            throw str;
        }

    }
    else if(sc == "if")
    {
        vector<string> v;
        v = split(com, ' ');
        if(v.size() <  3) throw string("if: if [var1] [compare] [var2] {command1}{commandn}");
        //string vs1 = GetVarVal(v[1]);
        string vs2("");
        string vs1("");

        if((vs1 = GetVarVal(v[1])) != "[err]")
            ;
        else if(v[1][0] == '"')
            vs1 = v[1];
        else
            vs1 = to_string(ret(v[1]));

        if((vs2 = GetVarVal(v[3])) != "[err]")
            ;
        else if(v[3][0] == '"')
            vs2 = v[3];
        else
            vs2 = to_string(ret(v[3]));

        if(IfStat(v)) RunCode(com);
    }
    else if(sc == "flush")
    {
        flush(cout);
    }
    else if(sc == "time")
    {
        if(GetVarVal(args) != "[err]")
            EditVar(args, to_string( time(0) ));
        else
        {
            string str("Not found var: ");
            str += args,
            str += ";";
            throw str;
        }
    }
    else if(sc == "for")
    {
        vector<string> s;
        vector<string> coms;
        string na("");
        for(unsigned i = sc.length() + (com[sc.length()]==' '?1:0); i < com.length(); i++)
            na += com[i];
        s = split(na, ' ');
        string str("");
        str = com.substr(com.find("{"), com.length());
        na = "";
        for(unsigned i = 0; i < str.length(); i++)
        {
            if(str[i] == '}')
            {
                coms.push_back(na);
                na = "";
            }
            else if(str[i] == '{');
            else na += str[i];
        }
        for(long i = stoi(s[0]); i <= stoi(s[1]); i += stoi(s[2]))
        {
            EditVar("__FOR__", to_string(i));
            for(unsigned j = 0; j < coms.size(); j++)
                Parse(coms[j]);
        }
    }
    else if(sc == "svar")
    {
        string val(""), name("");
        c = 0;
        for(unsigned i = 5; i < com.length(); i++)
        {
            if(com[i-1] != '=' && c) val += com[i];
            if(com[i] == '=') c = 1;
            if(com[i] != ' ' && !c) name += com[i];
        }
        if(val[0] != '"' && val[0] == '@')
        {
            string buf(val);
            val = "";
            for(unsigned i = 0; i < buf.length(); i++) if(buf[i] != ' ') val += buf[i];
            val = to_string(ret(val.substr(1, val.length()-1)));
        }
        PutVar(name, val);
    }
    else if(sc == "println")
    {
        string str("print ");
        if(args[0] == '@')
        {
            c = 0;
            args = "";
            for(unsigned i = 0; i < com.length(); i++)
            {
                if(com[i] != '@' && c) args += com[i];
                else if(com[i] == ' ') c = 1;
            }
        }
        str += args;
        Parse(str);
        cout << endl;
    }
    else if(sc == "print")
    {
        string val;

        if(args[0] == '@')
        {
            c = 0;
            args = "";
            for(unsigned i = 0; i < com.length(); i++)
            {
                if(com[i] != '@' && c) args += com[i];
                else if(com[i] == ' ') c = 1;
            }
        }
        if((val=GetVarVal(args)) != "[err]")
        {
            if(val[0] == '"') cout << val.substr(1, val.length()-2);
            else cout << val;
        }
        else if(args[0] == '"')
        {
            c = 0;
            for(unsigned i = 0; i < com.length()-1; i++)
            {
                if(c) cout << com[i];
                if(com[i] == '"') c = 1;
            }
        }
        else
        {

            long long lng = ret(args);
            cout << lng;
        }
    }
    else if(sc == "line")
    {
        cout << endl;
    }
    else
    {
        if(GetVarVal(sc) != "[err]")
        {
            string val("");
            c = 0;

            for(unsigned i = sc.length(); i < com.length(); i++)
            {
                if(com[i-1] != '=' && c) val += com[i];
                if(com[i] == '=') c = 1;
            }
            if(val[0] != '"' && val[0] == '@')
            {
                string buf(val);
                val = "";
                for(unsigned i = 0; i < buf.length(); i++) if(buf[i] != ' ') val += buf[i];
                val = to_string(ret(val.substr(1, val.length()-1)));
            }
            EditVar(sc, val);
        }
        else
        {
            cerr << "Interpret error: Command not found: " << sc << "; Arguments: " << args << endl;
            exit(EXIT_FAILURE);
        }
    }
}

void exit_script()
{
    RunPack("exit");
}

bool RunPack(string args)
{
    string c = "[err]";
    for(unsigned i = 0; i < packs.size(); i++)
        if(packs[i][0] == args)
        {
            c = packs[i][1];
            break;
        }

    if(c == "[err]")
        return 0;
    else
        RunCode(c);

    return 1;
}
