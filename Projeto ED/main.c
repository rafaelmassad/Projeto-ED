#include <stdio.h>
#include <stdlib.h>


typedef struct lista{
    int peso;
    int raridade;
    int subtracaoRaridadePeso;
    struct lista* prox;
    struct lista* ant;
}ListaDupla;



void imprimi(ListaDupla* L){
    while(L!=NULL){
        printf("Peso = %d |\t",L->peso);
        printf("Raridade = %d\t",L->raridade);
        printf("SubtracaoRaridadePeso = %d\n",L->subtracaoRaridadePeso);
        
        L=L->prox;
    }
}
//funcao para popular a lista com o valor de peso e raridade do dataset
ListaDupla* insereInicio(ListaDupla* L, int peso, int raridade){
	ListaDupla* novo = (ListaDupla*) malloc(sizeof(ListaDupla));
	novo->peso = peso;
	novo->raridade = raridade;
	novo->prox = L;
	novo->ant = NULL;
	if(L == NULL){
		return novo;
	}else{
		L->ant = novo;
		return novo;
	}
}

ListaDupla* insereFim(ListaDupla* L,int peso, int raridade,int resultado){
	ListaDupla* novo = (ListaDupla*) malloc(sizeof(ListaDupla));
	ListaDupla* aux = (ListaDupla*) malloc(sizeof(ListaDupla));
	novo->ant = NULL;
	novo->peso = peso;
	novo->raridade = raridade;
	novo->subtracaoRaridadePeso = resultado;
	novo->prox = NULL;
	aux->prox = L;
	
	if(L == NULL){
		return novo;
	}
	
	while(aux->prox != NULL){
		aux=aux->prox;
	}
	
	aux->prox = novo;
	novo->ant = aux;
	
	return L;
}

ListaDupla* removeListaDupla(ListaDupla* L, int info){
	printf("Removendo->%d...", info);
	ListaDupla* aux;
	ListaDupla* ant;
	aux = L;
	
	if(aux == NULL){
		return NULL;
	}
	
	while(aux != NULL && aux->info != info){
		ant = aux;
		aux = aux->prox;
	}
	
	if(aux->ant == NULL){
		L = aux->prox;
		aux->prox->ant = NULL;
		free(aux);
		return L;
	}
	if(aux->prox == NULL){
		aux->ant->prox = NULL;
		free(aux);
		return L;
	}
	
	aux->ant->prox = aux->prox;
	aux->prox->ant = aux->ant;
	
	return L;
}
//ordena do maior para o menor de acordo dom o atributo subRaridadePeso
ListaDupla* ordenaLista(ListaDupla* L){
	ListaDupla* nLista = NULL;
	ListaDupla* aux = NULL;
	ListaDupla* aux1 = NULL;
	ListaDupla* maior = NULL;
	
	aux1= L;
	aux = L;
	maior = L;
	
	while(aux1 != NULL){
		aux = aux1;
		while(aux != NULL && aux->subtracaoRaridadePeso > maior->subtracaoRaridadePeso){
			maior = aux;
			aux = aux->prox;
		}

		nLista = insereFim(nLista, maior->peso, maior->raridade, maior->subtracaoRaridadePeso);
		free(maior);
		aux1 = aux1->prox;
	}	
	
	return nLista;	
}

//fazer funcao para inserir melhores itens na mochila, conforme o maior valor da subtracaoRaridadePeso
ListaDupla* insereItensMochila(ListaDupla* L, int capacidade){
	
	return NULL;
}





int main()
{
ListaDupla* mochila = (ListaDupla*)malloc(sizeof(ListaDupla));

FILE *arq, *arq2, *arq3;
char str[10], str2[50], str3[50];
char *result;
char *result1;
char *result2;
int capacidade = NULL;
ListaDupla* L = NULL;

int i;

arq = fopen("p01_c.txt", "rt");
arq2 = fopen("p01_p.txt", "rt");
arq3 = fopen("p01_w.txt", "rt");

//----------------------------- verifica se nao houve error ------------------------------
if(arq==NULL){
    printf("Error!");
}
if(arq2==NULL){
    printf("Error!");
}
if(arq3==NULL){
    printf("Error!");
}
//----------------------------Leitura do Arquivo ---------------------------
while (!feof(arq)){
	
	// Lê uma linha (inclusive com o '\n')
      result = fgets(str, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
      if (result)  // Se foi possível ler
        capacidade = atoi(str);
}
while (!feof(arq2)){
	int resultado = NULL;
	// Lê uma linha (inclusive com o '\n')
      result1 = fgets(str2, 100, arq2);
	  result2 = fgets(str3, 100, arq3);  // o 'fgets' lê até 99 caracteres ou até o '\n'
	  resultado =   atoi(str2) - atoi(str3);
      if (result1)  // Se foi possível ler
        L = insereFim(L, atoi(str2), atoi(str3), resultado);
}

//---------------------------Fecha os arquivoss ---------------------------------
fclose(arq);
fclose(arq2);
fclose(arq3);

//-------------------------impressao dps valores -------------------------------
printf("Capacidade mochila 1: %d\n", capacidade);
imprimi(L);
printf("\n\n");
printf("Capacidade mochila 1: %d\n", capacidade);
L = ordenaLista(L);
imprimi(L);
printf("Teste");
}
