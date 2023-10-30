#include <stdio.h>

int main(){
    int valores[10];
    int num = 9;

    for (int i = 0; i <= num; i++){
        scanf("%d", &valores[i]);

    }

     for (int i = 0; i <= num - 1; i++){
        printf("%d ", valores[i]);
  
    }
    printf ("%d", valores[num]);

    printf("\n");
    num--;


    for (int i = 0; i = num + 1; i++) {

    
        for (int i =0; i <= num; i++){
                valores[i] = valores[i] + valores[i + 1];
            }

        for (int i = 0; i <= num - 1; i++){
                printf("%d ", valores[i]);
  
            }

        printf ("%d", valores[num]);

        printf("\n");
        num--;
    
    }
 
    return 0;
}
