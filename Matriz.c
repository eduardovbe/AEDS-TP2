#include "Matriz.h"

//int debug = 0;

void LeMatriz(FILE *OFILE, TMatriz* pMatriz, TItem *item)
{
	item->Chave = 0;
	printf("\nMudar nome da TLista para TMatriz e retirar PUltimo\n");
	char fileName[50];
	strcpy(fileName, "Matriz.txt");
	OFILE = fopen(fileName, "r");
	fscanf(OFILE, "%d, %d", &pMatriz->X, &pMatriz->Y);
	InicializarCabeça(pMatriz); //Inicializando com sucesso
	int L, C;
	float I;
	while (fscanf(OFILE, "%d, %d, %f", &L, &C, &I) != EOF)
	{
		
		printf("| %d %d %.2f |\n", L, C, I);
		Insere(pMatriz, I, L, C);
		//Chamar SubProgramar para inicializar cedulas;

	}
	fclose(OFILE);
}

void InicializarCabeça(TMatriz* pMatriz)
{
	pMatriz->pPrimeiro = (Apontador)malloc(sizeof(TCelula));
	pMatriz->pPrimeiro->linha = CABECA;
	pMatriz->pPrimeiro->coluna = CABECA;
	pMatriz->pPrimeiro->direita = pMatriz->pPrimeiro; /*Aponta para ele mesmo*/
	pMatriz->pPrimeiro->abaixo = pMatriz->pPrimeiro; /*Aponta para ele mesmo*/
	InicializarCabeçaColuna(pMatriz);
	InicializarCabeçaLinha(pMatriz);
}

void InicializarCabeçaLinha(TMatriz* pMatriz)
{
	int z;
	Apontador pAux;
	pAux = pMatriz->pPrimeiro; //Colocou na cabeça principal
	for (z = 0; z < pMatriz->Y; z++)
	{
		pAux->abaixo = (Apontador)malloc(sizeof(TCelula)); //baixo, criou algo
		pAux = pAux->abaixo;
		pAux->linha = CABECA;
		pAux->abaixo = pMatriz->pPrimeiro; /*Aponta para o inicio mesmo*/
		pAux->direita = pAux; /*Aponta para ele mesmo*/
	}
	
}

void InicializarCabeçaColuna(TMatriz* pMatriz)
{
	int z;
	Apontador pAux;
	pAux = pMatriz->pPrimeiro; //Colocou na cabeça principal
	for (z = 0; z < pMatriz->Y; z++)
	{
		pAux->direita = (Apontador)malloc(sizeof(TCelula)); //Direita, criou algo
		pAux = pAux->direita;
		pAux->coluna = CABECA;
		pAux->abaixo = pAux; /*Aponta para ele mesmo*/
		pAux->direita = pMatriz->pPrimeiro; /*Aponta para o inicio mesmo*/
	}
}

void ImprimeMatriz(TMatriz* pMatriz)
{
	Apontador Andante;
	Apontador posY;

	int verificarIndice = 0;
	int restante = 0;
	int rx;

	posY = pMatriz->pPrimeiro; // Y = -1 


	int xx = 0, yy = 0;

	printf("\n%f\n\n", pMatriz->pPrimeiro->abaixo->direita->Item); //Cabeça -> Abaixo -> Direita (Y = 0, X = 0)
	printf("\n%f\n\n", pMatriz->pPrimeiro->abaixo->direita->direita->Item); //Cabeça -> Abaixo -> Direita (Y = 0, X = 0)
	printf("\n%f\n\n", pMatriz->pPrimeiro->abaixo->direita->direita->direita->Item); //Cabeça -> Abaixo -> Direita (Y = 0, X = 0)
	for (yy = 0; yy < pMatriz->Y; yy++) //Linha
	{
		posY = posY->abaixo;
		Andante = posY;
		verificarIndice = 0;
		printf("[ ");
		for (xx = 0; xx < pMatriz->X; xx++)//Coluna
		{
			Andante = Andante->direita;
			/*verificarIndice = Andante->coluna - xx;
			if (verificarIndice > 0)
			{
				while (verificarIndice > 0)
				{
					printf("0 ");
					verificarIndice--;
					if (verificarIndice >= 0)
					{
						xx++;
					}
				}
			}	*/		
			if (Andante->linha == CABECA || Andante->coluna == CABECA)
			{
				//printf("(%d %d) ", Andante->coluna, Andante->linha);
				restante = pMatriz->X - xx;
				//printf("%d", restante);
				for (rx = 0; rx < restante; rx++)
				{
					printf("0 ");
					xx++;
				}
			}
			else
			{
				printf("%f ", Andante->Item);
				//printf("(%d %d) ", Andante->coluna, Andante->linha);
			}
			//printf("%f\n ", Andante->Item);
		}
		printf("]\n");
		posY = posY->abaixo;
		Andante = posY;
	}
	//Imprimir linha por linha
}

void Insere(TMatriz* pMatriz, float pItem, int Linha, int Coluna)
{
	Apontador posX;
	Apontador posY;
	Apontador Andador;
	Apontador AndadorAnteriorX;
	Apontador AndadorAnteriorY;

	int x = 0;
	int y = 0;
	int p = 0;
	int ini = 0;
	posX = pMatriz->pPrimeiro->direita; //Y = -1 X = 0;
	posY = pMatriz->pPrimeiro->abaixo; //Y = 0 X = -1;
	Andador = posY -> direita; //Y = 0, X = 0;
	AndadorAnteriorX = posY; // Y = 0 X = -1;
	AndadorAnteriorY = posX; // Y = -1 X = 0;
	for (y = 0; y < Linha; y++) //Linha
	{
		//scanf("%d", &debug);
		if (ini == 1)
		{
			break;
		}
		for (x = 0; x < Coluna; x++) //Coluna
		{
			//scanf("%d", &debug);
			if (y == (Linha - 1) && x == (Coluna - 1))
			{
				for (p = 0; p < Linha - 2; p++) //-1 para o vetor que começa em 0 + o -1 do y-1 que onde você quer;
				{
					AndadorAnteriorY->abaixo; //Chega no Y-1 que você quer
				}
				Andador->direita= (Apontador)malloc(sizeof(TCelula));
				Andador = Andador->direita;
				Andador->linha = Linha;
				Andador->coluna = Coluna;
				Andador->Item.Chave = pItem;
				Andador->abaixo = posX;
				Andador->direita = posY;
				AndadorAnteriorX->direita = Andador; //Chega no X-1 que você quer
				ini = 1;
				break;
			}
			posX = posX->direita; //Indo pra direita, chegando no X que você quer
			AndadorAnteriorY = posX;
			AndadorAnteriorX = Andador; //Andando Pra posição do Andador
			Andador = Andador->direita; //Andando pra frente +1;
		}
		posX = pMatriz->pPrimeiro->direita; //Cabeça -> Direita
		posY = posY->abaixo; //Vai pra baixo
		Andador = posY->direita; // Y = 1, X = 0;
		AndadorAnteriorX = posY; // Y = 1 X = -1;
		AndadorAnteriorY = posX;
	}

	return;
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
	//Matriz : 4x4
	//For x < 4;, Y < 4;
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
		//printf("-Aux: %d-\n", pAux->Item.Chave);
		//printf("-PTR: %d-\n", ptr->Item.Chave);
	}
	return 1;
}
