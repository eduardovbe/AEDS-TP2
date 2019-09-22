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
		printf("| %d %d %.2f |\n", L, C, I);
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
		pAux = pAux -> abaixo;
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

void ImprimeMatriz(TMatriz* pMatriz){
 int i, j;
    TCelula *pCelula;


    pCelula = pMatriz->pPrimeiro->abaixo;

    printf("\n");

    for (i = 1; i <= pMatriz ->X; i++){
        for (j = 1; j <= pMatriz ->Y; j++){
            if (pCelula->direita->linha == i && pCelula->direita->coluna == j){
                pCelula = pCelula->direita;
                printf("  \t%0.2f   ", pCelula ->valor);
            }
            else{
                printf("  \t%0.2f   ", 0.0F);
            }
        }
        printf("\n");
        pCelula = pCelula->direita->abaixo;
    }

}

void Insere(TMatriz* pMatriz, float valor, int Linha, int Coluna)
{

	Apontador AndadorLinha;
	Apontador AndadorColuna;
	Apontador Aux;

	int x;
	int i;
	int y;

	Aux  = (Apontador)malloc(sizeof(TCelula));
	Aux-> valor;
	Aux ->linha = Linha;
	Aux ->coluna = Coluna;
	AndadorLinha = pMatriz->pPrimeiro-> abaixo; // [-1,0]
	AndadorColuna = pMatriz ->pPrimeiro-> direita;// [0,-1]

	//LINHA
	for(x = 0;x < Linha-1;x++){ // Descer ate a linha desejada
	    AndadorLinha = AndadorLinha->abaixo;
	}
    for(i = 0;i < Coluna;i++){
            if(AndadorLinha ->direita ->linha =! CABECA){//verifica se aponta pra cabeça
                if( (AndadorLinha->direita->coluna) > (Aux->coluna)){//verifica se a celula esta a esquerda
                        Aux -> direita = AndadorLinha -> direita;
                        AndadorLinha->direita = Aux;
                }
                else{
                    AndadorLinha = AndadorLinha-> direita;
                }
        }

	}
	if (AndadorLinha->direita->linha == CABECA){ //Verifica se a celula esta a direita
        Aux->direita = AndadorLinha->direita; //aponta em cabeca
        AndadorLinha->direita = Aux; //
	}


	//COLUNA

    for(y = 0;y < Coluna-1;y++){ // Anda ate a coluna desejada
            AndadorColuna = AndadorColuna->direita;
	}
    for(i = 0;i < Linha;i++){
            if(AndadorColuna ->abaixo ->coluna =! CABECA){//verifica se aponta pra cabeça
                if((AndadorColuna->abaixo->coluna) > (Aux->coluna) ){//verifica se a celula esta a esquerda
                        Aux -> abaixo = AndadorColuna -> abaixo;
                        AndadorColuna->abaixo = Aux;
                }
                else{
                    AndadorLinha = AndadorLinha-> abaixo;
                }
        }

	}
	if (AndadorLinha->abaixo->coluna == CABECA){
        Aux->abaixo = AndadorColuna->abaixo; //aponta em cabeca
        AndadorColuna->abaixo = Aux; //
	}

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
