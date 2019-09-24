#include <stdlib.h>
#include <stdio.h>
#include "Matriz.h"
#include "Produto.h"
int main()
{
	FILE *nfile;
	TMatriz lista;
	int input;
	int running = 1;
	TItem item;
	int pos = 0;
	int error;
	//Interface:

	while(running == 1)
	{
		printf(" ____________________\n");
		printf("|---Menu principal---|\n");
		printf("|1) Ler Arquivo      |\n");
		printf("|2) Imprime          |\n");
		printf("|0) Sair             |\n");
		printf("|____________________|\n");
		scanf("%d", &input);
		if(input == 0)
		{
			running = 0;
			break;
		}
		else if (input == 1)
		{
			LeMatriz(&nfile, &lista, &item);
		}
		else if (input == 2)
		{
			ImprimeMatriz(&lista);
		}
	}
	//[6 >,[1] >,3,5]
	//[6,3,5,[1] -> 3]
	//





}
