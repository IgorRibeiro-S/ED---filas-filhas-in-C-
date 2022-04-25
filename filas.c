#include <stdio.h> 
#include <stdlib.h>

typedef struct list{
    int num;
    struct list *prox;
} celula;


void inserir(celula **fila, int dado){
    celula *ultimo, *primeiro, *novo = malloc(sizeof(celula));
    novo->num = dado;
    novo->prox = NULL;
    if (*fila == NULL){
        *fila = novo;
        primeiro = novo;
        ultimo = novo;
    }else{
        ultimo = *fila;
        while (ultimo ->prox)
            ultimo = ultimo ->prox;
        ultimo->prox = novo;
        }
    }
int remover(celula **primeiro){ 
    int x = 0;
    celula *apagar = NULL;
    if(*primeiro != NULL){
        apagar = *primeiro;
        *primeiro = apagar->prox;
        x = apagar->num;
    }
    else{
        printf("\n Fila vazia\n");
    }
    return x;
    free(apagar);
}

void PRINT(celula *lista) {
    while(lista != NULL){
        printf("%d, ", lista->num);
        lista = lista->prox;
    };
}

int main(){
celula *lista =NULL ;
inserir(&lista, 33);
inserir(&lista, 44);
inserir(&lista, 55);
inserir(&lista, 66);
inserir(&lista, 77);
remover(&lista);
PRINT(lista);
return 0;
}


