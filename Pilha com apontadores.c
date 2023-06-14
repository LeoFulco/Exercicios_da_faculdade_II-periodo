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

// Fun��o para criar uma nova pilha vazia
void criarPilha(Pilha* pilha) {
    pilha->topo = NULL;
}

// Fun��o que verifica se a pilha est� vazia
int ehVazia(Pilha* pilha) {
    return (pilha->topo == NULL);
}

// Fun��o para adicionar um jogo em promo��o no topo da pilha
void push(Pilha* pilha, const char* titulo, float preco) {
    // Cria um novo n� e atribui os valores do jogo
    Node* novoNo = (Node*)malloc(sizeof(Node));
    strcpy(novoNo->titulo, titulo);
    novoNo->preco = preco;
    
    // O novo n� aponta para o antigo topo da pilha
    novoNo->prox = pilha->topo;
    
    // O topo da pilha � atualizado para o novo n�
    pilha->topo = novoNo;
}

// Fun��o para remover e retornar o jogo do topo da pilha
void pop(Pilha* pilha) {
    // Verifica se a pilha est� vazia
    if (ehVazia(pilha)) {
        printf("A lista de jogos em promo��o est� vazia. N�o � poss�vel remover jogos.\n");
        return;
    }
    
    // Armazena o ponteiro para o n� do topo atual
    Node* noRemovido = pilha->topo;
    
    // Atualiza o topo para o pr�ximo n�
    pilha->topo = pilha->topo->prox;
    
    // Liberei a mem�ria do n� removido
    free(noRemovido);
}

// Fun��o para obter o jogo do topo da pilha sem remov�-lo
void verTopo(Pilha* pilha) {
    // Verifiquei se a pilha estava vazia
    if (ehVazia(pilha)) {
        printf("A lista de jogos em promo��o est� vazia. N�o h� jogos no topo.\n");
        return;
    }
    
    // Precisei visualizar o jogo do topo atual
    printf("Jogo em promo��o: %s\n", pilha->topo->titulo);
    printf("Pre�o: R$ %.2f\n", pilha->topo->preco);
}

// Fun��o para excluir todos os jogos da lista de promo��es
void excluirPilha(Pilha* pilha) {
    while (!ehVazia(pilha)) {
        pop(pilha);
    }
}

int main() {
	setlocale(LC_ALL, "portuguese");
    
	Pilha listaPromocoes;
    criarPilha(&listaPromocoes);
    
    // Adicionando jogos em promo��o � lista
    push(&listaPromocoes, "The Witcher 3: Wild Hunt", 59.99);
    push(&listaPromocoes, "Assassin's Creed Valhalla", 49.99);
    push(&listaPromocoes, "FIFA 23", 39.99);
    
    // Exibindo o jogo em promo��o no topo da pilha
    printf("Jogo atual em promo��o:\n");
    verTopo(&listaPromocoes);
    printf("\n");
    
    // Removendo o jogo do topo da pilha
    printf("Removendo o jogo do topo da lista de promo��es...\n");
    pop(&listaPromocoes);
    printf("\n");
    
    // Exibindo o novo jogo em promo��o no topo da pilha
    printf("Novo jogo em promo��o:\n");
    verTopo(&listaPromocoes);
    printf("\n");
    
    // Limpando a lista de promo��es
    printf("Limpando a lista de jogos em promo��o...\n");
    excluirPilha(&listaPromocoes);
    
    // Verificando se a lista de promo��es estava realmente vazia
    if (ehVazia(&listaPromocoes)) {
        printf("A lista de jogos em promo��o est� vazia.\n");
    } else {
        printf("A lista de jogos em promo��o n�o est� vazia.\n");
    }
    
    return 0;
}

