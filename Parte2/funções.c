#include "Produto.h"
void quantidadeComprasPorCliente(TMatriz* pMatriz){
    int i,j,h,quantidade = 0;
    TCelula *Aux;
	TCelula *Linha;

	Aux ->Item = Aux->Item->pPrimeiro
	Linha = pMatriz->pPrimeiro->abaixo;
	Aux = Linha;
    Aux = TMatriz->pPrimeiro->direita->abaixo;
	for (y = 1; y <= pMatriz->Y; y++) {
		for (x = 1; x <= pMatriz->X; x++) {
            if((Aux->linha || Aux->coluna) != CABECA){
                while(Aux->Item->pProx != NULL){
                    quantidade++;
                    Aux->Item = Aux->Item->pProx;
                    }
                
                printf("\ncliente %d realizou %d compras",Aux->linha ,quantidade);
                
            }
            Aux = Aux->direita;
        }
        Linha = Linha->abaixo;
		Aux = Linha;    
    }
		
}



void quantidadeComprasPorProduto(TMatriz* pMatriz){
    int i,j,h,quantidade = 0;
    TCelula *Aux;
	TCelula *Coluna;

	Aux ->Item = Aux->Item->pPrimeiro
	Linha = pMatriz->pPrimeiro->abaixo;
	Aux = Coluna;
    Aux = TMatriz->pPrimeiro->direita->abaixo;
	for (y = 1; y <= pMatriz->Y; y++) {
		for (x = 1; x <= pMatriz->X; x++) {
            if((Aux->linha || Aux->coluna) != CABECA){
                while(Aux->Item->pProx != NULL){
                    quantidade++;
                    Aux->Item = Aux->Item->pProx;
                    }
                
                printf("\nproduto %d foi comprado %d vezes",Aux->coluna ,quantidade);
                
            }
            Aux = Aux->abaixo;
        }
        Coluna = Coluna->direita;
		Aux = Coluna;
    }
		
}


    



void ImprimeMatriz(TMatriz* pMatriz) {
	int y, x;
	Apontador Aux;
	Apontador Linha;


	Linha = pMatriz->pPrimeiro->abaixo;
	Aux -> Item = Aux -> Item ->pPrimeiro;
	Aux = Linha;

    //printf("\n%f\n\n", pMatriz->pPrimeiro->abaixo->abaixo->abaixo->direita->valor);
	for (y = 1; y <= pMatriz->Y; y++) {
		printf("\n[");
		for (x = 1; x <= pMatriz->X; x++) {
			Aux = Aux->direita;
            		while(Aux->Item->pProx != NULL){
                		if (Aux->direita->linha == y && Aux->direita->coluna == x) {
                    		printf(" %d %s ",Aux->Item->quantidade, Aux->Item->data);
				Aux->Item = Aux->Item->pProx;
               	 	}
                
           	 }
            
		}
		Linha = Linha->abaixo;
		Aux = Linha;
		printf("]\n");
	}
}
