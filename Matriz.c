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
		printf("-%d-\n", pAux->Item.Chave);
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
	Apontador ptr;
	int x = 0;
	pAux = pLista->pPrimeiro->direita; // Cabeça -> Direita
	ptr = pLista->pPrimeiro; //Começa na Cabeça
	while (x <= pos)
	{

		if (x == pos)
		{
			ptr->direita = (Apontador)malloc(sizeof(TCelula));
			ptr->direita->direita = pAux;
			ptr->direita->Item = *pItem;
			break;
		}
		x++;
		ptr = ptr->direita; /*Proxima Celula*/
		pAux = pAux->direita; /* próxima célula */
		printf("-Aux: %d-\n", pAux->Item.Chave);
		printf("-PTR: %d-\n", ptr->Item.Chave);
		/*
		PTR -> Criar 
		PTR -> Criação - > Aux (Frente)
		
		
		
		*/
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
