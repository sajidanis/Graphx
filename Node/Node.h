//
// Created by sajid on 7/20/24.
//

#ifndef NODE_H
#define NODE_H

#include <memory>
#include <functional>

// Generic Node class template
template <typename T>
class Node {
private:
    T id;

public:
    explicit Node(T id) : id(id) {}
    T getId() const {
        return id;
    }

    bool operator==(const Node& other) const {
        return id == other.id;
    }

    bool operator!=(const Node& other) const {
        return id != other.id;
    }

    bool operator<(const Node& other) const {
        return id < other.id;
    }
};

// Hash function for Node
template <typename T>
struct NodeHasher {
    std::size_t operator()(const std::shared_ptr<Node<T>>& node) const {
        return std::hash<T>()(node->getId());
    }
};

#endif //NODE_H
