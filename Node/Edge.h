//
// Created by sajid on 7/20/24.
//

#ifndef EDGE_H
#define EDGE_H

#include <memory>
#include <functional>

// Generic Node class template
template <typename T>
class Edge {
private:
    unsigned long long id = 0;
    T u;
    T v;
    double edgeWeight;

public:
    explicit Edge(T u, T v, double weight) : id(reinterpret_cast<unsigned long long>(this)), u(u), v(v), edgeWeight(weight) {}

    bool operator==(const Edge& other) const {
        return u == other.u and v == other.v and edgeWeight == other.edgeWeight;
    }

    bool operator!=(const Edge& other) const {
        return u != other.u or v != other.v or edgeWeight != other.edgeWeight;
    }

    bool operator<(const Edge& other) const {
        return edgeWeight < other.edgeWeight;
    }

    bool operator<=(const Edge& other) const {
        return edgeWeight <= other.edgeWeight;
    }
};

// Hash function for Node
template <typename T>
struct EdgeHasher {
    std::size_t operator()(const std::shared_ptr<Edge<T>>& edge) const {
        return std::hash<T>()(edge->id);
    }
};

#endif //EDGE_H
