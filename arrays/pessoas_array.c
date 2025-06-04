#include <stdio.h>
#include <stdlib.h>

int main()
{
    typedef struct pessoas
    {
        int nascimento;
        char nome[50];
        float peso, altura;

    }pessoa;
    int i;
    pessoa vet[2];

    for ( i = 0; i < 2; i++)
    {
        printf("Nome: ");
        
        scanf("%s",&vet[i].nome);
        
        printf("Data nascimento: ");
        scanf("%d",&vet[i].nascimento);
        printf("Peso: ");
        scanf("%f",&vet[i].peso);
        printf("Altura: ");
        scanf("%f",&vet[i].altura);
    }
    
    for ( i = 0; i < 2; i++)
    {
        printf("Nome: %s\n",vet[i].nome);
        printf("Data nascimento: %d\n",vet[i].nascimento);
        printf("Peso: %.2f\n",vet[i].peso);
        printf("Altura: %.2f",vet[i].altura);


    }
    

    return 0;
}
