#include <stdbool.h>   /* variaveis bool assumem valores "true" ou "false" */
#include <stdlib.h>
#include <float.h>
#include <stdio.h>

void imprimeHeap(double *entrada);

void minHeapify(double *dist, int i, int n);

void buildMinHeap(double*dist, int n);

double * heapSort(double *dist, int n);