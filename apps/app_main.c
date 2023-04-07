#include "../include/lista_duplamente_ligada.h"
#include <stdio.h>
#include <stdlib.h> 

int main() {

    int valor;
    Lista *lista = criar_lista();

    do
    {
        printf("-----Menu-----\n");   //Aqui é o inicio do Menu
        printf("1 - Inserir inicio\n");      
        printf("2 - Inserir final\n");
        printf("3 - Remover inicio\n");
        printf("4 - Remover final\n");
        printf("5 - Buscar inicio\n");
        printf("6 - Buscar final\n");
        printf("7 - Imprimir inicio->final\n");
        printf("8 - Imprimir final->inicio\n");
        printf("9 - Ordenar (Quick Sort)\n");
        printf("0 - Sair\n");
        printf("---------------\n");

        scanf("%d", &valor);


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

        case 4:
            /* Código */
            break;

        case 5:
            /* Código */
            break;

        case 6:
            /* Código */
            break;

        case 7:
            valor = imprimir_inicio_final(lista);
            break;
        case 8:
            /* Código */
            break;

        case 9:
            /* Código */
            break;

        default:
            break;
        }
    } while (valor != 0);

}