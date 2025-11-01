#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int vertex;
  struct Node *next;
} Node;

typedef struct Graph {
  int vertices;
  Node **list;
} Graph;

Node *createNode(int v) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->vertex = v;
  node->next = NULL;
  return node;
}

Graph *init(int vertices) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->vertices = vertices;
  graph->list = (Node **)malloc(vertices * sizeof(Node *));
  for (int i = 0; i <= vertices; i++) {
    graph->list[i] = NULL;
  }
  return graph;
}

void addEdge(Graph *graph, int src, int dest) {
  if (src < 0 || src >= graph->vertices || dest < 0 ||
      dest >= graph->vertices) {
    printf("Not possible");
    return;
  }
  Node *node = createNode(dest);
  node->next = graph->list[src];
  graph->list[src] = node;

  node = createNode(src);
  node->next = graph->list[dest];
  graph->list[dest] = node;
}

void print(Graph *graph) {
  for (int i = 0; i < graph->vertices; i++) {
    printf("%d", i + 1);
    Node *temp = graph->list[i];
    while (temp != NULL) {
      printf(" %d ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

void buildGraph(Graph *graph) {
  int v = graph->vertices;
  for (int i = 1; i <= v; i++) {
    for (int j = 1; j <= v; j++) {
      if (i != j && (i % j == 0)) {
        addEdge(graph, i - 1, j - 1);
      }
    }
  }
}

int degree(Graph *graph, int v) {
  if (v < 0 || v >= graph->vertices) {
    return -1;
  }
  int count = 0;
  Node *temp = graph->list[v];
  while (temp) {
    count++;
    temp = temp->next;
  }
  return count;
}

void printNeighbors(Graph *graph, int v) {
  if (v < 0 || v >= graph->vertices) {
    printf("Invalid vertex.\n");
    return;
  }
  printf("Neighbors of %d: ", v + 1);
  Node *tmp = graph->list[v];
  if (!tmp)
    printf("(none)");
  while (tmp) {
    printf("%d ", tmp->vertex + 1);
    tmp = tmp->next;
  }
  printf("\n");
}

void printNeighboursOfNeighbours(Graph *graph, int v) {
  if (v < 0 || v > graph->vertices) {
    printf("Invalid\n");
    return;
  }
  int N = graph->vertices;
  int *direct = (int *)calloc(N, sizeof(int));
  int *result = (int *)calloc(N, sizeof(int));

  direct[v] = 1;
  Node *temp = graph->list[v];
  while (temp) {
    direct[temp->vertex] = 1;
    temp = temp->next;
  }

  temp = graph->list[v];
  while (temp) {
    Node *t = graph->list[temp->vertex];
    while (t) {
      int nvertex = t->vertex;
      if (!direct[nvertex]) {
        result[nvertex] = 1;
      }
      t = t->next;
    }
    temp = temp->next;
  }
  printf("Neighbours of Neighbours of %d:\n", v + 1);
  int exists = 0;
  for (int i = 0; i < N; i++) {
    if (result[i]) {
      printf(" %d ", i + 1);
    }
  }
  if (!exists)
    printf("(none)");
  printf("\n");
  free(direct);
  free(result);
}
