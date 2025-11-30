#include <stdio.h>
#include <stdlib.h>
typedef struct Queue {
  int arr[100];
  int front;
  int rear;
} Q;

typedef struct Graph {
  int vertices;
  int matrix[10][10];
} Graph;

Graph *init(int vertices) {
  Graph *graph = malloc(sizeof(Graph));
  graph->vertices = vertices;
  for (int i = 0; i < vertices; i++) {
    for (int j = 0; j < vertices; j++) {
      graph->matrix[i][j] = 0;
    }
  }
  return graph;
}

void addEdge(Graph *g, int src, int dest) {
  if (src >= g->vertices || dest >= g->vertices) {
    printf("Not possible\n");
    return;
  }
  g->matrix[src][dest] = 1;
  g->matrix[dest][src] = 1;
}

Q *initQ() {
  Q *q = malloc(sizeof(Q));
  q->front = -1;
  q->rear = -1;
  return q;
}

int isEmpty(Q q) {
  if (q.front == -1) {
    return 1;
  }
  return 0;
}

int isFull(Q q) {
  if (q.rear >= 100) {
    return 1;
  }
  return 0;
}

void enQueue(Q *q, int data) {
  if (isFull(*q)) {
    return;
  }
  if (isEmpty(*q)) {
    q->front = q->rear = 0;
  } else {
    q->rear++;
  }
  q->arr[q->rear] = data;
  return;
}

int deQueue(Q *q) {
  if (isEmpty(*q)) {
    return -1;
  }
  int popped = q->arr[q->front];
  if (q->rear == q->front) {
    q->rear = q->front = -1;
  } else {
    q->front++;
  }
  return popped;
}

void printGraph(Graph *graph) {
  printf("Graph is below:\n");
  for (int i = 0; i < graph->vertices; i++) {
    for (int j = 0; j < graph->vertices; j++) {
      printf("%d ", graph->matrix[i][j]);
    }
    printf("\n");
  }
}

void BFS(Graph *g, int v) {
  int visited[10] = {0};
  Q *q = initQ(); // Exploration queue
  visited[v] = 1;
  enQueue(q, v);
  while (!isEmpty(*q)) {
    int node = deQueue(q); // Dequed since done exploring
    printf("%d ", node);
    // Visit all the neighbours of the node
    for (int i = 0; i < g->vertices; i++) {
      if (g->matrix[node][i] == 1 && !visited[i]) {
        visited[i] = 1;
        enQueue(q, i); // Do enqueue the neighbours
      }
    }
  }
  printf("\n");
}

void DFS(Graph *g, int v) {
  static int visited[10] = {0};
  visited[v] = 1;
  // Visit all the neighbours
  for (int i = 0; i < g->vertices; i++) {
    // i is the neighbour
    if (g->matrix[v][i] == 1 && !visited[i]) {
      DFS(g, i);
    }
  }
}

int main() {
  Q *q = initQ();
  Graph *g = init(7);
  addEdge(g, 0, 1);
  addEdge(g, 0, 2);
  addEdge(g, 0, 3);
  addEdge(g, 2, 4);
  addEdge(g, 3, 4);
  addEdge(g, 4, 5);
  addEdge(g, 4, 6);
  printGraph(g);
  int v = 1;
  printf("\nBFS starting from %d is: ", v);
  BFS(g, v);
  return 0;
}
