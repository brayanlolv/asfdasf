#include <stdio.h>

void printMatriz(int * matriz, int length){

    for (int i = 0;i < length;i++){

        printf("\n");
         for (int j = 0;j < length;j++){
        printf(" %d  ", *(matriz + j + (i * length)));
    }}


}



int main()
{

    int array[3][3] = {{2,3,4},{5,6,7},{3,4,5}};

    int b = 3; 
    printMatriz( &array[0][0],3);
    printf("%p",&array[2][1]);


//0061FEF4
//0061FEF8
//0061FEFC
//0061FF00

  return 0 ;
}
