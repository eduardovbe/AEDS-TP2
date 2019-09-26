#include <stdlib.h>
#include <stdio.h>
#include "TAD_Matriz.h"

int main()
{
	FILE *nfile;
	TMatriz lista;
	int input;
	int running = 1;
	double valor;

	while(running == 1)
	{
		printf(" ____________________________\n");
		printf("|-------Menu Principal-------|\n");
		printf("|1) Ler Arquivo Matriz.txt   |\n");
		printf("|2) Imprimir Matriz CxP      |\n");
		printf("|3) N Compras Cliente        |\n");
		printf("|4) N compras produto        |\n");
		printf("|0) Sair                     |\n");
		printf("|____________________________|\n");
		printf("\n Escolha uma opcao: ");
		scanf("%d", &input);
		if(input == 0)
		{
			running = 0;
			break;
		}
		else if (input == 1)
		{
			printf("\n");
			LeMatriz(&nfile, &lista, &valor);
		}
		else if (input == 2)
		{
			printf("\n");
			ImprimeTAD(&lista);
		}
		else if (input == 3)
		{
			printf("\n");
			printf("Digite o numero de cliente: ");
			scanf("%d", &input);
			if (input > lista.Y)
			{
				printf("\nCliente não Existe\n");
			}
			else
			{
				quantidadeComprasPorCliente(&lista, input);
			}
		}
		else if (input == 4)
		{
			printf("\n");
			printf("Digite o numero do produto: ");
			scanf("%d", &input);
			if (input > lista.X)
			{
				printf("\nProduto não Existe\n");
			}
			else
			{
				quantidadeComprasPorProduto(&lista, input);
			}
		}
	}
}
