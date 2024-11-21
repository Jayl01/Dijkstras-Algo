
#include <string>
#include "Graph.hpp"
#include <list>
#include <iostream>
using namespace std;

Edge::Edge()
{
	from = nullptr;
	to = nullptr;
	weight = 0;
}

Edge::Edge(Vertex fromVal, Vertex toVal, int weightVal)
{
	from = &fromVal;
	to = &toVal;
	weight = weightVal;
}

Vertex::Vertex()
{
	label = '0';
	edges;
}

Vertex::Vertex(string labelVal)
{
	label = labelVal;
	edges;
}

Graph::Graph()
{
	vertices;
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
	list<Vertex>::iterator it;
	for (it = vertices.begin(); it != vertices.end(); it++)
	{
		if (it->label == label)		//finds target node from graph
		{
			list<Edge>::iterator eit;		//edge iterator
			for (eit = it->edges.begin(); eit != it->edges.end(); /* none */)		//gets nodes connected by edges
			{
				removeEdge(it->label, eit->to->label);
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
	list<Vertex>::iterator it;
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
	Edge edge = Edge(*target1, *target2, weight);
	target1->edges.push_back(edge);
	target2->edges.push_back(edge);
};

/// <summary>
/// Removes the edge from both the to and from vertices.
/// </summary>
/// <param name="label1"></param>
/// <param name="label2"></param>
void Graph::removeEdge(string label1, string label2)
{
	list<Vertex>::iterator it;
	Vertex* target1 = nullptr;
	Vertex* target2 = nullptr;
	bool searchSuccess = false;
	for (it = vertices.begin(); it != vertices.end(); it++)
	{
		if (it->label == label1)		//finds node '1' on graph
		{
			target1 = &(*it);
			if (target2 != nullptr && target2->label == label2)
			{
				searchSuccess = true;
				break;
			}
		}
		else if (it->label == label2)		//finds node '2' on graph
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
		list<Edge>::iterator eit;
		for (eit = target1->edges.begin(); eit != target1->edges.end(); eit++)
		{
			if (eit->to == target2 || eit->from == target2)
			{
				target1->edges.remove(*eit);
				break;
			}
		}
		for (eit = target2->edges.begin(); eit != target2->edges.end(); eit++)
		{
			if (eit->to == target1 || eit->from == target1)
			{
				target2->edges.remove(*eit);
				break;
			}
		}
	}
};

unsigned long Graph::shortestPath(string startLabel, string endLabel, vector<string>& path)
{
	list<Vertex>::iterator it;
	Vertex startVertex = *vertices.begin();
	if (startVertex.label != startLabel)
	{
		for (it = vertices.begin(); it != vertices.end(); it++)
		{
			if (it->label == startLabel)
			{
				startVertex = *it;
				break;
			}
		}
	}

	//path.push_back(startLabel);
	int edgesTraveled = 0;
	Vertex* currentVertex = &startVertex;
	while (currentVertex->label != endLabel)
	{
		int nearestWeight = 99;
		Vertex* closestVertex = nullptr;
		list<Edge>::iterator eit;
		for (eit = startVertex.edges.begin(); eit != startVertex.edges.end(); eit++)		//search currVert edges for closest distance (lowest weight)
		{
			if (eit->from == currentVertex && !nodeInPath(eit->to->label, path))
			{
				if (eit->weight < nearestWeight)
				{
					nearestWeight = eit->weight;
					closestVertex = eit->to;
				}
			}
		}
		path.push_back(currentVertex->label);		//this node has been searched and so push it to path
		currentVertex = closestVertex;		//update loop info
		edgesTraveled++;
	}
	path.push_back(endLabel);		//final node
	return edgesTraveled;
};

bool Graph::nodeInPath(string label, vector<string>& path)
{
	vector<string>::iterator it;
	for (it = path.begin(); it != path.end(); it++)
	{
		if (*it == label)
			return true;
	}
	return false;
}

long Graph::recursiveSearch(Vertex currVert, string startLabel, string endLabel, int currLen, vector<string>& path)
{
	return 0;

	/*currLen++;
	list<Vertex>::iterator it;
	for (it = currVert.edges.begin(); it != currVert.edges.end(); it++)
	{
		vector<string>::iterator sit;
		bool skipNode = false;
		for (sit = path.end(); sit != path.begin(); sit--)
		{
			if (*sit == it->label)
			{
				skipNode = true;
				break;
			}
		}
		if (skipNode)
			continue;

		if (it->label == endLabel)
			return currLen;
		else
		{
			path.push_back(it->label);
			recursiveSearch(*it, startLabel, endLabel, currLen, path);
		}
	}*/
}

void Graph::printGraph()
{
	list<Vertex>::iterator it;
	for (it = vertices.begin(); it != vertices.end(); it++)
	{
		cout << it->label << ": " << endl;
		list<Edge>::iterator it2;
		for (it2 = it->edges.begin(); it2 != it->edges.end(); it2++)
		{
			if (it2->to->label != it->label)
				cout << "    " << it2->to->label << endl;
		}
		cout << "    " << endl;
	}
}