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





int main()
{
ListaDupla* mochila = (ListaDupla*)malloc(sizeof(ListaDupla));

FILE *arq, *arq2, *arq3;
char str[10], str2[50], str3[50];
char *result;
char *result1;
char *result2;
int peso = NULL;
ListaDupla* L = NULL;

int capacidade;
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
        peso = atoi(str);
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
printf("Capacidade mochila 1: %d\n", peso);
imprimi(L);
printf("Teste");
}

