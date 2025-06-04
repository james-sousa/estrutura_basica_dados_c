#include <stdio.h>
#include <stdlib.h>
int main() {
    
    int i,vet[6];
    
    for (i = 0; i < 6; i++){
        printf("Digite um numero: ");
        scanf("%d", &vet[i]);
        
    }
    for (i = 0; i < 6; i++){
        printf("Indice %d \n", i+1);
        printf("Vetor[i] %d\n", vet[i]);
    }
    return 0;
}