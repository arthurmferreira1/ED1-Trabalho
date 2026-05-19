#ifndef _COMODOS_H_
#define _COMODOS_H_

#include "pilha.h"

typedef struct mapa
{
    char simb;
    int vis;
} mapa;
/*esse struct serve para guardar o simbolo no mapa '#' ou '.'
e salvar uma informação para verificar se esta posição foi verificada
pelo sistema, para não ocorrer multipla análise de um mesmo ponto*/

typedef struct posicao
{
    int l;
    int c;
} posicao;
/*essa struct guaradrá a informação das posicoes dos '.' e será salvo na lista generica,
sendo 'l' e 'c' respectivamente, linha e coluna, para que com isso o programa mapeeie os
quartos delimitados nos quartos*/


posicao * CriaPos(int l,int c);
/*essa funcao vai receber dois inteiros (l e c) que representam a posição linha e coluna do ponto na matriz,
e aloca uma memoria com esses dados retornando um ponteiro para este.
l:posicao na linha
c:posicao na coluna*/

void ExcluiPos(void*Pont);
/*esta funcao recebe um ponteiro void, cria um ponteiro que recebe um typecast do void ponteiro como posicao* 
e em seguida libera essa memoria*/

int VerificaComodo(ListaGen*L, int m, int n, mapa **mat, int comodos);
/*Essa funcao percorre um comodo da matriz a partir de uma posicao inicial
armazenada na pilha. Ela verifica as posicoes vizinhas livres ('.'),
marca as visitadas e adiciona novas posicoes na pilha para continuar
a busca pelas partes conectadas do comodo.

Ao finalizar a verificacao, soma 1 na quantidade de comodos encontrados
e retorna esse valor atualizado.

L: lista com as posicoes que serao verificadas.
m: quantidade de linhas da matriz.
n: quantidade de colunas da matriz.
mat: matriz do mapa, contendo simbolos das posicoes e controle de visitados.
comodos: quantidade atual de comodos encontrados.
*/
#endif