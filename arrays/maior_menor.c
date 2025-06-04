#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,maior,menor,aux,vet[5];
    
    

    for ( i = 0; i < 5; i++)
    {
        printf("Digite um valor: ");
        scanf("%d", &vet[i]);
        if (i == 0)
        {
            maior = vet[i];
            menor = maior;
        }
        
        else if (maior < vet[i])
        {
            maior = vet[i];
        }
        else if (maior < menor)
        {
            menor = maior;
        }
        
        
    }
    
    for ( i = 0; i < 5; i++)
    {
        printf("Indice %d\n", i+1);
        printf("Numero: %d\n", vet[i]);
    }

    printf("Maior: %d\n",maior);
    printf("Menor: %d\n", menor);
    
    return 0;
}
