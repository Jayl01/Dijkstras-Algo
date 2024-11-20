
#include <string>
#include "Graph.hpp"
#include <list>
#include <iostream>
using namespace std;

Edge::Edge()
{
	from = '0';
	to = '0';
}

Edge::Edge(string fromVal, string toVal, int weightVal)
{
	from = fromVal;
	to = toVal;
	weight = weightVal;
}

Vertex::Vertex()
{
	label = '0';
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
			std::list<Vertex>::iterator eit;
			for (eit = it->edges.begin(); eit != it->edges.end(); /* none */)		//gets nodes connected by edges
			{
				removeEdge(it->label, eit->label);
				eit = it->edges.begin();
			}
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
void Graph::addEdge(string label1, string label2, unsigned long weight)
{
	std::list<Vertex>::iterator it;
	Vertex* target1 = nullptr;
	Vertex* target2 = nullptr;
	for (it = vertices.begin(); it != vertices.end(); it++)
	{
		if (it->label == label1)
		{
			target1 = &(*it);
			if (target2 != nullptr && target2->label == label2)
				break;
		}
		else if (it->label == label2)
		{
			target2 = &(*it);
			if (target1 != nullptr && target1->label == label1)
				break;
		}
	}
	target1->edges.push_back(*target2);
	target2->edges.push_back(*target1);
};

void Graph::removeEdge(string label1, string label2)
{
	std::list<Vertex>::iterator it;
	Vertex* target1 = nullptr;
	Vertex* target2 = nullptr;
	bool searchSuccess = false;
	for (it = vertices.begin(); it != vertices.end(); it++)
	{
		if (it->label == label1)
		{
			target1 = &(*it);
			if (target2 != nullptr && target2->label == label2)
			{
				searchSuccess = true;
				break;
			}
		}
		else if (it->label == label2)
		{
			target2 = &(*it);
			if (target1 != nullptr && target1->label == label1)
			{
				searchSuccess = true;
				break;
			}
		}
	}

	if (searchSuccess)
	{
		target1->edges.remove(*target2);
		target2->edges.remove(*target1);
	}
};

unsigned long Graph::shortestPath(string startLabel, string endLabel, vector<string>& path)
{
	for (it = startVertex.edges.begin(); it != startVertex.edges.end(); it++)
	{

	}
	Vertex startVertex = *vertices.begin();

	std::list<Vertex>::iterator it;
	for (it = startVertex.edges.begin(); it != startVertex.edges.end(); it++)
	{

	}
};

void Graph::printGraph()
{
	std::list<Vertex>::iterator it;
	for (it = vertices.begin(); it != vertices.end(); it++)
	{
		cout << it->label << ": " << endl;
		std::list<Vertex>::iterator it2;
		for (it2 = it->edges.begin(); it2 != it->edges.end(); it2++)
		{
			cout << "    " << it2->label << endl;
		}
		cout << "    " << endl;
	}
}