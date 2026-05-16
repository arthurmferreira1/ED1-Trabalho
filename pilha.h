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

void AndaGen(ListaGen*L,void (*cb)(void*));
/*1- Função que usa estrutura de repetição para percorrer a lista L e chamar o 
 Callback (cb) para cada dado presente (passados como parâmetro)
 L: lista generica
 cb:ação*/

ListaGen* ExcluiGen(ListaGen*L,void (*cb)(void*));
/*2- Função de exclusão do primeiro termo da lista (logica pilha -> LIFO):
 recebe a lista e uma função que irá desalocar a informação interna enquanto ela (ExcluiGen) é responsável
 por desconectá-la da lista e desalocar a memória do nó ListaGen
 L: lista generica
 cb: callback,função de desalocação do 1° termo da lista*/

ListaGen* CriaNOGen(ListaGen*L,void*info);
/*3- Cria um novo nó e o implementa no incio da lista L passada como parâmetro, recebendo um ponteiro para
alocar naquela posição
L: lista generica
info:ponteiro para inserir na lista*/

int PertenceGen(ListaGen*L,int (*cb)(void*,void*),void*dado);
/*4-Percorre a lista verificando se o termo passado como parâmetro já está presente na lista atual
retorna 1 para Pertence e 0 para Nao Pertence
L: lista generica
cb:callback que verificará a informação interna
dado: valor que será buscado na lista*/

int VerificaVazioGen(ListaGen*L);
/*5- verifica se a lista L passada como parâmetro está vazia, e portanto retorna 1 para Vazio e 0 para Não Vazio
L: lista generica*/

#endif