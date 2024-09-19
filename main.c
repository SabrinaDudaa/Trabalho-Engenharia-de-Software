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
//struct e nó dos produtos
typedef struct produto{
  char nome[MAX];
  char desc [MAX];
  int id;
  int quant;
}Produto;


typedef struct produto{
  char nome[MAX];
  char desc [MAX];
  int id;
  int quant;
}Produto;

typedef struct molista{
  struct produto info;  
  struct molista *prox;
}Molista;

typedef struct lista{
  Molista *cab;
  Molista *cau;
}Lista;

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

void removerCliente(Nolista **l, Cliente* v) {
   Nolista* p, * ant = NULL;

  for (p = *l; p != NULL && strcmp(p->inf.nome, v->nome) != 0; p = p->prox){
     ant = p;
  }

  if (p==NULL){
    printf("Nome não encontrado");
  }

  else{
    if (ant !=NULL){
      ant->prox=p->prox;
    }
    else{
      *l = p->prox;
    }
    free(p);
  }  
}

void imprimeCliente(Nolista **l) { 
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
            //produtos
Produto* novoProduto() {
  Produto* prod = (Produto*)malloc(sizeof(Produto));


  printf("Digite o nome do produto:\t");
  getchar();
  scanf("%49[^\n]",prod->nome);
  printf("Digite a descricao do produto:\t");
  getchar();
  scanf("%49[^\n]",prod->desc);
  printf("Digite a quantidade no estoque:\t");
  scanf("%d",&prod->quant);

  return prod;
}

Produto* editaDesc(){
  Produto* prod = (Produto*)malloc(sizeof(Produto));

  printf("Digite o ID do Produto:\t");
  scanf("%d",&prod->id);
  getchar();
  printf("Digite a nova descricao do produto:\t");
  scanf("%49[^\n]",prod->desc);

  return prod;
}

//Função que vai ser usada no vendaProduto
Produto* vendProduto(){
  Produto* prod = (Produto*)malloc(sizeof(Produto));
  int y;
  
  printf("Digite o ID do Produto:\t");
  scanf("%d",&prod->id);
  printf("Digite a quantidade vendida:\t");
  scanf("%d",&y);

  if(y < 0){
    printf("quantidade invalida.\n");
    free(prod);
    vendProduto();
  }
  else{
    prod->quant = y;
    return prod;
  }
}

Produto* leProduto(int id,char nome[MAX],char desc[MAX],int qtde) {
  Produto* prod = (Produto*)malloc(sizeof(Produto));

  strcpy(prod->nome, nome);
  strcpy(prod->desc, desc);
  prod->quant=qtde;
  prod->id=id;

  return prod;
}

Lista criaVazia(){

Lista l;
l.cab = (Molista *)malloc(sizeof(Molista));
l.cau = (Molista *)malloc(sizeof(Molista));

l.cab->prox = l.cau;
l.cau->prox = NULL;

return l;
}

int estarVazia(Lista* l){
  return (l->cab->prox == l->cau);
}



void insereOrdenadoProd(Lista*l, Produto* v){ //vai receber a função novoProduto
  Molista *ult=l->cab;
  Molista*novo=(Molista*)malloc(sizeof(Molista));


  if(novo!=NULL){
    novo->info = *v;
    novo->prox = l->cau;

    for (; ult->prox != l->cau; ult = ult->prox);
    ult->prox = novo;
  }

  else{
    printf("Nao foi possivel alocar");
  }
}


void imprimeProduto(Lista*l) {
  Molista*p;

  if(!estarVazia(l)){
    for(p=l->cab->prox; p!=l->cau; p=p->prox){
       Produto prod = p->info;
      printf("%d:\t %s\t -- \t%s. qtde:%d\n",prod.id, prod.nome, prod.desc, prod.quant);
    }
  }

  else{
    printf("\nNenhum produto cadastrado");
  }

}

void editaDescProduto(Lista*l,Produto*v) {
  Molista*p;

  for(p=l->cab->prox;p!=l->cau && p->info.id != v->id;p=p->prox);

  if(p==l->cau){
    printf("Produto nao encontrado.");
  }
  else{
   strcpy(p->info.desc,v->desc);
  }
}
