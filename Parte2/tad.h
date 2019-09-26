#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct TItem* ApontadorItem;
typedef struct {
    char data[10];
	int quantidade;
	struct TItem *pProx;
	/* outros componentes */
} TItem;

typedef struct{
    Apontador pPrimeiro;
    Apontador pUltimo;
}TLista;

