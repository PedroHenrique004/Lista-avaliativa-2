#include <stdio.h>
#include <locale.h>
#include <string.h>

#define tamanho 4

void lerMatriz(int matriz[tamanho][tamanho]) {
    for (int i = 0; i < tamanho; i++)
        for (int j = 0; j < tamanho; j++)
            scanf("%d", &matriz[i][j]);
}

void somar(int m1[tamanho][tamanho], int m2[tamanho][tamanho], int resultado[tamanho][tamanho]) {
    for (int i = 0; i < tamanho; i++)
        for (int j = 0; j < tamanho; j++)
            resultado[i][j] = m1[i][j] + m2[i][j];
}

void subtrair(int m1[tamanho][tamanho], int m2[tamanho][tamanho], int resultado[tamanho][tamanho]) {
    for (int i = 0; i < tamanho; i++)
        for (int j = 0; j < tamanho; j++)
            resultado[i][j] = m1[i][j] - m2[i][j];
}

void multiplicar(int m1[tamanho][tamanho], int m2[tamanho][tamanho], int resultado[tamanho][tamanho]) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < tamanho; k++)
                resultado[i][j] += m1[i][k] * m2[k][j];
        }
    }
}

void realizarOperacao(int matriz1[tamanho][tamanho], int matriz2[tamanho][tamanho], char operacao[5], int resultado[tamanho][tamanho]) {
    if (strcmp(operacao, "soma") == 0) {
        somar(matriz1, matriz2, resultado);
    } else if (strcmp(operacao, "sub") == 0) {
        subtrair(matriz1, matriz2, resultado);
    } else if (strcmp(operacao, "mult") == 0) {
        multiplicar(matriz1, matriz2, resultado);
    } else {
        printf("\nOperação desconhecida.\n");
    }
}

int main() {
    int matriz1[tamanho][tamanho]; 
    int matriz2[tamanho][tamanho]; 
    int resultado[tamanho][tamanho]; 
    char operacao[5]; 

    setlocale(LC_ALL, "Portuguese");
    lerMatriz(matriz1);
    lerMatriz(matriz2);
    scanf("%s", operacao);

    realizarOperacao(matriz1, matriz2, operacao, resultado);

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%4d", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}
