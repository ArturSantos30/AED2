#include <stdio.h>
#include <stdlib.h>

void printArray(int v[], int n){

    printf("[ ");
    for (int i = 0; i < n; i++){
        printf("%i ",v[i]);
    }
    printf("]\n");

}

void merge(int v[], int l, int m, int r){

    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int *L = (int*)malloc(n1*sizeof(int));
    int *R = (int*)malloc(n2*sizeof(int));
  
    for (i = 0; i < n1; i++) 
        L[i] = v[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = v[m + 1+ j]; 

    i = 0; 
    j = 0; 
    k = l;
    while (i < n1 && j < n2){ 
        if (L[i] <= R[j]){ 
            v[k] = L[i]; 
            i++; 
        } 
        else{ 
            v[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1) { 
        v[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) { 
        v[k] = R[j]; 
        j++; 
        k++; 
    } 

    free(L);
    free(R);
}

void mergeSort(int v[], int leftInd, int rightInd){

    if ( leftInd < rightInd){
        int m = (leftInd + rightInd)/2;
        mergeSort(v, leftInd, m);
        mergeSort(v, m+1, rightInd);
        merge(v, leftInd, m, rightInd);
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
    
    mergeSort(v,0, n-1);
    printArray(v,n);

    return 0;
}