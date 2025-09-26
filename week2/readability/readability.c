#include <cs50.h>
#include <stdio.h>
#include <math.h>

int length(string s)
{
    int n = 0;
    while (s[n] != '\0')
        n++;
    return n;
}

int getLetras(string texto)
{
    int letras = 0;

    for (int i = 0; i < length(texto); i++)
    {
        if ((texto[i] >= 'A' && texto[i] <= 'Z') || (texto[i] >= 'a' && texto[i] <= 'z'))
            letras++;
    }
    return letras;
}

int getFrases(string texto)
{
    int frases = 0;
    for (int i = 0; i < length(texto); i++)
    {
    if (texto[i] == '.' || texto[i] == '!' || texto[i] == '?')
            frases++;
    }
    return frases;
}

int getPalavras(string texto)
{
    int palavras = 0;

    for (int i = 0; i < length(texto); i++)
    {
        if (texto[i] != ' ' && (i == 0 || texto[i-1] == ' '))
            palavras++;
    }
    return palavras;
}   

int main(void)
{
    string texto = "ASD DSA  ASFASD FF.  essa foi uma frase.";

    int palavras = getPalavras(texto); 
    int letras = getLetras(texto); 
    int frases = getFrases(texto); 

    float l = ((float) letras / palavras) * 100;
    float s = ((float) frases / palavras) * 100;

    float index = 0.0588 * l - 0.296 * s - 15.8;
    int res = round(index);

    printf("palavras: %i\nletras: %i\nfrases:%i\nl: %i", palavras, letras, frases, res);
}
