#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    string vert;
    int weight;
    Node *next;
};

struct List {
    struct Node *head;
};

// Edge struct to hold edge data for finding MST
struct Edge {
    string source;
    string sink;
    int weight;
} temp;


class Graph {
    int vertices;
    int edges;
    struct List *vertexArray;
    int count = 0;
    map<string, int> vertList;
    vector<Edge> kruskal;

public:

    Graph(int vertices) {
        this->vertices = vertices;
        vertexArray = new List[vertices];
        for (int i = 0; i < vertices; i++) {
            vertexArray[i].head = NULL;
        }
    }

    ~Graph() {
        vertList.clear();
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
                if (atoi(str.c_str()) != 0) {
                    edges = stoi(str);
                    break;
                } else {
                    addVertex(str);
                }
            }
            while (!inputFile.eof()) {
                getline(inputFile, str);
                if (str == "") {
                    break;
                }
                stringstream line(str);
                line >> str >> str2 >> str3;
                addEdge(str, str2, stoi(str3));
            }
        }
    }

    bool doesExist(string v) {
        return vertList.count(v) != 0;
    }

    void TopologicalSort() {}

    void ShortestPath() {}

    bool ascend(Node i, Node j) { return i.weight < j.weight; }

    bool cycleCheck(Edge n)
    {
        // true = cycle, false = no cycle
        if (kruskal.size() == 0)
            return false;

	// check for cycle here

        return true;
    }

    // Precondition for MST is that the graph is connected
    void MinimumSpanningTree()
    {
        int total = 0; // total weight from tree

        // will hold data for all edges
        vector<Edge> data;

        // loop through the adjacency list and get all edge data
        for (int i = 0; i < edges; i++)
        {
            Node *x = vertexArray[i].head;
            temp.source = x->vert;
            x = x->next;
            while (x)
            { 
                temp.sink = x->vert;
                temp.weight = x->weight;
                data.push_back(temp);
                x = x->next;
            }
        }

        // sort the edge data in ascending order by weight (possibly move up "ascend")
//        sort(data.begin(), data.end(), ascend);

        // loop through edge data determining which edges to add
        int j = 0;
        while (j < vertices-1)
        {
            if (!cycleCheck(data[j]))
            {
                kruskal.push_back(data[j]);
                total += data[j].weight;
            }
            j++;
        }

        // print total tree weight and Kruskal edges
        cout << "The Minimum Spanning Tree of this graph has a weight of " << total 
             << ", and contains the following edges:" << endl;
        for (int i = 0; i < kruskal.size(); i++)
        {
            cout << kruskal[i].source << " -> " << kruskal[i].sink << ", weight: "
                 << kruskal[i].weight << endl;
        }
        cout << "MST Complete" << endl;
    }
};

int main() {
    string response;
    Graph *graph;
    cout << "Would you like to enter a file? [y/n]" << endl;
    cin >> response;
    if (response == "y") {
        graph = new Graph(5); //int parameter shouldn't matter since graph will be recreated in the readGraph function
        string path;
        cout << "Please enter a file: ";
        cin >> path;
        ifstream inputFile(path);
        graph->readGraph(inputFile);
    } else if (response == "n") {
        bool x = true;
        int vertices;
        int edges;
        while (x) {
            cout << "How many vertices would you like?" << endl;
            cin >> response;
            if (atoi(response.c_str()) != 0) {
                vertices = stoi(response);
                graph = new Graph(vertices);
                break;
            } else {
                cout << "Invalid response. Enter integer.";
            }
        }
        for (int i = 0; i < vertices; i++) {
            cout << "Enter the name of a vertex:" << endl;
            cin >> response;
            graph->addVertex(response);
        }
        while (x) {
            cout << "How many edges would you like?" << endl;
            cin >> response;
            if (atoi(response.c_str()) != 0) {
                edges = stoi(response);
                break;
            } else {
                cout << "Invalid response. Enter integer.";
            }
        }
        for (int i = 0; i < edges; i++) {
            string first;
            string second;
            string w;
            while (x) {
                cout << "Enter the first vertex of the edge:" << endl;
                cin >> first;
                if (graph->doesExist(first)) {
                    break;
                } else {
                    cout << "Invalid response. Vertex does not exist." << endl;
                }
            }
            while (x) {
                cout << "Enter the second vertex of the edge:" << endl;
                cin >> second;
                if (graph->doesExist(second)) {
                    break;
                } else {
                    cout << "Invalid response. Vertex does not exist." << endl;
                }
            }
            while (x) {
                cout << "Enter the weight of the edge:" << endl;
                cin >> w;
                if (atoi(w.c_str()) != 0) {
                    graph->addEdge(first, second, stoi(w));
                    break;
                } else {
                    cout << "Invalid response. Enter integer." << endl;
                }
            }
        }
    } else {
        cout << "Entered incorrect key" << endl;
        main();
    }
    bool y = true;
    while (y) {
        cout << "Now that we have a graph, would you like to print out the:" << endl
             << "[T] Topological Sort" << endl << "[S] Shortest Path" << endl << "[M] Minimum Spanning Tree" << endl
             << endl << "Or would you like to" << endl << "[G] Make a new Graph" << endl << "[E] Exit" << endl;
        cin >> response;
        if (response == "T" || response == "t") {
            graph->TopologicalSort();
        } else if (response == "S" || response == "s") {
            graph->ShortestPath();
        } else if (response == "M" || response == "m") {
            graph->MinimumSpanningTree();
        } else if (response == "G" || response == "g") {
            main();
            break;
        } else if (response == "E" || response == "e") {
            break;
        } else {
            cout << "Invalid response." << endl;
        }
    }
    return 0;
}
