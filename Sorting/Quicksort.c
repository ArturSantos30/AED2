#include <stdio.h>
#include <stdlib.h>

void printArray(int v[], int n){

    printf("[ ");
    for (int i = 0; i < n; i++){
        printf("%i ",v[i]);
    }
    printf("]\n");

}

void swap(int v[], int i, int j){
    int auxSwap = v[j];
    v[j] = v[i];
    v[i] = auxSwap;
}

int partition(int v[], int leftInd, int rightInd){

    int i = leftInd + 1;
    int j = rightInd;
    int pivot = v[leftInd];

    while ( i <= j){
        if ( v[i] <= pivot){
            i++;
        }
        else if (v[j] > pivot){
            j--;
        }
        else if (i <= j ){
            swap(v, i, j);
            i++;
            j--;
        }
    }
    swap(v, leftInd, j);
    return j;

}

void quicksort(int v[], int leftInd, int rightInd){

    if ( leftInd < rightInd){
        int j = partition(v, leftInd, rightInd );
        quicksort(v, leftInd, j-1);
        quicksort(v, j+1, rightInd);
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
    
    quicksort(v,0, n-1);
    printArray(v,n);

    return 0;
}