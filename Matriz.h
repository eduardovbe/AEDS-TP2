#include <stdio.h>
#include <stdlib.h>

typedef double TipoChave;
typedef struct {
	TipoChave Chave;
	/* outros componentes */
} TItem;

typedef struct Celula* Apontador;
typedef struct Celula {
	TItem Item;
	int linha, coluna;
	struct Celula* direita; /* Apontador para a Proxima casa; */
	struct Celula* abaixo;  /* Apontador para a casa abaixo; */
} TCelula;

typedef struct {
	Apontador pPrimeiro;
	Apontador pUltimo;
} TLista;

//Valores: -1 < Cabeça
//struct Celula* e um ponteiro...
//Alocar somente oque vai usar.
void imprimeMatriz(); // Aqui vai fazer a Matriz na tela

void LeMatriz(FILE *OFILE); //Aqui vai ler de um arquivo, e montar a Matriz.

void FLVazia(TLista* pLista);
int LEhVazia(TLista* pLista);
int LInsere(TLista* pLista, TItem *pItem);
int LInserePos(TLista *pLista, TItem* pItem, int pos);
int LRetira(TLista* pLista, TItem *pItem);
int LRetiraPos(TLista* pLista, TItem* pItem, int pos);
void LImprime(TLista* pLista);
