#include <stdio.h>
#include <time.h>

#define C 40

void combinationUtil(int arr[], int data[], int start, int end,int index, int r, int peso[],int* valort,int vetor[], int N, int pesoData[]);

void printCombination(int arr[], int n, int r,int peso[],int*valort,int vetor[], int N)
{
    int data[r];
    int pesoData[r];

    combinationUtil(arr, data, 0, n-1, 0, r, peso,valort,vetor,N, pesoData);
}

void combinationUtil(int arr[], int data[], int start, int end,int index, int r,int peso[],int* valort,int vetor[], int N, int pesoData[])
{
    int pesot = 0;
    int newvalor = 0;

    if (index == r)
    {

        for (int j=0; j<r; j++){
                newvalor += data[j];
                for(int k = 0; k < N; k++)
                {
                    if(data[j] == arr[k] && pesoData[j] == peso[k])
                    {
                        pesot+= peso[k];
                        break;
                    }
                }
        }
         if(pesot <= C)
        {
            if(*valort <= newvalor)
            {
                *valort = newvalor;
                for(int i =0;i < r;i++)
                {
                    vetor[i] = data[i];
                }
            }
        }
        return;
    }

    for (int i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        pesoData[index] = peso[i];
        combinationUtil(arr, data, i+1, end, index+1, r,peso,valort,vetor,N, pesoData);
    }
}

int main()
{
    clock_t Ticks[3];
    Ticks[0] = clock();

    int N = 0;
    int l;
    int valort = 0;

    FILE* input;
    input = fopen("Input.txt", "r");
    if(input == NULL)
    {
        return 0;
    }
    else
    {
        fscanf(input, "%d", &N);
        int itens[N];
        int peso[N];
        int vetor[N];

        int j = 0;
        for (j = 0; j < N; j++)
        {
        vetor[j] = 0;
        }
        j = 0;
        while(fscanf(input, "%d %d", &peso[j], &itens[j]) != EOF)
        {
            j++;
        }

        int n = sizeof(itens)/sizeof(itens[0]);
        for(int i = 1;i <= N;i++)
        {
            //Ticks[1] = clock(); //Usado pelo debug abaixo
            l = i;
            printCombination(itens, n, l,peso,&valort,vetor, N);
            //Ticks[2] = clock(); // Usado pelo debug abaixo
            //double TempoTotal = (Ticks[2] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC; //Usado pela função abaixo
            //double Tempo = (Ticks[2] - Ticks[1]) * 1000.0 / CLOCKS_PER_SEC;      //Usadop pela função abaixo
            //printf("Tempo gasto pela operacao de tamanho %d:  %g ms.\n", l, Tempo); //Debug, mostra o tempo gasto no total pela operação de um tamanho l
            //printf("Tempo gasto pela operacao no total:\t %g ms.\n",TempoTotal); //Debug, mostra o tempo gasto no total pelo programa nesse momento;
        }
        printf("Valores na mochila: ");
        for(int i =0;i < N;i++){
            if(vetor[i] != 0)
            {
            printf("%d ",vetor[i]);
            }
        }
    }

    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms.\n", Tempo);
    return 0;
}
