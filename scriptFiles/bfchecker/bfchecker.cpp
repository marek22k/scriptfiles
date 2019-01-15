#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    string res;
    string line;
    ifstream f(argv[1]);
    while(getline(f, line))
    {
        res += line;
    }
    f.close();

    int BFwhileOpen = 0;
    int BFwhileClose = 0;
    int BFRight = 0;
    int BFLeft = 0;
    int BFA = 0;
    int BFM = 0;
    int BFOutput = 0;
    int BFInput = 0;
    int BFComments = 0;
    string comment = "";
    for(int i = 0; i < res.length(); i++)
    {
        if(res[i] == '[') BFwhileOpen++;
        else if(res[i] == ']') BFwhileClose++;
        else if(res[i] == '>') BFRight++;
        else if(res[i] == '<') BFLeft++;
        else if(res[i] == '+') BFA++;
        else if(res[i] == '-') BFM++;
        else if(res[i] == '.') BFOutput++;
        else if(res[i] == ',') BFInput++;
        else
        {
            BFComments++;
            comment += res[i];
        }
    }

    cout << "[: " << BFwhileOpen << endl;
    cout << "]: " << BFwhileClose << endl;
    cout << ">: " << BFRight << endl;
    cout << "<: " << BFLeft << endl;
    cout << "+: " << BFA << endl;
    cout << "-: " << BFM << endl ;
    cout << ".: " << BFOutput << endl;
    cout << ",: " << BFInput << endl;
    cout << "Comments: " << BFComments << " - " << comment << endl << endl;

    if(BFwhileOpen == BFwhileClose)
        cout << "ok - while" << endl;
    else
        cout << "not ok - while" << endl;

    if(BFRight - BFLeft >= 0)
        cout << "ok - cell" << endl;
    else
        cout << "not ok - cell" << endl;

    return 0;
}
