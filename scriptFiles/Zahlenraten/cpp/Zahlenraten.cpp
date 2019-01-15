#include <iostream>

using namespace std;

// Creator: Marek K.

bool target = false;
void Start();
void Win();
int Query(int num);
void Wtl();

int main()
{
    Start();
    int tmp;
    cin >> tmp;
    return 0;
}

void Start()
{
    cout << "Willkommen beim Spiel Zahlenraten. Du denkst dir eine Zahl und ich muss versuchen sie zu erraten. Die must mir jede Runde sagen ob deine Zahl groszer(b), kleiner(s) oder ob ich sie erraten habe(t). Fangen wir an! ";
    cout << "Bis zu welcher Zahl soll ich raten? ";
    int max;
    cin >> max;
    Wtl();
    int x = max / 2;
    int xx = max;
    int xn = 0;
    while(target == false)
    {
        int ans = Query(x);
        if(ans == 1)  //  if big
        {
            xn = x;
            x = (xx + xn) / 2;
        }
        else if(ans == 0)  //  if small
        {
            xx = x;
            x = (xx + xn) / 2;
        }
    }
    Win();
}

void Win()
{
    cout << "Ich habe die Zahl erraten!" << endl;
}

int Query(int num)
{
    cout << "Ist die Zahl groszer oder kleiner als ";
    cout << num;
    cout << "? Deine Antwort: ";  //  Antworte mit b(big) fuer groszer, s(small) fuer kleiner oder t(target) für erraten.
    string ans;
    cin >> ans;
    if(ans == "b")
    {
        return 1;
    }
    else if(ans == "s")
    {
        return 0;
    }
    else if(ans == "t")
    {
        target = true;
    }
    else
    {
        return Query(num);
    }
    cout << endl << endl;
    return 2;
}

void Wtl()
{
    cout << endl << endl;
}
