//
// Created by sajid on 7/20/24.
//

#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <forward_list>

#include "BaseStructure.h"

#include <unordered_map>
#include <unordered_set>
#include <stdexcept>
#include <iostream>

template <typename T>
class AdjacencyList : public BaseStructure<T> {
private:
    std::unordered_map<std::shared_ptr<Node<T>>, std::unordered_set<std::shared_ptr<Node<T>>, NodeHasher<T>>, NodeHasher<T>> adjacencyList;
    // std::unordered_set<std::shared_ptr<Edge<T>>, EdgeHasher<T>> edges;
    std::unordered_map<std::pair<std::shared_ptr<Node<T>>, std::shared_ptr<Node<T>>>, std::shared_ptr<EdgeData>, PairHash<T>, PairEqual<T>> edgeMappings;

public:

    AdjacencyList() = default;

    void addVertex(std::shared_ptr<Node<T>> u) override {
        if(adjacencyList.contains(u)) {
            throw std::runtime_error("Vertex already existing");
        }
        adjacencyList[u];
        ++this->numberOfNodes;
    }

    void removeVertex(std::shared_ptr<Node<T>> u) override {
        if(!adjacencyList.contains(u)) {
            throw std::runtime_error("Vertex not existing existing");
        }
        --this->numberOfNodes;
    }

    void addEdge(std::shared_ptr<Node<T>> u, std::shared_ptr<Node<T>> v, std::shared_ptr<EdgeData> edgeData) override {
        if(!adjacencyList.contains(u)) { // Check if source vertex is there or not in the list
            throw std::runtime_error("Source vertex not found");
        }
        if(adjacencyList[u].contains(v)) {
            throw std::runtime_error("Duplicate entry found");
        }
        adjacencyList[u].insert(v);
        edgeMappings[{u, v}] = edgeData;
        ++this->numberOfEdges;
    }

    void removeEdge(std::shared_ptr<Node<T>> u, std::shared_ptr<Node<T>> v) override {
        if(!adjacencyList.contains(u) || !adjacencyList[u].contains(v)) {
            throw std::runtime_error("Edge does not exist in the graph");
        }
        adjacencyList[u].erase(v);
        edgeMappings.erase({u, v});
        --this->numberOfEdges;
    }

    bool hasEdge(std::shared_ptr<Node<T>> u, std::shared_ptr<Node<T>> v) override {
        if(adjacencyList.contains(u) and adjacencyList[u].contains(v)) {
            return true;
        }
        return false;
    }

    std::vector< std::pair< std::shared_ptr<Node<T>>, std::shared_ptr< EdgeData> > > getNeighbours(std::shared_ptr<Node<T>> u) const override {
        std::vector< std::pair< std::shared_ptr< Node<T>>, std::shared_ptr<EdgeData>>> neighbours;
        for(auto &neighbour : adjacencyList.at(u)) {
            neighbours.emplace_back(neighbour, edgeMappings.at({u, neighbour}));
        }
        return neighbours;
    }

    void display() const override {
        for (const auto& [vertex, neighbors] : adjacencyList) {
            std::cout << vertex->getId() << ": ";
            for (const auto& neighbor : neighbors) {
                std::cout << neighbor->getId() << " ";
            }
            std::cout << std::endl;
        }
    }
};

#endif //ADJACENCYLIST_H
