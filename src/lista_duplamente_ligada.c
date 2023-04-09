#include "lista_duplamente_ligada.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct aluno
{
    int ra;
    char nome[50];
    int idade;
} Aluno;


struct no
{
    struct aluno aluno;
    struct No *ptr_prox;
    struct No *ptr_ant;
};

struct lista
{
    int tamanho;
    No *ptr_cabeca;
    No *ptr_cauda;
};


Lista *iniciar_lista(){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->tamanho = 0;
    l->ptr_cabeca = NULL;
    l->ptr_cauda = NULL;

    return l;
}

