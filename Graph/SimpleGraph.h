//
// Created by sajid on 7/20/24.
//

#ifndef SIMPLEGRAPH_H
#define SIMPLEGRAPH_H

#include <memory>

#include "BaseGraph.h"
#include "GraphRepresentation.h"

template <typename T>
class SimpleGraph : public BaseGraph<T> {

public:

    SimpleGraph() = default;

    explicit SimpleGraph(
        const GraphRepresentation repr,
        size_t nodes = 0,
        bool isDirected = true,
        bool isWeighted = true

    ) {
        if(repr == GraphRepresentation::ADJACENCY_MATRIX and nodes <= 0) {
            throw std::runtime_error("For adjacency matrix number of nodes need to be defined");
        }
        this->repr = createGraphRepresentation<T>(repr, nodes);
        this->nodes = nodes;
    }

    auto addEdge(T u, T v, std::shared_ptr<EdgeData> ed) -> void override;
    auto removeEdge(T u, T v) -> void override;
};

template<typename T>
auto SimpleGraph<T>::addEdge(T u, T v, std::shared_ptr<EdgeData> ed) -> void {
    if(!this->nodeMappings.contains(u)) {
        this->nodeMappings[u] = std::make_shared<Node<T>>(u);
        this->repr->addVertex(this->nodeMappings[u]);
        ++this->nodes;
    }

    if(!this->nodeMappings.contains(v)) {
        this->nodeMappings[v] = std::make_shared<Node<T>>(v);
        this->repr->addVertex(this->nodeMappings[v]);
        ++this->nodes;
    }

    // add the edge
    this->repr->addEdge(this->nodeMappings[u], this->nodeMappings[v], ed);
    ++this->edges;
    if(!this->isDirected) {
        this->repr->addEdge(this->nodeMappings[v], this->nodeMappings[u], ed);
        ++this->edges;
    }
}

template<typename T>
auto SimpleGraph<T>::removeEdge(T u, T v) -> void {
    this->repr->removeEdge(this->nodeMappings[u], this->nodeMappings[v]);
    if(!this->isDirected) {
        this->repr->removeEdge(this->nodeMappings[v], this->nodeMappings[u]);
    }
    --this->edges;
}

#endif //SIMPLEGRAPH_H
