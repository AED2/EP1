#include "grafo_listaadj.h"
#include "heap_binario.h"

void imprimeVetor(int *entrada){
	int j;
    int tam = sizeof(entrada)-4;
    for(j = 1; j<= tam; j++){
        printf("%d",entrada[j]);
        printf(" ");
    }
    printf("\n");
}

void imprimeVetorDouble(double *entrada){
    int j;
    int tam = sizeof(entrada)-4;
    for(j = 1; j<= tam; j++){
		//printf("%.0f",entrada[j]);
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

/*
double * inicializaHeap(TipoGrafo* grafo, double vStart){
    double d= DBL_MAX;
    int i;
    double vetorHeap[grafo->numVertices];
    for(i=0; i<grafo->numVertices; i++){
        vetorHeap[i] = d;
    }
    vetorHeap[0] = vStart;
    return vetorHeap;
}
*/

int extract_min(double * vHeap){
    double min = vHeap[0];
    int i;
    for(i = 1; vHeap[i]!= 0; i++){
        if(min>vHeap[i]){
            min = vHeap[i];
        }
    }
	vHeap[i-1]= 0;
    int resp = (int)min;
    return resp;
}

TipoGrafo dijkstra(TipoGrafo* grafo, int vStart, int n){
	
	int i;
	double d= DBL_MAX;

	///INICIALIZAÇÃO
	int vetorAnt[grafo->numVertices + 1];
	double vetorDist[grafo->numVertices + 1];
	for(i = 0; i <=grafo->numVertices; i++){
		vetorDist[i] = d;
		vetorAnt[i] = -1;
	}
	
	imprimeVetor(vetorAnt);
	imprimeVetorDouble(vetorDist);
	
	///MAKE - heap de infinitos	
	double vetorHeap[grafo->numVertices];
    for(i=0; i<grafo->numVertices; i++){
        vetorHeap[i] = d;
    }
	//distancia ate vStart;
	vetorHeap[0] = 0;
	
	i=1;
	TipoApontador p = grafo->listaAdj[vStart];
	while(p){
		vetorHeap[i++] = (double)p->peso;
		p = p->prox;
	}
	imprimeHeap(vetorHeap);
	
	//double* q = heapSort(vetorHeap, sizeof(vetorHeap)-4);
	double* q = heapSort(vetorHeap, n);
	
	printf("\n*******************OK START***************\n");
	
	imprimeHeap(q);

	

	///enquanto o heap/Q n estiver vazio
	while(q[0]!= 0){
		int u = extract_min(q);
		imprimeHeap(q);
		//printf("\n %d \n", u);
		/// u - vertice atual q eu pego adj
		/// v - distancia ate o vertice u
	}
/*		TipoApontador p = grafo->listaAdj[u];
		if(p){
			 while(p){
				//relax(u,v,w);
				int v = p->vdest;
				if(vetorDist[u] > vetorDist[v] + pesoAresta(&grafo,u,v)){
					vetorDist[u] = vetorDist[v]+ pesoAresta(&grafo,u,v);
					vetorAnt[u] = v;
				}
				p = p->prox;
			}
		}
	}
*/	
	printf("\n*******************OK FINALE***************\n");
	
	TipoGrafo subGrafoDijkstra;
	inicializaGrafo2(&subGrafoDijkstra, grafo->numVertices);
	//for(){
	if(1==1){
		int o,d,c;
	    o = vStart;
	    d = subGrafoDijkstra.numVertices-1;
	    c = 3;
		insereAresta2(&subGrafoDijkstra, o,d,c);
		//insereArestaSubgrafo(&subGrafoDijkstra, v1, d, ant);
	}
	return subGrafoDijkstra;
}

int main(){
	
	TipoGrafo grafo;
	int s, n;
	
	  FILE *fp;
	  fp = fopen("entrada_teste1.txt","r");
	  if (!fp) {
		printf("Erro ao abrir o arquivo");
	  }
	  else{
	   char buff[255];
	  
	   fscanf(fp, "%s", buff);
	   //printf("1 : %s\n", buff );
	   char*save = buff;
	   s = (int)save[0]-48;
	   printf("NUM S: %d\n",s);

	   fgets(buff, 255, (FILE*)fp);
	   
	   fgets(buff, 255, (FILE*)fp);
	   int m;
	   n = (int)save[0]-48;
	   m = (int)save[2]-48;
	   inicializaGrafo2(&grafo, n);
	   printf("NUM N: %d NUM M: %d\n",n ,m);
		  int i;
		  for(i = 1; i<n; i++){
		   fgets(buff, 255, (FILE*)fp);
		   int o,d,c;
		   o = (int)save[0]-48;
		   d = (int)save[2]-48;
		   c = (int)save[4]-48;
		   insereAresta2(&grafo, o,d,c);
		   printf("NUM O: %d NUM D: %d NUM C: %d\n",o ,d, c);
		  }
  
	   fclose(fp);
	  
	   printf("\n FOPEM\n");
      }
	
    imprimeGrafo(&grafo);
	
	TipoGrafo grafoRespDijkstra;
	inicializaGrafo2(&grafoRespDijkstra, s);
	grafoRespDijkstra = dijkstra(&grafo, s, n);
	//dijkstra(&grafo, s);
	
	imprimeGrafo(&grafoRespDijkstra);
	
	printf("CHEGAMOS AO FIM \n");
}