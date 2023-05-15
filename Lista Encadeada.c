//LISTA ENCADEADA 
//FACULDADE IMACULADA CONCEI��O DO RECIFE
//AN�LISE E DESENVOLVIMENTO DE SISTEMAS 
//TURMA: 302 B - NOITE 
//PROFESSOR: MAYRTON
/*Com base na solicita��o do professor, afim de construir uma estrutura com lista
encadeada, tomei a liberdade de demonstrar o que foi aprendido, num contexto onde,
o poss�vel cliente ser� uma locadora de ve�culos*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estrutura para armazenar informa��es do carro
typedef struct carro {
    char nome[20];
    float preco;
} Carro;

// Estrutura para a lista encadeada
typedef struct no {
    Carro info;
    struct no* prox;
} No;

// Cria uma lista vazia
No* criarLista() {
    return NULL;
}

// Insere um elemento no final da lista
No* inserirElemento(No* lista, Carro c) {
    No* novo = (No*) malloc(sizeof(No));
    novo->info = c;
    novo->prox = NULL;

    if (lista == NULL) {
        return novo;
    }

    No* atual = lista;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;
    return lista;
}

// Insere um elemento em uma posi��o espec�fica da lista
No* inserirElementoID(No* lista, Carro c, int posicao) {
    if (posicao < 0) {
        printf("Posi��o inv�lida!\n");
        return lista;
    }

    No* novo = (No*) malloc(sizeof(No));
    novo->info = c;

    if (posicao == 0) {
        novo->prox = lista;
        return novo;
    }

    if (lista == NULL) {
        printf("Posi��o inv�lida!\n");
        return lista;
    }

    No* atual = lista;
    int i;
    for (i = 0; i < posicao - 1 && atual->prox != NULL; i++) {
        atual = atual->prox;
    }
    if (i != posicao - 1) {
        printf("Posi��o inv�lida!\n");
        return lista;
    }
    novo->prox = atual->prox;
    atual->prox = novo;
    return lista;
}

// Insere um elemento no in�cio da lista
No* inserirElementoInicio(No* lista, Carro c) {
    No* novo = (No*) malloc(sizeof(No));
    novo->info = c;
    novo->prox = lista;
    return novo;
}

// Apresenta todas as informa��es dos elementos da lista
void listarElementos(No* lista) {
    if (lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    No* atual = lista;
    while (atual != NULL) {
        printf("%s - Pre�o por di�ria: R$ %.2f\n", atual->info.nome, atual->info.preco);
        atual = atual->prox;
    }
}

// Remove um elemento pela posi��o na lista
No* removerElemento(No* lista, int posicao) {
    if (posicao < 0) {
        printf("Posi��o inv�lida!\n");
        return lista;
    }

    if (lista == NULL) {
        printf("Posi��o inv�lida!\n");
        return lista;
    }

    No* atual = lista;
    No* anterior = NULL;
    int i;
    for (i = 0; i < posicao && atual != NULL; i++) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) {
        printf("Posi��o inv�lida!\n");
        return lista;
}
if (anterior == NULL) {
    lista = atual->prox;
} else {
    anterior->prox = atual->prox;
}
free(atual);
return lista;
}

// Remove um elemento pelo nome na lista
No* removerElementoNome(No* lista, char nome[]) {
if (lista == NULL) {
printf("Lista vazia!\n");
return lista;
}
No* atual = lista;
No* anterior = NULL;
int posicao = 0;
while (atual != NULL && strcmp(atual->info.nome, nome) != 0) {
    anterior = atual;
    atual = atual->prox;
    posicao++;
}
if (atual == NULL) {
    printf("Carro n�o encontrado!\n");
    return lista;
}
if (anterior == NULL) {
    lista = atual->prox;
} else {
    anterior->prox = atual->prox;
}
free(atual);
printf("Carro %s removido da posi��o %d\n", nome, posicao);
return lista;
}

// Altera os campos de um elemento da lista
No* atualizar(No* lista, char nome[], float preco) {
if (lista == NULL) {
printf("Lista vazia!\n");
return lista;
}
No* atual = lista;
int posicao = 0;
while (atual != NULL && strcmp(atual->info.nome, nome) != 0) {
    atual = atual->prox;
    posicao++;
}
if (atual == NULL) {
    printf("Carro n�o encontrado!\n");
    return lista;
}
atual->info.preco = preco;
printf("Carro %s atualizado com sucesso!\n", nome);
return lista;
}

// Encontra e retorna o elemento pesquisado
No* buscarElemento(No* lista, char nome[]) {
if (lista == NULL) {
printf("Lista vazia!\n");
return NULL;
}
No* atual = lista;
while (atual != NULL && strcmp(atual->info.nome, nome) != 0) {
    atual = atual->prox;
}
if (atual == NULL) {
    printf("Carro n�o encontrado!\n");
    return NULL;
}
printf("Carro encontrado: %s - Pre�o por di�ria: R$ %.2f\n", atual->info.nome, atual->info.preco);
return atual;
}

// Retorna a quantidade de elementos da lista
int tamanho(No* lista) {
int tamanho = 0;
No* atual = lista;
while (atual != NULL) {
tamanho++;
atual = atual->prox;
}
return tamanho;
}

// Apaga todos os elementos e a lista
No* excluirLista(No* lista) {
No* atual = lista;
while (atual != NULL) {
No* temp = atual;
atual = atual->prox;
free(temp);
}
return NULL;
}
/*Por fim, temos a fun��o principal (MAIN) que ir� chamar todas as fun��es 
declaradas. Nesse contexto, a fun��o ir� retornar uma lista de possibilidades, onde
o usu�rio ir� determinar o que gostaria de realizar no sistemas, por isso, tomei a 
liberdade de implementar a estrutura Swit/Case ao final.*/
int main() {
	setlocale(LC_ALL,"portuguese");
No* lista = criarLista();
int opcao;
do {
    printf("------- LOCADORA DE VE�CULOS ------");
    printf("\n\n-----------------------------------\n");
    printf("1. Inserir carro no final da lista\n");
    printf("2. Inserir carro em uma posi��o espec�fica da lista\n");
    printf("3. Inserir carro no in�cio da lista\n");
    printf("4. Listar carros da locadora\n");
        printf("5. Remover carro pela posi��o na lista\n");
    printf("6. Remover carro pelo nome\n");
    printf("7. Atualizar informa��es de um carro\n");
    printf("8. Buscar um carro pelo nome\n");
    printf("9. Mostrar tamanho da lista\n");
    printf("10. Excluir todos os carros da lista\n");
    printf("11. Sair\n");
    printf("Digite sua op��o: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: {
            Carro c;
            printf("Digite o nome do carro: ");
            scanf("%s", c.nome);
            printf("Digite o pre�o por di�ria do carro: ");
            scanf("%f", &c.preco);
            lista = inserirElemento(lista, c);
            break;
        }
        case 2: {
            Carro c;
            int posicao;
            printf("Digite o nome do carro: ");
            scanf("%s", c.nome);
            printf("Digite o pre�o por di�ria do carro: ");
            scanf("%f", &c.preco);
            printf("Digite a posi��o em que o carro ser� inserido: ");
            scanf("%d", &posicao);
            lista = inserirElementoID(lista, c, posicao);
            break;
        }
        case 3: {
            Carro c;
            printf("Digite o nome do carro: ");
            scanf("%s", c.nome);
            printf("Digite o pre�o por di�ria do carro: ");
            scanf("%f", &c.preco);
            lista = inserirElementoInicio(lista, c);
            break;
        }
        case 4: {
            listarElementos(lista);
            break;
        }
        case 5: {
            int posicao;
            printf("Digite a posi��o do carro a ser removido: ");
            scanf("%d", &posicao);
            lista = removerElemento(lista, posicao);
            break;
        }
        case 6: {
            char nome[50];
            printf("Digite o nome do carro a ser removido: ");
            scanf("%s", nome);
            lista = removerElementoNome(lista, nome);
            break;
        }
        case 7: {
            char nome[50];
            float preco;
            printf("Digite o nome do carro a ser atualizado: ");
            scanf("%s", nome);
            printf("Digite o novo pre�o por di�ria do carro: ");
            scanf("%f", &preco);
            lista = atualizar(lista, nome, preco);
            break;
        }
        case 8: {
            char nome[50];
            printf("Digite o nome do carro a ser buscado: ");
            scanf("%s", nome);
            buscarElemento(lista, nome);
            break;
        }
        case 9: {
            int tam = tamanho(lista);
            printf("Tamanho da lista: %d\n", tam);
            break;
        }
        case 10: {
            lista = excluirLista(lista);
            printf("Lista de carros exclu�da com sucesso!\n");
            break;
        }
        case 11: {
            printf("Saindo...\n");
            lista = excluirLista(lista);
            break;
        }
        default: {
            printf("Op��o inv�lida!\n");
            break;
        }
    }
} while (opcao != 11);

return 0;
}
