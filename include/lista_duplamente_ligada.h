#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h> 

typedef struct registro Aluno;
typedef struct lista Lista;
typedef struct elemento elemento;

Lista *criar_lista();

int adicionar_inicio();
int adicionar_final();

void remover_inicio();
void remover_final();

void buscar_inicio();
void buscar_final();

void imprimir_inicio_final();
void imprimir_final_inicio();