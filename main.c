#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM_BUFFER 20
#define tam 5

typedef struct aresta {
	int verticeDe;
	int verticePara;
	int peso;
}Aresta;


typedef struct vertice {
	int vertice;
	Vertice *proximo;
	Aresta *aresta;
}Vertice;


typedef struct grafo { // Onde Grafo é uma lista
	char nVertice;
	char nAresta;
	Vertice *primeiro;
	Vertice *ultimo;

}Grafo;

/*
Aresta *alocaAresta(){
	Aresta *aresta = (Aresta*)malloc(sizeof(Aresta));
}

Vertice *alocaVertice(){
	Vertice *vertice = (Vertice)malloc(sizeof(Vertice));
}

*/

void add(Grafo *grafo,Aresta *s, Vertice *u, Vertice *v)
{
int i=0, j=0;
        if(grafo->nVertice==0)
        {
            grafo->primeiro=u;
            grafo->ultimo=v;
            grafo->primeiro->proximo=grafo->ultimo;

            grafo->primeiro->aresta=inicializarAresta(s, u, v);

            grafo->nVertice=2;
            grafo->nAresta=1;
        }
        else{
            for(i=0;i<grafo->nVertice;i++)
            {
                if(grafo->primeiro->vertice!=u.vertice && grafo->ultimo->vertice!=u.vertice && grafo->ultimo->proximo==NULL)
                {
                    grafo->ultimo->proximo = inicializarVertice(u, u->vertice );
                    grafo->ultimo = grafo->ultimo->proximo;
                    grafo->ultimo->proximo==NULL;
                    grafo->nVertice++;

                }
                if(grafo->primeiro->vertice!=v.vertice && grafo->ultimo->vertice!=v.vertice && grafo->ultimo->proximo==NULL)
                {
                    grafo->ultimo->proximo = inicializarVertice(v, v->vertice );
                    grafo->ultimo = grafo->ultimo->proximo;
                    grafo->ultimo->proximo==NULL;
                    grafo->nVertice++;

                }

            }
            for(j=0; grafo->nAresta, j++)
            {
            //Grafo->
                while(grafo->primeiro->aresta->verticeDe!=aresta->verticeDe)
                {
              //      grafo->
                }
            }

        }

        return grafo;


}
Aresta *inicializarAresta(Aresta *s, Vertice *u, Vertice *v)
{
    s->verticeDe = u->vertice;
    s->verticePara =v->vertice;
    if(u->vertice >v->vertice)
    {
        s->peso=  u->vertice-v->vertice;
    }else{
        s->peso = v->vertice - u->vertice;
    }
    return s;
}

Vertice *inicializarVertice(Vertice* vertice, int v)
{
    vertice->vertice=v;
    vertice->aresta=NULL;
    vertice->proximo=NULL;
    return vertice;
}
Grafo *inicializarGrafo(Grafo *grafo,  FILE *arquivo) {
	char c, tab;
	char var[tam];
	int i, a, b, cont;
	Vertice *u=NULL, *v=NULL;
	Aresta *s=NULL;
	i = 0;
	cont = 0;
	grafo->nAresta=0;
	grafo->nVertice=0;

  	char buffer[TAM_BUFFER];
	while((fgets(buffer, TAM_BUFFER, arquivo))!=NULL){
        while((tab = buffer[i]) != '\t'){
            var[i] = tab;
            i++;
        }
        a = atoi(var);
        u = (Vertice*)malloc(sizeof(Vertice));
        u = inicializarVertice(u, a);
        printf("%d \t", a);
        i=0;

        while((tab = buffer[i]) != '\n'){
            var[i] = tab;
            i++;
        }

        i=0;
        b = atoi(var);

        v = (Vertice*)malloc(sizeof(Vertice));


        v = inicializarVertice(v, b);


        printf("%d \n", b);

        s = (Aresta*)malloc(sizeof(Aresta));

        s =  inicializarAresta(s, u, v);


        grafo = add(grafo,u,v,s);


        }

	fclose(arquivo);
	return grafo;
}

int main() {

   //printf("TO AQUI2");
	FILE *arquivo = fopen("roadNet-PA.txt", "r");
	//printf("AQUI2");
	Grafo *grafo = (Grafo*)malloc(sizeof(Grafo));
	grafo = inicializarGrafo(grafo,arquivo);
	char c;
	printf("\n\n");
  	return 0;
}
