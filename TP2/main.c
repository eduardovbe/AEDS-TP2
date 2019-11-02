
// Program to print all combination of size r in an array of size n
#include <stdio.h>
#include <time.h>

#define C 40

void combinationUtil(int arr[], int data[], int start, int end,
                     int index, int r, int peso[],int* valort,int vetor[]);

// The main function that prints all combinations of size r
// in arr[] of size n. This function mainly uses combinationUtil()
void printCombination(int arr[], int n, int r,int peso[],int*valort,int vetor[])
{
    // A temporary array to store all combination one by one
    int data[r];

    // Print all combination using temprary array 'data[]'
    combinationUtil(arr, data, 0, n-1, 0, r, peso,valort,vetor);
}

/* arr[]  ---> Input Array
   data[] ---> Temporary array to store current combination
   start & end ---> Staring and Ending indexes in arr[]
   index  ---> Current index in data[]
   r ---> Size of a combination to be printed */
void combinationUtil(int arr[], int data[], int start, int end,
                     int index, int r,int peso[],int* valort,int vetor[])
{
    int pesot = 0;
    int newvalor = 0;



    // Current combination is ready to be printed, print it
    if (index == r)
    {

        for (int j=0; j<r; j++){
                newvalor += data[j];
                for(int k = 0; k < 5; k++)
                {
                    if(data[j] == arr[k]){
                        pesot+= peso[k];
                    }
                }

            //printf("%d ", data[j]);
        }
         if(pesot <= C)
        {
            if(*valort <= newvalor)
            {
                printf("=%d=\n", newvalor);
                *valort = newvalor;
                for(int i =0;i < r;i++){
                    if(i >= r)
                    {
                        vetor[i] = 0;
                    }
                    else
                    {
                        vetor[i] = data[i];
                    }

                }
            }
        }

        //printf("peso total = %d \n",pesot);
        return;
    }

    // replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    for (int i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r,peso,valort,vetor);
    }
}

// Driver program to test above functions
int main()
{
    clock_t Ticks[2];
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
        //printf("%d", N);
        while(fscanf(input, "%d %d", &peso[j], &itens[j]) != EOF)
        {
            j++;
        }

        int n = sizeof(itens)/sizeof(itens[0]);
        for(int i = 1;i <= N;i++)
        {
            l = i;
            printCombination(itens, n, l,peso,&valort,vetor);
        }
        printf("Valores na mochila: ");
        for(int i =0;i < 5;i++){
            if(vetor[i] != 0)
            {
            printf("%d ",vetor[i]);
            }
        }
    }

    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms.", Tempo);

    return 0;
}
