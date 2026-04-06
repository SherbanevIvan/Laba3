#include <stdio.h> 
#include <stdlib.h>


int main() { 

    int N; 
    scanf("%d", &N);

    int addN;
    int num;

    int *arr = (int*)malloc(N*sizeof(int)); 

    for (int i = 0; i<N; i++){ 

        printf("Введите число №%d: ", (i+1)); 
        scanf("%d", &arr[i]);

    }

    printf("куда по индексу хотите лобавить новый элемент? ");
    scanf("%d", &addN); 
    N++; 

    printf("Какое число хотите вставить на это место? ");
    scanf("%d", &num);


    int *arr2 = (int*)realloc(arr, N * sizeof(int));



    for (int i = N - 1; i > addN; i--){

        arr[i] = arr[i - 1];
    
    }
    arr[addN] = num;

    printf("\nОбновлённый массив: ");

    for (int i = 0; i<N; i++){ 

        printf(" %d ", arr[i]);

    }
    printf("\n");
    free(arr);
}