#include <stdio.h>

// torre vai pra direita usando recursao
void torre(int n) {
    if (n <= 0) {
        return;
    }
    printf("Direita\n");
    torre(n - 1);
}

// rainha vai pra esquerda com recursao tambem
void rainha(int n) {
    if (n == 0) {
        return;
    }
    printf("Esquerda\n");
    rainha(n - 1);
}

// bispo vai na diagonal pra cima e direita
void bispoRec(int n) {
    if (n == 0) {
        return;
    }
    printf("Cima Direita\n");
    bispoRec(n - 1);
}

// cavalo faz dois pra cima e um pra direita (tipo L)
void cavalo() {
    printf("\nMovimento do Cavalo:\n");
    int i, j;
    for (i = 0; i < 3; i++) {
        j = 0;
        while (j < 2) {
            if (i < 2 && j == 0) {
                printf("Cima\n");
                break;
            }
            if (i == 2 && j == 1) {
                printf("Direita\n");
            }
            j++;
        }
    }
}

// bispo com dois for
void bispoLoops() {
    printf("\nMovimento do Bispo com Loops:\n");
    int a, b;
    for (a = 0; a < 5; a++) {
        for (b = 0; b < 1; b++) {
            printf("Cima Direita\n");
        }
    }
}

int main() {

    printf("Movimento da Torre:\n");
    torre(5);

    printf("\nMovimento do Bispo:\n");
    bispoRec(5);

    printf("\nMovimento da Rainha:\n");
    rainha(8);

    cavalo();

    bispoLoops();

    // Tabuleiro 10x10
    printf("\nTabuleiro de Batalha Naval:\n");

    int tabuleiro[10][10];
    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Navio horizontal (linha 1, colunas 1 a 3)
    tabuleiro[1][1] = 3;
    tabuleiro[1][2] = 3;
    tabuleiro[1][10] = 3; 

    // Navio vertical
    tabuleiro[2][5] = 3;
    tabuleiro[3][5] = 3;
    tabuleiro[4][5] = 3;

    // Diagonal ↘
    tabuleiro[5][5] = 3;
    tabuleiro[6][6] = 3;
    tabuleiro[7][7] = 3;

    // Diagonal ↙
    tabuleiro[3][6] = 3;
    tabuleiro[4][5] = 3;
    tabuleiro[5][4] = 3;

    // tabuleiro
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
