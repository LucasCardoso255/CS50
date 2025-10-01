#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>

// while key < 26 
//  key = key - 26;        <----------- engenharia pura!

int only_digits(string s)
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
}

string rotate(int key, string c)
{
    int i = 0;
    while (c[i] != '\0')
    {    
        if (c[i] >= 'a' && c[i] <= 'z')
        {
            int key_b = key;
            while (key_b > 122)
                key_b = key_b - 26;

            c[i] = c[i] + key_b;
            i++;
        }
        
        else if (c[i] >= 'A' && c[i] <= 'Z')
        {
            int key_b = key;
            while (key_b > 90)
                key_b = key_b - 26;

            c[i] = c[i] + key_b;
            i++;
        }
    }
    return c;
}

int main(int argc, string argv[])
{
    if (argc != 1)
    {
        if (only_digits(argv[1]) == 1)
        {
            int key = atoi(argv[1]);
            string plaintext = get_string("plaintext:  ");
            string cipher = rotate(key, plaintext);
            printf("chiphertext: %s\n",cipher);
            return 0;
        }

        else
            printf("Usage: ./caesar key\n");
            return 1;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1; 
    }

    
}