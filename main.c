#include "func.h"
#include "stack.h"   //arquivo q tera as funcoes relacionadas a pilha
#include "structs.h" //arquivo com as structs grafo, vertice
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

char comandolimpar[6] = "cls"; // para windows, se for linux mudar isso

// se mudar o escolher processo de document apaga
void modificarMatriz(
    int *matriz, int V0, int V1, int valor,
    struct Grafo *grafo); // se mudar o escolher processo de document apaga
void dfsPilha(int verticeinicial, int vertices, int *matrizAdj,
              struct Grafo grafo);
void escolherProcesso(int *matriz, int length, struct Grafo grafo);
void printMatriz(int *matriz, int length, struct Grafo grafo);
void initMatriz(int *matriz, int length);
int main() {
  int digrafo;
  struct Grafo grafo = {0, 0, 0};
  printf("se o grafo for um digrafo (direcionado) digite 1 ?\n");
  scanf("%d", &digrafo);
  if (digrafo == 1) {
    grafo.digrafo = 1;
  }
  printf("quantos vertices tera grafo ?\n");
  scanf("%d", &grafo.vertice);
  printf("seu grafo tem %d vertices e %d arestas", grafo.vertice,
         grafo.arestasGrafo);

  // iniciar matriz, no caso atribuir 0 e printar ela
  int matrizAdjacencia[grafo.vertice][grafo.vertice];
  initMatriz(&matrizAdjacencia[0][0], grafo.vertice);
  printMatriz(&matrizAdjacencia[0][0], grafo.vertice, grafo);
  ////
  escolherProcesso(&matrizAdjacencia[0][0], grafo.vertice, grafo);

  return 7;
};

// printf("1.adicionar vertice.\n2.remover vertice.\n qualquer coisa para
// voltar");
void modificarMatriz(int *matriz, int V0, int V1, int valor,
                     struct Grafo *grafo) {

  if (valor == 0) // zerar o valor da aresta é considerado removela
  {
    grafo->arestasGrafo = grafo->arestasGrafo - 1;
  } else {
    grafo->arestasGrafo = grafo->arestasGrafo + 1;
  }

  int i = V0 - 1;
  int j = V1 - 1;

  *(matriz + j + (i * grafo->vertice)) = valor;

  if (grafo->digrafo != 1) // se o grafo nao for um digrafo o mesmo valor sera
                           // associado tanto a i->j tanto j->i
  {
    *(matriz + i + (j * grafo->vertice)) = valor;
  }
};

void escolherProcesso(int *matriz, int length, struct Grafo grafo) {
  printf("\ndigite:\n1.para modificar um vertice.\n2.para calcular");

  int escolha = 0;
  int verticeTarefa;
  scanf("%d", &escolha);
  if (escolha == 1) { // qual vertice modificar?

    system(comandolimpar);
    printMatriz(matriz, length, grafo);
    int escolha = 0;
    int vertice0, vertice1, valor; // por um float para valor
    printf(
        "\n qual vertice desejas modificar ?\nselecione o vertice de  1 a %d\n",
        length);
    scanf("%d", &vertice0);
    printf(" com qual outro vertice desejas mudar sua adjacencia(aresta)\n");
    scanf("%d", &vertice1);
    printf("qual valor desejas atribuir a esse vertice ?\n");
    scanf("%d", &valor);

    // verificar se o vertice escolhido existe

    modificarMatriz(matriz, vertice0, vertice1, valor, &grafo);
    system(comandolimpar);
    printMatriz(matriz, length, grafo);
    escolherProcesso(matriz, length, grafo);
  } else if (escolha == 2) {
    static char temp[256];
    fgets(temp, sizeof(temp), stdin); // limpar o q ficou no buffer

    int verticeInicial;
    printf("de qual verticevc quer comecaro dfs ? \n\n\n");
    scanf("%d", &verticeInicial);
    system(comandolimpar);
    dfsPilha(verticeInicial, grafo.vertice, matriz, grafo);
  } else {
    static char temp[256];
    fgets(temp, sizeof(temp), stdin); // limpar o q ficou no buffer
    escolherProcesso(matriz, length, grafo);
  }
}

void printMatriz(int *matriz, int length, struct Grafo grafo) {

  printf("\n matriz de adjacencia\n");

  for (int i = 0; i < length; i++) {
    printf("\033[4m   %d\033[0m", i + 1);
  }

  for (int i = 0; i < length; i++) {
    printf("\n%d|", i + 1);
    for (int j = 0; j < length; j++) {
      printf(" %d  ", *(matriz + j + (i * length)));
    }
  }
  printf(" \no grafo tem %d vertices e %d arestas", grafo.vertice,
         grafo.arestasGrafo);
}

// void execDfs(int verticeinicial, struct Grafo *grafo, int *matrizAdj)
// {
//     static char temp[256];
//     fgets(temp, sizeof(temp), stdin); // limpar o q ficou no buffer
//     escolherProcesso(matriz, length, grafo);

//     int verticeInicial;
//     scanf("&d", &verticeInicial);
//     system(comandolimpar);
//     dfsPilha(verticeInicial, &grafo, matrizAdj);
// }

void dfsPilha(int verticeinicial, int vertices, int *matrizAdj,
              struct Grafo grafo) {
  verticeinicial -= 1; // se pah tapvez temja q tirar isso
  // printf("%d",verticeinicial);
  int verticesvisitados[vertices];
  setarArray(&verticesvisitados[0], vertices, 0);
  // verificar se o vertice ja foi visitado

  // criar pilha q vai guardar os vertices visitados
  struct Pilha *pilha = criarPilha();
  struct Pilha *pesos = criarPilha();
  // empilhar o vertice inicial
  empilhar(pilha,
           verticeinicial); // talvez tenh q por um -1 no vertice inicial !!!!!!

  while (!estaVazia(pilha)) { // enquanto estiver vazia
    int temVertice = 0;
    int vertice = elementoTopo(pilha);
    //desempilhar(pilha);//nao -e prara deempilhar todod hora
    if(verticesvisitados[vertice] == 0){
       printf("%d  ", vertice + 1);
    }
   
    verticesvisitados[vertice] = 1;

    
    for (int i = 0; i < vertices; i++) { // procurar alguma adjacencia no grafo
                                         // o e é o elemento, o adj é uum vetor;
      int elemento = *(matrizAdj + (vertice * vertices) + i);
      if (verticesvisitados[i] == 0 && elemento != 0) {
        empilhar(pilha, i);
        temVertice =1;
        //se o vertice a foi visitado nao é pra ser empilhado, mas, aoser desempilhado ele podeter suas vertices repesquisadas.
        //empilhar(pesos, elemento); // jogar os pesos das arestas
        i = vertices;
      }
    }

      if(temVertice==0){
        desempilhar(pilha);
      }
    
  }
  
  //printf("top %d",pesos->topo);
  //printf("\nmostrar os pesos dos vertices\n");
  for(int i = 0 ;i < pesos->topo;i++){// resolvr esse bo
    printf("e  ");
    printf("%d  ",*(pesos->itens+i));
  }
  escolherProcesso(matrizAdj, vertices, grafo);
}
