//
// Created by sajid on 7/28/24.
//

#ifndef SSSP_H
#define SSSP_H

#include <cfloat>
#include <queue>

#include "BaseGraph.h"

template<typename T>
struct DistNode{
    double dist{};
    T node{};

    bool operator>(const DistNode<T> &other) const {
        return dist > other.dist;
    }
};

template <typename T>
std::unordered_map<T, double> djikstra(const BaseGraph<T> &graph, const T source) {
    std::unordered_map<T, double> distance;

    // initialize the distance mapping of all other vertex to INF
    for(auto &[k, _] : graph.getNodeMappings()) {
        distance[k] = DBL_MAX;
    }
    distance[source] = 0;

    std::priority_queue<DistNode<T>, std::vector<DistNode<T>>, std::greater<DistNode<T>>> pq;

    pq.push({0, source});

    while(!pq.empty()) {
        T cur = pq.top().node;
        pq.pop();

        // get the neighbours
        auto neighbours = graph.getRepr()->getNeighbours(graph.getNode(cur));

        for(auto &nbr : neighbours) {
            T v = nbr.first->getId();
            auto weight = nbr.second.get()->weight;

            if(distance[v] > distance[cur] + weight) {
                // update the distance
                distance[v] = distance[cur] + weight;
                pq.push({distance[v], v});
            }
        }
    }
    return distance;
}

template <typename T>
std::unordered_map<T, double> bellmanFord(const BaseGraph<T> &graph, T source) {
    std::unordered_map<T, double> distance;
    for(auto &[k, _] : graph.getNodeMappings()) {
        distance[k] = DBL_MAX;
    }
    distance[source] = 0;
    auto edges = graph.getRepr()->getEdges();
    for(size_t iter = 1 ; iter <= graph.getNodes(); iter++) {
        bool updated = false;
        for(auto &[nodes, data] : edges) {
            T u = nodes.first->getId();
            T v = nodes.second->getId();
            double weight = data->weight;

            if(distance[u] != DBL_MAX and distance[v] > distance[u] + weight) {
                distance[v] = distance[u] + weight;
                updated = true;
            }
        }
        if(!updated) {
            break;
        }
    }

    // We can detect negative cycle as well if it exists after
    for(auto &[nodes, data] : edges) {
        T u = nodes.first->getId();
        T v = nodes.second->getId();
        double weight = data->weight;

        if(distance[u] != DBL_MAX and distance[v] > distance[u] + weight) {
            throw std::runtime_error("This graph contains negative cycle");
        }
    }
    return distance;
}

#endif //SSSP_H
