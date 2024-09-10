#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

//struct e nó do cliente
typedef struct cliente {
  char nome[MAX];
  int id;
} Cliente;

typedef struct Nolista {
  struct cliente inf;
  struct Nolista *prox;
} Nolista;

void criarVazia(Nolista **l) { *l = NULL; }

int estaVazia(Nolista **l) {
  if (*l == NULL) {
    return 1;
  } else {
    return 0;
  }
}

Cliente *criarCliente() {
  Cliente *c = (Cliente *)malloc(sizeof(Cliente));
  getchar();

  printf("Digite seu nome:\t");
  scanf("%49[^\n]", c->nome);

  return c;
}

Cliente* removeCliente(){
  Cliente *c = (Cliente*)malloc (sizeof(Cliente));
  printf("Digite o nome a ser removido: ");
  getchar();
  scanf("%49[^\n]", c->nome);

  return c;
}

void insereOrdenado(Nolista** l, Cliente* v) { Nolista* novo = (Nolista*)malloc(sizeof(Nolista)); Nolista* p, * ant = NULL;

if (novo != NULL) {
    novo->inf.id = v->id;
    strcpy(novo->inf.nome, v->nome);
       

    // Encontrar a posição correta na lista
    for (p = *l; p != NULL && strcmp(p->inf.nome, v->nome) < 0; p = p->prox){
      ant = p;
    }

    if (ant == NULL) {
        // Insere no início da lista
        novo->prox = *l;
        *l = novo;
    } else {
        // Insere no meio ou final da lista
        ant->prox = novo;
        novo->prox = p;
    }
}
}

void removerCliente(Nolista l, Cliente v) { Nolista p, * ant = NULL;

for (p = *l; p != NULL && strcmp(p->inf.nome, v->nome) != 0; p = p->prox){ ant = p; }

if (p==NULL){ printf("Nome não encontrado"); }

else{ if (ant !=NULL){ ant->prox=p->prox; } else{ *l = p; } free(p); }
}
