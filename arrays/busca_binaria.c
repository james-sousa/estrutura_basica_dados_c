#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int vet[],int tam,int num){
    int ini = 0;
    int fim = tam - 1;
    while (ini <= fim)
    {
        int meio = (ini + fim) / 2;
        if (num == vet[meio])
        {
            return meio;
        }else
        {
            if (num > vet[meio])
            {
                ini = meio + 1;
            }else
            {
                fim = meio - 1;
            }
            
            
        }
        
        
    }

    return -1;
    
}

int main(){
    int vet_test[] = {1, 3, 4, 55, 104, 222, 229, 300};
    int tam = sizeof(vet_test)/sizeof(int);
    int num = 222;
    printf("%d\n", buscaBinaria(vet_test, tam,num));
}