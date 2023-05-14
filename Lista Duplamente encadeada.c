//O CÓDIGO ABAIXO É PARA A DISCIPLINA DE ESTRUTURA DE DADOS 
//PROFESSOR MAYRTON TURMA: 302B NOITE
//ALUNO: LEANDRESSON CLEITON MOREIRA FULCO

//DEIXAREI TODO O CÓDIGO COMENTADO E PEÇO QUE CONSIDERE O COMENTÁRIO, SEGUIDO
//DO CÓDIGO (COMENTÁRIO ACIMA, CÓDIGO ABAIXO).

/*Nessa primeira parte fiz a declaração das bibliotecas que utilizarei no código. 
conforme os padões estudados de boas práticas.
stdio.h é a biblioteca padrão de entrada e saída.
stdlib.h é a biblioteca padrão que contém funções de alocação de memória, e 
string.h contém funções de manipulação de strings.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Aqui abaixo comecei a criar a estrutura pensando numa loja de Brinquedo, que contém 
	os campos: id, nome, preco, anterior e proximo.
    Pensei em anterior e proximo como sendo os ponteiros para outros elementos 
	da lista, permitindo assim que a lista seja duplamente encadeada.*/

typedef struct brinquedo {
    int id;
    char nome[50];
    float preco;
    struct brinquedo* prox;
    struct brinquedo* ant;
} Brinquedo;

/*Aqui abaixo comecei a criar a estrutura Lista, que contém os campos primeiro, ultimo e tamanho.
  Deixando claro que (primeiro e ultimo) são ponteiros para o primeiro e último elementos da lista,
  respectivamente.
  (tamanho) é a variável que usei para guardar o número de elementos da lista.*/

typedef struct lista {
    Brinquedo* primeiro;
    Brinquedo* ultimo;
    int tamanho;
} Lista;

/* Seguindo adiante utilizei esta função recebe um ponteiro para a lista e inicializa seus campos.
Como ela nao precisa retornar nada, então utilizei como VOID*/

void criarLista(Lista* lista) {
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->tamanho = 0;
}

/*Agora precisei implementar a função que insere um novo elemento no final da lista. 
Essa função vai tem como objetivo receber um ponteiro para a lista, o id, o nome e o preco
do novo elemento. Onde primeiro a função separa um espaço de memória para um novo elemento e
preenche seus campos. (utilizei o MALLOC para isso).
Depois a função verifica se a lista está vazia. Se estiver, o novo elemento 
é o primeiro e último da lista. Se não estiver, o novo elemento é adicionado ao final da lista.*/

void inserirElemento(Lista* lista, int id, char nome[], float preco) {
    Brinquedo* novoBrinquedo = (Brinquedo*) malloc(sizeof(Brinquedo));
    novoBrinquedo->id = id;
    strcpy(novoBrinquedo->nome, nome);
    novoBrinquedo->preco = preco;
    novoBrinquedo->prox = NULL;

    if (lista->primeiro == NULL) {
        lista->primeiro = novoBrinquedo;
        lista->ultimo = novoBrinquedo;
        novoBrinquedo->ant = NULL;
    } else {
        lista->ultimo->prox = novoBrinquedo;
        novoBrinquedo->ant = lista->ultimo;
        lista->ultimo = novoBrinquedo;
    }

    lista->tamanho++;
}

/*Agora eu precisava inserir um novo elemento numa posição mais específica da lista
por isso declarei a função (inserirElementoID) que terá a função de  
receber um ponteiro para a lista, indicando a posicao onde o novo elemento 
será inserido, o id, o nome e o preco desse novo elemento. 
Primeiro eu precisava verificar se essa posição será válida. Se não for, a função retorna e manda 
uma mensagem de "Posição inválida". 
Depois, a função separa memória para um novo elemento e preenche seus campos. 
Depois, a função verifica se o novo elemento será inserido no início, no final ou no meio da lista. 
Se for no início, o novo elemento se torna o primeiro elemento da lista. 
Se for no final, o novo elemento se torna o último elemento da lista. 
Se for no meio, o novo elemento é adicionado na posição especificada 
e os ponteiros dos elementos anteriores e posteriores são corrigidos 
(CONFESSO QUE ESSA LÓGICA NÃO ME DEIXOU SEGURO, PORÉM ENTENDI QUE SERIA UM "PLUS" ..KKK...*/

void inserirElementoID(Lista* lista, int id, char nome[], float preco, int posicao) {
    if (posicao < 1 || posicao > lista->tamanho + 1) {
        printf("Posicao invalida!\n");
        return;
    }

    Brinquedo* novoBrinquedo = (Brinquedo*) malloc(sizeof(Brinquedo));
    novoBrinquedo->id = id;
    strcpy(novoBrinquedo->nome, nome);
    novoBrinquedo->preco = preco;

    if (posicao == 1) {
        novoBrinquedo->prox = lista->primeiro;
        novoBrinquedo->ant = NULL;
        lista->primeiro->ant = novoBrinquedo;
        lista->primeiro = novoBrinquedo;
    } else if (posicao == lista->tamanho + 1) {
        lista->ultimo->prox = novoBrinquedo;
        novoBrinquedo->ant = lista->ultimo;
        novoBrinquedo->prox = NULL;
        lista->ultimo = novoBrinquedo;
    } else {
        Brinquedo* atual = lista->primeiro;
        int i;
        for (i = 1; i < posicao - 1; i++) {
            atual = atual->prox;
        }
        novoBrinquedo->prox = atual->prox;
        novoBrinquedo->ant = atual;
        atual->prox->ant = novoBrinquedo;
        atual->prox = novoBrinquedo;
    }

    lista->tamanho++;
}

/*Como eu já havia declarado a função inserir elemento apenas chamei essa função
para adicionar um elemento na posição 1*/

void inserirElementoInicio(Lista* lista, int id, char nome[], float preco) {
    inserirElementoID(lista, id, nome, preco, 1);
}

/*Agora eu preciso saber quais são os elementos de minha lista por isso, 
declarei a função (listarElementos) onde ela vai receber um ponteiro para a lista 
e percorre todos os elementos, imprimindo suas informações depois.*/

void listarElementos(Lista* lista) {
    if (lista->primeiro == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    Brinquedo* atual = lista->primeiro;
    while (atual != NULL) {
       printf("%.2f\n", atual->preco);
    atual = atual->prox;
}

/*Assim como na função anterior, essa função percorre todos os elementos
só que dessa vez, irá listar na ordem inversa e como na anterior, caso a lista
esteja vazia, ela retorna uma mensagem "LISTA VAZIA"*/

}
void listarElementosOrdemInversa(Lista* lista) {
if (lista->ultimo == NULL) {
printf("Lista vazia!\n");
return;
}

Brinquedo* atual = lista->ultimo;
while (atual != NULL) {
    printf("ID: %d | Nome: %s | Preco: R$ %.2f\n", atual->id, atual->nome, atual->preco);
    atual = atual->ant;
}
}

/*Agora suponhamos que nosso professor Mayrton ou algum cliente queira excluir um elemento de
uma posição específica, então precisarei criar essa função pensando na seguinte lógica: 
A função precisa receber um ponteiro para a lista e a posicao do elemento que será removido. 
Se a posição não for válida, a função retorna. Caso contrário, a função encontra 
o elemento a ser removido, ajusta os ponteiros dos elementos anterior e posterior, 
e libera a memória do elemento removido.*/

void removerElemento(Lista* lista, int posicao) {
if (posicao < 1 || posicao > lista->tamanho) {
printf("Posicao invalida!\n");
return;
}
Brinquedo* atual = lista->primeiro;
if (posicao == 1) {
    lista->primeiro = atual->prox;
    if (lista->primeiro == NULL) {
        lista->ultimo = NULL;
    } else {
        lista->primeiro->ant = NULL;
    }
} else if (posicao == lista->tamanho) {
    atual = lista->ultimo;
    lista->ultimo = atual->ant;
    lista->ultimo->prox = NULL;
} else {
    int i;
    for (i = 1; i < posicao; i++) {
        atual = atual->prox;
    }
    atual->ant->prox = atual->prox;
    atual->prox->ant = atual->ant;
}

free(atual);
lista->tamanho--;
}

/*E mesmo se o professor Mayrton ou nosso cliente, queira remover um elemento da lista
especificando pelo nome será possível com a lógica da função a seguir: 
Essa função recebe um ponteiro para a lista e o nome do elemento que será removido. 
A função vai percorrer todos os elementos da lista e encontrar a posição do elemento 
com o nome especificado. Caso não encontre nenhum elemento com 
o nome especificado, a função retorna. Caso contrário, a função chama a 
função removerElemento passando a posição do elemento encontrado.*/

void removerElementoNome(Lista* lista, char nome[]) {
Brinquedo* atual = lista->primeiro;
int posicao = 1;
while (atual != NULL) {
if (strcmp(atual->nome, nome) == 0) {
removerElemento(lista, posicao);
return;
}
atual = atual->prox;
posicao++;
}
printf("Elemento nao encontrado!\n");
}

/*Depois de remover qulquer elemento, preciso manter essa lista atualizada, por isso,
declarei a função (ATUALIZAR)
 Essa função recebe um ponteiro para a lista, a posicao do elemento que será atualizado, e 
 as novas informações do elemento. Se a posição não for válida, a função retorna. 
 Mas se ela for válida, a função encontra o elemento a ser atualizado e atualiza suas informações.*/

void atualizar(Lista* lista, int posicao, int id, char nome[], float preco) {
if (posicao < 1 || posicao > lista->tamanho) {
printf("Posicao invalida!\n");
return;
}

Brinquedo* atual = lista->primeiro;
int i;
for (i = 1; i < posicao; i++) {
    atual = atual->prox;
}

atual->id = id;
strcpy(atual->nome, nome);
atual->preco = preco;
}

/*Agora pensei em buscar um elemento pelo sei ID para ser mais específico na busca.
para isso, declarei minha função para buscar pelo ID. 
Essa função recebe um ponteiro para a lista e o id do elemento a ser buscado. 
A função vai percorrer todos os elementos da lista e retornar o elemento 
quando encontrar o id especificado. Caso contrário, a função retorna NULL.*/

Brinquedo* buscarElemento(Lista* lista, int id) {
Brinquedo* atual = lista->primeiro;
while (atual != NULL) {
if (atual->id == id) {
return atual;
}
atual = atual->prox;
}

return NULL;
}

/*Para que eu possa inserir, atualizar e buscar corretamente, seriaa preciso que eu 
saiba o tamanho da minha lista, por isso declarei a função (TAMANHO).
Essa função recebe um ponteiro para a lista e retorna o valor do campo tamanho da lista.*/

int tamanho(Lista* lista) {
return lista->tamanho;
}

/*Suponhamos que o professor Mayrton ou nosso cliente, esteja limpando seu estoque. 
Ele irá precisar excluir todos esses elementos da lista e liberar espaço em memória.
Assim, a função (EXCLUIRLISTA) irá receber um ponteiro para a lista e percorrer todos os 
elementos da lista, liberando a memória de cada elemento. Depois de liberar a memória de 
todos os elementos, a função alinha os campos ultimo e tamanho da lista.*/


void excluirLista(Lista* lista) {
Brinquedo* atual = lista->primeiro;
while (atual != NULL) {
Brinquedo* temp = atual->prox;
free(atual);
atual = temp;
}
lista->primeiro = NULL;
lista->ultimo = NULL;
lista->tamanho = 0;
}

/*Por fim temos a nossa função (MAIN) que irá chamar todas as nossas funçoes e
retornar todos os dados de acordo com cada função requisitada. Mostrando os tipos de brinquedos,
preços e IDs correspondentes numa lista duplamente encadeada.*/

int main() {
Lista lista;
criarLista(&lista);
inserirElemento(&lista, 2, "Bola", 15.00);
inserirElemento(&lista, 3, "Carrinho", 30.75);
inserirElemento(&lista, 4, "Skate", 80.20);
inserirElemento(&lista, 5, "Patins", 90.99);
inserirElemento(&lista, 6, "Casinha", 60.00);

printf("Lista de Brinquedos:\n");
listarElementos(&lista);

printf("Lista de Brinquedos em Ordem Inversa:\n");
listarElementosOrdemInversa(&lista);

printf("Tamanho da lista: %d\n", tamanho(&lista));

Brinquedo* boneca = buscarElemento(&lista, 1);
printf("Boneca encontrada: ID: %d | Nome: %s | Preco: R$ %.2f\n", boneca->id, boneca->nome, boneca->preco);

atualizar(&lista, 3, 7, "Aviao", 45.00);
printf("Lista de Brinquedos atualizada:\n");
listarElementos(&lista);

removerElementoNome(&lista, "Skate");
printf("Lista de Brinquedos apos remocao:\n");
listarElementos(&lista);

excluirLista(&lista);
printf("Lista de Brinquedos apos exclusao:\n");
listarElementos(&lista);

return 0;
}



