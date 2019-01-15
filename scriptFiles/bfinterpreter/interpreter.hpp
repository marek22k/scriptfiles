/*
    interpreter.hpp
    The author of this file is Marek K.
*/

#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <string>

namespace Interpreter
{
    class interpreter
    {
        public:
            std::string icode(std::string code);
            std::string input(std::string in);
            std::string interpret();
            bool qinput();

        private:
            /* declare functions for the instructions < > + - */
            void LEFT();  // <
            void RIGHT();  // >
            void INCREMENTED();  // +
            void DECREMENTED();  // -
            void action(char code);
            int bfloop(int i, std::string code);

            std::string code;  // Brainf*ck code
            std::string in;  // input
            char cell[32767];  // cell
            int cur;  // current cell

            std::string res;
            int inpos;
    };
}

#endif // INTERPRETER_H
