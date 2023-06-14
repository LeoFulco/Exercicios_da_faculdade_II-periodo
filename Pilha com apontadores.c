#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Node {
    char titulo[50];
    float preco;
    struct Node* prox;
} Node;

typedef struct {
    Node* topo;
} Pilha;

// Função para criar uma nova pilha vazia
void criarPilha(Pilha* pilha) {
    pilha->topo = NULL;
}

// Função que verifica se a pilha está vazia
int ehVazia(Pilha* pilha) {
    return (pilha->topo == NULL);
}

// Função para adicionar um jogo em promoção no topo da pilha
void push(Pilha* pilha, const char* titulo, float preco) {
    // Cria um novo nó e atribui os valores do jogo
    Node* novoNo = (Node*)malloc(sizeof(Node));
    strcpy(novoNo->titulo, titulo);
    novoNo->preco = preco;
    
    // O novo nó aponta para o antigo topo da pilha
    novoNo->prox = pilha->topo;
    
    // O topo da pilha é atualizado para o novo nó
    pilha->topo = novoNo;
}

// Função para remover e retornar o jogo do topo da pilha
void pop(Pilha* pilha) {
    // Verifica se a pilha está vazia
    if (ehVazia(pilha)) {
        printf("A lista de jogos em promoção está vazia. Não é possível remover jogos.\n");
        return;
    }
    
    // Armazena o ponteiro para o nó do topo atual
    Node* noRemovido = pilha->topo;
    
    // Atualiza o topo para o próximo nó
    pilha->topo = pilha->topo->prox;
    
    // Liberei a memória do nó removido
    free(noRemovido);
}

// Função para obter o jogo do topo da pilha sem removê-lo
void verTopo(Pilha* pilha) {
    // Verifiquei se a pilha estava vazia
    if (ehVazia(pilha)) {
        printf("A lista de jogos em promoção está vazia. Não há jogos no topo.\n");
        return;
    }
    
    // Precisei visualizar o jogo do topo atual
    printf("Jogo em promoção: %s\n", pilha->topo->titulo);
    printf("Preço: R$ %.2f\n", pilha->topo->preco);
}

// Função para excluir todos os jogos da lista de promoções
void excluirPilha(Pilha* pilha) {
    while (!ehVazia(pilha)) {
        pop(pilha);
    }
}

int main() {
	setlocale(LC_ALL, "portuguese");
    
	Pilha listaPromocoes;
    criarPilha(&listaPromocoes);
    
    // Adicionando jogos em promoção à lista
    push(&listaPromocoes, "The Witcher 3: Wild Hunt", 59.99);
    push(&listaPromocoes, "Assassin's Creed Valhalla", 49.99);
    push(&listaPromocoes, "FIFA 23", 39.99);
    
    // Exibindo o jogo em promoção no topo da pilha
    printf("Jogo atual em promoção:\n");
    verTopo(&listaPromocoes);
    printf("\n");
    
    // Removendo o jogo do topo da pilha
    printf("Removendo o jogo do topo da lista de promoções...\n");
    pop(&listaPromocoes);
    printf("\n");
    
    // Exibindo o novo jogo em promoção no topo da pilha
    printf("Novo jogo em promoção:\n");
    verTopo(&listaPromocoes);
    printf("\n");
    
    // Limpando a lista de promoções
    printf("Limpando a lista de jogos em promoção...\n");
    excluirPilha(&listaPromocoes);
    
    // Verificando se a lista de promoções estava realmente vazia
    if (ehVazia(&listaPromocoes)) {
        printf("A lista de jogos em promoção está vazia.\n");
    } else {
        printf("A lista de jogos em promoção não está vazia.\n");
    }
    
    return 0;
}

