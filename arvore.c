#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dado;
    struct Node* esquerda;
    struct Node* direita;
} No;

// Criar um novo nó
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

// Inserir um nó na árvore
No* inserirNo(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->dado) {
        raiz->esquerda = inserirNo(raiz->esquerda, valor);
    } else if (valor > raiz->dado) {
        raiz->direita = inserirNo(raiz->direita, valor);
    }

    return raiz;
}

// Busca em pré-ordem
void buscaPreOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        buscaPreOrdem(raiz->esquerda);
        buscaPreOrdem(raiz->direita);
    }
}

// Busca em ordem
void buscaEmOrdem(No* raiz) {
    if (raiz != NULL) {
        buscaEmOrdem(raiz->esquerda);
        printf("%d ", raiz->dado);
        buscaEmOrdem(raiz->direita);
    }
}

// Busca em pós-ordem
void buscaPosOrdem(No* raiz) {
    if (raiz != NULL) {
        buscaPosOrdem(raiz->esquerda);
        buscaPosOrdem(raiz->direita);
        printf("%d ", raiz->dado);
    }
}

// Encontrar o nó com o menor valor 
No* encontrarMenor(No* raiz) {
    No* atual = raiz;
    while (atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

// Remover um nó
No* removerNo(No* raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }

    if (valor < raiz->dado) {
        raiz->esquerda = removerNo(raiz->esquerda, valor);
    } else if (valor > raiz->dado) {
        raiz->direita = removerNo(raiz->direita, valor);
    } else {
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        No* temp = encontrarMenor(raiz->direita);
        raiz->dado = temp->dado;
        raiz->direita = removerNo(raiz->direita, temp->dado);
    }

    return raiz;
}

// Função principal
int main() {
    No* raiz = NULL;
    int escolha, valor;

    do {
        
        printf("\n* * * MENU DE OPCOES * * *\n");
        printf("1. Incluir no\n");
        printf("2. Remover no\n");
        printf("3. Buscar pre-ordem\n");
        printf("4. Buscar em ordem\n");
        printf("5. Buscar pos-ordem\n");
        printf("0. Encerrar\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                // Incluir nó
                printf("Digite o valor a ser incluido: ");
                scanf("%d", &valor);
                raiz = inserirNo(raiz, valor);
                break;

            case 2:
                // Remover nó
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                raiz = removerNo(raiz, valor);
                break;

            case 3:
                // Buscar pré-ordem
                printf("Busca pre-ordem: ");
                buscaPreOrdem(raiz);
                printf("\n");
                break;

            case 4:
                // Buscar em ordem
                printf("Busca em ordem: ");
                buscaEmOrdem(raiz);
                printf("\n");
                break;

            case 5:
                // Buscar pós-ordem
                printf("Busca pos-ordem: ");
                buscaPosOrdem(raiz);
                printf("\n");
                break;

            case 0:
                // Encerrar o programa
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (escolha != 0);

    return 0;
}
