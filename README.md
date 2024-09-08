# Trabalho-Engenharia-de-Software
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

void criarVazia(Nolista **l) { //cria a lista de clientes vazia
*l = NULL; 
}

int estaVazia(Nolista **l) {//checa se a mesma está vazia
  if (*l == NULL) {
    return 1;
  } else {
    return 0;
  }
}

Cliente *criarCliente() {// pede as informaçoes do cliente e retorna um ponteiro para o nó alocado
  Cliente *c = (Cliente *)malloc(sizeof(Cliente));
  getchar();

  printf("Digite seu nome:\t");
  scanf("%49[^\n]", c->nome);

  return c;
}

Cliente* removeCliente(){//funçao para remover o cliente por nome e retorna um ponteiro para o no a ser removido
  Cliente *c = (Cliente*)malloc (sizeof(Cliente));
  printf("Digite o nome a ser removido: ");
  getchar();
  scanf("%49[^\n]", c->nome);

  return c;
}


void imprimeCliente(Nolista **l) { //imprime a lista de clientes
  Nolista *p;
  if (!estaVazia(l)) {
    for (p = *l; p != NULL; p = p->prox) {
      Cliente i = p->inf;

      printf("%d: %s\n",i.id, i.nome);
    }
  }

  else {
    printf("Lista Vazia!");
  }
}
