// Copyright 2021 Skripal Andrey
#include "../../../modules/task_1/skripal_a_dijkstra_algorithm/dijkstra_algorithm.h"
#include <ctime>
#include <random>

std::vector<int> getGraph(int size) {
    std::mt19937 gen;
    gen.seed(static_cast<unsigned int>(time(0)));
    std::vector<int> graph(size*size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                graph[i*size + j] = 0;
            } else {
                if (j < i) {
                    graph[i*size + j] = graph[j*size   + i];
                } else {
                    graph[i*size + j] = gen() % 100;
                }
            }
        }
    }
    return graph;
}

std::vector<int> seqDijkstras(std::vector<int> graph, int start, int end) {
    int size = sqrt(graph.size());
    int max_weight = std::numeric_limits<int>::max();

    std::vector<int> dist(size, max_weight);
    std::vector<bool> visit(size, false);
    std::vector<int> res;
    start--;
    end--;

    int min_index = max_weight;
    dist[start] = 0;

    for (int i = 0; i < size-1; i++) {
        int min_weight = max_weight;
        for (int j = 0; j < size  ; j++) {
            if (!visit[j] && dist[j] <= min_weight) {
                min_weight = dist[j];
                min_index = j;
            }
        }
         visit[min_index] = true;

        for (int k = 0; k < size  ; k++) {
            if (!visit[k] && dist[min_index] != max_weight &&
                graph[min_index*size + k] &&
                dist[min_index] + graph[min_index*size+ k] < dist[k]) {
                dist[k] = dist[min_index] + graph[min_index*size+ k];
            }
        }
    }
    res.push_back(end + 1);
    int weight = dist[end];

    while (end != start) {
        for (int i = 0; i < size; i++) {
            if (graph[end * size + i] > 0) {
                int tmp = weight - graph[end * size + i];
                if (dist[i] == tmp) {
                    weight = tmp;
                    end = i;
                    res.push_back(i + 1);
                }
            }
        }
    }

    return res;
}
