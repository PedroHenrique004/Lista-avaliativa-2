#include <stdio.h>
#include <string.h>

int main() {
    int vetorA[16];
    int vetorB[16];
    int matriz[4][4];
    char operacao[10];

    for (int i = 0; i < 16; i++) {
        scanf("%d", &vetorA[i]);
    }

    for (int i = 0; i < 16; i++) {
        scanf("%d", &vetorB[i]);
    }

    scanf("%s", operacao);

    if (strcmp(operacao, "soma") == 0) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                matriz[i][j] = vetorA[i] + vetorB[j];
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                printf("%4d", matriz[i][j]);
            }
            printf("\n");
        }
    } else if (strcmp(operacao, "sub") == 0) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                matriz[i][j] = vetorA[i * 4 + j] - vetorB[i * 4 + j];
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                printf("%4d", matriz[i][j]);
            }
            printf("\n");
        }
    } else if (strcmp(operacao, "mult") == 0) {
        for (int i = 0; i < 4; i++) {
          for (int j = 0; j < 4; j++) {
            matriz[i][j] = 0;
               for (int k = 0; k < 4; k++) {
                     matriz[i][j] += vetorA[i * 4 + k] * vetorB[k * 4 + j];
               }
            }
         }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                printf("%4d", matriz[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
