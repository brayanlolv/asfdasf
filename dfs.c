#include <stdio.h>
#include "stack.h"
#include "structs.h"


void dfsPilha(int verticeinicial,struct Grafo * grafo,int * matrizAdj){
    verticeinicial  -= 1;          //se pah tapvez temja q tirar isso

    int verticesvisitados[grafo->vertice];
    setarArray(&verticesvisitados[0],grafo->vertice,0);
   //verificar se o vertice ja foi visitado

    //criar pilha q vai guardar os vertices visitados 
    struct Pilha * pilha = criarPilha();
    //empilhar o vertice inicial 
    empilhar(pilha,verticeinicial);//talvez tenh q por um -1 no vertice inicial  !!!!!!

    while(!estaVazia(pilha)){//enquanto estiver vazia
        int vertice = elementoTopo(pilha);
        desempilhar(pilha);
        verticesvisitados[vertice] = 1;
            printf("%d  ",vertice + 1);
            
            for(int i = 0; i < grafo->vertice;i++){  //for (auto e : adj) isso é um um map, o e é o elemento, o adj é uum vetor;  
                int  elemento = *(matrizAdj +(vertice * grafo->vertice)+i)  ;
                if(verticesvisitados[i]==0 && elemento != 0 ){
                    empilhar(pilha,i);   
                    i = grafo->vertice;
                }
            }


    }



}

// grafo q estou testando

int main(){
    struct Grafo grafo = {5,5};
    int matrizAdjacencia[5][5] ={   {0,1,1,0,1},
                                    {1,0,1,1,0},
                                    {1,1,0,1,1},
                                    {0,1,1,0,0},
                                    {1,0,1,0,0}};
    int numeroVerices;

    dfsPilha(3,&grafo,&matrizAdjacencia[0][0]);

    return 0;
}
