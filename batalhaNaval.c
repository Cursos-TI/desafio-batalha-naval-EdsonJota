#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // Inicializar o tabuleiro com 0 (água)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posicionar navios (valor 3)
    // Horizontal
    tabuleiro[1][1] = 3;
    tabuleiro[1][2] = 3;
    tabuleiro[1][3] = 3;

    // Vertical
    tabuleiro[2][5] = 3;
    tabuleiro[3][5] = 3;
    tabuleiro[4][5] = 3;

    // Diagonal ↘
    tabuleiro[5][5] = 3;
    tabuleiro[6][6] = 3;
    tabuleiro[7][7] = 3;

    // Diagonal ↙ (ajustado pra não bater no outro)
    tabuleiro[2][7] = 3;
    tabuleiro[3][6] = 3;
    tabuleiro[4][4] = 3;

    // Matrizes das habilidades (5x5)
    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // Cone (forma de V de cabeça pra baixo)
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if ((i == 0 && j == 2) ||
                (i == 1 && (j >= 1 && j <= 3)) ||
                (i == 2)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // Cruz (linha e coluna do meio)
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // Octaedro (losango com centro no meio)
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // Pontos de origem no tabuleiro
    int origemConeLinha = 1, origemConeCol = 1;
    int origemCruzLinha = 5, origemCruzCol = 5;
    int origemOctLinha = 7, origemOctCol = 7;

    // Aplicar as habilidades no tabuleiro com valor 5
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int li, co;

            // Cone
            li = origemConeLinha - 2 + i;
            co = origemConeCol - 2 + j;
            if (li >= 0 && li < TAM && co >= 0 && co < TAM) {
                if (cone[i][j] == 1 && tabuleiro[li][co] == 0) {
                    tabuleiro[li][co] = 5;
                }
            }

            // Cruz
            li = origemCruzLinha - 2 + i;
            co = origemCruzCol - 2 + j;
            if (li >= 0 && li < TAM && co >= 0 && co < TAM) {
                if (cruz[i][j] == 1 && tabuleiro[li][co] == 0) {
                    tabuleiro[li][co] = 5;
                }
            }

            // Octaedro
            li = origemOctLinha - 2 + i;
            co = origemOctCol - 2 + j;
            if (li >= 0 && li < TAM && co >= 0 && co < TAM) {
                if (octaedro[i][j] == 1 && tabuleiro[li][co] == 0) {
                    tabuleiro[li][co] = 5;
                }
            }
        }
    }

    // Mostrar o tabuleiro
    printf("\nTabuleiro Final:\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("~ ");
            } else if (tabuleiro[i][j] == 3) {
                printf("# ");
            } else if (tabuleiro[i][j] == 5) {
                printf("* ");
            } else {
                printf("? ");
            }
        }
        printf("\n");
    }

    return 0;
}
