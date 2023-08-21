#include <stdio.h>
#include <string.h>

void encryption(char k[], char pt[])
{

    int c[3][3];
    int index = 0; // Index to access the elements of the key array
    // int c;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (k[j] >= 'a' && k[j] <= 'z' || k[j] >= 'A' && k[j] <= 'Z')
            {
                c[i][j] = (k[index] - 'a' + 26) % 26;
                printf("%d ", c[i][j]);
                index++;
            }
        }
        printf("\n");
    }
}

int main()
{
    char key[9], pt[100];
    printf("enter 9 length of string:");
    gets(key);
    // printarr(key);
    printf("enter plaintext:");
    gets(pt);
    // printarr(pt);
    encryption(key, pt);

    return 0;
}
