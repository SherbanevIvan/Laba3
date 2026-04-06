#include <stdio.h> 
#include <stdlib.h> 

int main() { 

    int N; 
    scanf("%d", &N);
    int delN;

    int *arr = (int*)malloc(N*sizeof(int)); 

    for (int i = 0; i<N; i++){ 

        printf("Введите число №%d: ", (i+1)); 
        scanf("%d", &arr[i]);

    }

    printf("какой по индексу элемент хотите удалить? ");
    scanf("%d", &delN); 

    for (delN; delN<(N-1); delN++){ 

        arr[delN] = arr[delN+1]; 

    }
    N--; 

    int *arr2 = (int*)realloc(arr, N * sizeof(int));

    printf("\nОбновлённый массив: ");

    for (int i = 0; i<N; i++){ 

        printf(" %d ", arr[i]);

    }
    printf("\n");
    free(arr);
}