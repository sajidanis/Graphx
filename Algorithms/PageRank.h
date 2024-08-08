//
// Created by sajid on 8/1/24.
//

#ifndef PAGERANK_H
#define PAGERANK_H

#include "BaseGraph.h"

template <typename T>
std::unordered_map<T, double> pageRank(const BaseGraph<T> &graph, float damping=0.85, const int max_iter = 100, const double epsilon = 1e-6) {
    std::unordered_map<T, double> pr_map;
    const size_t numNodes = graph.getNodes();
    double diff = 0.0;
    auto nodeMappings = graph.getNodeMappings();
    auto repr = graph.getRepr();
    // Create an initial pr_map
    for(auto &[key, node] : nodeMappings) {
        pr_map[key] = ((1.0 - damping) / numNodes);
    }

    for(int iter = 0 ; iter < max_iter ; iter++) {
        std::unordered_map<T, double> new_pr_map;
        for(auto &[key, node]  : nodeMappings) {
            auto neighbours = repr->getNeighbours(node);
            size_t outlink = neighbours.size();
            if(outlink == 0) {
                for(auto &[k, val] : pr_map) {
                    new_pr_map[k] = damping * pr_map[key] / numNodes;
                }
            } else {
                const double distributePr = pr_map[key] / outlink;
                for(auto &[nbr, edgeData] : neighbours) {
                    T node_id = nbr->getId();
                    new_pr_map[node_id] += damping * distributePr;
                }
            }
        }

        for (auto &[k, _] : nodeMappings) {
            diff += static_cast<double>(std::abs(new_pr_map[k] - pr_map[k]));
        }

        pr_map = new_pr_map;

        if(diff < epsilon) {
            std::cout << "\n[+] Converged after : " << iter + 1 << " iterations.\n";
            break;
        }
    }
    return pr_map;
}


#endif //PAGERANK_H
