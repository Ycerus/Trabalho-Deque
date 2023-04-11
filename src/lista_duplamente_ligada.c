#include "../include/lista_duplamente_ligada.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definindo uma struct para, futuramente, alocar dinamicamente novos registros
struct registro
{
    int cpf;
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

    elemento *no_auxiliar = ptr_lista->ptr_cauda;
    ptr_lista->ptr_cauda = ptr_lista->ptr_cauda->ptr_anterior;
    free(no_auxiliar);
}

void remover_inicio(Lista *ptr_lista)
{

    elemento *no_auxiliar = ptr_lista->ptr_cabeca;
    ptr_lista->ptr_cabeca = ptr_lista->ptr_cabeca->ptr_proximo;
    free(no_auxiliar);
}

void imprimir_inicio_final(Lista *ptr_lista)
{

    elemento *no_final = ptr_lista->ptr_cauda;
    elemento *no_atual;

    if (ptr_lista != NULL)
    {

        printf("Lista: {");

        for (no_atual = ptr_lista->ptr_cabeca;
             no_atual != no_final;
             no_atual = no_atual->ptr_proximo)
        {
            printf("Nome -> %s \n", no_atual->dados.nome);
            printf("Cpf -> %d \n", no_atual->dados.cpf);
            printf("Curso -> %s \n", no_atual->dados.curso);
            printf("Idade -> %d \n", no_atual->dados.idade);
        }
        printf("Nome -> %s \n", no_atual->dados.nome);
        printf("Cpf -> %d \n", no_atual->dados.cpf);
        printf("Curso -> %s \n", no_atual->dados.curso);
        printf("Idade -> %d \n", no_atual->dados.idade);
    }
    else
    {
        printf("NULL\n");
    }
}

void imprimir_final_inicio(Lista *ptr_lista)
{

    elemento *no_inicio = ptr_lista->ptr_cabeca;
    elemento *no_atual;

    if (ptr_lista != NULL)
    {

        printf("Lista\n");

        for (no_atual = ptr_lista->ptr_cabeca;
             no_atual != no_inicio;
             no_atual = no_atual->ptr_anterior)
        {
            printf("Nome -> %s \n", no_atual->dados.nome);
            printf("Cpf -> %d \n", no_atual->dados.cpf);
            printf("Curso -> %s \n", no_atual->dados.curso);
            printf("Idade -> %d \n", no_atual->dados.idade);
        }
        printf("Nome -> %s \n", no_atual->dados.nome);
        printf("Cpf -> %d \n", no_atual->dados.cpf);
        printf("Curso -> %s \n", no_atual->dados.curso);
        printf("Idade -> %d \n", no_atual->dados.idade);
    }
    else
    {
        printf("Lista Vazia!\n");
    }
}