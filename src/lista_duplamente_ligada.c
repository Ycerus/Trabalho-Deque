#include "lista_duplamente_ligada.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//A partir daqui, basta começar os códigos, Structs e funções.
struct no
{
    int valor;
    No *ptr_proximo;
    No *ptr_anterior;
};

struct cabeca
{
    int tamanho;
    No *ptr_cabeca;
    No *ptr_cauda;
};

cabeca *criar_lista() {

   cabeca *prt_lista = (cabeca*) malloc(sizeof(cabeca));
   prt_lista->tamanho = 0;
   prt_lista->ptr_cabeca = NULL;
   prt_lista->ptr_cauda = NULL;
 
   return  prt_lista;

}

void adicionar_final(cabeca **ptr_auxiliar, int valor){
    
}
void remover_final(cabeca **ptr_auxiliar){

}
void ordenar(){

}