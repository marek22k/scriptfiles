// mbfinterpreter written by Marek K.

#include <stdio.h>
#include <string.h>

char bfin[262143], bfout[262143];
char cell[32767];
int inpos, cur;

int bfhandle(char *code, int i);

int main(int argc, char *argv[])
{
    char tmp;
    FILE *f = fopen(argv[1], "r");

    fseek(f, 0, SEEK_END);
    char bfcode[ftell(f)];
    fseek(f, 0, SEEK_SET);
    while((tmp = fgetc(f)) != EOF)
        strncat(bfcode, &tmp, 1);

    if(strchr(bfcode, ','))
    {
        printf("Input: ");
        scanf("%s", bfin);
    }

    for(size_t i = 0; i < strlen(bfcode); i++)
        i += bfhandle(bfcode, i);

    printf("%s", bfout);
    return 0;
}

int bfhandle(char *code, int i)
{
    switch(code[i])
        {
            case '+':
                {
                    cell[cur]++;
                    break;
                }
            case '-':
                {
                    cell[cur]--;
                    break;
                }
            case '<':
                {
                    cur--;
                    break;
                }
            case '>':
                {
                    cur++;
                    break;
                }
            case '.':
                {
                    strncat(bfout, &cell[cur], 1);
                    break;
                }
            case ',':
                {
                    cell[cur] = bfin[inpos++];
                    break;
                }
            case '[':
                {
                    int sp = i+1, pp = 0, o = 0;
                    while(code[sp+pp] != ']' || o != 0)
                    {
                        if(code[sp+pp] == ']' && o != 0) o--;
                        if(code[sp+pp++] == '[') o++;
                    }
                    char lcode[pp];
                    strncpy(lcode, code+sp, pp);
                    while(cell[cur]) for(unsigned int j = 0; j < pp; j++)
                        j+=bfhandle(lcode, j);
                    return pp+1;
                    break;
                }
        }
        return 0;
}
