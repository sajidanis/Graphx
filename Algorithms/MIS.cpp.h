//
// Created by sajid on 8/23/24.
//

#ifndef MIS_CPP_H
#define MIS_CPP_H
#include <set>


#include "BaseGraph.h"

template <typename T>
std::vector<T> mis(BaseGraph<T> &graph) {
    std::vector<T> result;
    std::set<T> vertexSet;
    auto mappings = graph.getNodeMappings();
    std::transform(mappings.begin(), mappings.end(), std::inserter(vertexSet, vertexSet.end()),
        [](auto pair) {
        return pair.first;
    });

    while(!vertexSet.empty()) {
        auto node = *vertexSet.begin();
        vertexSet.erase(node);
        result.push_back(node);

        // remove the neighbours of this node
        for(auto &el : graph.getRepr()->getNeighbours(mappings[node])) {
            auto v = el.first->getId();
            vertexSet.erase(v);
        }
    }
    return result;
}

#endif //MIS_CPP_H
