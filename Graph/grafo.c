#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

typedef struct Queue {
    int items[SIZE];
    int front;
    int rear;
}Queue;

typedef struct Node {
    int vertex;
    struct Node* next;
}Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* visited;
}Graph;

Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {

    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

Queue* createQueue(){
    Queue* q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue* q){
    return (q->rear == -1)? 1 : 0;
}

void enqueue(Queue* q, int value){
    if (q->rear == SIZE - 1)
        printf("\nQueue is Full!!");
    else {
        if (q->front == -1)
        q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q){
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            printf("Resetting queue ");
            q->front = q->rear = -1;
        }
    }
    return item;
}

void printQueue(Queue* q){
    int i = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty");
    } else {
        printf("\nQueue contains \n");
        for (i = q->front; i < q->rear + 1; i++) {
            printf("%d ", q->items[i]);
        }
    }
}

void bfs(Graph* graph, int startVertex){
    Queue* q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        printQueue(q);
        int currentVertex = dequeue(q);
        printf("Visited %d\n", currentVertex);

        Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

void is_there_path(Graph* graph, int src, int dest){
    bfs(graph, src);
    printf("\nProcurando caminho entre %d e %d \n",src,dest);
    if (graph->visited[dest])
        printf("Caminho encontrado\n");
    else printf("Caminho nao encontrado\n");
}

int main() {
    int nVertices,nArestas,u,v;
    printf("Digite a quantidade de vertices: ");
    scanf("%d",&nVertices);
    Graph* graph = createGraph(nVertices+1);

    printf("Digite a quantidade de arestas: ");
    scanf("%d",&nArestas);

    for(int i=0; i<nArestas; i++){
        scanf("%d",&u);
        scanf("%d",&v);
        addEdge(graph, u, v);
    }
    
    printf("Digite o vertice de origem e o de destino: ");
    scanf("%d",&u);
    scanf("%d",&v);
    is_there_path(graph,u,v);

    return 0;
}