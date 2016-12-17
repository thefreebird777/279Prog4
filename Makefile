Graph: Graph.o
	g++ -std=c++11 Graph.o -o Graph

Graph.o: Graph.cpp
	g++ -c Graph.cpp
clean:
	rm *.o Graph
