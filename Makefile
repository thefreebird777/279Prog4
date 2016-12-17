Graph: Graph.o
	g++ -std=c++11 -o Graph Graph.o
	
Graph.o: Graph.cpp 
	g++ -std=c++11 -c Graph.cpp
	
clean:
	rm Graph *.o
