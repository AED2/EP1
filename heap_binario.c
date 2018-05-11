#include "heap_binario.h"

int esq(int i){
    if (i==0){
        return 1;
    }
    else {
        return 2*i;
    }
}
int pai(int i){

    return (i/2);
}
int dir(int i){
    if (i==0){
        return 2;
    }
    return (2*i)+1;
}

void minHeapify(double *dist, int i, int n){
    int m = i;
    if(esq(i)< n && dist[esq(i)]<dist[i]) {
        m = esq(i);
    }
    if( dir(i) < n && dist[dir(i)]<dist[m]) {
        m = dir(i);
    }
    if(m!=i) {
        double aux = dist[m];
        dist[m] = dist[i];
        dist[i] = aux;
        minHeapify(dist,m,n);
	}
    
}

void buildMinHeap(double*dist, int n){
	int i;
	 for(i=(n/2); i>= 0; i--){
        minHeapify(dist, i, n);
    }
}

double * heapSort(double *dist, int n){
    int i;
	buildMinHeap(dist, n);
    for(i = n-1; i>0;i--){
        double aux = dist[0];
        dist[0] = dist[i];
        dist[i] = aux;
		minHeapify(dist, 0, --n);
		//return v[i];
    }
	//return -1;
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
