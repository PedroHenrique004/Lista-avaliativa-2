#include <stdio.h>

int main(){
   int matrizA[16];
   int  matrizB[16];
   char operacao;

   for(int i = 0; i <= 15; i++){
        scanf("%d", &matrizA[i]);
   }

   for(int j = 0; j <= 15; j++){
        scanf("%d", &matrizB[j]);
   }

    for (int i = 0; i <= 15; i++)
    {
       printf("%d" , &matrizA[i]);
       printf(" ");
    }

    printf("\n");

    for (int i = 0; i <= 15; i++)
    {
       printf("%d", &matrizB[i]);
       printf(" ");
    }
    

   return 0;
}