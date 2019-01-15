#include <iostream>
#include <cstdlib>
#include <csignal>
#include <cstdio>

using namespace std;

bool sig = 1;

void signalHandler(int param)
{
    clog << "Signal received!" << endl;
    sig = 0;
}

bool work()
{
    return printf("Hello World!\n");
}

int main()
{
    signal(SIGINT, signalHandler);

    if( work() != 1)
        raise(SIGINT);

    if(sig == 0)
        return( EXIT_FAILURE );
    else
        return( EXIT_SUCCESS );
}
