#include "Matriz.h"

void LeMatriz(FILE *OFILE)
{
	//Le arquivo
	//Faz Matriz	
	
	
}


void ImprimeMatriz(TLista* pLista)
{
	Apontador pAux;
	pAux = pLista->pPrimeiro->direita;
	while (pAux != NULL)
	{
		printf("%d\n", pAux->Item.Chave);
		pAux = pAux->direita; /* próxima célula */
	}	
}

void FLVazia(TLista* pLista)
{
	pLista->pPrimeiro = (Apontador) malloc(sizeof(TCelula));
	pLista->pUltimo = pLista->pPrimeiro;
	pLista->pPrimeiro->direita = NULL;	
	printf("\nHello\n");
}
int LEhVazia(TLista* pLista)
{
	return (pLista->pPrimeiro == pLista->pUltimo);	
}

int LInsere(TLista *pLista, TItem* pItem)
{
	pLista->pUltimo->direita = (Apontador) malloc(sizeof(TCelula));
	pLista->pUltimo = pLista->pUltimo->direita;	
	pLista->pUltimo->Item = *pItem;
	pLista->pUltimo->direita = NULL;
	
	return 1;
}

int LInserePos(TLista *pLista, TItem* pItem, int pos)
{
	Apontador pAux;
	int x = 0;
	pAux = pLista->pPrimeiro->direita;
	while (x < pos)
	{
		x++;
		if (x == pos - 1)
		{
			pLista->pUltimo->direita = (Apontador)malloc(sizeof(TCelula));
			pLista->pUltimo = pLista->pUltimo->direita;
			pLista->pUltimo->Item = *pItem;
			//pLista->pUltimo->direita = pAux->direita;
		}
		printf("-%d-\n", pAux->Item.Chave);
		pAux = pAux->direita; /* próxima célula */
	}

	return 1;
}

int LRetira(TLista* pLista, TItem* pItem)
{
	TCelula* pAux;
	if (LEhVazia(pLista))
		return 0;
	*pItem = pLista->pPrimeiro->direita->Item;
	pAux = pLista->pPrimeiro;
	pLista->pPrimeiro = pLista->pPrimeiro->direita;
	free(pAux);
	return 1;
}
