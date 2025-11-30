#include <limits.h>
#include <stdlib.h>
typedef struct GrapgMatrix {
  int matrix[100][100];
  int vertices;
} GMatrix;

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
