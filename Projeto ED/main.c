#include <stdio.h>
#include <stdlib.h>
typedef struct lista{
    int info;
    struct lista* prox;
}Lista;
void imprimi(Lista* A){
    while(A!=NULL){
        printf("%d",A->info);
        A=A->prox;
    }
}
Lista* insere_Inicio_Lista (Lista* A, int valor){
    Lista* novo = (Lista*)malloc(sizeof(Lista));

    novo->info = valor;
    novo->prox = NULL;

    return novo;
}
Lista* insere_Fim_Lista(Lista *L, int valor){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    Lista* aux = L;

    novo->info = valor;
    novo->prox = NULL;

    if(L == NULL){
        return novo;
    }else{
        while(aux->prox !=NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
        return L;
    }
}
int main()
{
Lista* peso = (Lista*)malloc(sizeof(Lista));
Lista* raridade = (Lista*)malloc(sizeof(Lista));

FILE *arq, *arq2, *arq3;
char str[10], str2[50], str3[50];
char *result;

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
	// Lê uma linha (inclusive com o '\n')
      result = fgets(str2, 100, arq2);  // o 'fgets' lê até 99 caracteres ou até o '\n'
      if (result)  // Se foi possível ler
        peso = insere_Fim_Lista(peso, atoi(str2));
}
 while (!feof(arq3)){
	// Lê uma linha (inclusive com o '\n')
      result = fgets(str3, 100, arq3);  // o 'fgets' lê até 99 caracteres ou até o '\n'
      if (result){  // Se foi possível ler
        raridade = insere_Fim_Lista(raridade, atoi(str3));
      }
}
//---------------------------Fecha os arquivoss ---------------------------------
fclose(arq);
fclose(arq2);
fclose(arq3);

//-------------------------impressao dps valores -------------------------------
printf("Capacidade mochila 1: %d", peso);
imprimi(peso);
imprimi(raridade);
printf("Teste");
}

