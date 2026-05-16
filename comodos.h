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