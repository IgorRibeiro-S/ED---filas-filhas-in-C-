#include <stdio.h> 
#include <stdlib.h>

typedef struct list{
    int num;
    struct list *prox;
} celula;


celula *empilhar(celula *topo, int dado){
    celula *novo = malloc(sizeof(celula));

    if (novo){
        novo->num = dado;
        novo->prox = topo->prox; //o novo passa a ser o topo e aponta pro topo ANTIGO
        topo->prox = novo; // topo aponta para o novo
        return novo;
    }
    else{
        printf("\nerro ao alocar memoria\n");
    return NULL;
    }
}

int remover(celula *topo){ // sem passagem por referencia, apenas passagem por valor, por isso o ponteiro do ponteiro, pois ele cria uma cópia e a cópia está em outro end de memoria
    int x = 0;
    if(topo != NULL){
        celula *apagar = NULL;
        apagar = topo->prox;
        topo->prox = apagar->prox;
        x = apagar->num;
        free(apagar);
        
    }
    else{
        printf("\nlista vazia\n");
    }
    return x;

}


void PRINT(celula *lista) {
    while(lista != NULL){
        printf("%d\n", lista->num);
        lista = lista->prox;
    };
    printf("-=-=-=-=Fim da pilha-=-=-=-=\n");
}

int main(){
celula *top = NULL;
top = malloc(sizeof(celula));
top->prox = NULL;
top->num = 0;

empilhar(top, 5);
empilhar(top, 4);
remover(top);
empilhar(top, 44);
PRINT(top);

return 0;
}


