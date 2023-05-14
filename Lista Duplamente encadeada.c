//O C�DIGO ABAIXO � PARA A DISCIPLINA DE ESTRUTURA DE DADOS 
//PROFESSOR MAYRTON TURMA: 302B NOITE
//ALUNO: LEANDRESSON CLEITON MOREIRA FULCO

//DEIXAREI TODO O C�DIGO COMENTADO E PE�O QUE CONSIDERE O COMENT�RIO, SEGUIDO
//DO C�DIGO (COMENT�RIO ACIMA, C�DIGO ABAIXO).

/*Nessa primeira parte fiz a declara��o das bibliotecas que utilizarei no c�digo. 
conforme os pad�es estudados de boas pr�ticas.
stdio.h � a biblioteca padr�o de entrada e sa�da.
stdlib.h � a biblioteca padr�o que cont�m fun��es de aloca��o de mem�ria, e 
string.h cont�m fun��es de manipula��o de strings.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Aqui abaixo comecei a criar a estrutura pensando numa loja de Brinquedo, que cont�m 
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

/*Aqui abaixo comecei a criar a estrutura Lista, que cont�m os campos primeiro, ultimo e tamanho.
  Deixando claro que (primeiro e ultimo) s�o ponteiros para o primeiro e �ltimo elementos da lista,
  respectivamente.
  (tamanho) � a vari�vel que usei para guardar o n�mero de elementos da lista.*/

typedef struct lista {
    Brinquedo* primeiro;
    Brinquedo* ultimo;
    int tamanho;
} Lista;

/* Seguindo adiante utilizei esta fun��o recebe um ponteiro para a lista e inicializa seus campos.
Como ela nao precisa retornar nada, ent�o utilizei como VOID*/

void criarLista(Lista* lista) {
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->tamanho = 0;
}

/*Agora precisei implementar a fun��o que insere um novo elemento no final da lista. 
Essa fun��o vai tem como objetivo receber um ponteiro para a lista, o id, o nome e o preco
do novo elemento. Onde primeiro a fun��o separa um espa�o de mem�ria para um novo elemento e
preenche seus campos. (utilizei o MALLOC para isso).
Depois a fun��o verifica se a lista est� vazia. Se estiver, o novo elemento 
� o primeiro e �ltimo da lista. Se n�o estiver, o novo elemento � adicionado ao final da lista.*/

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

/*Agora eu precisava inserir um novo elemento numa posi��o mais espec�fica da lista
por isso declarei a fun��o (inserirElementoID) que ter� a fun��o de  
receber um ponteiro para a lista, indicando a posicao onde o novo elemento 
ser� inserido, o id, o nome e o preco desse novo elemento. 
Primeiro eu precisava verificar se essa posi��o ser� v�lida. Se n�o for, a fun��o retorna e manda 
uma mensagem de "Posi��o inv�lida". 
Depois, a fun��o separa mem�ria para um novo elemento e preenche seus campos. 
Depois, a fun��o verifica se o novo elemento ser� inserido no in�cio, no final ou no meio da lista. 
Se for no in�cio, o novo elemento se torna o primeiro elemento da lista. 
Se for no final, o novo elemento se torna o �ltimo elemento da lista. 
Se for no meio, o novo elemento � adicionado na posi��o especificada 
e os ponteiros dos elementos anteriores e posteriores s�o corrigidos 
(CONFESSO QUE ESSA L�GICA N�O ME DEIXOU SEGURO, POR�M ENTENDI QUE SERIA UM "PLUS" ..KKK...*/

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

/*Como eu j� havia declarado a fun��o inserir elemento apenas chamei essa fun��o
para adicionar um elemento na posi��o 1*/

void inserirElementoInicio(Lista* lista, int id, char nome[], float preco) {
    inserirElementoID(lista, id, nome, preco, 1);
}

/*Agora eu preciso saber quais s�o os elementos de minha lista por isso, 
declarei a fun��o (listarElementos) onde ela vai receber um ponteiro para a lista 
e percorre todos os elementos, imprimindo suas informa��es depois.*/

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

/*Assim como na fun��o anterior, essa fun��o percorre todos os elementos
s� que dessa vez, ir� listar na ordem inversa e como na anterior, caso a lista
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
uma posi��o espec�fica, ent�o precisarei criar essa fun��o pensando na seguinte l�gica: 
A fun��o precisa receber um ponteiro para a lista e a posicao do elemento que ser� removido. 
Se a posi��o n�o for v�lida, a fun��o retorna. Caso contr�rio, a fun��o encontra 
o elemento a ser removido, ajusta os ponteiros dos elementos anterior e posterior, 
e libera a mem�ria do elemento removido.*/

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
especificando pelo nome ser� poss�vel com a l�gica da fun��o a seguir: 
Essa fun��o recebe um ponteiro para a lista e o nome do elemento que ser� removido. 
A fun��o vai percorrer todos os elementos da lista e encontrar a posi��o do elemento 
com o nome especificado. Caso n�o encontre nenhum elemento com 
o nome especificado, a fun��o retorna. Caso contr�rio, a fun��o chama a 
fun��o removerElemento passando a posi��o do elemento encontrado.*/

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
declarei a fun��o (ATUALIZAR)
 Essa fun��o recebe um ponteiro para a lista, a posicao do elemento que ser� atualizado, e 
 as novas informa��es do elemento. Se a posi��o n�o for v�lida, a fun��o retorna. 
 Mas se ela for v�lida, a fun��o encontra o elemento a ser atualizado e atualiza suas informa��es.*/

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

/*Agora pensei em buscar um elemento pelo sei ID para ser mais espec�fico na busca.
para isso, declarei minha fun��o para buscar pelo ID. 
Essa fun��o recebe um ponteiro para a lista e o id do elemento a ser buscado. 
A fun��o vai percorrer todos os elementos da lista e retornar o elemento 
quando encontrar o id especificado. Caso contr�rio, a fun��o retorna NULL.*/

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
saiba o tamanho da minha lista, por isso declarei a fun��o (TAMANHO).
Essa fun��o recebe um ponteiro para a lista e retorna o valor do campo tamanho da lista.*/

int tamanho(Lista* lista) {
return lista->tamanho;
}

/*Suponhamos que o professor Mayrton ou nosso cliente, esteja limpando seu estoque. 
Ele ir� precisar excluir todos esses elementos da lista e liberar espa�o em mem�ria.
Assim, a fun��o (EXCLUIRLISTA) ir� receber um ponteiro para a lista e percorrer todos os 
elementos da lista, liberando a mem�ria de cada elemento. Depois de liberar a mem�ria de 
todos os elementos, a fun��o alinha os campos ultimo e tamanho da lista.*/


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

/*Por fim temos a nossa fun��o (MAIN) que ir� chamar todas as nossas fun�oes e
retornar todos os dados de acordo com cada fun��o requisitada. Mostrando os tipos de brinquedos,
pre�os e IDs correspondentes numa lista duplamente encadeada.*/

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



