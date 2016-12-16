//#include <rpcndr.h>
#include <iostream>
#include <fstream>
#include "Graph.h"
using namespace std;

struct Node {
    string vert;
    int weight;
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

    Node *nextNode(string vert) {
        Node *newNode = new Node;
        newNode->vert = vert;
        newNode->next = NULL;
        return newNode;
    }

    void newEdge(int head, string vert, int weight) {
        Node *newNode = nextNode(vert);
        newNode->next = vertexArray[head].head;
        vertexArray[head].head = newNode;
    }

    void test() {
        for (int i = 1; i < 6; i++) {
            Node *printNode = vertexArray[i].head;
            cout << i;
            while (printNode) {
                cout << "->" << printNode->vert << "(" << printNode->weight << ")";
                printNode = printNode->next;
            }
            cout << endl;
        }
    }

//    boolean ReadGraph(char *arg[]) {
//        ifstream inputFile(arg[1]);
//        if (!inputFile.is_open()) {
//            cout << "Error opening file " << arg[1] << endl;
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

    graph->nextNode("a");
    graph->nextNode("b");
    graph->nextNode("c");
    graph->nextNode("d");
    graph->nextNode("e");

    graph->newEdge(1, "b", 4);
    graph->newEdge(1, "d", 3);
    graph->newEdge(2, "c", 5);
    graph->newEdge(4, "e", 6);
    graph->newEdge(1, "c", 1);
    graph->newEdge(2, "d", 2);

    graph->test();


    return 0;
}
