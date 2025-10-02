#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>

// while key < 26 
//  key = key - 26;        <----------- engenharia pura!

int only_digits(string s) // method to check if a string contains only digits
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            i++;
        }
        else
            return 0;
    } 
    if (i != 0)
        return 1;

    return 0;
}

string rotate(int key, string c) // method to encrypt each char from a string based on a given key
{
    int i = 0;
    while (c[i] != '\0')
    {    
        if (c[i] >= 'a' && c[i] <= 'z')
        {
            c[i] = ((c[i] - 'a' + key) % 26) + 'a';
        }
        else if (c[i] >= 'A' && c[i] <= 'Z')
        {
            c[i] = ((c[i] - 'A' + key) % 26) + 'A';
        }
        i++;

    }

    return c;
}

int main(int argc, string argv[])
{
    if (argc != 2) // only 1 argument
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]); // was too lazy to make my own atoi      xD
    string plaintext = get_string("plaintext:  ");
    string cipher = rotate(key, plaintext);
    printf("ciphertext: %s\n", cipher);
    return 0;
}
