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
// usando for e while juntos com break e continue
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

// outra versao do bispo com dois for
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

    // torre anda 5 casas pra direita
    printf("Movimento da Torre:\n");
    torre(5);

    // bispo recursivo
    printf("\nMovimento do Bispo:\n");
    bispoRec(5);

    // rainha anda 8 pra esquerda
    printf("\nMovimento da Rainha:\n");
    rainha(8);

    // cavalo em L
    cavalo();

    // bispo com for dentro de for
    bispoLoops();

    return 0;
}
