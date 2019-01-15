#include <stdio.h>
#include <string.h>

#define ERRLOG(msg) fprintf(stderr, (msg))
//#define DEBUG

void encrypt(const char text[], const unsigned int key, const unsigned int len);
void decrypt(const char text[], const unsigned int key, const unsigned int len);

int main()
{
    #ifdef DEBUG
        printf("DEBUG MODE\n");
    #endif  // DEBUG
    printf("option( 1: encrypt / 2: decrypt / 3: version ): ");
    char text[255];
    int option = 3, key;
    scanf("%i", &option);
    switch(option)
    {
        case 1:
            {
                printf("Text and Key(text key): ");
                scanf("%s %i", &text, &key);
                encrypt(text, key, strlen(text));
                break;
            }
        case 2:
            {
                printf("Text and Key(text key): ");
                scanf("%s %i", &text, &key);
                decrypt(text, key, strlen(text));
                break;
            }
        case 3:
            {
                printf("\nccaesarcrypt\n============\n\nThe program ccaesarcrypt was written on 18.03.2018 by Marek K. in the C programming language.\n");
                break;
            }
        default:
            {
                ERRLOG("Errorcode: 0x0001");
                break;
            }
    }

    return 0;
}

void encrypt(const char text[], const unsigned int key, const unsigned int len)
{
    char e[26], d[26];
    for(unsigned char i = 0; i < 26; i++)
        e[i] = 'a' + i;

    for(unsigned char i = 0; i < 26-key; i++)
        d[i] = 'a' + i + key;

    for(unsigned char i = 26-key; i < 26; i++)
        d[i] = 'a' + i - 26 + key;

    #ifdef DEBUG
        for(unsigned char i = 0; i < 26; i++)
            printf("%c", e[i]);

        printf("\n");

        for(unsigned char i = 0; i < 26; i++)
            printf("%c", d[i]);

        printf("\n");
    #endif  // DEBUG

    for(unsigned int i = 0; i < len; i++)
        printf("%c", d[(strchr(e, text[i])-e)]);

    printf("\n");
}

void decrypt(const char text[], const unsigned int key, const unsigned int len)
{
    char e[26], d[26];
    for(unsigned char i = 0; i < 26; i++)
        e[i] = 'a' + i;

    for(unsigned char i = 0; i < 26-key; i++)
        d[i] = 'a' + i + key;

    for(unsigned char i = 26-key; i < 26; i++)
        d[i] = 'a' + i - 26 + key;

    #ifdef DEBUG
        for(unsigned char i = 0; i < 26; i++)
            printf("%c", e[i]);

        printf("\n");

        for(unsigned char i = 0; i < 26; i++)
            printf("%c", d[i]);

        printf("\n");
    #endif  // DEBUG

    for(unsigned int i = 0; i < len; i++)
        printf("%c", e[(strchr(d, text[i])-d)]);

    printf("\n");
}
