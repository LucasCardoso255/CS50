#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%i\n", *p);
    printf("=============================================\n");

    string s = "HI!";
    printf("%s\n", s);
    printf("=============================================\n");

    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
    printf("=============================================\n");

    char *str = "HI!";
    printf("%s\n", str);
    printf("=============================================\n");
}