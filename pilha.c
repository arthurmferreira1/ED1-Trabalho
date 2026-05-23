#include "pilha.h"

ListaGen *ExcluiGen(ListaGen*L,void (*cb)(void*)){
    if(L==NULL) return L;
    ListaGen*aux=L;
    L=aux->prox;
    cb(aux->info);
    free(aux);
    return L;
}

ListaGen* CriaNOGen(ListaGen*L,void*info){
    ListaGen*novo=(ListaGen*)calloc(1,sizeof(ListaGen));
    if(novo==NULL){
        exit(1);
    }
    novo->prox=L;
    L=novo;
    novo->info=info;
    return L;
}



