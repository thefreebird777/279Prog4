#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

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
        newNode->weight = 0;
        newNode->next = NULL;
        return newNode;
    }

    void addVertex(string vert) {
        vertList[vert] = count; //maps Vertex to an integer in the order the Vertex is added
        count++;
    }

    void addEdge(string head, string vert, int weight) {
        Node *newNode = nextNode(vert);
        newNode->weight = weight;
        newNode->next = vertexArray[vertList.at(head)].head;
        vertexArray[vertList.at(head)].head = newNode;
        /*the result of the adjacency graph will look something like this
         * example:
         *
         * inputVertices: a,b,c,d
         * inputEdges: (a,b), (a,d), (b,c) (d,b)]
         *
         * mapping:
         * a<->0, b<->1, c<->2, d<->3
         *
         * adjacency list:
         * arr elements| linked lists connected to elements
         *      0      |->b->d
         *      1      |->c
         *      2      |
         *      3      |->b
         *
         *      the nodes in the linked list should carry the weight of the edge
        */

    }

    bool readGraph(ifstream &inputFile) {
        if (!inputFile.is_open()) {
            cout << "Error opening file " << endl;
        } else {
            string str;
            string str2;
            string str3;
            getline(inputFile, str);
            vertices = stoi(str);
            new Graph(vertices);
            while (!inputFile.eof()) {
                getline(inputFile, str);
                if (atoi(str.c_str())!= 0) {
                    edges = stoi(str);
                    break;
                } else {
                    addVertex(str);
                }
            }
            while (!inputFile.eof()) {
                getline(inputFile, str);
                stringstream line(str);
                line >> str >> str2 >> str3;
                addEdge(str, str2, stoi(str3));
            }
        }
    }

    void TopologicalSort() {}

    void ShortestPath() {}

    void MinimumSpanningTree() {}
};

int main() {
    Graph *graph = new Graph(5); //int parameter shouldn't matter since graph will be recreated in the readGraph function
    string path;
    cout << "Please enter a file path: ";
    cin >> path;
    ifstream inputFile(path);
    graph->readGraph(inputFile);

    return 0;
}
