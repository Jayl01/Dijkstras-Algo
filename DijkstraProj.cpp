#include "Graph.hpp"

int main()
{
	Graph g;

	g.addVertex("N0");
	g.addVertex("N1");
	g.addVertex("N2");
	g.addVertex("N3");
	g.addVertex("N4");
	g.addVertex("N5");
	g.addVertex("N6");
	g.addVertex("N7");

	g.addEdge("N0", "N2", 0);
	g.addEdge("N2", "N3", 0);
	g.addEdge("N3", "N7", 0);

	g.addEdge("N0", "N1", 0);
	g.addEdge("N1", "N7", 0);

	g.addEdge("N0", "N4", 0);
	g.addEdge("N4", "N5", 0);
	g.addEdge("N5", "N6", 0);
	g.addEdge("N6", "N7", 0);

	g.printGraph();
}