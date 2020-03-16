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

void heapify( int v[], int n, int i){

    int largest = i;  
    int l = 2*i + 1; 
    int r = 2*i + 2; 
  
    if (l < n && v[l] > v[largest]) 
        largest = l; 
  
    if (r < n && v[r] > v[largest]) 
        largest = r; 
  
    if (largest != i) { 
        swap( v, i, largest); 
        heapify(v, n, largest); 
    } 
}

void heapsort( int v[], int n){

    for (int i = n/2 - 1; i >=0; i--){
        heapify(v, n, i);
    }

    for (int i = n-1; i>=0; i--){
        swap( v, 0, i);
        heapify( v, i, 0);
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
    
    heapsort(v, n);
    printArray(v,n);

    return 0;
}