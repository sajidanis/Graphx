//
// Created by sajid on 8/8/24.
//

#ifndef TRIANGLECOUNTING_H
#define TRIANGLECOUNTING_H
#include "BaseGraph.h"

// Trace of A^3 // 3

template<typename T>
long long tc(const BaseGraph<T> &graph) {
    auto repr = graph.getRepr();
    long long res = 0;

    for (auto &[nodeId, node] : graph.getNodeMappings()) {
        for (auto &[p, _] : repr->getNeighbours(node)) {
            for (auto &[r, _] : repr->getNeighbours(p)) {
                if (graph.isDirectedGraph()) {
                    if (repr->hasEdge(r, node)) {
                        res++;
                    }
                } else {
                    if (r->getId() > p->getId() && repr->hasEdge(r, node)) {
                        res++;
                    }
                }
            }
        }
    }
    return graph.isDirectedGraph() ? res : res / 3;
}

#endif //TRIANGLECOUNTING_H
