#include <stdio.h>
#include <stdlib.h>
#define TAM 20
 
typedef struct {
   int tamOcupado;
   int tamDisponivel;
}Pendrive;
 
typedef struct Memory{
   int quantPendrives;
   Pendrive pendrive[TAM];
}Memory;
 
void printMemory(Memory *memory){
   for(int i = 0; i<memory->quantPendrives; i++){
       printf("\nPendrive %d\n",i+1);       
       printf("Tamanho ocupado: %d\n",memory->pendrive[i].tamOcupado);
       printf("Tamanho disponível: %d\n",memory->pendrive[i].tamDisponivel);
   }
}
 
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
       if ( v[i] >= pivot){
           i++;
       }
       else if (v[j] < pivot){
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
 
Memory* createMemory(){
   Memory *memory = (Memory*)malloc(sizeof(Memory));
   memory->quantPendrives = 0;
   for(int i = 0; i < TAM; i++){
       memory->pendrive[i].tamOcupado = 0;
       memory->pendrive[i].tamDisponivel = 64;
   }
   return memory;
}
 
void storeItemInPendrive(Memory *memory, int item){
   for(int i = 0; i < TAM; i++){
       if(memory->pendrive[i].tamDisponivel >= item){
           if (memory->pendrive[i].tamOcupado == 0){
               memory->quantPendrives += 1;
           }          
           memory->pendrive[i].tamOcupado += item;
           memory->pendrive[i].tamDisponivel -= item;
           break;
       }
   }
}
 
void storeData(Memory *memory, int itens[], int quantItens){
   for (int i = 0; i < quantItens; i++){
       storeItemInPendrive(memory ,itens[i]);
   }
}
 
int main(){
   int quantItens, *itens;
  
   Memory *memory;  
   memory = createMemory();
 
   printf("Digite a quantidade de arquivos: ");
   scanf("%i",&quantItens);
   itens = (int*)malloc(quantItens*sizeof(int));
 
   printf("Digite o tamanho de cada arquivo: \n");
   for (int i = 0; i < quantItens; i++){
       scanf("%i", &itens[i]);
   }
  
   quicksort(itens,0, quantItens-1);
   printArray(itens,quantItens);
 
   storeData(memory, itens, quantItens);
   printf("\nQuantidade de pendrives: %d\n",memory->quantPendrives);
   printMemory(memory);
 
   return 0;
}
