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
	int pos = 0;
	//Interface:

	while(running == 1)
	{
		printf(" ____________________________\n");
		printf("|-------Menu Principal-------|\n");
		printf("|1) Ler Arquivo Matriz.txt   |\n");
		printf("|2) Imprimir Matriz          |\n");
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
			ImprimeMatriz(&lista);
		}
	}

}
