//#include <rpcndr.h>
#include <iostream>
#include <fstream>
#include "Graph.h"

struct Node {
    int adj;
    Node *next;
};
struct List {
    struct Node *head;
};

class Graph {
    int vertices;
    struct List *vertexArray;

public:
    Graph(int vertices) {
        this->vertices = vertices;
        vertexArray = new List[vertices];
        for (int i = 0; i < vertices; i++) {
            vertexArray[i].head = NULL;
        }
    }

    Node *nextNode(int adj) {
        Node *newNode = new Node;
        newNode->adj = adj;
        newNode->next = NULL;
        return newNode;
    }

    void newEdge(int vert, int adj) {
        Node *newNode = nextNode(adj);
        newNode->next = vertexArray[vert].head;
        vertexArray[vert].head = newNode;
        newNode = nextNode(vert);
        newNode->next = vertexArray[adj].head;
        vertexArray[adj].head = newNode;
    }

    void test(){
        for (int i = 1; i < 6; i++) {
            Node *printNode = vertexArray[i].head;
            std::cout<<i;
            while (printNode) {
                std::cout << "->" << printNode->adj;
                printNode = printNode->next;
            }
            std::cout<<std::endl;
        }
    }

//    boolean ReadGraph(char *arg[]) {
//        std::ifstream inputFile(arg[1]);
//        if (!inputFile.is_open()) {
//            std::cout << "Error opening file " << arg[1] << std::endl;
//        } else {
//            while (!inputFile.eof()) {
//                //TODO
//            }
//        }
//    }

    void TopologicalSort() {}

    void ShortestPath() {}

    void MinimumSpanningTree() {}
};

int main() {
    Graph *graph = new Graph(5);

    graph->nextNode(1);
    graph->nextNode(2);
    graph->nextNode(3);
    graph->nextNode(4);
    graph->nextNode(5);

    graph->newEdge(1, 2);
    graph->newEdge(1, 4);
    graph->newEdge(2, 3);
    graph->newEdge(4, 5);
    graph->newEdge(1, 3);
    graph->newEdge(2, 4);

    graph->test();



    return 0;
}
