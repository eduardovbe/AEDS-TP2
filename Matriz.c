#include "Matriz.h"

void LeMatriz(FILE *OFILE)
{

	//Inicializar Matriz (Cabeça 1)

	char fileName[50];
	strcpy(fileName, "Matriz.txt");
	int L, C;
	OFILE = fopen(fileName, "r");
	fscanf(OFILE, "%d, %d", &L, &C);
	//Inicializar cabeças adjacentes
	int O, H;
	float J;
	while (fscanf(OFILE, "%d, %d, %f", &O, &H, &J) != EOF)
	{
		
		printf("| %d %d %.2f |\n", O, H, J);
		//Chamar SubProgramar para inicializar cedulas;

	}
	
}


void ImprimeMatriz(TLista* pLista)
{
	Apontador pAux;
	pAux = pLista->pPrimeiro->direita;
	while (pAux->linha != -1)
	{
		printf("-%d-\n", pAux->Item.Chave);
		pAux = pAux->direita; /* próxima célula */
	}
}

void FLVazia(TLista* pLista)
{
	pLista->pPrimeiro = (Apontador) malloc(sizeof(TCelula));
	pLista->pUltimo = pLista->pPrimeiro;
	pLista->pPrimeiro->linha = -1;
	pLista->pPrimeiro->coluna = -1;
	pLista->pPrimeiro->direita = pLista->pPrimeiro;	
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
	pLista->pUltimo->direita = pLista->pPrimeiro;
	
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
		//printf("-Aux: %d-\n", pAux->Item.Chave);
		//printf("-PTR: %d-\n", ptr->Item.Chave);
	}

	return 1;
}

int LRetira(TLista* pLista, TItem* pItem)
{
	Apontador pAux;
	if (LEhVazia(pLista))
		return 0;
	*pItem = pLista->pPrimeiro->direita->Item;
	pAux = pLista->pPrimeiro;
	pLista->pPrimeiro = pLista->pPrimeiro->direita;
	free(pAux);
	return 1;
}

int LRetiraPos(TLista* pLista, TItem* pItem, int pos)
{
	Apontador pAux;
	Apontador ptr;
	if (LEhVazia(pLista))
		return 0;
	int x = 0;
	pAux = pLista->pPrimeiro->direita; // Cabeça -> Direita
	ptr = pLista->pPrimeiro; //Começa na Cabeça
	while (x <= pos)
	{

		if (x == pos)
		{
			//*pItem = pLista->pPrimeiro->direita->Item;// < Não alimente o PItem
			ptr->direita = pAux->direita;
			free(pAux);
			break;
		}
		x++;
		ptr = ptr->direita; /*Proxima Celula*/
		pAux = pAux->direita; /* próxima célula */
		printf("-Aux: %d-\n", pAux->Item.Chave);
		printf("-PTR: %d-\n", ptr->Item.Chave);
	}
	return 1;
}
