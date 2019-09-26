#include <stdio.h>
#include <stdlib.h>

#define CABECA -1

typedef struct Celula* Apontador;
typedef struct Celula {
	struct Celula* direita;
	struct Celula* abaixo;
	double valor;
	int linha, coluna;
} TCelula;

typedef int matriz;
typedef struct {
	Apontador pPrimeiro;
	matriz X;
	matriz Y;
} TMatriz;

void LeMatriz(FILE *OFILE, TMatriz* pMatriz, double *item); //Aqui vai ler de um arquivo, e montar a Matriz.
void ImprimeMatriz(TMatriz* pMatriz);

void InicializarCabeca(TMatriz* pMatriz); //Inicializou 
void InicializarCabecaLinha(TMatriz* pMatriz);
void InicializarCabecaColuna(TMatriz* pMatriz);
void Insere(TMatriz* pMatriz, double pItem, int Linha, int Coluna);
Apontador getColuna(Apontador linhaCabeca, int coluna);
Apontador getLinha(Apontador linhaCabeca, int linha);
