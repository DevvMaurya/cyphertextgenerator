#include<stdio.h>
#include<string.h>
#include<ctype.h>
void encryption(char str[],int k)
{
     if (k == 0) {
        return;
    }

    // base case
    if (k == 1) {
        printf("%s", str);
        return;
    }

    
    for (int i = 0; i < strlen(str); i += (k - 1) * 2) {
        printf("%c", str[i]);
    }


    for (int j = 1; j < k - 1; j++) {
        int down = 1;
        for (int i = j; i < strlen(str);) {
            printf("%c", str[i]);
            if (down) {         
                i += (k - j - 1) * 2;
            } else {            
                i += (k - 1) * 2 - (k - j - 1) * 2;
            }

            down = !down;       
        }
    }

    
    for (int i = k - 1; i < strlen(str); i += (k - 1) * 2) {
        printf("%c", str[i]);
    }
}

int main()
{
     char pt[1000];
     gets(pt);
     int d;
     printf("enter the deapth:");
     scanf("%d",&d);
     encryption(pt,d);
}