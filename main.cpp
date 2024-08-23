#include <iostream>
#include <memory>

#include "Algorithms/DFS.h"
#include "BaseGraph.h"
#include "Color.h"
#include "MIS.cpp.h"
#include "PageRank.h"
#include "SSSP.h"
#include "SimpleGraph.h"
#include "TriangleCounting.h"

int main() {
    const auto graph = std::make_unique<SimpleGraph<int> >(GraphRepresentation::ADJACENCY_LIST);
    graph->addEdge(1, 2, std::make_shared<EdgeData>(2));
    graph->addEdge(2, 3, std::make_shared<EdgeData>(1));
    graph->addEdge(1, 4, std::make_shared<EdgeData>(2));
    graph->addEdge(2, 4, std::make_shared<EdgeData>(3));
    graph->addEdge(3, 1, std::make_shared<EdgeData>(2));
    graph->addEdge(4, 3, std::make_shared<EdgeData>(2));
    graph->addEdge(4, 5, std::make_shared<EdgeData>(2));
    graph->addEdge(5, 3, std::make_shared<EdgeData>(2));\
    graph->addEdge(5, 1, std::make_shared<EdgeData>(2));

    graph->display();

    std::cout << "\n";
    dfs<int>(*graph, 1);

    std::cout << "\n***************************\nPage Rank \n";

    for(auto &[k, val] : pageRank(*graph)) {
        std::cout << "Key : " << k << " --> [ " << val << " ]\n";
    }

    std::cout << "\n***************************\nSSSP \n";
    auto sssp = bellmanFord<int>(*graph, 1);

    for(auto &[k, val] : sssp) {
        std::cout << "Key : " << k << " --> [ " << val << " ]\n";
    }

    std::cout << "\n***************************\nTriangle counting \n";
    std::cout << "Total triangle count: " << tc<int>(*graph) << "\n";


    std::cout << "\n***************************\nGraph Coloring \n";
    for (auto colors = color<int>(*graph); auto &[k, val] : colors) {
        std::cout << "Key : " << k << " --> [ " << val << " ]\n";
    }

    std::cout << "\n***************************\nMaximal Independent State\nIndependent Set --> ";
    for (const auto v : mis<int>(*graph)) {
        std::cout << v << " ";
    }
    std::cout << "\n";

    return 0;
}
