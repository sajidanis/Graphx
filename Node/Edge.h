//
// Created by sajid on 7/20/24.
//

#ifndef EDGE_H
#define EDGE_H

#include <memory>
#include <functional>

#include "EdgeData.h"

// Generic Node class template
template <typename T>
class Edge {
private:
    uid_t id = 0;
    T u;
    T v;
    EdgeData edgeData;

public:
    explicit Edge(T u, T v, const EdgeData ed) : id(reinterpret_cast<uid_t>(this)), u(u), v(v), edgeData(ed) {}

    bool operator==(const Edge& other) const {
        return u == other.u and v == other.v and edgeData == other.edgeData;
    }

    bool operator!=(const Edge& other) const {
        return u != other.u or v != other.v or edgeData != other.edgeData;
    }

    bool operator<(const Edge& other) const {
        return edgeData < other.edgeData;
    }

    bool operator<=(const Edge& other) const {
        return edgeData <= other.edgeData;
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
