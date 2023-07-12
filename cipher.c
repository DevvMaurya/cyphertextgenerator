
#include<stdio.h>
#include<string.h>

void encryption(char str[], int x) 
{
    char s;
    for(int i=0; i<strlen(str); i++)
    {
        s=str[i];
        if((s>='a' && s<='z') || (s>='A' && s<='Z'))
        {
            s=s+x;
            if(s>'z' || s<'A') 
            {
                s=(s-x)%26 + 'A'; 
            }
            str[i]=s;
        }
    }
    printf("%s",str);
}

void decryption(char str[], int x) 
{
    char s;
    for(int i=0; i<strlen(str); i++)
    {
        s=str[i];
        if((s>='a' && s<='z') || (s>='A' && s<='Z'))
        {
            s=s-x;
            if(s<='A')
            {
                s=(s-x)%26 +'J'; 
            }
            else if(s<'a')
            {
                s=(s-x)%26 +'j';
            }
            str[i]=s;
        }
    }
    printf("%s",str);
}

int main()
{
    char s[100];
    int n,x;
    printf("enter string:\n");
    fgets(s,100,stdin);
    printf("enter key:\n");
    scanf("%d",&x);
    printf("what will you do?"); 
    printf("1)encryption 2)decryption:\n");
    scanf("%d",&n);
    if(n==1 || n==2)
    {
        switch (n)
        {
            case 1:
            {
                encryption(s,x);
                break;
            }
            case 2:
            {
                decryption(s,x);
                break;
            }
            default:
            {
                printf("invalid");
                break; 
            }
        }
    }
    else
    {
        printf("invalid");
    }

    return 0;
}