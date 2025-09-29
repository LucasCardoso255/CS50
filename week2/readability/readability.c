#include <cs50.h>
#include <math.h>
#include <stdio.h>

int length(string s) // get string length method
{
    int n = 0;
    while (s[n] != '\0')
        n++;
    return n;
}

int getLetras(string texto) // method to calculate total of letters
{
    int letras = 0;

    // here i consider every letter from "a" to "z" to be added to the "letras" variable
    for (int i = 0; i < length(texto); i++)
    {
        if ((texto[i] >= 'A' && texto[i] <= 'Z') || (texto[i] >= 'a' && texto[i] <= 'z'))
            letras++;
    }
    return letras;
}

int getFrases(string texto) // method to calculate total of sentences
{
    int frases = 0;
    // here i consider some punctuations to sinalize the end of a sentence
    for (int i = 0; i < length(texto); i++)
    {
        if (texto[i] == '.' || texto[i] == '!' || texto[i] == '?')
            frases++;
    }
    return frases;
}

int getPalavras(string texto) // method to calculate total of words
{
    int palavras = 0;

    for (int i = 0; i < length(texto); i++)
    {
        if (texto[i] != ' ' && (i == 0 || texto[i - 1] == ' '))
            palavras++;
    }
    return palavras;
}   

int main(void)
{
    string texto = get_string("Text: ");

    int palavras = getPalavras(texto); 
    int letras = getLetras(texto); 
    int frases = getFrases(texto); 

    float l = ((float) letras / palavras) * 100;
    float s = ((float) frases / palavras) * 100;

    float index = 0.0588 * l - 0.296 * s - 15.8; // Coleman-Liau index formula
    int grade = round(index);

    if (grade >= 16)
        printf("Grade 16+\n");

    else if (grade < 1)
        printf("Before Grade 1\n");

    else
        printf("Grade %i\n", grade);
}
