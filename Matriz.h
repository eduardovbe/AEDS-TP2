#include <stdio.h>
#include <stdlib.h>
#include "Produto.h"

#define CABECA -1

typedef struct Celula* Apontador;
typedef struct Celula {
	struct Celula* direita;
	struct Celula* abaixo;
	double valor;
	int linha, coluna;
} TCelula;

/*
typedef struct {
	Apontador pPrimeiro;
	Apontador pUltimo;
	matriz X;
	matriz Y;
} TLista;
*/
typedef int matriz;
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

void InicializarCabeca(TMatriz* pMatriz); //Inicializou 
void InicializarCabecaLinha(TMatriz* pMatriz);
void InicializarCabecaColuna(TMatriz* pMatriz);
void Insere(TMatriz* pMatriz, double pItem, int Linha, int Coluna);
Apontador getColuna(Apontador linhaCabeca, int coluna);
Apontador getLinha(Apontador linhaCabeca, int linha);
/*
int LEhVazia(TLista* pLista);
int LInsere(TLista* pLista, TItem *pItem);
int LInserePos(TLista *pLista, TItem* pItem, int pos);
int LRetira(TLista* pLista, TItem *pItem);
int LRetiraPos(TLista* pLista, TItem* pItem, int pos);
*/
