//
// Created by sajid on 7/20/24.
//

#ifndef BASEGRAPH_H
#define BASEGRAPH_H

#include "BaseStructure.h"
#include <iostream>

template <typename T>
class BaseGraph {
protected:
    size_t nodes = 0;
    size_t edges = 0;

    bool isDirected = true;
    bool isWeighted = false;

    std::unique_ptr<BaseStructure<T>> repr;

    std::unordered_map<T, std::shared_ptr<Node<T>>> nodeMappings;

public:
    virtual ~BaseGraph() = default;

    BaseGraph() = default;

    virtual void addEdge(T u, T v, std::shared_ptr<EdgeData> ed) = 0;

    virtual void removeEdge(T u, T v) = 0;

    std::shared_ptr<Node<T>> getNode(T id) const {
        if(!nodeMappings.contains(id)) {
            throw std::runtime_error("Node does not exist");
        }
        return nodeMappings.at(id);
    }

    bool hasNode(T id) const {
        return nodeMappings.contains(id);
    }

    const BaseStructure<T>* getRepr() const {
        return repr.get();
    }

    void display() const {
        std::cout << "===================Graph Output==================" << std::endl;
        for (const auto& [key, node] : nodeMappings) {
            std::cout << "Node [" << key << "]: \n";
            for (auto neighbors = repr->getNeighbours(node); const auto& [neighbor, edgeData] : neighbors) {
                std::cout << " \t=> " << neighbor->getId() << " [Edge Data -> " << edgeData->toString() << "]\n";
            }
        }
        std::cout << "===================Graph Output==================" << std::endl;
    }

};

#endif //BASEGRAPH_H
