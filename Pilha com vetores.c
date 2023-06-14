#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM_MAX 100 // Tamano m�ximo da minha pilha 



typedef struct {
    int topo;
    int elementos[TAM_MAX];
} Pilha;

// Fun��o para criar uma nova pilha, inicializando o topo como -1
void criarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

// Fun��o que verifica se a pilha est� vazia
int ehVazia(Pilha *pilha) {
    return (pilha->topo == -1);
}


// Fun��o para adicionar um elemento no topo da pilha
void push(Pilha *pilha, int valor) {
    if (pilha->topo == TAM_MAX - 1) {
        printf("A pilha est� cheia. N�o � poss�vel inserir mais elementos.\n");
        return;
    }
    // Incrementei o topo e inseri o elemento no topo da pilha
    pilha->elementos[++pilha->topo] = valor;
}

// Fun��o para remover e retornar o elemento do topo da pilha
int pop(Pilha *pilha) {
    if (ehVazia(pilha)) { // Precisei verificar se a pilha estava vazia
        printf("A pilha est� vazia. N�o � poss�vel remover elementos.\n");
        return -1;
    }
    // Retorna o elemento do topo e decrementa o topo
    return pilha->elementos[pilha->topo--];
}

// Fun��o para obter o elemento do topo da pilha sem remov�-lo
int verTopo(Pilha *pilha) {
    if (ehVazia(pilha)) { // Para isso precisava verificar se a pilha estava vazia
        printf("A pilha est� vazia. N�o h� elementos no topo.\n");
        return -1;
    }
     // Retorna o elemento do topo
    return pilha->elementos[pilha->topo];
}

// Fun��o para excluir todos os elementos da pilha, resetando o topo
void excluirPilha(Pilha *pilha) {
    pilha->topo = -1;
}

int main() {
	setlocale(LC_ALL, "portuguese");
    Pilha minhaPilha;
    criarPilha(&minhaPilha);
     // Inserindo elementos na pilha
    push(&minhaPilha, 10);
    push(&minhaPilha, 20);
    push(&minhaPilha, 30);
    
    // Imprimindo o topo da pilha
    printf("Topo da pilha: %d\n", verTopo(&minhaPilha));
    
    // Removendo um elemento da pilha
    pop(&minhaPilha);
    
    // Imprimindo o topo da pilha ap�s a remo��o
    printf("Topo da pilha ap�s remo��o: %d\n", verTopo(&minhaPilha));
    
    // Excluindo todos os elementos da pilha
    excluirPilha(&minhaPilha);
    // Por fim, verifiquei se a pilha estava realmente vazia
    if (ehVazia(&minhaPilha)) {
        printf("A pilha est� vazia.\n");
    } else {
        printf("A pilha n�o est� vazia.\n");
    }
    
    return 0;
}
