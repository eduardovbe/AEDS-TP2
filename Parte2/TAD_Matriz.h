#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CABECA -1 //Definição para -1, util para leitura de codigo.

typedef struct CelItem* ApontadorItem;
typedef struct CelItem {
	char data[20];
	int quantidade;
	struct TItem *pProx;
} TItem;

typedef double produto;
typedef struct Celula* Apontador;
typedef struct Celula {
	struct Celula* direita;
	struct Celula* abaixo;
	ApontadorItem lPrimeiro;
	ApontadorItem lUltimo;
	int linha, coluna;
} TCelula;


typedef int matriz;
typedef struct {
	Apontador pPrimeiro;
	matriz X;
	matriz Y;
} TMatriz;

void LeMatriz(FILE *OFILE, TMatriz* pMatriz); //Aqui vai ler de um arquivo, e montar a Matriz.

void InicializarCabeca(TMatriz* pMatriz); //Inicializou 
void InicializarCabecaLinha(TMatriz* pMatriz);
void InicializarCabecaColuna(TMatriz* pMatriz);
void Insere(TMatriz* pMatriz, char data[20], int quantidade, int Linha, int Coluna, int vezes);
void InsereLinha(Apontador aux, TMatriz* pMatriz, char data[20], int quantidade, int vezes);

Apontador getColuna(Apontador linhaCabeca, int coluna);
Apontador getLinha(Apontador linhaCabeca, int linha);

void quantidadeComprasPorCliente(TMatriz* pMatriz, int cliente);
void quantidadeComprasPorProduto(TMatriz* pMatriz, int produto);
