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
    // In future further data could be added

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

template <typename T>
struct PairHash {
    std::size_t operator()(const std::pair<std::shared_ptr<Node<T>>, std::shared_ptr<Node<T>>>& p) const {
        NodeHasher<T> hasher;
        auto h1 = hasher(p.first);
        auto h2 = hasher(p.second);
        return h1 ^ (h2 << 1); // Combine hash values
    }
};

template <typename T>
struct PairEqual {
    bool operator()(const std::pair<std::shared_ptr<Node<T>>, std::shared_ptr<Node<T>>>& lhs,
                    const std::pair<std::shared_ptr<Node<T>>, std::shared_ptr<Node<T>>>& rhs) const {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }
};

#endif //NODE_H
