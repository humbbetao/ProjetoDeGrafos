#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
  Vertice v ;
  struct no *prox;
} tipo_no;

typedef struct lista
{
  tipo_no *primeiro, *ultimo;
  int tamanho;
} tipo_lista;

tipo_lista *inicializar_lista(tipo_lista *lista)
{
  lista -> primeiro  = NULL;
  lista -> ultimo    = NULL;
  lista -> tamanho = 0;

  printf("Lista Inicializada\n");
}

int lista_vazia(tipo_lista *lista)
{
  return(lista -> primeiro == NULL);
}

tipo_no *aloca_no()
{
  tipo_no *novo_no = (tipo_no *) malloc(sizeof(tipo_no));

  printf("Novo elemento: ");
  scanf("%d", &novo_no -> valor);
  return novo_no;
}

void inserir_inicio_lista(tipo_lista *lista)
{
  tipo_no *novo_no  = aloca_no();
  tipo_no *aux      = lista -> primeiro;

  lista -> primeiro = novo_no;
  novo_no -> prox   = aux;

  lista -> tamanho++;
}

void inserir_meio_lista(tipo_lista *lista)
{
    int pos, count;
    printf("Em que posicao, [de 1 ate %d] Voce Deseja Inserir o Elemento: ", lista -> tamanho);
    scanf("%d", &pos);
    if (pos > 0 && pos <= lista -> tamanho)
    {
       if (pos == 1) inserir_inicio_lista(lista);
       else
       {
          tipo_no *atual   = lista -> primeiro, *anterior = lista -> primeiro;
          tipo_no *novo_no = aloca_no();
	      for(count = 1; count < pos ; count++)
          {
             anterior = atual;
             atual    = atual -> prox;
          }

          anterior -> prox = novo_no;
          novo_no -> prox  = atual;
          lista -> tamanho++;
       }
    }
    else printf("Posicao Fora da Faixa Valida!\n\n");
}

void inserir_fim_lista(tipo_lista *lista)
{
  tipo_no *novo_no = aloca_no();
  novo_no -> prox = NULL;

  if (lista_vazia(lista))
  {
    lista -> primeiro = novo_no;
    lista -> ultimo   = novo_no;
  }
  else
  {
    lista -> ultimo -> prox = novo_no;
    lista -> ultimo         = novo_no;
  }

  lista -> tamanho++;
}

int retirar_inicio_lista(tipo_lista *lista)
{
   if (lista_vazia(lista))
   {
     printf("Lista Vazia!\n");
     return 0;
   }
   tipo_no *aux;
   int valor_aux;
   aux               = lista -> primeiro;
   valor_aux         = lista -> primeiro -> valor;
   lista -> primeiro = lista -> primeiro -> prox;
   free(aux);
   lista -> tamanho--;
   return valor_aux;
}

int tamanho(tipo_lista *lista)
{
  return (lista -> tamanho);
}

int retirar_fim_lista(tipo_lista *lista)
{
   if (lista_vazia(lista))
   {
     printf("Lista Vazia!\n");
     return 0;
   }
   else
   {
     int valor_aux;

     tipo_no *ultimo = lista -> primeiro, *penultimo = lista -> primeiro;

     while(ultimo -> prox != NULL)
     {
       printf("%d", ultimo -> valor);
       penultimo = ultimo;
       ultimo = ultimo -> prox;
     }

     penultimo -> prox = NULL;
     valor_aux         = ultimo -> valor;
     free(ultimo);
     lista -> tamanho--;
     return valor_aux;
  }
}

int retirar_meio_lista(tipo_lista *lista)
{
    int pos, count;
    printf("Em que posicao, [de 1 ate %d] Voce Deseja Retirar o Elemento: ", lista -> tamanho);
    scanf("%d", &pos);
    if (pos > 0 && pos <= lista -> tamanho)
    {
        if (pos == 1) return retirar_inicio_lista(lista);
        else
        {
            int valor_aux;

            tipo_no *atual = lista -> primeiro, *anterior = lista -> primeiro;

            for(count = 1; count < pos; count++)
            {
                anterior = atual;
                atual    = atual -> prox;
            }

            anterior -> prox = atual -> prox;
            valor_aux        = atual -> valor;
            free(atual);
            lista -> tamanho--;
            return valor_aux;
         }

    }
    else
    {
        printf("Elemento invalido\n\n");
        return NULL;
    }
}

void imprimir_lista(tipo_lista *lista)
{
  if (lista_vazia(lista)) printf("Lista Vazia!\n");
  else
  {
    tipo_no *aux;
    aux = lista -> primeiro;
    while (aux != NULL)
    {
      printf("%d ", aux -> valor);
      aux = aux -> prox;
    }
    printf("\n");
  }
}

main()
{
  tipo_lista *lista;
  int i, numero;

  lista = (tipo_lista *) malloc (sizeof(tipo_lista));

  inicializar_lista(lista);

  inserir_fim_lista(lista);
  inserir_fim_lista(lista);
  inserir_fim_lista(lista);
  inserir_fim_lista(lista);

  imprimir_lista(lista);

  getch();

//  numero = retirar_inicio_lista(lista);
  numero = retirar_fim_lista(lista);
//  numero = retirar_meio_lista(lista);

  imprimir_lista(lista);

  getch();
}
