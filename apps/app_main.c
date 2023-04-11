#include "../include/lista_duplamente_ligada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    struct registro
    {
        char cpf[12];
        char nome[50];
        char curso[50];
        int idade;
    } aluno_main;

    int valor;
    Lista *lista = criar_lista();

    do
    { // Menu de seleção de ações.
        printf("-----Menu-----\n");
        printf("1 - Inserir aluno no inicio\n"); // Inserir inicio.
        printf("2 - Inserir aluno no final\n");  // Inserir final.
        printf("3 - Remover aluno do inicio\n"); // Remover inicio.
        printf("4 - Remover aluno do final\n");  // Remover final.
        printf("5 - Buscar primeiro aluno\n");   // Buscar inicio.
        printf("6 - Buscar ultimo aluno\n");     // Buscar final.
        printf("7 - Imprimir inicio->final\n");  // Imprimir do inicio até o final.
        printf("8 - Imprimir final->inicio\n");  // Imprimir do final até o inicio.
        printf("9 - Retornar Tamanho\n");
        printf("0 - Sair\n");
        printf("---------------\n");

        scanf("%d", &valor);

        // A partir daqui é o resultado da seleção do Menu.
        switch (valor)
        {
        case 1:
            printf("Insira os dados do aluno a seguir: \n");
            printf("Nome: ");
                fflush(stdin);
                gets(aluno_main.nome);
            printf("CPF: ");
                fflush(stdin);
                gets(aluno_main.cpf);
            printf("Nome do Curso: ");
                fflush(stdin);
                gets(aluno_main.curso);
            printf("Idade: ");
                fflush(stdin);
                scanf("%d", &aluno_main.idade);
            adicionar_inicio(lista, aluno_main);
            break;

        case 2:
            printf("Insira os dados do aluno a seguir: \n");
            printf("Nome: ");
                fflush(stdin);
                gets(aluno_main.nome);
            printf("CPF: ");
                fflush(stdin);
                gets(aluno_main.cpf);
            printf("Nome do Curso: ");
                fflush(stdin);
                gets(aluno_main.curso);
            printf("Idade: ");
                fflush(stdin);
                scanf("%d", &aluno_main.idade);
            adicionar_final(lista, aluno_main);
            break;

        case 3:
            remover_inicio(lista);
            break;

        case 4:
            remover_final(lista);
            break;

        case 5:
            buscar_inicio(lista);
            break;

        case 6:
            buscar_final(lista);
            break;

        case 7:
            imprimir_inicio_final(lista);
            break;
        case 8:
            imprimir_final_inicio(lista);
            break;

        case 9:
            retornar_tamanho(lista);
            break;

        default:
            break;
        }
    } while (valor != 0);
}