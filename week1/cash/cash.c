#include <cs50.h>
#include <stdio.h>

int main(void){
    int arr[] = {25, 10, 5, 1};
    int contador = 0;
    int valor = 0;
    
    while(valor <= 0)
        valor = get_int("Digite um integer: ");
    
    for(int i = 0; i < 4; i++)
    {
        while ((valor - arr[i]) > -1){
            valor = valor - arr[i];
            contador = contador + 1;
        }
    }
    printf("Resposta: %i", contador);
}