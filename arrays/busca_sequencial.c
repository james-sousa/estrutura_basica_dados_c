#include <stdio.h>
#include <stdlib.h>

int buscaSequencial(int tam, int vet[], int num){
    int i;
    for ( i = 0; i < tam; i++)
    {
        if (vet[i] == num)
        {
            return vet[i];
        }
        
        
    }
    printf("Numero não encontrado");
    return -1;
}

int main()
{
    int vet_num[8] = {6,4,3,7,10,18,4,8};
    int n,result;
    printf("Informe o numero: ");
    scanf("%d",&n);
    result = buscaSequencial(8,vet_num,n);
    printf("%d",result);
    printf("\n");
    return 0;
}
