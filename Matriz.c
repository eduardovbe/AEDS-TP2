#include "Matriz.h"

//int debug = 0;
//int debug;
void LeMatriz(FILE *OFILE, TMatriz* pMatriz, TItem *item)
{
	item->Chave = 0;
	printf("\nMudar nome da TLista para TMatriz e retirar PUltimo\n");
	char fileName[50];
	strcpy(fileName, "Matriz.txt");
	OFILE = fopen(fileName, "r");
	fscanf(OFILE, "%d, %d", &pMatriz->X, &pMatriz->Y);
	//printf("%d x %d\n",pMatriz -> X,pMatriz -> Y);
	InicializarCabeca(pMatriz); //Inicializando com sucesso
	int L, C;
	float I;
	while (fscanf(OFILE, "%d, %d, %f", &L, &C, &I) != EOF)
	{
		//printf("| %d %d %.2f |\n", L, C, I);
		Insere(pMatriz, I, L, C);
		//Chamar SubProgramar para inicializar cedulas;

	}
	fclose(OFILE);
}

void InicializarCabeca(TMatriz* pMatriz)
{
	pMatriz->pPrimeiro = (Apontador)malloc(sizeof(TCelula));
	pMatriz->pPrimeiro->linha = CABECA;
	pMatriz->pPrimeiro->coluna = CABECA;
	pMatriz->pPrimeiro->direita = pMatriz->pPrimeiro; /*Aponta para ele mesmo*/
	pMatriz->pPrimeiro->abaixo = pMatriz->pPrimeiro; /*Aponta para ele mesmo*/
	InicializarCabecaColuna(pMatriz);
	InicializarCabecaLinha(pMatriz);
}

void InicializarCabecaLinha(TMatriz* pMatriz)
{
	int z;
	Apontador pAux;
	pAux = pMatriz->pPrimeiro->abaixo; //Colocou na cabeça principal
	for (z = 0; z < pMatriz->Y; z++)
	{
		pAux = (Apontador)malloc(sizeof(TCelula)); //baixo, criou algo
		pAux->linha = CABECA;
		pAux->coluna = 0;
		pAux->abaixo = pMatriz->pPrimeiro; /*Aponta para o inicio*/
		pAux->direita = pAux; /*Aponta para ele mesmo*/
		pAux = pAux->abaixo;
	}

}

void InicializarCabecaColuna(TMatriz* pMatriz)
{
	int z;
	Apontador pAux;
	pAux = pMatriz->pPrimeiro->direita; //Colocou na cabeça principal
	for (z = 0; z < pMatriz->Y; z++)
	{
		pAux = (Apontador)malloc(sizeof(TCelula)); //Direita, criou algo
		pAux->coluna = CABECA;
		pAux->linha = 0;
		pAux->direita = pMatriz->pPrimeiro; /*Aponta para o inicio*/
		pAux->abaixo = pAux; /*Aponta para ele mesmo*/
		pAux = pAux->direita;
	}
}
/*void ImprimeMatriz(TMatriz* pMatriz)
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
			verificarIndice = Andante->coluna - xx;
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
			}
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
		//posY = posY->abaixo;
		//Andante = posY;
	}
	//Imprimir linha por linha
}
*/
void ImprimeMatriz(TMatriz* pMatriz) {
	int y, x;
	Apontador Aux;
	Apontador Linha;


	Linha = pMatriz->pPrimeiro->abaixo;
	Aux = Linha;

	printf("\n%f\n\n", pMatriz->pPrimeiro->abaixo->abaixo->direita->Item); //Cabeça -> Abaixo -> Direita (Y = 0, X = 0)
	printf("\n%f\n\n", pMatriz->pPrimeiro->abaixo->direita->direita->Item); //Cabeça -> Abaixo -> Direita (Y = 0, X = 0)
	printf("\n%f\n\n", pMatriz->pPrimeiro->abaixo->direita->direita->direita->Item); //Cabeça -> Abaixo -> Direita (Y = 0, X = 0)
	printf("\n%f\n\n", pMatriz->pPrimeiro->abaixo->direita->direita->direita->direita->Item); //Cabeça -> Abaixo -> Direita (Y = 0, X = 0)

	for (y = 1; y <= pMatriz->Y; y++) {
		printf("\n[");
		for (x = 1; x <= pMatriz->X; x++) {
			if (Aux->direita->linha == y && Aux->direita->coluna == x) {
				Aux = Aux->direita;
				printf("\t%0.2f\t", Aux->Item);
			}
			else {
				printf("\t%0.2f\t", 0.0F);
			}
		}
		Linha = Linha->abaixo;
		Aux = Linha->direita;
		printf("]\n");
	}
}

void Insere(TMatriz* pMatriz, float pItem, int Linha, int Coluna)
{

	Apontador AndadorLinha;
	Apontador AjudantanteColuna;
	Apontador AndadorColuna;
	Apontador Aux;

	int y = 0;
	int i = 0;
	int x = 0;
	//Aux->linha = Linha;
	//Aux->coluna = Coluna;
	AndadorLinha = pMatriz->pPrimeiro; // [-1,-1]
	AndadorColuna = pMatriz->pPrimeiro;// [-1,-1]

	for (y = 0; y < Linha; y++) 
	{ // Descer ate a linha desejada
		AndadorLinha = AndadorLinha->abaixo; //[-1,0] e assim por diante
	}
	Aux = AndadorLinha->direita;
	AjudantanteColuna = AndadorLinha;
	for (i = 0; i < Coluna; i++)  //Coluna
	{
		printf("\nLinha: %d", y);
		printf("Coluna: %d\n", i);
		if (Aux->direita->linha != CABECA)//verifica se não aponta pra cabeça
		{
			AjudantanteColuna = AjudantanteColuna->direita;
			Aux = Aux->direita;
		}
		if (Aux->direita->linha == CABECA)
		{ //Verifica se a celula esta a direita
			Aux->direita = (Apontador)malloc(sizeof(TCelula)); //aponta para a direita e inicializa a celula
			Aux = Aux->direita; //Vai para a celula
			Aux->direita = AndadorLinha; // Aponta para a celula
			Aux->coluna = Coluna;
			Aux->linha = Linha;
			Aux->direita = AndadorLinha;
			Aux->Item.Chave = pItem;
			printf("\n%f\n", Aux->Item);
			break;
		}

	}


	//COLUNA

	/*for (y = 0; y < Coluna - 1; y++) { // Anda ate a coluna desejada
		AndadorColuna = AndadorColuna->direita;
	}
	for (i = 0; i < Linha; i++) {
		if (AndadorColuna->abaixo->coluna != CABECA) {//verifica se aponta pra cabeça
			if ((AndadorColuna->abaixo->coluna) > (Aux->coluna)) {//verifica se a celula esta a esquerda
				Aux->abaixo = AndadorColuna->abaixo;
				AndadorColuna->abaixo = Aux;
			}
			else {
				AndadorLinha = AndadorLinha->abaixo;
			}
		}

	}
	if (AndadorLinha->abaixo->coluna == CABECA) {
		Aux->abaixo = AndadorColuna->abaixo; //aponta em cabeca
		AndadorColuna->abaixo = Aux; //
	}
	*/
}


int LEhVazia(TLista* pLista)
{
	return (pLista->pPrimeiro == pLista->pUltimo);
}

int LInsere(TLista *pLista, TItem* pItem)
{
	pLista->pUltimo->direita = (Apontador)malloc(sizeof(TCelula));
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
