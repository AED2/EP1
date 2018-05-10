#include "grafo_listaadj.h"
//#include "grafo_listaadj.c"
#include "heap_binario.h"
//#include "heap_binario.c"

int main(){
	
	TipoGrafo grafo;
    inicializaGrafo2(&grafo, 10);

    insereAresta(&grafo, 5,7,12);
    insereAresta(&grafo, 5,3,12);
    insereAresta(&grafo, 4,3,12);

    imprimeGrafo(&grafo);
	printf("CHEGAMOS AO FIM \n");
}