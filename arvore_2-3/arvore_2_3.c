#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int num;
}valor;




typedef struct no23{
    
    valor info1,info2;
    struct no23 *esq;
    struct no23 *meio;
    struct no23 *dir;
    int num_chaves;
}arvore23;

int ehfolha(arvore23 *No){
    int flag = 0;
    if(No != NULL){
        if (No->esq == NULL && No->meio == NULL && No->dir == NULL)
        {
            flag = 1;
        }
        
    }

    return flag;
}

void criaNo(arvore23 **No, valor info, arvore23 *esq, arvore23 *meio){

    *No = (arvore23 *)malloc(sizeof(arvore23));
    (*No)->info1 = info;
    (*No)->num_chaves = 1;
	(*No)->esq = esq;
	(*No)->meio = meio;
	(*No)->dir = NULL;
}

void adicionaNo(arvore23 **No, valor info, arvore23 *filho){
    if (info.num > (*No)->info1.num)
    {
        (*No)->info2 = info;
        (*No)->dir = filho;
    }else
    {
        (*No)->info2 = (*No)->info1;
        (*No)->info1 = info;
        (*No)->dir = (*No)->meio;
        (*No)->meio = filho;
    }
    
    (*No)->num_chaves = 2;
}

void quebraNo(arvore23 **No, valor info, valor *sobe, arvore23 **No_maior, arvore23 *filho){
    if (info.num < (*No)->info1.num)
    {
        *sobe = (*No)->info1;
		(*No)->info1 = info;
		criaNo(No_maior,(*No)->info2,(*No)->meio,(*No)->dir);
		(*No)->meio = filho;
    }else if (info.num < (*No)->info2.num)
    {
        *sobe = info;
        criaNo(No_maior,(*No)->info2,filho,(*No)->dir);
    }else
    {
        *sobe = (*No)->info2;
		criaNo(No_maior,info,(*No)->dir,filho);
    }
    
    (*No)->dir = NULL;
	(*No)->num_chaves = 1;
    
}


arvore23 *inserirRec(arvore23 *No, valor info, valor *sobe, arvore23 **novo) {
    if (No == NULL) {
        criaNo(novo, info, NULL, NULL);
        *sobe = info;
        return NULL;
    }

    if (ehfolha(No)) {
        if (No->num_chaves == 1) {
            adicionaNo(&No, info, NULL);
            return NULL;
        } else {
            arvore23 *No_maior = NULL;
            quebraNo(&No, info, sobe, &No_maior, NULL);
            *novo = No_maior;
            return No;
        }
    }

    arvore23 *ret = NULL;
    if (info.num < No->info1.num)
        ret = inserirRec(No->esq, info, sobe, novo);
    else if (No->num_chaves == 1 || info.num < No->info2.num)
        ret = inserirRec(No->meio, info, sobe, novo);
    else
        ret = inserirRec(No->dir, info, sobe, novo);

    if (ret == NULL) return NULL;

    if (No->num_chaves == 1) {
        if (ret == No->esq)
            adicionaNo(&No, *sobe, *novo);
        else
            adicionaNo(&No, *sobe, *novo);
        return NULL;
    } else {
        arvore23 *No_maior = NULL;
        quebraNo(&No, *sobe, sobe, &No_maior, *novo);
        *novo = No_maior;
        return No;
    }
}

arvore23 *inserir(arvore23 *Raiz, int num) {
    valor info, sobe;
    arvore23 *novo = NULL, *ret = NULL;
    info.num = num;

    ret = inserirRec(Raiz, info, &sobe, &novo);

    if (ret != NULL) {
        arvore23 *novaRaiz;
        criaNo(&novaRaiz, sobe, ret, novo);
        return novaRaiz;
    }
    return Raiz ? Raiz : novo;
}


void imprime_(valor v) {
    printf("%d ", v.num);
}

void imprimirInOrder(arvore23 *Raiz) {
    if (Raiz != NULL) {
        imprimirInOrder(Raiz->esq);
        imprime_(Raiz->info1);
        imprimirInOrder(Raiz->meio);
        if (Raiz->num_chaves == 2)
            imprime_(Raiz->info2);
        imprimirInOrder(Raiz->dir);
    }
}

/*---------------- Impressão hierárquica ----------------*/

void imprimirHierarquia(arvore23 *Raiz, int nivel) {
    if (Raiz == NULL) return;

    // imprime subárvore direita primeiro (para parecer visualmente uma árvore de lado)
    imprimirHierarquia(Raiz->dir, nivel + 1);

    // imprime recuo para o nível atual
    for (int i = 0; i < nivel; i++)
        printf("    "); // 4 espaços por nível

    // imprime o nó atual
    if (Raiz->num_chaves == 1)
        printf("[%d]\n", Raiz->info1.num);
    else
        printf("[%d | %d]\n", Raiz->info1.num, Raiz->info2.num);

    // imprime filhos à esquerda
    imprimirHierarquia(Raiz->meio, nivel + 1);
    imprimirHierarquia(Raiz->esq, nivel + 1);
}


// Libera nó
void liberaNo(arvore23** no) {
    if (*no) free(*no);
    *no = NULL;
}

/*----------------------- Função de balanceamento -----------------------*/

// Corrige nó que ficou com 0 chaves
int balancear(arvore23** raiz) {
    arvore23* no = *raiz;

    // Caso raiz tenha apenas um filho e esteja vazia
    if (no->num_chaves == 0) {
        arvore23* filho = no->esq ? no->esq : no->meio ? no->meio : no->dir;
        free(no);
        *raiz = filho;
        return 1;
    }

    return 0;
}

/*----------------------- Remove menor elemento -----------------------*/

int removeMenor(arvore23** raiz, valor* menor) {
    if (!*raiz) return 0;

    if ((*raiz)->esq) {
        int desb = removeMenor(&(*raiz)->esq, menor);
        if (desb) return balancear(raiz);
        return 0;
    }

    // Encontrou o menor (nó folha)
    *menor = (*raiz)->info1;
    if ((*raiz)->num_chaves == 2) {
        (*raiz)->info1 = (*raiz)->info2;
        (*raiz)->num_chaves = 1;
        return 0;
    } else {
        liberaNo(raiz);
        return 1;
    }
}

/*----------------------- Função principal de remoção -----------------------*/

int remover(arvore23** raiz, int valo) {
    if (!*raiz) return 0;

    arvore23* no = *raiz;
    int desb = 0;

    // Caso 1: valor encontrado
    if (no->info1.num == valo || (no->num_chaves == 2 && no->info2.num == valo)) {

        // Caso folha
        if (ehfolha(no)) {
            if (no->num_chaves == 2) {
                if (valo == no->info1.num)
                    no->info1 = no->info2;
                no->num_chaves = 1;
                return 0;
            } else {
                liberaNo(raiz);
                return 1; // Nó ficou vazio
            }
        }

        // Caso interno → substitui pelo menor da subárvore direita correspondente
        valor menor;
        if (valo == no->info1.num)
            desb = removeMenor(&no->meio, &menor), no->info1 = menor;
        else
            desb = removeMenor(&no->dir, &menor), no->info2 = menor;

        if (desb) return balancear(raiz);
        return 0;
    }

    // Caso 2: busca recursiva
    if (valo < no->info1.num)
        desb = remover(&no->esq, valo);
    else if (no->num_chaves == 2 && valo > no->info2.num)
        desb = remover(&no->dir, valo);
    else
        desb = remover(&no->meio, valo);

    // Caso 3: ajusta se algum filho desbalanceou
    if (desb) return balancear(raiz);
    return 0;
}

void imprimir(arvore23 *Raiz){

	if(Raiz != NULL){

		imprimir(Raiz->esq);
		imprime_(Raiz->info1);
		imprimir(Raiz->meio);

		if(Raiz->num_chaves == 2){
			imprime_(Raiz->info2);
		}
		imprimir(Raiz->dir);
	}
}


int main() {
    arvore23* raiz = NULL;
    int opcao, num;

    do {
        printf("\n--- ÁRVORE 2-3 ---\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Imprimir (em ordem)\n");
        printf("4 - Mostrar hierarquia\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o número a inserir: ");
                scanf("%d", &num);
                raiz = inserir(raiz, num);
                break;
            case 2:
                printf("Digite o número a remover: ");
                scanf("%d", &num);
                remover(&raiz, num);
                break;
            case 3:
                printf("\nÁrvore em ordem: ");
                imprimirInOrder(raiz);
                printf("\n");
                break;
            case 4:
                printf("\n--- Estrutura da árvore ---\n");
                imprimirHierarquia(raiz, 0);
                printf("---------------------------\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}