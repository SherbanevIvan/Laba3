#include <stdio.h>
#include <stdlib.h>


int main(){ 

    int N; 
    scanf("%d", &N);

    int *arr = (int*)calloc(N, sizeof(int)); 

    for (int i = 0; i<N; i++){ 

        printf("ВВедите число№%d ", i+1); 
        scanf("%d", &arr[i]); 

    }
    printf("\n");

    for (int i = 0; i < N; i++){ 

        printf(" %d ", arr[i]);

    }

    printf("\n");
    free(arr);

}