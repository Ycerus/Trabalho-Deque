#include "../include/lista_duplamente_ligada.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definindo uma struct para, futuramente, alocar dinamicamente novos registros
struct registro
{
    char cpf[12];
    char nome[50];
    char curso[50];
    int idade;
};

struct elemento
{
    elemento *ptr_proximo;
    Aluno dados;
    elemento *ptr_anterior;
};

// Definindo uma struct que será a cabeça-cauda do nosso DEQUE
struct lista
{
    int tamanho;
    elemento *ptr_cabeca;
    elemento *ptr_cauda;
};

// Função para inicializar a cabeça-cauda
Lista *criar_lista()
{

    Lista *prt_lista = (Lista *)malloc(sizeof(Lista));
    prt_lista->tamanho = 0;
    prt_lista->ptr_cabeca = NULL;
    prt_lista->ptr_cauda = NULL;

    return prt_lista;
}

void adicionar_inicio(Lista *ptr_lista, Aluno dados)
{
    elemento *ptr_novo_elemento = (elemento *)malloc(sizeof(elemento));

    ptr_novo_elemento->dados = dados;
    ptr_novo_elemento->ptr_anterior = NULL;
    ptr_novo_elemento->ptr_proximo = NULL;

    ptr_novo_elemento->dados = dados;

    if (ptr_lista->ptr_cabeca == NULL)
    {
        ptr_lista->ptr_cabeca = ptr_novo_elemento;
        ptr_lista->ptr_cauda = ptr_novo_elemento;
    }
    else
    {

        ptr_novo_elemento->ptr_proximo = ptr_lista->ptr_cabeca;

        ptr_lista->ptr_cabeca->ptr_anterior = ptr_novo_elemento;

        ptr_lista->ptr_cabeca = ptr_novo_elemento;
    }

    ptr_lista->tamanho++;
}

int adicionar_final(Lista *ptr_lista, Aluno novos_dados)
{

    if (ptr_lista == NULL)
        return 0; // Verificação se existe uma struct lista na memória
    elemento *no = (elemento *)malloc(sizeof(elemento));
    if (no == NULL)
        return 0; // Verificação se foi possível alocar memória para um novo nó (aluno)

    no->dados = novos_dados;
    no->ptr_proximo = NULL; // Pelo fato de estarmos acrescentando ao final da lista, é necessário setar NULL no próximo.

    if (ptr_lista->ptr_cauda == NULL)
    { // Caso seja um deque vazio
        no->ptr_anterior = NULL;
        ptr_lista->ptr_cabeca = no;
    }
    else
    {
        no->ptr_anterior = ptr_lista->ptr_cauda;
        ptr_lista->ptr_cauda->ptr_proximo = no;
    }
    ptr_lista->ptr_cauda = no;
    ptr_lista->tamanho++;

    return 1;
}

void remover_final(Lista *ptr_lista)
{
    if (ptr_lista->tamanho != 0)
    {
        elemento *no_auxiliar = ptr_lista->ptr_cauda;
        ptr_lista->ptr_cauda = ptr_lista->ptr_cauda->ptr_anterior;
        free(no_auxiliar);
        ptr_lista->tamanho--;
    }
    else
    {
        printf("lista vazia\n");
    }
}

void remover_inicio(Lista *ptr_lista)
{
    if (ptr_lista->tamanho != 0)
    {
        elemento *no_auxiliar = ptr_lista->ptr_cabeca;
        ptr_lista->ptr_cabeca = ptr_lista->ptr_cabeca->ptr_proximo;
        free(no_auxiliar);
        ptr_lista->tamanho--;
    }
    else
    {
        printf("lista vazia\n");
    }
}

void imprimir_inicio_final(Lista *ptr_lista)
{

    elemento *no_final = ptr_lista->ptr_cauda;
    elemento *no_atual;

    if (ptr_lista->tamanho != 0)
    {

        printf("Lista \n");
        printf("--------------------------\n");

        for (no_atual = ptr_lista->ptr_cabeca;
             no_atual != no_final;
             no_atual = no_atual->ptr_proximo)
        {
            printf("Nome -> %s \n", no_atual->dados.nome);
            printf("Cpf -> %s \n", no_atual->dados.cpf);
            printf("Curso -> %s \n", no_atual->dados.curso);
            printf("Idade -> %d \n", no_atual->dados.idade);
            printf("--------------------------\n");
        }
        printf("Nome -> %s \n", no_atual->dados.nome);
        printf("Cpf -> %s \n", no_atual->dados.cpf);
        printf("Curso -> %s \n", no_atual->dados.curso);
        printf("Idade -> %d \n", no_atual->dados.idade);
        printf("--------------------------\n");
    }
    else
    {
        printf("lista vazia\n");
    }
}

void imprimir_final_inicio(Lista *ptr_lista)
{
    elemento *no_atual;

    if (ptr_lista->tamanho != 0)
    {

        printf("Lista\n");
        printf("--------------------------\n");

        for (no_atual = ptr_lista->ptr_cauda;
             no_atual != ptr_lista->ptr_cabeca;
             no_atual = no_atual->ptr_anterior)
        {
            printf("Nome -> %s \n", no_atual->dados.nome);
            printf("Cpf -> %s \n", no_atual->dados.cpf);
            printf("Curso -> %s \n", no_atual->dados.curso);
            printf("Idade -> %d \n", no_atual->dados.idade);
            printf("--------------------------\n");
        }
        printf("Nome -> %s \n", no_atual->dados.nome);
        printf("Cpf -> %s \n", no_atual->dados.cpf);
        printf("Curso -> %s \n", no_atual->dados.curso);
        printf("Idade -> %d \n", no_atual->dados.idade);
        printf("--------------------------\n");
    }
    else
    {
        printf("lista vazia\n");
    }
}

void retornar_tamanho(Lista *ptr_lista)
{
    int tamanho = ptr_lista->tamanho;
    printf("Tamanho -> %i\n", tamanho);
};

void buscar_inicio(Lista *ptr_lista)
{
    elemento *primeiro_no = ptr_lista->ptr_cabeca;

    printf("O primeiro aluno eh : \n");
    printf("Nome -> %s \n", primeiro_no->dados.nome);
    printf("Cpf -> %s \n", primeiro_no->dados.cpf);
    printf("Curso -> %s \n", primeiro_no->dados.curso);
    printf("Idade -> %d \n", primeiro_no->dados.idade);
    printf("--------------------------\n");
};

void buscar_final(Lista *ptr_lista)
{
    elemento *ultimo_no = ptr_lista->ptr_cauda;

    printf("O ultimo aluno eh : \n");
    printf("Nome -> %s \n", ultimo_no->dados.nome);
    printf("Cpf -> %s \n", ultimo_no->dados.cpf);
    printf("Curso -> %s \n", ultimo_no->dados.curso);
    printf("Idade -> %d \n", ultimo_no->dados.idade);
    printf("--------------------------\n");

};