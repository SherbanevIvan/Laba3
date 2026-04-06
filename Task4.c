#include <stdio.h> 
#include <stdlib.h>

int main(){ 

    int N;
    int m; 
    int k; 
    scanf("%d", &N); 

    int *arr = (int*)malloc(N * sizeof(int)); 

    for (int i = 0; i < N; i++) { 

        printf("Введите число№%d: ", (i+1));
        scanf("%d", &arr[i]);

    }

    printf("Введите новый размер массива (больше прошлого): ");
    scanf("%d", &m);
    
    int *arr2 = (int*)realloc(arr, m * sizeof(int));

    printf("\nЗаполните новый массив\n");

    for (int i = 0; i < m; i++) { 

        printf("Введите число№%d: ", (i+1));
        scanf("%d", &arr[i]);

    }

    printf("Обновлённый массив: ");

    for (int i = 0; i < m; i++){ 

        printf(" %d ", arr[i]); 

    }

    printf("\nВведите новый размер массива (меньше прошлого): ");
    scanf("%d", &k);

    int *arr3 = (int*)realloc(arr2, k * sizeof(int));

    printf("\nЗаполните новый массив\n");

    for (int i = 0; i < k; i++) { 

        printf("Введите число№%d: ", (i+1));
        scanf("%d", &arr[i]);

    }

    printf("Обновлённый массив: ");

    for (int i = 0; i < k; i++){ 

        printf(" %d ", arr[i]); 

    }

    printf("\n");
    free(arr);
}