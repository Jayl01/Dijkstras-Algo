
#include <string>
#include "Graph.hpp"
#include <list>
#include <iostream>
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

Vertex::Vertex()
{
	label = nullptr;
}

Vertex::Vertex(string labelVal)
{
	label = labelVal;
}

Graph::Graph()
{
	vertices = list<Vertex>();
	length = 0;
}

Graph::~Graph()
{

}

void Graph::addVertex(string label)
{
	vertices.push_back(Vertex(label));
	length += 1;
};


void Graph::removeVertex(string label)
{
	std::list<Vertex>::iterator it;
	for (it = vertices.begin(); it != vertices.end(); it++)
	{
		if (it->label == label)
		{
			length -= 1;
			vertices.remove(*it);
			break;
		}
	}
};

/// <summary>
/// Creates a new connector between two vertices.
/// </summary>
/// <param name="label1">Current node</param>
/// <param name="label2">Next node</param>
/// <param name="weight">Weight?</param>
void Graph::addEdge(string label1, string label2, unsigned long weight)		//no need to implement because edges are implied
{
	std::list<Vertex>::iterator it;
	Vertex target1;
	Vertex target2;
	for (it = vertices.begin(); it != vertices.end(); it++)
	{
		if (it->label == label1)
		{
			target1 = *it;
			if (target2.label == label2)
				break;
		}
		else if (it->label == label2)
		{
			target2 = *it;
			if (target1.label == label1)
				break;
		}
	}
	target1.edges.push_back(target2);
	target2.edges.push_back(target1);
};

void Graph::removeEdge(string label1, string label2)		//no need to implement because edges are implied
{
	std::list<Vertex>::iterator it;
	Vertex target1;
	Vertex target2;
	for (it = vertices.begin(); it != vertices.end(); it++)
	{
		if (it->label == label1)
		{
			target1 = *it;
			if (target2.label == label2)
				break;
		}
		else if (it->label == label2)
		{
			target2 = *it;
			if (target1.label == label1)
				break;
		}
	}
	target1.edges.remove(target2);
	target2.edges.remove(target1);
};

unsigned long Graph::shortestPath(string startLabel, string endLabel, vector<string>& path)
{

};