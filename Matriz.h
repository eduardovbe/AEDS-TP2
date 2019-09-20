#include <stdio.h>
#include <stdlib.h>

#define CABECA -1

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

typedef int matriz;
typedef struct {
	Apontador pPrimeiro;
	Apontador pUltimo;
	matriz X;
	matriz Y;
} TLista;

typedef struct {
	Apontador pPrimeiro;
	matriz X;
	matriz Y;
} TMatriz;

//Valores: -1 < Cabeça
//struct Celula* e um ponteiro...
//Alocar somente oque vai usar. // Aqui vai fazer a Matriz na tela

void LeMatriz(FILE *OFILE, TMatriz* pMatriz, TItem *item); //Aqui vai ler de um arquivo, e montar a Matriz.
void ImprimeMatriz(TMatriz* pMatriz);

void InicializarCabeça(TMatriz* pMatriz); //Inicializou 
void InicializarCabeçaLinha(TMatriz* pMatriz);
void InicializarCabeçaColuna(TMatriz* pMatriz);
void Insere(TMatriz* pMatriz, float pItem, int Linha, int Coluna);

int LEhVazia(TLista* pLista);
int LInsere(TLista* pLista, TItem *pItem);
int LInserePos(TLista *pLista, TItem* pItem, int pos);
int LRetira(TLista* pLista, TItem *pItem);
int LRetiraPos(TLista* pLista, TItem* pItem, int pos);

