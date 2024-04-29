#include <iostream>
using namespace std;

bool check_matrix(int** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (matrix[i][i] != 0)
        {
            return false;
        }
    }
    return true;
}

int minDist(int* dist, bool* sptSet, int size)
{
    //min = ∞
    int min = INT_MAX, min_index;

    for (int v = 0; v < size; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

//Функція для виведення відстані від вершин до стартової вершини
void printRessult(int* dist, int size)
{
    cout << "Vertex         Distance from Source" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "V:" << i << " \t\t" << dist[i] << endl;
    }
}

int* dijkstras_alg(int** graph, int m_size, int start_v)
{
    if (!check_matrix(graph, m_size))
    {
        throw invalid_argument("Matrix has loops.");
    }
    int* dist = new int[m_size]; //масив з відстаннями до стартової вершини
    bool* sptSet = new bool[m_size]; // sptSet[i] = true якщо вершина включена в найкоротший шлях
    // ініціалізовано всі вершини як ∞, та встановлюємо значення sptSet в нуль
    for (int i = 0; i < 4; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    //відстань від стартової вершини до самої себе в нуль
    dist[start_v] = 0;

    // Знаходження найкоротшого шляху до вершин
    for (int count = 0; count < m_size - 1; count++) {
        // вибір з множини dist мінімальне значення та додаємо його в в множину sptSet  
        int u = minDist(dist, sptSet, m_size);
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < m_size; v++)
        {
            // Оновлюємо відстань dist[v], якщо її нема в вершині, 
            // або якщо загальна відстань від шляху від стартової вершини до v через u є менша за поточне значення dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    //веводимо результат
    return dist;
}


int main()
{
    const int size = 4;
    int** matrix = new int* [size];
    matrix[0] = new int[size] {0, 2, 1, 0};
    matrix[1] = new int[size] {1, 0, 0, 3};
    matrix[2] = new int[size] {1, 0, 0, 5};
    matrix[3] = new int[size] {0, 3, 5, 0};

    int* distances = dijkstras_alg(matrix, size, 0);
    printRessult(distances, size);

    // Очистка пам'яті
    delete[] distances;
    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
    

    return 0;
}
