#ifndef _PILHA_H_
#define _PILHA_H_

#include<stdio.h>
/*para inputs e outputs*/
#include<stdlib.h>
/*para alocação dinamica*/

typedef struct ListaGen{
    void *info;
    struct ListaGen *prox;
} ListaGen;

ListaGen* ExcluiGen(ListaGen*L,void (*cb)(void*));
/*1- Função de exclusão do primeiro termo da lista (logica pilha -> LIFO):
 recebe a lista e uma função que irá desalocar a informação interna enquanto ela (ExcluiGen) é responsável
 por desconectá-la da lista e desalocar a memória do nó ListaGen
 L: lista generica
 cb: callback,função de desalocação do 1° termo da lista*/

ListaGen* CriaNOGen(ListaGen*L,void*info);
/*2- Cria um novo nó e o implementa no incio da lista L passada como parâmetro, recebendo um ponteiro para
alocar naquela posição
L: lista generica
info:ponteiro para inserir na lista*/

#endif