#include <stdlib.h>
#include <stdio.h>
#include "Matriz.h"
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
		printf("1) Ler Arquivo\n");
		printf("2) Insere\n");
		printf("3) Imprime\n");
		printf("4) Inserir Pos\n");
		printf("5) Retirar\n");
		printf("6) RetirarPos\n");
		printf("0) Sair \n");
		scanf("%d", &input);
		if(input == 0)
		{
			running = 0;
			break;	
		}
		else if (input == 2)
		{
			scanf("%d", &item);
			error = LInsere(&lista, &item, pos);
		}
		else if (input == 3)
		{
			ImprimeMatriz(&lista);
		}
		else if (input == 4) 
		{
			scanf("%d", &pos);
			scanf("%d", &item);
			error = LInserePos(&lista, &item, pos);
		}
		else if (input == 5)
		{
			error = LRetira(&lista, &item);
		}
		else if (input == 6)
		{
			scanf("%d", &pos);
			error = LRetiraPos(&lista, &item, pos);
		}
		else if (input == 1)
		{
			LeMatriz(&nfile, &lista, &item);
		}
	}
	//[6 >,[1] >,3,5]
	//[6,3,5,[1] -> 3]
	//
	
	
	
	
	
}
