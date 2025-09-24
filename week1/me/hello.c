#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Whats your name? "); // adding comments just to pass style50
    printf("hello, %s\n", name);
}