#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,m;
    n = 2;
    m = 2;
    int mat[n][m];
    int soma = 0;

    printf("\nDigite valor para os elementos da matriz\n");
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < m; j++)
        {
            printf("\nElemento[%d][%d] = ", i,j);
            scanf("%d", &mat[i][j]);
        }
        
    }
    
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < m; j++)
        {
            soma = soma + mat[i][j];
        }
        
    }
    printf("Soma da matriz: %d", soma);

    return 0;
}
