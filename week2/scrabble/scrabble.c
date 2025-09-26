#include <cs50.h>
#include <stdio.h>

int length(string s) // method to get string length 
{
    int n = 0;
    while (s[n] != '\0')
        n++;
    return n;
}

string toUpper(string lower) // method to always get uppercase letters
{
    for (int i = 0; i < length(lower); i++)
    {
        if (lower[i] >= 'a' && lower[i] <= 'z')
            lower[i] = (lower[i] - 32);
    }
    return lower;
}

void scrabble(string p1_str, string p2_str) // comparison method
{
    char arr_char[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M',
        'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int arr_num[] = {
        1,3,3,2,1,4,2,4,1,8,5,1,3,
        1,1,3,10,1,1,1,1,4,4,8,4,10};
    int p1_count = 0;
    int p2_count = 0;

    for (int i = 0; i < length(p1_str); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (p1_str[i] == arr_char[j])
                p1_count = p1_count + arr_num[j];
        }
    }
    
    for (int k = 0; k < length(p2_str); k++)
    {
        for (int l = 0; l < 26; l++)
        {
            if (p2_str[k] == arr_char[l])
                p2_count = p2_count + arr_num[l];
        }
    }

    if (p1_count > p2_count)
        printf("Player 1 wins!\n");
    else if (p1_count == p2_count)
        printf("Tie\n");
    else
        printf("Player 2 wins!\n");
}

int main(void)
{
    string a1 = get_string("Player 1:");
    string a2 = get_string("Player 2:");
    a1 = toUpper(a1);
    a2 = toUpper(a2);
    scrabble(a1, a2);
}