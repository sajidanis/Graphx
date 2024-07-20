//
// Created by sajid on 7/20/24.
//

#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <forward_list>

#include "DataStructure_Interface.h"

#include <unordered_map>
#include <unordered_set>

template <typename T>
class AdjacencyList : public BaseStructure<T> {
private:
    std::unordered_map<std::shared_ptr<Node<T>>, std::unordered_set<std::shared_ptr<Node<T>>, NodeHasher<T>>, NodeHasher<T>> adjacencyList;
    // std::unordered_set<std::shared_ptr<Edge<T>>, EdgeHasher<T>> edges;
    std::unordered_map<std::pair<std::shared_ptr<Node<T>>, std::shared_ptr<Node<T>>>, std::shared_ptr<Edge<T>>> edgeMappings;

public:

    void addEdge(std::shared_ptr<Node<T>> u, std::shared_ptr<Node<T>> v, double weight) override {
        if(!adjacencyList.contains(u)) { // Check if source vertex is there or not in the list
            throw std::runtime_error("Source vertex not found");
        }
        if(adjacencyList[u].contains(v)) {
            throw std::runtime_error("Duplicate entry found");
        }
        adjacencyList[u].insert(v);
        edgeMappings[{u, v}] = new Edge<T>(u, v, weight);
    }

    void removeEdge(std::shared_ptr<Node<T>> u, std::shared_ptr<Node<T>> v) override {
        if(!adjacencyList.contains(u) || !adjacencyList[u].contains(v)) {
            throw std::runtime_error("Edge does not exist in the graph");
        }
        adjacencyList[u].erase(v);
        edgeMappings.erase({u, v});
    }

    bool hasEdge(std::shared_ptr<Node<T>> u, std::shared_ptr<Node<T>> v) override {
        if(adjacencyList.contains(u) and adjacencyList[u].contains(v)) {
            return true;
        }
        return false;
    }

    std::vector<std::shared_ptr<Node<T>>> getNeighbours(std::shared_ptr<Node<T>> u) override {
        std::vector<std::shared_ptr<Node<T>>> neighbours;
        for(auto &neighbour : adjacencyList[u]) {
            neighbours.emplace_back(neighbour);
        }
        return neighbours;
    }
};

#endif //ADJACENCYLIST_H
