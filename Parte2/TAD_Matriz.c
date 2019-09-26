#include "TAD_Matriz.h"

void LeMatriz(FILE *OFILE, TMatriz* pMatriz)
{
	char fileName[50];
	strcpy(fileName, "arquivo.txt");
	OFILE = fopen(fileName, "r");
	fscanf(OFILE, "%d, %d", &pMatriz->X, &pMatriz->Y);
	InicializarCabeca(pMatriz);

	int usuario, produto = 0, x = 0, y = 0, quantidade;
	fscanf(OFILE, "%d %d", &usuario, &produto);
	int lendoResto = 1;
	int lendoSeparado = 1;
	char data[20];

	int z = 0;
	while (fscanf(OFILE, "%s %d", &data, &quantidade) != EOF)
	{
		//printf("\n%s//%d\n", data, quantidade);
		Insere(pMatriz, data, quantidade, usuario, produto, z); //Chama subprograma para inicializar cedulas
		z++;
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

void ImprimeTAD(TMatriz* pMatriz) {
	int y, x;
	Apontador Aux;
	Apontador Linha;
	ApontadorItem AuxItem;


	Linha = pMatriz->pPrimeiro->abaixo;
	Aux = Linha;
	for (y = 1; y <= pMatriz->Y; y++) {
		printf("\n[");
		for (x = 1; x <= pMatriz->X; x++) {
			if (Aux->direita->linha == y && Aux->direita->coluna == x) {
				Aux = Aux->direita;
				AuxItem = Aux->lPrimeiro;
				while (AuxItem->pProx != NULL) 
				{
					AuxItem = AuxItem->pProx;
					if (AuxItem->quantidade != -1)
					{
						printf(" %s %d ", AuxItem->data, AuxItem->quantidade);
					}
				}
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
    return aux;
}

void Insere(TMatriz* pMatriz, char data[20], int quantidade, int Linha, int Coluna, int vezes)
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
	{ // Descer ate a coluna desejada
		AndadorColuna = AndadorColuna->direita; //[0,-1] e assim por diante
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
	if(Aux->direita->coluna != CABECA)// && //Aux->coluna != Coluna)
	{
        proxCelula = Aux->direita;
	}

	if (Aux->direita->coluna != Coluna)
	{
		Aux->direita = (Apontador)malloc(sizeof(TCelula)); //aponta para a direita e inicializa a celula
		Aux = Aux->direita; //Vai para a celula
		Aux->direita = proxCelula; // Aponta para a celula
		Aux->lPrimeiro = NULL;
		Aux->coluna = Coluna;
		Aux->linha = Linha;
		Aux->abaixo = AndadorColuna; // Por padrão aponta para a Cabeça Coluna
	}
	else
	{
		Aux = Aux->direita;
	}
	InsereLinha(Aux, pMatriz, data, quantidade, vezes);
    Apontador linhaAbaixo = AndadorLinha->abaixo; // Se ecncontrar algum elemento abaixo, aponta para ele
    for(i = Linha+1; i < (pMatriz->Y+1); i++){
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

void InsereLinha(Apontador aux,TMatriz* pMatriz, char data[20], int quantidade, int vezes)
{
	ApontadorItem auxItem;
	//printf("\n\t%s %d\n", data, quantidade);
	if (vezes == 0)
	{
		aux->lPrimeiro = (ApontadorItem)malloc(sizeof(TItem));
		auxItem = aux->lPrimeiro;
		aux->lUltimo = aux->lPrimeiro;
		auxItem->quantidade = -1;
	}
	auxItem = aux->lUltimo;
	auxItem->pProx = (ApontadorItem)malloc(sizeof(TItem));
	auxItem = auxItem->pProx;
	aux->lUltimo = auxItem;
	strcpy(auxItem->data, data);
	auxItem->quantidade = quantidade;
	auxItem->pProx = NULL;
	//printf("\n\t%s %d\n", auxItem->data, auxItem->quantidade);
}


void quantidadeComprasPorCliente(TMatriz* pMatriz, int cliente) {
	int i, j, h, quantidade = 0;
	Apontador Aux;
	Apontador Linha;
	ApontadorItem AuxItem;

	Linha = pMatriz->pPrimeiro->abaixo;
	Aux = Linha;
	for (i = 1; i <= cliente; i++) {
		for (j = 1; j <= pMatriz->X; j++) {
			if (Aux->linha != CABECA  && Aux->coluna != CABECA)
			{
				if (i == cliente)
				{
					if (j == pMatriz->X)
					{
						AuxItem = Aux->lPrimeiro;
						while (AuxItem->pProx != NULL) {
							quantidade++;
							AuxItem = AuxItem->pProx;
						}
						printf("\ncliente %d realizou %d compras\n", cliente, quantidade);
					}
					else
					{
						quantidade = 0;
					}
				}
			
			}
			if (Aux->direita->linha != CABECA && Aux->direita->coluna != CABECA && Aux->direita->coluna <= cliente)
			{
				Aux = Aux->direita;
			}
		}
		if (Linha->abaixo->linha <= cliente)
		{
			Linha = Linha->abaixo;
			Aux = Linha;
		}
	}

}
/*
void quantidadeComprasPorProduto(TMatriz* pMatriz, int produto) {
	int i, j, h, quantidade = 0;
	Apontador Aux;
	Apontador Coluna;
	ApontadorItem AuxItem;
	Coluna = pMatriz->pPrimeiro->abaixo;
	Aux = Coluna;
	for (i = 1; i <= pMatriz->Y; i++) {
		for (j = 1; j <= produto; j++) {
			if (Aux->linha != CABECA && Aux->coluna != CABECA) {
				if (j == produto)
				{
					AuxItem = Aux->lPrimeiro;
					while (AuxItem->pProx != NULL) {
						quantidade++;
						AuxItem = AuxItem->pProx;
					}
					printf("\nproduto %d foi comprado %d vezes\n", produto, quantidade);
					
				}

			}
			Aux = Aux->direita;
		}
			Coluna = Coluna->abaixo;
			Aux = Coluna;
	}

}
*/

void quantidadeComprasPorProduto(TMatriz* pMatriz, int produto) {
	int i, j, h, quantidade = 0;
	Apontador Aux;
	Apontador Linha;
	ApontadorItem AuxItem;

	Linha = pMatriz->pPrimeiro->abaixo;
	Aux = Linha;
	for (i = 1; i <= pMatriz->Y; i++) {
		for (j = 0; j <= produto; j++) {
			if (Aux->linha != CABECA && Aux->coluna != CABECA)
			{
				if (j == produto)
				{
					if (Aux->coluna == produto)
					{
						AuxItem = Aux->lPrimeiro;

						while (AuxItem->pProx != NULL)
						{
							quantidade++;
							AuxItem = AuxItem->pProx;
						}

						printf("\O produto %d foi comprado %d vezes\n", Aux->coluna, quantidade);
					}
					else
					{
						quantidade = 0;
					}
				}
				
			}
			if (Aux->direita->linha != CABECA && Aux->direita->coluna != CABECA && Aux->direita->coluna <= produto)
			{
				Aux = Aux->direita;
			}
		}
		Linha = Linha->abaixo;
		Aux = Linha;
	}

}
