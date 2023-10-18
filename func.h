#include <stdio.h>

#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"




void initMatriz(int *matriz, int length){
    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++)
        {
             *(matriz + j + (i * length)) = 0 ;
        }
    }
}