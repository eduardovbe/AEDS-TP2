#include "Matriz.h"

//int debug = 0;
//int debug;
void LeMatriz(FILE *OFILE, TMatriz* pMatriz, TItem *item)
{
	item->Chave = 0;
	printf("\nMudar nome da TLista para TMatriz e retirar PUltimo, Deletar lixo de memoria!!!\n");
	char fileName[50];
	strcpy(fileName, "Matriz.txt");
	OFILE = fopen(fileName, "r");
	fscanf(OFILE, "%d, %d", &pMatriz->X, &pMatriz->Y);
	//printf("%d x %d\n",pMatriz -> X,pMatriz -> Y);
	InicializarCabeca(pMatriz); //Inicializando com sucesso
	int L, C;
	double I;
	while (fscanf(OFILE, "%d, %d, %lf", &L, &C, &I) != EOF)
	{
		Insere(pMatriz, I, L, C); //Chama subprograma para inicializar cedulas
	}
	printf("Arquivo Lido com sucesso!\n");
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
	pAux = pMatriz->pPrimeiro; //Colocou na cabeça principal
	for (z = 0; z < pMatriz->Y; z++)
	{
		pAux->abaixo = (Apontador)malloc(sizeof(TCelula)); //baixo, criou algo
		pAux = pAux->abaixo;
		pAux->linha = CABECA;
		pAux->coluna = 0;
		pAux->abaixo = pMatriz->pPrimeiro; /*Aponta para o inicio*/
		pAux->direita = pAux; /*Aponta para ele mesmo*/
	}

}

void InicializarCabecaColuna(TMatriz* pMatriz)
{
	int z;
	Apontador pAux;
	pAux = pMatriz->pPrimeiro; //Colocou na cabeça principal
	for (z = 0; z < pMatriz->Y; z++)
	{
		pAux->direita = (Apontador)malloc(sizeof(TCelula)); //Direita, criou algo
        pAux = pAux->direita;
		pAux->coluna = CABECA;
		pAux->linha = 0;
		pAux->direita = pMatriz->pPrimeiro; /*Aponta para o inicio*/
		pAux->abaixo = pAux; /*Aponta para ele mesmo*/
	}
}

void ImprimeMatriz(TMatriz* pMatriz) {
	int y, x;
	Apontador Aux;
	Apontador Linha;


	Linha = pMatriz->pPrimeiro->abaixo;
	Aux = Linha;

    //printf("\n%f\n\n", pMatriz->pPrimeiro->abaixo->abaixo->abaixo->direita->valor);
	for (y = 1; y <= pMatriz->Y; y++) {
		printf("\n[");
		for (x = 1; x <= pMatriz->X; x++) {
			if (Aux->direita->linha == y && Aux->direita->coluna == x) {
				Aux = Aux->direita;
				printf("\t%0.2f\t", Aux->valor);
			}
			else {
				printf("\t%0.2f\t", 0.0);
			}
		}
		Linha = Linha->abaixo;
		Aux = Linha;
		printf("]\n");
	}
}

Apontador getColuna(Apontador linhaCabeca, int coluna){
    Apontador aux = linhaCabeca;
    int i;
    for(i = 0; (i < coluna) && (aux->direita->linha != CABECA); i++){
        aux = aux->direita;
    }
    //printf("\tgetColuna Desejo = %d | Consegui = %d\n", coluna, aux->coluna);
    if(aux->coluna == coluna)
        return aux;
    else
        return NULL;
}

Apontador getLinha(Apontador linhaCabeca, int linha){
    Apontador aux = linhaCabeca;
    int i;
    for(i = 0; i < linha; i++){
        aux = aux->abaixo;
    }
	//printf("\tgetLinha Desejo = %d | Consegui = %d\n", linha, aux->linha);
    return aux;
}

void Insere(TMatriz* pMatriz, double pItem, int Linha, int Coluna)
{
	Apontador AndadorLinha; // Celula Cabeça Eixo Y
	Apontador AndadorColuna; // Celula Cabeça Eixo X
	Apontador Aux;

	int i;
	AndadorLinha = pMatriz->pPrimeiro; // [-1,-1]
	AndadorColuna = pMatriz->pPrimeiro;// [-1,-1]

	for (i = 0; i < Linha; i++)
	{ // Descer ate a linha desejada
		AndadorLinha = AndadorLinha->abaixo; //[-1,0] e assim por diante
	}
    for (i = 0; i < Coluna; i++)
	{ // Descer ate a linha desejada
		AndadorColuna = AndadorColuna->direita; //[-1,0] e assim por diante
	}
	Aux = AndadorLinha; // Começa na Linha CORRETA
	for(i = 1; i < Coluna && (Aux->direita->linha != CABECA); i++)
    { // Anda até a Pos X e Y para inserir
        if(Aux->direita->coluna < Coluna){
            Aux = Aux->direita;
            i = Aux->coluna;
        }
	}
	Apontador proxCelula = AndadorLinha;
	if(Aux->direita->coluna != CABECA){
        proxCelula = Aux->direita;
	}
	Aux->direita = (Apontador)malloc(sizeof(TCelula)); //aponta para a direita e inicializa a celula
    Aux = Aux->direita; //Vai para a celula
    Aux->direita = proxCelula; // Aponta para a celula
    Aux->coluna = Coluna;
    Aux->linha = Linha;
    Aux->valor = pItem;
    Aux->abaixo = AndadorColuna; // Por padrão aponta para a Cabeça Coluna
    //printf("\tAdicionado Linha %d | Coluna %d\n", Linha, Coluna);
    Apontador linhaAbaixo = AndadorLinha->abaixo; // Se ecncontrar algum elemento abaixo, aponta para ele
    for(i = Linha+1; i < (pMatriz->Y+1); i++){
        //printf("\tTentando Linha %d", i);
        Apontador celulaAbaixo = getColuna(linhaAbaixo, Coluna);
        if(celulaAbaixo != NULL){
            Aux->abaixo = celulaAbaixo;
            break;
        }else{
            linhaAbaixo = linhaAbaixo->abaixo;
        }
    }

    Apontador linhaCima;
    Apontador celulaCima;
    for(i = Linha-1; i >= 0; i--){
        linhaCima = getLinha(pMatriz->pPrimeiro, i);
        celulaCima = getColuna(linhaCima, Coluna);
        if(celulaCima != NULL){
            celulaCima->abaixo = Aux;
            break;
        }
    }
}

/*
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
		ptr = ptr->direita; /*Proxima Celula
		pAux = pAux->direita; /* próxima célula
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
		ptr = ptr->direita; /*Proxima Celula
		pAux = pAux->direita; //próxima célula 
		//printf("-Aux: %d-\n", pAux->Item.Chave);
		//printf("-PTR: %d-\n", ptr->Item.Chave);
	}
	return 1;
}
*/
