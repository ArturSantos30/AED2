#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node{
   char key;
   int isEndOfString;
   struct Node *left, *right, *mid;
} Node;
 
typedef struct{
   Node *root;
} TST;
 
Node* newNode(char c){
   Node *node = (Node*) malloc(sizeof(Node));
   node->isEndOfString = 0;
   node->key = c;
   node->left = NULL;
   node->right = NULL;
   node->mid = NULL;
   return node;
}
 
int len(char *word){
   int i = 0;
   while (word[i]!='\0'){
       i++;
   }
   return i;
}
 
Node* insertNodeOnTree(Node *node, char *word, int i){
  
   if(node == NULL)
       node = newNode(word[i]);
 
   if( i < len(word)-1){
       if (word[i] < node->key)
           node->left = insertNodeOnTree(node->left, word, i);
      
       else if (word[i] > node->key)
           node->right = insertNodeOnTree(node->right, word, i);
 
       else
           node->mid = insertNodeOnTree(node->mid, word, i+1);
   }
   else
       node->isEndOfString = 1;
  
   return node;
}
 
void insert(TST *tree, char *word){
   for (int i = 0; i < len(word); i++){
       insertNodeOnTree(tree->root, word, i);
   }
}
 
int search(TST *tree, char *word){
 
   if(len(word)==0){
       return 0;
   }
 
   Node *p = tree->root;
   int i = 0;
 
   while (p!=NULL){
       if (word[i] < p->key)
           p = p->left;
       else if (word[i] > p->key)
           p = p->right;
       else{
           if (p->isEndOfString)
               return 1;
           i++;
           p = p->mid;
       }
   }
   return 0;
}
 
TST* createTST(){
   TST *tree = (TST*) malloc(sizeof(TST));
   tree->root = (Node*) malloc(sizeof(Node));
   return tree;
}
 
int main(){
  
   TST *tree = createTST();
 
   insert(tree, "blue");
   insert(tree, "black");
   insert(tree, "orange");
   insert(tree, "purple");
   insert(tree, "white");
 
   printf("%d \n",search(tree,"green"));
   printf("%d \n",search(tree,"blue"));
   printf("%d \n",search(tree,"yellow"));
   printf("%d \n",search(tree,"black"));
 
   return 0;
}
