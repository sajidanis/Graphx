//
// Created by sajid on 7/22/24.
//

#ifndef BFS_H
#define BFS_H
#include <queue>
#include <unordered_set>

#include "BaseGraph.h"

template <typename T>
void bfs(const BaseGraph<T> &graph, T startId ) {
    if(!graph.hasNode(startId)) {
        throw std::runtime_error("Start node not found");
    }

    std::queue<std::shared_ptr<Node<T>>> q;
    std::unordered_set<T> visited;

    q.push(graph.getNode(startId));
    std::cout << "BFS Traversal : ";

    while(!q.empty()) {
        auto currentNode = q.front();
        q.pop();

        std::cout << currentNode->getId() << " ";

        for(auto const &[neighbor, _] : graph.getRepr()->getNeighbours(currentNode)) {
            if(!visited.contains(neighbor->getId())) {
                q.push(neighbor);
                visited.insert(neighbor->getId());
            }
        }
    }
    std::cout << "\n";
}

#endif //BFS_H
