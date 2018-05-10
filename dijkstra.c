#include "grafo_listaadj.h"
#include "heap_binario.h"

void imprimeVetor(int *entrada){
	int j;
    int tam = sizeof(entrada);
    for(j = 1; j<= tam; j++){
        printf("%d",entrada[j]);
        printf(" ");
    }
    printf("\n");
}

void imprimeVetorDouble(double *entrada){
    int j;
    int tam = sizeof(entrada);
    for(j = 1; j<= tam; j++){
        //printf("%.0f",entrada[j]);
        printf("%.0ef",entrada[j]);
        printf(" ");
    }
    printf("\n");
}

TipoGrafo dijkstra(TipoGrafo* grafo, int vStart){
	
	int i;
	double d= DBL_MAX;

	///INICIALIZAÇÃO
	int vetorAnt[grafo->numVertices + 1];
	double vetorDist[grafo->numVertices + 1];
	for(i = 1; i <=grafo->numVertices; i++){
		vetorDist[i] = d;
		vetorAnt[i] = -1;
	}
	
	imprimeVetor(vetorAnt);
	imprimeVetorDouble(vetorDist);
	printf("\n*******************OK START***************\n");
	
/*	///MAKE - heap de infinitos
	double v1 = (double)vStart;
	double *q = inicializaHeap(&grafo, v1);

	///d[s] = 0 - o primeiro verificado do heap tem valor 0
	vetorDist[vStart] = 0;

	///enquanto o heap/Q n estiver vazio
	while(q[0]!= -1){
		int u = extract_min(q);
		/// u - vertice atual q eu pego adj
		/// v - distancia ate o vertice u
		TipoApontador p = grafo->listaAdj[u];
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
	int s;
	
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
	   int n,m;
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
	grafoRespDijkstra = dijkstra(&grafo, s);
	//dijkstra(&grafo, s);
	
	imprimeGrafo(&grafoRespDijkstra);
	
	printf("CHEGAMOS AO FIM \n");
}