#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i,n;
  FILE *lista;
  lista = fopen("lista.txt","w");

  scanf("%d",&n);
  fprintf(lista,"%d",n);
  fprintf(lista,"%s","\n");
  for (i = 0; i < n*2; i++)
  {
    if((i % 2 == 0) && i != 0){
        fprintf(lista,"%s","\n");
    }
    /* gerando valores aleatórios entre zero e 100 */
    fprintf(lista,"%d ", 1+ rand() % 9);

  }
  fclose(lista);
  return 0;
}

