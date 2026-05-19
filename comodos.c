#include "comodos.h"

posicao * CriaPos(int l,int c){
    posicao*novo=(posicao*)malloc(sizeof(posicao));
    if(novo==NULL){
        printf("Erro de alocacao!\n");
        exit(1);
    }
    novo->l=l;
    novo->c=c;
    return novo;
}

void ExcluiPos(void*Pont){
    posicao *aux=(posicao*)Pont;
    free(aux);
}

int VerificaComodo(ListaGen*L, int m, int n, mapa **mat, int comodos){
    int c,l;
    posicao*aux,*novo;
    if(L==NULL) return comodos;
    do{
        aux=(posicao*)(L->info);
        c=aux->c;
        l=aux->l;
        L=ExcluiGen(L,ExcluiPos);

        if(l>0 && mat[l-1][c].vis==0){
            mat[l-1][c].vis=1;
            if(mat[l-1][c].simb=='.'){
                novo=CriaPos(l-1,c);
                L=CriaNOGen(L,novo);
            }
        }//cima

        if(c>0 && mat[l][c-1].vis==0){
            mat[l][c-1].vis=1;
            if(mat[l][c-1].simb=='.'){
                novo=CriaPos(l,c-1);
                L=CriaNOGen(L,novo);
            }
        }//esquerda

        if(l<(m-1) && mat[l+1][c].vis==0){
            mat[l+1][c].vis=1;
            if(mat[l+1][c].simb=='.'){
                novo=CriaPos(l+1,c);
                L=CriaNOGen(L,novo);
            }
        }//baixo

        if(c<(n-1) && mat[l][c+1].vis==0){
            mat[l][c+1].vis=1;
            if(mat[l][c+1].simb=='.'){
                novo=CriaPos(l,c+1);
                L=CriaNOGen(L,novo);
            }
        }//direita

    }while(L!=NULL);
    comodos+=1;
    return comodos;
}