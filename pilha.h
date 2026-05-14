#ifndef _aluno_h_
#define aluno.h

#include<stdio.h>
/*para inputs e outputs*/
#include<stdlib.h>
/*para alocação dinamica*/

typedef struct ListaGen{
    void *info;
    struct ListaGen *prox;
} ListaGen;

void AndaGen(void*L,void (*cb)(void*));
/*1- Função que usa estrutura de repetição para percorrer a lista L e chamar o 
 Callback (cb) para cada dado presente (passados como parâmetro)*/

void ExcluiGen(void*L,void (*cb)(void*));
/*2- Função de exclusão do primeiro termo da lista (logica pilha -> FIFO):
 recebe a lista e uma função que irá desalocar a informação interna enquanto está é responsável
 por liberá-la da lista e desalocar o ponteiro void*/

void CriaNOGen(void*L,void*info);
/*3- Cria um novo nó e o implementa no incio da lista L passada como parâmetro, recebendo um ponteiro para
alocar naquela posição*/

int VerificaVazioGen(void *L);
/*4- verifica se a lista L passada como parâmetro está vazia, e portanto retorna 1 para Vazio e 0 para Não Vazio*/

#endif