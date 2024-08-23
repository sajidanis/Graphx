//
// Created by sajid on 8/18/24.
//

#ifndef COLOR_H
#define COLOR_H
#include <set>
#include <vector>

#include "BaseGraph.h"

inline int c = 0;

// Welsh-Powell algorithm
template <typename T>
std::unordered_map<T, int> color(BaseGraph<T> &graph) {
    std::unordered_map<T, int> colors;

    auto repr = graph.getRepr();
    auto valency = graph.getValency();
    sort(valency.begin(), valency.end(), [](const std::pair<int, T> &p1, const std::pair<int, T> &p2)
    {
        return p1.first > p2.first;
    });

    for(auto &el : valency) {
        T node = el.second;
        if(colors.contains(node)) {
            continue;
        }
        colors[node] = c;
        std::set<T> nbrs;
        auto pred = [](std::pair<std::shared_ptr<Node<T>>, std::shared_ptr<EdgeData>> &item)
        {
            return item.first->getId();
        };
        auto temp = graph.getRepr()->getNeighbours(graph.getNodeMappings()[node]);
        std::transform(temp.begin(), temp.end(), std::inserter(nbrs, nbrs.begin()), pred);

        for(auto &[id, _] : graph.getNodeMappings()) {
            if(!nbrs.contains(id) and !colors.contains(id)) {
                colors[id] = c;
                // Append the neighbours of this node
                for(auto &nbr : graph.getRepr()->getNeighbours(graph.getNodeMappings()[id])) {
                    nbrs.insert(nbr.first->getId());
                }
            }
        }
        c++;
    }
    return colors;
}

#endif //COLOR_H
