#include <stdio.h>
#include <string.h>
#include <ctype.h>

char ct[] = {
    'a',    'b',    'c',    'd',    'e',    'f',    'g',
    'h',    'i',    'j',    'k',    'l',    'm',    'n',
    'o',    'p',    'q',    'r',    's',    't',    'u',
    'v',    'w',    'x',    'y',    'z', };

char pt[] = {
    'q',    'w',    'e',    'r',    't',    'y',    'u',
    'i',    'o',    'p',    'a',    's',    'd',    'f',
    'g',    'h',    'j',    'k',    'l',    'z',    'x',
    'c',    'v',    'b',    'n',    'm', };

char frequentChars[] = {'E', 'T', 'A', 'O', 'I', 'N', 'S', 'H', 'R', 'D', 'L',
     'C', 'U', 'M', 'W', 'F', 'G', 'Y', 'P', 'B', 'V', 'K', 'J', 'X', 'Q', 'Z'};

float frq[1000];
float counting[128] = {0};

void encryption(char *input)
{
    for (int i = 0; i < strlen(input); i++)
    {
        char lowercaseChar = tolower(input[i]);
        for (int j = 0; j < 26; j++)
        {
            if (lowercaseChar == ct[j])
            {
                input[i] = islower(input[i]) ? pt[j] : toupper(pt[j]);
                break;
            }
        }
    }
    puts(input);
}

void count(char *input)
{
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
            counting[(int)input[i]]++;
    }

    for (int i = 0; i < 128; i++)
    {
        if (counting[i] > 0)
        {
            printf("%c --> %.0f\n", i, counting[i]);
            frq[i] = (counting[i] * 100) / strlen(input);
            printf("frequency of %c --> %.4f\n", i, frq[i]);
        }
    }
}

void decryption(char *input)
{
    float max = frq[0];
    int index = 0;

        for (int j = 0; j < sizeof(counting)/sizeof(counting[0]); j++)
        {
            /* code */
            if(max < frq[j])
                max = frq[j];
                index = j;
        }


        
    printf("\n%.4f maximum %d\n",max,index);
    
}

int main()
{
    char s[20];
    gets(s);
    encryption(&s[0]);
    count(&s[0]);
    decryption(&s[0]);

    return 0;
}