#include<stdio.h>
#include<stdlib.h>



struct Pilha{
    int * itens;
    int capacidade;
    int topo;

};

struct Pilha* criarPilha(){ // a funcao retorna um ponteiro

struct Pilha * pilha = (struct Pilha*)malloc(sizeof(struct Pilha));//a pilha toda é um ponteiro,
pilha->capacidade = 1;
pilha->topo = -1; //setinha aponta para o ponteiro, difierentedo dot
pilha->itens = (int *)malloc(pilha->capacidade * sizeof(int));
return pilha;
};



int estaVazia(struct Pilha *pilha){
    return pilha->topo == -1; 
};


void empilhar(struct Pilha * pilha, int item){
  pilha->itens[++pilha->topo]=item;
   // printf("%d empilhado na pilha",item);
   }

    
int desempilhar(struct Pilha * pilha){
    if(estaVazia(pilha)){
     // printf("pilha esta vazia, nada a desempilhar \n");
      return -1;
    }
    return pilha->itens[pilha->topo--];}

    
int elementoTopo(struct Pilha *pilha){
    if(!estaVazia(pilha)){
        return pilha->itens[pilha->topo];
    }
    
}

void setarArray(int * array,int length,int valor){
    
    for(int i = 0; i < length; i++){
      *(array + i) = valor;
    }
}
