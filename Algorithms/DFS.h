//
// Created by sajid on 7/22/24.
//

#ifndef DFS_H
#define DFS_H

#include <stack>
#include <unordered_set>

#include "BaseGraph.h"

template <typename T>
void dfs(const BaseGraph<T> &graph, T startId) {
    if (!graph.hasNode(startId)) {
        throw std::runtime_error("Start node not found");
    }

    std::unordered_set<T> visited;

    std::stack<std::shared_ptr<Node<T>>> s;
    s.push(graph.getNode(startId));
    visited.insert(startId);

    std::cout << "DFS Traversal : ";

    while (!s.empty()) {
        auto currentNode = s.top();
        s.pop();
        T currentId = currentNode->getId();

        // Print the node and its level
        std::cout << currentNode->getId() << " ";

        // Process all neighbors
        for (auto const &[neighbor, _] : graph.getRepr()->getNeighbours(currentNode)) {
            if (T neighborId = neighbor->getId(); !visited.contains(neighborId)) {
                visited.insert(neighborId);
                s.push(neighbor);
            }
        }
    }
    std::cout << "\n";
}

#endif //DFS_H
