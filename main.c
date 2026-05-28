#include "comodos.h"

int main(){
    int m,n,comodos=0;
    posicao *novo;
    int i,j;
    ListaGen *L=NULL;

    scanf("%d %d",&m,&n);

    mapa **mat = (mapa**)malloc(m * sizeof(mapa*));
    if(mat==NULL){ exit(1); }
    for(i=0;i<m;i++){
        mat[i] = (mapa*)malloc(n * sizeof(mapa));
        if(mat[i]==NULL){ exit(1); }
    }

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            mat[i][j].vis=0;
            do{
                scanf("%c",&mat[i][j].simb);
            }while(mat[i][j].simb!='.' && mat[i][j].simb!='#');
        }
    }

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(mat[i][j].vis!=1 && mat[i][j].simb=='.'){
                mat[i][j].vis=1;
                novo=CriaPos(i,j);
                L=CriaNOGen(L,novo);
                comodos=VerificaComodo(L,m,n,mat,comodos);
                L=NULL;
            }
            mat[i][j].vis=1;
        }
    }

    printf("%d\n",comodos);

    for(i=0;i<m;i++) free(mat[i]);
    free(mat);
    
    return 0;
}
