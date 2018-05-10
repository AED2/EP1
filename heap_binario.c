#include "heap_binario.h"

void imprimeHeap(double *entrada){
    int j;
    int tam = sizeof(entrada);
    for(j = 0; j< tam; j++){
        printf("%.0f",entrada[j]);
        //printf("%.0ef",entrada[j]);
        printf(" ");
    }
    printf("\n");
}