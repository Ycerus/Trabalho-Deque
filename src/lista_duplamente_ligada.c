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
Lista *criar_lista() {

   Lista *prt_lista = (Lista*) malloc(sizeof(Lista));
   prt_lista->tamanho = 0;
   prt_lista->ptr_cabeca = NULL;
   prt_lista->ptr_cauda = NULL;

   return prt_lista;

}

int adicionar_final(Lista *ptr_lista, Aluno novos_dados){
    
    if(ptr_lista == NULL) return 0; // Verificação se existe uma struct lista na memória
    elemento *no = (elemento*) malloc(sizeof(elemento));
    if(no ==  NULL) return 0; // Verificação se foi possível alocar memória para um novo nó (aluno)

    no->dados = novos_dados;
    no->ptr_proximo = NULL; // Pelo fato de estarmos acrescentando ao final da lista, é necessário setar NULL no próximo.

    if(ptr_lista->ptr_cauda == NULL){ // Caso seja um deque vazio
        no->ptr_anterior = NULL;
        ptr_lista->ptr_cabeca = no;
    } else {
        no->ptr_anterior = ptr_lista->ptr_cauda;
        ptr_lista->ptr_cauda->ptr_proximo = no;
    }
    ptr_lista->ptr_cauda = no;
    ptr_lista->tamanho++;

    return 1;
}

/*void remover_final(Lista *ptr_lista){

    elemento *no_auxiliar = ptr_lista;


}*/

void imprimir_inicio_final(Lista *ptr_lista){

    elemento *no_final = ptr_lista->ptr_cauda;
    elemento *no_atual;

    if(ptr_lista != NULL){

        printf("Lista: {");

        for (no_atual = ptr_lista->ptr_cabeca;
            no_atual != no_final;
            no_atual = no_atual->ptr_proximo)
        {
            printf("%d -> ", no_atual->dados.cpf);    
        }
            printf("%d -> \n", no_atual->dados.cpf);
            
    } else {
        printf("NULL\n");
    }

}