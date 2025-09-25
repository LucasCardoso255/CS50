#include <cs50.h>
#include <stdio.h>
#include <string.h>

int length(string s)
{
    int n = 0;
    while (s[n] != '\0')
        n++;
    return n;
}

string toUpper(string lower)
{
    for (int i = 0; i < length(lower); i++)
    {
        if (lower[i] >= 'a' && lower[i] <= 'z')
            lower[i] = (lower[i] - 32);
    }
    return lower;
}

int main(void)
{
    char teste[] = "como tira letra grande??";
    string result = toUpper(teste);
    printf("result: %s\n", result);
}