#include <stdio.h>
#include <stdlib.h>

int main()
{
    typedef struct carros {
        char marca[50];
        int fabricacao;
        char cor[30];
        float preco;
    }carro;
    int i = 5;
    carro vet[5];
    for ( i = 0; i < 5; i++)
    {
        printf("Digite a marca do carro: ");
        scanf("%s",vet[i].marca);
        printf("Ano fabricação: ");
        scanf("%d",&vet[i].fabricacao);
        printf("Cor: ");
        scanf("%s",vet[i].cor);
        printf("Preço: ");
        scanf("%f",&vet[i].preco);
    }
    
    for ( i = 0; i < 5; i++)
    {
        printf("Marca: %s\n",vet[i].marca);
        printf("Fabricação: %d\n",vet[i].fabricacao);
        printf("Cor: %s\n",vet[i].cor);
        printf("Preço: %.2f\n",vet[i].preco);

    }
    


    return 0;
}
