#include <stdio.h> 
#include <stdlib.h>

typedef struct list{
    int num;
    struct list *prox;
} celula;


celula *inserir(celula *fila, int dado){
    celula *novo = malloc(sizeof(celula));
    celula *primeiro ;
    celula *ultimo ;
    primeiro = NULL;
    ultimo = NULL;
    novo->num = dado;
    novo->prox = fila->prox;
    fila->prox = novo;
        if (primeiro == NULL){
            primeiro = novo;
        }
        else{
            ultimo->prox = novo;
        }
        ultimo = novo;
}

int remover(celula *primeiro){ 
    int x = 0;
    if(primeiro != NULL){
        celula *apagar = NULL;
        apagar = primeiro->prox;
        x = apagar->num;
        primeiro -> prox = apagar->prox;
        free(apagar);
    }
    else{
        printf("\nlista vazia\n");
    }
    return x;
}

void PRINT(celula *lista) {
    while(lista != NULL){
        printf("%d, ", lista->num);
        lista = lista->prox;
    };
}

int main(){
celula *top = NULL;
top = malloc(sizeof(celula));
top->prox = NULL;
top->num = 0;
inserir(top, 44);
inserir(top, 33);
inserir(top, 55);
inserir(top, 77);
remover(top);
PRINT(top);
return 0;
}


