#include <iostream>
#include <memory>

#include "BaseGraph.h"
#include "PageRank.h"
#include "SimpleGraph.h"
#include "Algorithms/DFS.h"

int main() {
    const auto graph = std::make_unique<SimpleGraph<int> >(GraphRepresentation::ADJACENCY_LIST);
    graph->addEdge(1, 2, std::make_shared<EdgeData>(2));
    graph->addEdge(1, 3, std::make_shared<EdgeData>(1));
    graph->addEdge(2, 3, std::make_shared<EdgeData>(2));
    graph->addEdge(3, 4, std::make_shared<EdgeData>(2));

    graph->display();

    std::cout << "\n";
    dfs<int>(*graph, 1);

    std::cout << "\n***************************\n";

    for(auto &[k, val] : pageRank(*graph))
    {
        std::cout << "Key : " << k << " --> [ " << val << " ]\n";
    }

    return 0;
}
