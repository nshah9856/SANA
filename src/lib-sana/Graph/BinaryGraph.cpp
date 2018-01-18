#include "BinaryGraph.hpp"


void BinaryGraph::AddEdge(const unsigned int &node1, const unsigned int &node2, const unsigned int& weight) {
    adjacencyMatrix[node1][node2] = adjacencyMatrix[node2][node1] = true;
    Graph::AddEdge(node1, node2);
}

void BinaryGraph::RemoveEdge(const unsigned int &node1, const unsigned int &node2) {
    adjacencyMatrix[node1][node2] = adjacencyMatrix[node2][node1] = false;
    Graph::RemoveEdge(node1, node2);
}

void BinaryGraph::SetNumNodes(const unsigned int &numNodes) {
    adjacencyMatrix.resize(numNodes);
    for (int i = 0; i < numNodes; i++)
        adjacencyMatrix[i].resize(numNodes);
    Graph::SetNumNodes(numNodes);
}