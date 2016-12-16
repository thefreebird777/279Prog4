//#include <rpcndr.h>
#include <iostream>
#include <fstream>
#include <map>
#include "Graph.h"

using namespace std;

struct Node {
    string vert;
    //int weight;
    Node *next;
};
struct List {
    struct Node *head;
};


class Graph {
    int vertices;
    struct List *vertexArray;
    int count = 0;
    map<string, int> vertList;

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

    void addVertex(string vert) {
        vertList[vert] = count;
        count++;
    }

    void addEdge(string head, string vert) {
        Node *newNode = nextNode(vert);
        newNode->next = vertexArray[vertList.at(head)].head;
        vertexArray[vertList.at(head)].head = newNode;

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

    graph->addVertex("a");
    graph->addVertex("b");
    graph->addVertex("c");
    graph->addVertex("d");
    graph->addVertex("e");

    graph->addEdge("a", "b");
    graph->addEdge("a", "d");
    graph->addEdge("b", "c");
    graph->addEdge("d", "e");
    graph->addEdge("a", "c");
    graph->addEdge("b", "d");


    return 0;
}
