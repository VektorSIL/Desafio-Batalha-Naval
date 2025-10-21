#include <stdio.h>

int main(){
    int i, j; //Definição das colunas e linhas
    
    char coluna[10] = {'A', 'B', 'C', 'D', 'E', 'F','G', 'H', 'I', 'J'};//Colocando
    
    int tabuleiro[10][10] ={
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
    };

    //Definindo os quadrantes dos navios na Horizontal
    tabuleiro[7][4] = 3;
    tabuleiro[7][5] = 3;
    tabuleiro[7][6] = 3;

    //Definindo os quadrantes dos navios na Vertical
    tabuleiro[1][9] = 3; 
    tabuleiro[2][9] = 3; 
    tabuleiro[3][9] = 3;

    //imprimindo o tabuleiro
    printf("  "); 
    for (j = 0; j < 10; j++) {
        printf("%c ", coluna[j]);
    }
    printf("\n");
    for (i = 0; i < 10; i++) {
        
        printf("%d ", i + 1); 
        
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]); 
        }
        
        printf("\n");
    }
    
    return 0;
}