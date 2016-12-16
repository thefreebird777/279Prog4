#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
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
    int edges;
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
        newNode->weight=NULL;
        newNode->next = NULL;
        return newNode;
    }

    void addVertex(string vert) {
        vertList[vert] = count;
        count++;
    }

    void addEdge(string head, string vert, int weight) {
        Node *newNode = nextNode(vert);
        newNode->weight = weight;
        newNode->next = vertexArray[vertList.at(head)].head;
        vertexArray[vertList.at(head)].head = newNode;
    }

    bool readGraph(char arg[]) {
        ifstream inputFile((const char *) arg[0]);
        if (!inputFile.is_open()) {
            cout << "Error opening file " << endl;
        } else {
            string str;
            string str2;
            string str3;
            getline(inputFile, str);
            vertices = stoi(str);
            while (!inputFile.eof()) {
                getline(inputFile, str);
                if (stoi(str)){
                    edges = stoi(str);
                    break;
                }else{
                    addVertex(str);
                }
            }
            while (!inputFile.eof()) {
                getline(inputFile, str);
                stringstream line(str);
                line >> str >> str2 >> str3;
                    addEdge(str,str2,stoi(str3));
            }
        }
    }

    void TopologicalSort() {}

    void ShortestPath() {}

    void MinimumSpanningTree() {}
};

int main(char *arg[]) {
    Graph *graph = new Graph(5);

    graph->readGraph(arg[0]);

//    graph->addVertex("a");
//    graph->addVertex("b");
//    graph->addVertex("c");
//    graph->addVertex("d");
//    graph->addVertex("e");
//
//    graph->addEdge("a", "b", 1);
//    graph->addEdge("a", "d", 3);
//    graph->addEdge("b", "c", 4);
//    graph->addEdge("d", "e", 6);
//    graph->addEdge("a", "c", 2);
//    graph->addEdge("b", "d", 3);

    return 0;
}
