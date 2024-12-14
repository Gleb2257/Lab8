#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <ctime>

#define MAX_VERTICES 10 

// Функция для генерации случайной матрицы смежности
void generateAdjacencyMatrix(std::vector<std::vector<int>>& graph, int vertices) {
    srand(static_cast<unsigned>(time(0))); // Инициализация генератора случайных чисел

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
void printAdjacencyMatrix(const std::vector<std::vector<int>>& graph, int vertices) {
    std::cout << "Матрица смежности графа:" << std::endl;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Обход графа в ширину с использованием std::queue
void bfs(const std::vector<std::vector<int>>& graph, int vertices, int startVertex) {
    std::vector<bool> visited(vertices, false); 
    std::queue<int> q;                         

    visited[startVertex] = true;
    q.push(startVertex);

    std::cout << "Обход графа в ширину, начиная с вершины " << startVertex << ":" << std::endl;

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();

        std::cout << currentVertex << " ";

        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "");

    int vertices;
    std::cout << "Введите количество вершин графа (не более " << MAX_VERTICES << "): ";
    std::cin >> vertices;

    if (vertices <= 0 || vertices > MAX_VERTICES) {
        std::cout << "Ошибка: некорректное количество вершин." << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> graph(vertices, std::vector<int>(vertices, 0));

    generateAdjacencyMatrix(graph, vertices);
    printAdjacencyMatrix(graph, vertices);

    int startVertex;
    std::cout << "Введите начальную вершину для обхода в ширину: ";
    std::cin >> startVertex;

    if (startVertex < 0 || startVertex >= vertices) {
        std::cout << "Ошибка: некорректная начальная вершина." << std::endl;
        return 1;
    }

    bfs(graph, vertices, startVertex);

    return 0;
}
