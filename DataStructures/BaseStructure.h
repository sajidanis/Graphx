//
// Created by sajid on 7/20/24.
//

#ifndef DATASTRUCTURE_INTERFACE_H
#define DATASTRUCTURE_INTERFACE_H

#include "Node.h"
#include "Edge.h"

#include <vector>
#include <memory>

template <typename T>
class BaseStructure {

protected:
    size_t numberOfNodes = 0;
    size_t numberOfEdges = 0;

public:
    virtual ~BaseStructure() = default;

    virtual void addVertex(std::shared_ptr<Node<T>> u) = 0;

    virtual void removeVertex(std::shared_ptr<Node<T>> u) = 0;

    virtual void addEdge(std::shared_ptr<Node<T>> u, std::shared_ptr<Node<T>> v, std::shared_ptr<EdgeData> ed) = 0;

    virtual void removeEdge(std::shared_ptr<Node<T>> u, std::shared_ptr<Node<T>> v) = 0;

    virtual bool hasEdge(std::shared_ptr<Node<T>> u, std::shared_ptr<Node<T>> v) = 0;

    virtual std::vector<std::pair<std::shared_ptr<Node<T>>, std::shared_ptr<EdgeData>>> getNeighbours(std::shared_ptr<Node<T>> u) const = 0;

    virtual size_t getOutbounds(std::shared_ptr<Node<T>> u) const = 0;

    virtual void display() const = 0;
};

#endif //DATASTRUCTURE_INTERFACE_H
