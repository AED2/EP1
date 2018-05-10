#include "grafo_listaadj.h"
#include "heap_binario.h"

int main(){
	
	TipoGrafo grafo;
	
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
	   int s = (int)save[0]-48;
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
	
    insereAresta2(&grafo, 5,7,12);
    insereAresta2(&grafo, 5,3,12);
    insereAresta2(&grafo, 4,3,12);

    //imprimeGrafo(&grafo);
	printf("CHEGAMOS AO FIM \n");
}