//
// Created by sajid on 7/21/24.
//

#ifndef EDGEDATA_H
#define EDGEDATA_H

typedef struct EdgeData {
    double weight;

    explicit EdgeData(const double weight = 0) : weight(weight) {}

    [[nodiscard]] std::string toString() const {
        return "{weight: " + std::to_string(weight) + " }";
    }

    bool operator==(const EdgeData& other) const {
        return  weight == other.weight;
    }

    bool operator!=(const EdgeData& other) const {
        return weight != other.weight;
    }

    bool operator<(const EdgeData& other) const {
        return weight < other.weight;
    }

    bool operator<=(const EdgeData& other) const {
        return weight <= other.weight;
    }
} EdgeData;

#endif //EDGEDATA_H
