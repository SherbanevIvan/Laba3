#include <stdio.h>
#include <stdlib.h>

//нам не надо как-либо изменять массивы, поэтому передавая их в аргументы функций можем не пользоваться указателями

int findmax(int arr[], int N){ 

    int max = 0;

    for (int i = 0; i < N; i++){ 

        if (i == 0){ 

            max = arr[i]; 

        }

        if(arr[i]>max){ 

            max = arr[i]; 

        }

    }

    return max; 
}

int findmin(int arr[], int N){ 

    int min = 0;

    for (int i = 0; i < N; i++){ 

        if (i == 0){ 

            min = arr[i]; 

        }

        if(arr[i]<min){ 

            min = arr[i]; 

        }

    }

    return min; 
}

int getsum(int arr[], int N){ 

    int sum = 0;

    for (int i = 0; i < N; i++){ 

        sum += arr[i]; 

    }

    return sum;

}

int main(){ 

    int N; 
    scanf("%d", &N);

    int *arr = (int*)malloc(N * sizeof(int)); 

    for (int i = 0; i<N; i++){ 

        printf("ВВедите число№%d ", i+1); 
        scanf("%d", &arr[i]); 

    }
    printf("\n");

    for (int i = 0; i < N; i++){ 

        printf(" %d ", arr[i]);

    }

    printf("\n минимальнное значение: %d\nмаксимальное значение: %d\nсумма: %d\n", findmin(arr, N), findmax(arr, N), getsum(arr, N));

    printf("\n");

    free(arr); 

}