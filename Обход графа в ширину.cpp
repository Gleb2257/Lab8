#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define MAX_VERTICES 10 
void generateAdjacencyMatrix(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    srand(time(NULL)); // Инициализация генератора случайных чисел

    for (int i = 0; i < vertices; i++) {
        for (int j = i; j < vertices; j++) {
            if (i == j) {
                graph[i][j] = 0; 
            }
            else {
                int edge = rand() % 2;
                graph[i][j] = edge;
                graph[j][i] = edge;
            }
        }
    }
}

// Функция для вывода матрицы смежности
void printAdjacencyMatrix(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    printf("Матрица смежности графа:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Функция для обхода графа в ширину
void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex) {
    int visited[MAX_VERTICES] = { 0 };
    int queue[MAX_VERTICES];         
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("Обход графа в ширину, начиная с вершины %d:\n", startVertex);

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, ""); 

    int vertices;
    printf("Введите количество вершин графа (не более %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    if (vertices <= 0 || vertices > MAX_VERTICES) {
        printf("Ошибка: некорректное количество вершин.\n");
        return 1;
    }

    int graph[MAX_VERTICES][MAX_VERTICES];
    generateAdjacencyMatrix(graph, vertices);
    printAdjacencyMatrix(graph, vertices);

    int startVertex;
    printf("Введите начальную вершину для обхода в ширину: ");
    scanf("%d", &startVertex);

    if (startVertex < 0 || startVertex >= vertices) {
        printf("Ошибка: некорректная начальная вершина.\n");
        return 1;
    }

    bfs(graph, vertices, startVertex);

    return 0;
}
