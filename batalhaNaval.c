#include <stdio.h>
#include <stdlib.h>

#define TAM_NOVATO 5
#define TAM_AVENTUREIRO 10

// Funções auxiliares
void limparTabuleiro(int **tabuleiro, int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        for(int j = 0; j < tamanho; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void exibirTabuleiro(int **tabuleiro, int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        for(int j = 0; j < tamanho; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Funções de posicionamento
void posicionarNavioVertical(int **tabuleiro, int x, int y, int tamanho, int valor) {
    for(int i = 0; i < tamanho; i++) {
        tabuleiro[x + i][y] = valor;
    }
}

void posicionarNavioHorizontal(int **tabuleiro, int x, int y, int tamanho, int valor) {
    for(int j = 0; j < tamanho; j++) {
        tabuleiro[x][y + j] = valor;
    }
}

void posicionarNavioDiagonal(int **tabuleiro, int x, int y, int tamanho, int valor) {
    for(int i = 0; i < tamanho; i++) {
        tabuleiro[x + i][y + i] = valor;
    }
}

int main() {
    // Alocação dinâmica dos tabuleiros
    int **tabuleiroNovato = malloc(TAM_NOVATO * sizeof(int*));
    int **tabuleiroAventureiro = malloc(TAM_AVENTUREIRO * sizeof(int*));
    int **habilidade = malloc(TAM_NOVATO * sizeof(int*));
    
    for(int i = 0; i < TAM_NOVATO; i++) {
        tabuleiroNovato[i] = malloc(TAM_NOVATO * sizeof(int));
        habilidade[i] = malloc(TAM_NOVATO * sizeof(int));
    }
    
    for(int i = 0; i < TAM_AVENTUREIRO; i++) {
        tabuleiroAventureiro[i] = malloc(TAM_AVENTUREIRO * sizeof(int));
    }

    // Nível Novato
    printf("=== NIVEL NOVATO ===\n");
    limparTabuleiro(tabuleiroNovato, TAM_NOVATO);
    posicionarNavioVertical(tabuleiroNovato, 0, 0, 3, 1);
    posicionarNavioHorizontal(tabuleiroNovato, 2, 2, 3, 1);
    exibirTabuleiro(tabuleiroNovato, TAM_NOVATO);

    // Nível Aventureiro
    printf("=== NIVEL AVENTUREIRO ===\n");
    limparTabuleiro(tabuleiroAventureiro, TAM_AVENTUREIRO);
    posicionarNavioVertical(tabuleiroAventureiro, 0, 0, 4, 3);
    posicionarNavioHorizontal(tabuleiroAventureiro, 5, 5, 3, 3);
    posicionarNavioDiagonal(tabuleiroAventureiro, 2, 2, 3, 3);
    posicionarNavioDiagonal(tabuleiroAventureiro, 7, 0, 3, 3);
    exibirTabuleiro(tabuleiroAventureiro, TAM_AVENTUREIRO);

    // Nível Mestre - Habilidades
    printf("=== NIVEL MESTRE ===\n");
    
    // Habilidade Cone
    printf("Habilidade Cone:\n");
    limparTabuleiro(habilidade, TAM_NOVATO);
    habilidade[0][2] = 1;
    for(int j = 1; j <= 3; j++) habilidade[1][j] = 1;
    for(int j = 0; j < TAM_NOVATO; j++) habilidade[2][j] = 1;
    exibirTabuleiro(habilidade, TAM_NOVATO);

    // Habilidade Octaedro
    printf("Habilidade Octaedro:\n");
    limparTabuleiro(habilidade, TAM_NOVATO);
    habilidade[0][2] = 1;
    for(int j = 1; j <= 3; j++) habilidade[1][j] = 1;
    habilidade[2][2] = 1;
    exibirTabuleiro(habilidade, TAM_NOVATO);

    // Habilidade Cruz
    printf("Habilidade Cruz:\n");
    limparTabuleiro(habilidade, TAM_NOVATO);
    for(int i = 0; i < TAM_NOVATO; i++) {
        habilidade[1][i] = 1;
        habilidade[i][2] = 1;
    }
    exibirTabuleiro(habilidade, TAM_NOVATO);

    // Liberação da memória
    for(int i = 0; i < TAM_NOVATO; i++) {
        free(tabuleiroNovato[i]);
        free(habilidade[i]);
    }
    for(int i = 0; i < TAM_AVENTUREIRO; i++) {
        free(tabuleiroAventureiro[i]);
    }
    free(tabuleiroNovato);
    free(tabuleiroAventureiro);
    free(habilidade);

    return 0;
}
