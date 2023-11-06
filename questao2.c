#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Jogador {
    char nome[31];
    char posicao;
    int forca;
};

int calcularForca(struct Jogador time[11]) {
    int forcaTotal = 0;

    for (int i = 0; i < 11; i++) {
        if (time[i].posicao == 'G') {
            forcaTotal += 8 * time[i].forca;
        } else if (time[i].posicao == 'L') {
            forcaTotal += 10 * time[i].forca;
        } else if (time[i].posicao == 'Z') {
            forcaTotal += 5 * time[i].forca;
        } else if (time[i].posicao == 'V') {
            forcaTotal += 8 * time[i].forca;
        } else if (time[i].posicao == 'M') {
            forcaTotal += 11 * time[i].forca;
        } else if (time[i].posicao == 'A') {
            forcaTotal += 12 * time[i].forca;
        }
    }

    return forcaTotal;
}

void imprimirForcaDoTime(char nomeDoTime[31], int forcaTotal) {
    double forcaDoTime = (double)forcaTotal / 100;
    printf("%s: %.2lf de forca\n", nomeDoTime, forcaDoTime);
}

int main() {
    setlocale(LC_ALL, "C");

    char nomeDoTime1[31];
    char nomeDoTime2[31];
    struct Jogador time1[11];
    struct Jogador time2[11];

    fgets(nomeDoTime1, sizeof(nomeDoTime1), stdin);
    nomeDoTime1[strcspn(nomeDoTime1, "\n")] = '\0';

    for (int i = 0; i < 11; i++) {
        scanf("%30[^;]; %c; %d", time1[i].nome, &time1[i].posicao, &time1[i].forca);
        getchar();
    }

    fgets(nomeDoTime2, sizeof(nomeDoTime2), stdin);
    nomeDoTime2[strcspn(nomeDoTime2, "\n")] = '\0';

    for (int i = 0; i < 11; i++) {
        scanf("%30[^;]; %c; %d", time2[i].nome, &time2[i].posicao, &time2[i].forca);
        getchar();
    }

    int forcaTotalTime1 = calcularForca(time1);
    int forcaTotalTime2 = calcularForca(time2);

    imprimirForcaDoTime(nomeDoTime1, forcaTotalTime1);
    imprimirForcaDoTime(nomeDoTime2, forcaTotalTime2);

    if (forcaTotalTime1 > forcaTotalTime2) {
        printf("%s eh mais forte\n", nomeDoTime1);
    } else if (forcaTotalTime2 > forcaTotalTime1) {
        printf("%s eh mais forte\n", nomeDoTime2);
    } else {
        printf("Os times tem a mesma força\n");
    }

    return 0;
}
