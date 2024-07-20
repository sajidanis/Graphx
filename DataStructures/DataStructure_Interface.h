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
public:
    virtual ~BaseStructure() = default;

    virtual void addEdge(std::shared_ptr<Node<T>> u, std::shared_ptr<Node<T>> v, double weight) = 0;

    virtual void removeEdge(std::shared_ptr<Node<T>> u, std::shared_ptr<Node<T>> v) = 0;

    virtual bool hasEdge(std::shared_ptr<Node<T>> u, std::shared_ptr<Node<T>> v) = 0;

    virtual std::vector<std::shared_ptr<Node<T>>> getNeighbours(std::shared_ptr<Node<T>> u) = 0;

};

#endif //DATASTRUCTURE_INTERFACE_H
