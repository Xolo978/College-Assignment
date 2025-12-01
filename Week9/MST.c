#include <limits.h>
#include <stdlib.h>
#define MAX 100

typedef struct GraphMatrix {
  int matrix[100][100];
  int vertices;
} GMatrix;

typedef struct Node {
  int vertex;
  int weight;
  struct Node *next;
} Node;

typedef struct GraphList {
  Node *head;
} GList;

GList *list[MAX]; // list[0] would hold all neighbours of vertex 0

void initList(int v) {
  for (int i = 0; i < v; i++) {
    list[i] = (GList *)malloc(sizeof(GList));
    list[i]->head = NULL;
  }
}

void addEdgeList(int src, int dest, int weight) {
  Node *new = (Node *)malloc(sizeof(Node));
  new->vertex = dest;
  new->weight = weight;
  // Insert at head of the list
  new->next = list[src]->head;
  list[src]->head = new;

  new->vertex = src;
  new->weight = weight;
  // Insert at head of the list
  new->next = list[dest]->head;
  list[dest]->head = new;
}

GMatrix *initGMatrix(int vertices) {
  GMatrix *g = malloc(sizeof(GMatrix));
  g->vertices = vertices;
  for (int i = 0; i < vertices; i++) {
    for (int j = 0; j < vertices; j++) {
      g->matrix[i][j] = 0;
    }
  }
  return g;
}

int minKey(int key[], int mstSet[], int vertices) {
  int min = INT_MAX;
  int minIndex = -1;
  for (int i = 0; i < vertices; i++) {
    if (!mstSet[i] && key[i] < min) {
      min = key[i];
      minIndex = i;
    }
  }
  return minIndex;
}

int minKeyList(int v, int key[], int mstSet[]) {}

void primList(int v, int start) {
  int parent[v];
  int key[v];
  int mstSet[v];
  for (int i = 0; i < v; i++) {
    key[i] = INT_MAX;
    parent[i] = -1;
    mstSet[i] = 0;
  }
  // Start usually 0
  key[start] = 0;
  for (int count = 0; count < v; count++) {
    int u = minKeyList(v, key, mstSet);
  }
}

void prim(GMatrix *g) {
  int vertices = g->vertices;

  int parent[vertices];
  int mstSet[vertices];
  int key[vertices];

  for (int i = 0; i < vertices; i++) {
    key[i] = INT_MAX;
    mstSet[i] = 0;
    parent[i] = -1;
  }
  key[0] = 0;
  // There are V-1 edges for a spanning tree
  for (int count = 0; count < vertices - 1; count++) {
    int m = minKey(key, mstSet, vertices); // Min vertex not yet in MST
    mstSet[m] = 1;                         // Add the vertex to the mst
    for (int v = 0; v < vertices; v++) {
      int weight = g->matrix[m][v];
      if (weight != 0 && !mstSet[v] && weight < key[v]) {
        parent[v] = m;
        key[v] = weight;
      }
    }
  }
}
