#include "grafo_listaadj.h"

bool inicializaGrafo(TipoGrafo* grafo, int numV){
    int i;
    if(numV<=0){
        printf("Erro ao inicializar");
    }
    else{
        grafo->numVertices = numV;
	    grafo->numArestas = 0;

        grafo->listaAdj = (TipoApontador*) calloc(numV+1,sizeof(TipoApontador));
        for(i = 1; i<= grafo->numVertices; i++){
            //TipoApontador q = (TipoAresta*) malloc(sizeof(TipoAresta));
            TipoApontador q;
            q->prox=VERTICE_INVALIDO;
            grafo->listaAdj[i] = q;
        }
	    return true;
    }
    return false;
}

bool inicializaGrafo2(TipoGrafo *g, int nv){
    if(nv<=0){
        printf("Erro ao inicializar");
    }
    else{
        g->listaAdj = (TipoApontador*) calloc(nv+1,sizeof(TipoApontador));
	    g->numVertices = nv;
	    g->numArestas = 0;
	    return true;
    }
    return false;
}

bool inicializaGrafo3(TipoGrafo* grafo, int numV){
    int i;
    if(numV<=0){
        printf("Erro ao inicializar");
    }
    else{
        grafo->numVertices = numV;
	    grafo->numArestas = 0;

        grafo->listaAdj = (TipoApontador*) calloc(numV+1,sizeof(TipoApontador));
        for(i = 1; i<= grafo->numVertices; i++){
            //TipoApontador q = (TipoAresta*) malloc(sizeof(TipoAresta));
			//q->prox=NULL;
            //q->prox=VERTICE_INVALIDO;
            //grafo->listaAdj[i] = q;
			//grafo->listaAdj[i] = VERTICE_INVALIDO;
        }
	    return true;
    }
    return false;
}

void insereAresta(TipoGrafo * g, int v1,int v2, TipoPeso peso){
    TipoApontador p= g->listaAdj[v1];
    TipoApontador q = (TipoAresta*) malloc(sizeof(TipoAresta));
    q->prox=NULL;
    q->vdest=v2;
    q->peso=peso;
    if(!p){
        //g->listaAdj[v1]=q;
		TipoApontador r = (TipoAresta*) malloc(sizeof(TipoAresta));
		r->prox=NULL;
		g->listaAdj[v1]=r;
		insereAresta(g,v1,v2,peso);
    }
    else{
        q->prox=p;
        g->listaAdj[v1]=q;
    }
}

void insereAresta2(TipoGrafo * g, int v1,int v2, TipoPeso peso){
    TipoApontador p= g->listaAdj[v1];
    TipoApontador q = (TipoAresta*) malloc(sizeof(TipoAresta));
    q->prox=NULL;
    q->vdest=v2;
    q->peso=peso;
    if(!p){g->listaAdj[v1]=q;}
    else{
        q->prox=p;
        g->listaAdj[v1]=q;
    }
}

void insereAresta3(TipoGrafo * g, int v1,int v2, TipoPeso peso){
    TipoApontador p= g->listaAdj[v1];
    TipoApontador q = (TipoAresta*) malloc(sizeof(TipoAresta));
    q->prox=NULL;
    q->vdest=v2;
    q->peso=peso;
    if(!p){
        //g->listaAdj[v1]=q;
		TipoApontador r = g->listaAdj[v1];
		r->prox = q;
    }
    else{
        q->prox=p;
        g->listaAdj[v1]=q;
    }
}

void imprimeGrafo(TipoGrafo* grafo){
    int i = 1;
    TipoApontador p;
    while( i <= grafo->numVertices){
        p = grafo->listaAdj[i];
        printf("%p %d",(void *)p,i);
        TipoApontador q = VERTICE_INVALIDO;
        if(p){
            q = p->prox;
        }
        while(q){
            printf(" -> (P:%d |D:%d |N:%1p)", q->peso, q->vdest, (void *)q->prox);
            q = q->prox;
        }
        printf("\n");
        i++;
    }
}