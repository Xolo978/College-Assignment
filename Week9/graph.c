// If there is an edge between vertex i and j then
// matrix[i][j] = 1; else its 0

/**
 0 —— 1
|    /
|   /
2——3

 Considering this graph for adjacency list
 We want to store in this format
0 → [1 → 2]
1 → [0 → 3]
2 → [0 → 3]
3 → [1 → 2]
 basically we want to store all the neighbours of a vertex

 adjLists → [ * | * | * | * ]
              ↓   ↓   ↓   ↓
Vertex 0:   1 → 2 → NULL
Vertex 1:   0 → 3 → NULL
Vertex 2:   0 → 3 → NULL
Vertex 3:   1 → 2 → NULL

**/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
  int numVertices;
  int matrix[MAX][MAX];
} GraphMatrix;

typedef struct Node {
  int vertex;
  struct Node *next;
} Node;

typedef struct {
  int numVertices;
  Node **adjLists; // Pointer to an array of linked list heads
} GraphList;

// i is the source node
// j is the dest node
// matrix[i][j] tells wether there is an edge btwn vertex i and vertex j
// For n vertices the matrix is nxn which means 1 row and 1 column for 1 vertex
GraphMatrix *initMatrix(int vertices) {
  GraphMatrix *graph = malloc(sizeof(GraphMatrix));
  graph->numVertices = vertices;
  for (int i = 0; i < vertices; i++) {
    for (int j = 0; j < vertices; j++) {
      graph->matrix[i][j] = 0;
    }
  }
  return graph;
}

GraphList *initList(int vertices) {
  GraphList *graph = malloc(sizeof(GraphList));
  graph->numVertices = vertices;

  graph->adjLists = malloc(
      vertices *
      sizeof(Node *)); // Allocate memory for node pointers not the nodes itself
  for (int i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
  }
  return graph;
}

void addEdgeList(GraphList *graph, int src, int dest) {
  Node *new = malloc(sizeof(Node));
  new->vertex = dest;
  new->next = graph->adjLists[src];
  graph->adjLists[src] = new; // Updated list of neighbours

  // Same thing with the dest
  new = malloc(sizeof(Node));
  new->vertex = src;
  new->next = graph->adjLists[dest];
  graph->adjLists[dest] = new; // Updated list of neighbours
}

void addVertexList(GraphList *graph) {
  graph->numVertices++;
  graph->adjLists =
      realloc(graph->adjLists, graph->numVertices * sizeof(Node *));
  graph->adjLists[graph->numVertices - 1] = NULL;
}

void printGraphList(GraphList *graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    Node *temp = graph->adjLists[i];
    printf("%d ->", i);
    while (temp != NULL) {
      printf("%d ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

void addNodeMatrix(GraphMatrix *graph) {
  if (graph->numVertices >= MAX) {
    printf("Matrix full");
    return;
  }
  int v = graph->numVertices;
  for (int i = 0; i <= v; i++) {
    graph->matrix[v][i] = 0;
    graph->matrix[i][v] = 0;
  }
  graph->numVertices++;
}

void addEdgeMatrix(GraphMatrix *graph, int src, int dest) {
  if (src >= graph->numVertices || dest >= graph->numVertices) {
    printf("Not possible");
    return;
  }
  graph->matrix[src][dest] = 1;
  graph->matrix[dest][src] = 1;
}

void printGraphMatrix(GraphMatrix *graph) {
  printf("Graph is below:\n");
  for (int i = 0; i < graph->numVertices; i++) {
    for (int j = 0; j < graph->numVertices; j++) {
      printf("%d", graph->matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int vertices = 4;
  printf("Graph with matrix\n");
  GraphMatrix *matrixGraph = initMatrix(vertices);
  addEdgeMatrix(matrixGraph, 0, 1);
  addEdgeMatrix(matrixGraph, 0, 2);
  addEdgeMatrix(matrixGraph, 1, 3);
  printGraphMatrix(matrixGraph);
  addNodeMatrix(matrixGraph);
  printf("After adding one vertex:\n");
  printGraphMatrix(matrixGraph);

  printf("\n");
  printf("Graph with list\n");

  GraphList *listGraph = initList(vertices);
  addEdgeList(listGraph, 0, 1);
  addEdgeList(listGraph, 0, 2);
  addEdgeList(listGraph, 1, 3);
  printGraphList(listGraph);
  addVertexList(listGraph);
  printf("After adding one vertex:\n");
  printGraphList(listGraph);
}
