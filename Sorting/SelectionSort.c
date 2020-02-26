#include <stdio.h>
#include <stdlib.h>

void printArray(int v[], int n){

    printf("[ ");
    for (int i = 0; i < n; i++){
        printf("%i ",v[i]);
    }
    printf("]\n");

}

void selectionSort(int v[], int n){

    int i, j, minInd, aux;

    for (i = 0; i < n-1; i++){
        minInd = i;
        for ( j = i + 1; j < n; j++){
            if ( v[j] < v[minInd]){
                minInd = j;
            }
        }

        // swap
        aux = v[minInd];
        v[minInd] = v[i];
        v[i] = aux;        
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
    
    selectionSort(v,n);
    printArray(v,n);

    return 0;
}