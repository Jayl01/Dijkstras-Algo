#ifndef EDGE_H
#define EDGE_H

#include <string>
#include <list>
#include "Vertex.hpp"

using namespace std;

class Edge		//Represents connection lines
{
	public:
		Vertex to;
		Vertex from;
		unsigned long weight;

		Edge();
		Edge(Vertex fromVal, Vertex toVal, unsigned long weightVal);
		~Edge();

		bool operator==(const struct Edge& edge) const
		{
			return (edge.from.label == this->from.label && edge.to.label == this->to.label && edge.weight == this->weight);
		}

	private:
		friend struct Vertex;        //gives "Graph" access to Edge values.
};

#endif /* EDGE_H */