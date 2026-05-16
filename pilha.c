#include "pilha.h"

void AndaGen(ListaGen*L,void (*cb)(void*)){
    ListaGen*aux=L;
    while(aux!=NULL){
        cb(aux->info);
        aux=aux->prox;
    }
}

ListaGen* ExcluiGen(ListaGen*L,void (*cb)(void*)){
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
        printf("Erro de alocacao!\n");
        exit(1);
    }
    novo->prox=L;
    L=novo;
    novo->info=info;
    return L;
}

int PertenceGen(ListaGen*L,int (*cb)(void*,void*),void*dado){
    ListaGen*aux=L;
    while(aux!=NULL){
        if(cb(aux->info,dado)) return 1;
        aux=aux->prox;
    }
    return 0;
}

int VerificaVazioGen(ListaGen*L){
    if(L==NULL) return 1;
    return 0;
}