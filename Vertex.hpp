#ifndef VERTEX_H
#define VERTEX_H

#include <string>
#include <list>
#include "Edge.hpp"

using namespace std;

struct Vertex		//Represents graph points
{
public:
	string label;
	Vertex();
	Vertex(string labelVal);
	~Vertex();

	bool operator==(const struct Vertex& vert) const
	{
		return (vert.label == this->label);
	}

private:
	list<Edge> edges;
	friend class Graph;        //gives "Graph" access to Vertex values.
	//friend struct Edge;        //gives "Edge" access to Vertex values.
};

#endif /* VERTEX_H */