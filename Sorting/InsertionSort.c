#include <stdio.h>
#include <stdlib.h>

void printArray(int v[], int n){

    printf("[ ");
    for (int i = 0; i < n; i++){
        printf("%i ",v[i]);
    }
    printf("]\n");

}

void insertionSort(int v[], int n){

    int key, i, j;

    for (i = 1; i < n; i++){
        key = v[i];
        j = i - 1;
        while (key < v[j] && j >= 0){
            v[j + 1] = v[j];
            j--;          
        }
        v[j + 1] = key;
    }

}

int main(){
    
    int n, *v;

    printf("Type the size of the Array: ");
    scanf("%i",&n);
    v = (int*)malloc(n*sizeof(int));

    printf("Type the elements of the Array: \n");
    for (int i = 0; i < n; i++){
        scanf("%i", &v[i]);
    }
    
    insertionSort(v,n);
    printArray(v,n);

    return 0;
}