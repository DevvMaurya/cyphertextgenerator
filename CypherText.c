#include <stdio.h>
#include <string.h>
char cyphertext[] = {'\0'};

void decryption(char *cypherText, int key)
{
    char ch;
    for (int i = 0; i < strlen(cypherText); i++)
    {
        ch = cypherText[i];
        ch = ch == ' ' ? ' ' : ch - key;
        cyphertext[i] = ch;
    }
    puts(cyphertext);
}

void encryption(char *input_text, int key)
{
    char ch;
    for (int i = 0; i < strlen(input_text); i++)
    {
        ch = input_text[i];
        ch = ch == ' ' ? ' ' : ch + key;
        cyphertext[i] = ch;
    }
    puts(cyphertext);
}

void main()
{
    char input_text[] = {'\0'};
    int key_val = 0;
    int option = 0;

    printf("Enter Your msg:\n");
    // fgets(input_text,sizeof(input_text),stdin);
    gets(input_text);

    printf("Enter Security key.:\n");
    scanf("%d", &key_val);

    printf("___________________\n");
    printf("1.> Encryption\n");
    printf("2.> Decryption\n");
    printf("-------------------\n");

    printf("Enter Your choice\n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        encryption(&input_text[0], key_val);
        break;

    case 2:
        decryption(&input_text[0], key_val);
        break;

    default:
        printf("NOT A PROPER CHOICE\n");
        break;
    }

}