#include "heap_binario.h"

int pai(int i) {
    return((i+1)/2)-1;
}

int esq(int i) {
    return 2*i+1;
}

int dir(int i) {
    return 2*i+2;
}

void heapify(double *dist, int i, int n){
    int m = i;
    if(esq(i)< n && dist[esq(i)]>dist[m]) {
        m = esq(i);
    }
    if( dir(i) <n && dist[dir(i)]>dist[m]) {
        m = dir(i);
    }
    if(m!=i) {
        double aux = dist[m];
        dist[m] = dist[i];
        dist[i] = aux;
        heapify(dist,m,n);
    }
}

void buildheap(double *dist, int n){
    int i;
    for(i=(n/2)-1; i>= 0; i--){
        heapify(dist, i, n);
    }
}

double * heapSort(double *dist, int n){
    int i;
    buildheap(dist, n);
    for(i = n-1; i>0;i--){
        double aux = dist[i];
        dist[0] = dist[i];
        dist[i] = aux;
        heapify(dist, 0 , --n);
    }
	return dist;
}

void imprimeHeap(double *entrada){
    int j;
    int tam = sizeof(entrada)-4;
    for(j = 0; j< tam; j++){
        if(entrada[j] <100){
			printf("%.0f",entrada[j]);
		}
		else{
			printf("%.0ef",entrada[j]);
		}
        printf(" ");
    }
    printf("\n");
}
