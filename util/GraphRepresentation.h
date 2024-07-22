//
// Created by sajid on 7/21/24.
//

#ifndef GRAPHREPRESENTATIONTYPE_H
#define GRAPHREPRESENTATIONTYPE_H

#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"


#include <memory>

enum class GraphRepresentation {
    ADJACENCY_LIST,
    ADJACENCY_MATRIX
};

template<typename T>
std::unique_ptr<BaseStructure<T>> createGraphRepresentation(
    const GraphRepresentation repr,
    const size_t nodes
) {
    switch (repr) {
        case GraphRepresentation::ADJACENCY_LIST:
            return std::make_unique<AdjacencyList<T>>();
        default:
            throw std::invalid_argument("Unsupported graph representation type");
    }
}

#endif //GRAPHREPRESENTATIONTYPE_H
