#include "lista_duplamente_ligada.h"
#include <stdio.h>
#include <stdlib.h> 

int main() {

    int valor;

    valor = 1;

    do
    {
        printf("-----Menu-----\n");   //Aqui é o inicio do Menu, basta alterar a descrição das operações
        printf("1 - Inserir\n");      
        printf("2 - Remover\n");
        printf("3 - Buscar\n");
        printf("0 - Sair\n");
        printf("---------------\n");

        scanf("%d", &valor);

    } while (valor != 0);
    


    // A partir daqui é o resultado da seleção do Menu.
    switch (valor)
    {
    case 1:
        /* Código */
        break;

    case 2:
        /* Código */
        break;

    case 3:
        /* Código */
        break;
    
    default:
        break;
    }

}