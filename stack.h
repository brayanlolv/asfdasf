#include<stdio.h>
#include<stdlib.h>


struct Pilha{
    int * itens;
    int capacidade;
    int topo;

};


int estaVazia(struct Pilha *pilha){
    return pilha->topo == -1; 
};


void empilhar(struct Pilha * pilha, int item){
  pilha->itens[++pilha->topo]=item;
    prinf("%d empilhado na pilha",item);}

    
int desempilhar(struct Pilha * pilha){
    if(estaVazia(pilha)){
      printf("pilha esta vazia, nada a desempilhar \n");
      return -1;
    }
    return pilha->itens[pilha->topo--];}

    
int elementoTopo(struct Pilha * pilha ){
    
}