#include <rpcndr.h>
#include <iostream>
#include <fstream>
#include "Graph.h"

struct Node {
    int data;
    Node *next;
};
struct List {
    struct Node *head;
};

class Graph {
    int vertices;
    struct List *adjacencyList;

public:
    Graph(int vertices) {
        this->vertices = vertices;
        adjacencyList = new List[vertices];
        for (int i = 0; i < vertices; i++) {
            adjacencyList[i].head = NULL;
        }
    }

    Node *newAdjListNode(int data) {
        Node *nextNode = new Node;
        nextNode->data = data;
        nextNode->next = NULL;
        return nextNode;
    }

    boolean ReadGraph(char *arg[]) {
        std::ifstream inputFile(arg[1]);
        if (!inputFile.is_open()) {
            std::cout << "Error opening file " << arg[1] << std::endl;
        } else {
            while (!inputFile.eof()) {
                //TODO
            }
        }
    }

    void TopologicalSort() {}

    void ShortestPath() {}

    void MinimumSpanningTree() {}
};

int main() {

    return 0;
}
