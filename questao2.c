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

void imprimirForcaDoTime(char nomeTime[31], int forcaTotal) {
    double forcaDoTime = (double)forcaTotal / 100;
    printf("%s: %.2lf de forca\n", nomeTime, forcaDoTime);
}

char* verificarTimeMaisForte(struct Jogador time1[11], struct Jogador time2[11], char nomeTime1[31], char nomeTime2[31]) {
    int forcaTotalTime1 = calcularForca(time1);
    int forcaTotalTime2 = calcularForca(time2);

    if (forcaTotalTime1 > forcaTotalTime2) {
        return nomeTime1;
    } else if (forcaTotalTime2 > forcaTotalTime1) {
        return nomeTime2;
    } else {
        return "Os times tem a mesma força";
    }
}

int main() {
    setlocale(LC_ALL, "C");

    char nomeTime1[31];
    char nomeTime2[31];
    struct Jogador time1[11];
    struct Jogador time2[11];

    fgets(nomeTime1, sizeof(nomeTime1), stdin);
    nomeTime1[strcspn(nomeTime1, "\n")] = '\0';

    for (int i = 0; i < 11; i++) {
        scanf("%30[^;]; %c; %d", time1[i].nome, &time1[i].posicao, &time1[i].forca);
        getchar();
    }

    fgets(nomeTime2, sizeof(nomeTime2), stdin);
    nomeTime2[strcspn(nomeTime2, "\n")] = '\0';

    for (int i = 0; i < 11; i++) {
        scanf("%30[^;]; %c; %d", time2[i].nome, &time2[i].posicao, &time2[i].forca);
        getchar();
    }

    imprimirForcaDoTime(nomeTime1, calcularForca(time1));
    imprimirForcaDoTime(nomeTime2, calcularForca(time2));

    char* timeMaisForte = verificarTimeMaisForte(time1, time2, nomeTime1, nomeTime2);
    printf("%s eh mais forte\n", timeMaisForte);

    return 0;
}
