#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <ctime>

#define MAX_VERTICES 10 
// Функция для генерации графа в виде списка смежности
void generateAdjacencyList(std::vector<std::vector<int>>& adjList, int vertices) {
    srand(static_cast<unsigned>(time(0))); // Инициализация генератора случайных чисел

    for (int i = 0; i < vertices; i++) {
        for (int j = i + 1; j < vertices; j++) {
            int edge = rand() % 2; 
            if (edge) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
}

// Функция для вывода списка смежности
void printAdjacencyList(const std::vector<std::vector<int>>& adjList, int vertices) {
    std::cout << "Список смежности графа:" << std::endl;
    for (int i = 0; i < vertices; i++) {
        std::cout << i << ": ";
        for (int neighbor : adjList[i]) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}

// Обход графа в ширину с использованием std::queue
void bfs(const std::vector<std::vector<int>>& adjList, int vertices, int startVertex) {
    std::vector<bool> visited(vertices, false); 
    std::queue<int> q;                         

    visited[startVertex] = true;
    q.push(startVertex);

    std::cout << "Обход графа в ширину, начиная с вершины " << startVertex << ":" << std::endl;

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();

        std::cout << currentVertex << " ";

        for (int neighbor : adjList[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
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

    std::vector<std::vector<int>> adjList(vertices);

    generateAdjacencyList(adjList, vertices);
    printAdjacencyList(adjList, vertices);

    int startVertex;
    std::cout << "Введите начальную вершину для обхода в ширину: ";
    std::cin >> startVertex;

    if (startVertex < 0 || startVertex >= vertices) {
        std::cout << "Ошибка: некорректная начальная вершина." << std::endl;
        return 1;
    }

    bfs(adjList, vertices, startVertex);

    return 0;
}
