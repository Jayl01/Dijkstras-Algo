
#include <string>
#include "Graph.hpp"
#include <list>
using namespace std;

Edge::Edge()
{
	from = nullptr;
	to = nullptr;
}

Edge::Edge(string fromVal, string toVal, int weightVal)
{
	from = fromVal;
	to = toVal;
	weight = weightVal;
}

void Graph::addVertex(string label)
{
	addEdge();
};


void Graph::removeVertex(string label)
{

};

/// <summary>
/// Creates a new connector between two vertices.
/// </summary>
/// <param name="label1">Current node</param>
/// <param name="label2">Next node</param>
/// <param name="weight">Weight?</param>
void Graph::addEdge(string label1, string label2, unsigned long weight)
{
	startingVertex.edges.push_back(Edge(label1, label2, weight));
};

void Graph::removeEdge(string label1, string label2)
{
	std::list<Edge>::iterator it;
	for (it = startingVertex.edges.begin(); it != startingVertex.edges.end(); it++)
	{

	}
};

unsigned long Graph::shortestPath(string startLabel, string endLabel, vector<string>& path)
{

};