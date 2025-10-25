#include <stdio.h>
#include <stdlib.h> 

// Definições de tamanho
#define TAB_TAMANHO 10
#define CONE_LINHAS 3
#define CONE_COLUNAS 5
#define CRUZ_LINHAS 3
#define CRUZ_COLUNAS 5
#define OCTA_LINHAS 3
#define OCTA_COLUNAS 3

// Definição dos valores 
#define AGUA         0
#define CHAVE_1      1
#define HABILIDADE   2 
#define NAVIO        3
#define CHAVE_4      4

// funções
void preencher_tabuleiro_chaves(int tabuleiro[TAB_TAMANHO][TAB_TAMANHO]);
void criar_habilidade_cone(int matriz_hab[CONE_LINHAS][CONE_COLUNAS]);
void criar_habilidade_cruz(int matriz_hab[CRUZ_LINHAS][CRUZ_COLUNAS]);
void criar_habilidade_octaedro(int matriz_hab[OCTA_LINHAS][OCTA_COLUNAS]);
void aplicar_cone(int tabuleiro[TAB_TAMANHO][TAB_TAMANHO], const int matriz_hab[CONE_LINHAS][CONE_COLUNAS], int origem_linha, int origem_coluna);
void aplicar_cruz(int tabuleiro[TAB_TAMANHO][TAB_TAMANHO], const int matriz_hab[CRUZ_LINHAS][CRUZ_COLUNAS], int origem_linha, int origem_coluna);
void aplicar_octaedro(int tabuleiro[TAB_TAMANHO][TAB_TAMANHO], const int matriz_hab[OCTA_LINHAS][OCTA_COLUNAS], int origem_linha, int origem_coluna);
void exibir_tabuleiro(const int tabuleiro[TAB_TAMANHO][TAB_TAMANHO]);

int main() {
    int tabuleiro[TAB_TAMANHO][TAB_TAMANHO];
    
    // Matrizes de habilidade
    int cone[CONE_LINHAS][CONE_COLUNAS] = {0};
    int cruz[CRUZ_LINHAS][CRUZ_COLUNAS] = {0};
    int octaedro[OCTA_LINHAS][OCTA_COLUNAS] = {0};

    // Ponto de origem 
    int origem_l = 4;
    int origem_c = 4;

    // Matrizes de habilidade
    criar_habilidade_cone(cone);
    criar_habilidade_cruz(cruz);
    criar_habilidade_octaedro(octaedro);
    
    preencher_tabuleiro_chaves(tabuleiro);
    printf("\n \n");
    aplicar_cone(tabuleiro, cone, origem_l, origem_c); 
    exibir_tabuleiro(tabuleiro);

    preencher_tabuleiro_chaves(tabuleiro);
    printf("\n \n");
    aplicar_cruz(tabuleiro, cruz, 7, 7); 
    exibir_tabuleiro(tabuleiro);

    preencher_tabuleiro_chaves(tabuleiro);
    printf("\n \n");
    aplicar_octaedro(tabuleiro, octaedro, 1, 1);
    exibir_tabuleiro(tabuleiro);

    return 0;
}

// Inicialização de visualizações

void preencher_tabuleiro_chaves(int tabuleiro[TAB_TAMANHO][TAB_TAMANHO]) {
    int matriz_chaves[TAB_TAMANHO][TAB_TAMANHO] = {
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 4, 0},
        {0, 0, 0, 0, 2, 0, 0, 4, 4, 4},
        {0, 0, 2, 2, 2, 2, 2, 0, 4, 0},
        {3, 0, 0, 0, 2, 0, 0, 0, 0, 3},
        {0, 3, 0, 0, 0, 0, 0, 0, 3, 0},
        {0, 0, 3, 0, 0, 0, 0, 3, 0, 0},
        {3, 3, 3, 0, 0, 0, 3, 3, 3, 0}
    };
    for (int i = 0; i < TAB_TAMANHO; i++) {
        for (int j = 0; j < TAB_TAMANHO; j++) {
            tabuleiro[i][j] = matriz_chaves[i][j];
        }
    }
}

void exibir_tabuleiro(const int tabuleiro[TAB_TAMANHO][TAB_TAMANHO]) {
    printf("  a b c d e f g h i j\n");

    for (int i = 0; i < TAB_TAMANHO; i++) {
        printf("%-2d", i + 1);
        for (int j = 0; j < TAB_TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Criação de Habilidade 

void criar_habilidade_cone(int matriz_hab[CONE_LINHAS][CONE_COLUNAS]) {
    int centro_c = CONE_COLUNAS / 2;
    for (int i = 0; i < CONE_LINHAS; i++) {
        int largura_max_na_linha = i;
        for (int j = 0; j < CONE_COLUNAS; j++) {
            if (j >= centro_c - largura_max_na_linha && j <= centro_c + largura_max_na_linha) {
                matriz_hab[i][j] = 1;
            } else {
                matriz_hab[i][j] = 0;
            }
        }
    }
}

void criar_habilidade_cruz(int matriz_hab[CRUZ_LINHAS][CRUZ_COLUNAS]) {
    int centro_l = CRUZ_LINHAS / 2;
    int centro_c = CRUZ_COLUNAS / 2;
    for (int i = 0; i < CRUZ_LINHAS; i++) {
        for (int j = 0; j < CRUZ_COLUNAS; j++) {
            if (i == centro_l || j == centro_c) {
                matriz_hab[i][j] = 1;
            } else {
                matriz_hab[i][j] = 0;
            }
        }
    }
}

void criar_habilidade_octaedro(int matriz_hab[OCTA_LINHAS][OCTA_COLUNAS]) {
    int centro_hab = OCTA_LINHAS / 2;
    for (int i = 0; i < OCTA_LINHAS; i++) {
        for (int j = 0; j < OCTA_COLUNAS; j++) {
            int dist_manhattan = abs(i - centro_hab) + abs(j - centro_hab);
            if (dist_manhattan <= centro_hab) {
                matriz_hab[i][j] = 1;
            } else {
                matriz_hab[i][j] = 0;
            }
        }
    }
}

void aplicar_logica(int tabuleiro[TAB_TAMANHO][TAB_TAMANHO], int i, int j, int centro_l, int centro_c, int linha_tab, int coluna_tab, int hab_valor) {
    if (linha_tab >= 0 && linha_tab < TAB_TAMANHO && 
        coluna_tab >= 0 && coluna_tab < TAB_TAMANHO) {
        
        if (hab_valor == 1 && tabuleiro[linha_tab][coluna_tab] != NAVIO && 
            tabuleiro[linha_tab][coluna_tab] != CHAVE_4) {
            tabuleiro[linha_tab][coluna_tab] = HABILIDADE; 
        }
    }
}

void aplicar_cone(int tabuleiro[TAB_TAMANHO][TAB_TAMANHO], const int matriz_hab[CONE_LINHAS][CONE_COLUNAS], int origem_linha, int origem_coluna) {
    int centro_l = CONE_LINHAS / 2;
    int centro_c = CONE_COLUNAS / 2;
    
    for (int i = 0; i < CONE_LINHAS; i++) {
        for (int j = 0; j < CONE_COLUNAS; j++) {
            int linha_tab = origem_linha + (i - centro_l);
            int coluna_tab = origem_coluna + (j - centro_c);
            aplicar_logica(tabuleiro, i, j, centro_l, centro_c, linha_tab, coluna_tab, matriz_hab[i][j]);
        }
    }
}

void aplicar_cruz(int tabuleiro[TAB_TAMANHO][TAB_TAMANHO], const int matriz_hab[CRUZ_LINHAS][CRUZ_COLUNAS], int origem_linha, int origem_coluna) {
    int centro_l = CRUZ_LINHAS / 2;
    int centro_c = CRUZ_COLUNAS / 2;
    
    for (int i = 0; i < CRUZ_LINHAS; i++) {
        for (int j = 0; j < CRUZ_COLUNAS; j++) {
            int linha_tab = origem_linha + (i - centro_l);
            int coluna_tab = origem_coluna + (j - centro_c);
            aplicar_logica(tabuleiro, i, j, centro_l, centro_c, linha_tab, coluna_tab, matriz_hab[i][j]);
        }
    }
}

void aplicar_octaedro(int tabuleiro[TAB_TAMANHO][TAB_TAMANHO], const int matriz_hab[OCTA_LINHAS][OCTA_COLUNAS], int origem_linha, int origem_coluna) {
    int centro_l = OCTA_LINHAS / 2;
    int centro_c = OCTA_COLUNAS / 2;
    
    for (int i = 0; i < OCTA_LINHAS; i++) {
        for (int j = 0; j < OCTA_COLUNAS; j++) {
            int linha_tab = origem_linha + (i - centro_l);
            int coluna_tab = origem_coluna + (j - centro_c);
            aplicar_logica(tabuleiro, i, j, centro_l, centro_c, linha_tab, coluna_tab, matriz_hab[i][j]);
        }
    }
}