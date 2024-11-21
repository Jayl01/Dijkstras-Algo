#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include "GraphBase.hpp"
#include <list>

using namespace std;

struct Vertex		//Represents graph points
{
	public:
		string label;
		Vertex();
		Vertex(string labelVal);

		bool operator==(const struct Vertex& vert) const
		{
			return (vert.label == this->label);
		}

	private:
		list<Edge> edges;
		friend class Graph;        //gives "Graph" access to Edge values.
		friend struct Edge;        //gives "Graph" access to Edge values.

};

struct Edge		//Represents connection lines
{
	public:
		Vertex* to;
		Vertex* from;
		int weight;

		Edge();
		Edge(Vertex fromVal, Vertex toVal, int weightVal);

		bool operator==(const struct Edge& edg) const
		{
			return (edg.from->label == this->from->label && edg.to->label == this->to->label && edg.weight == this->weight);
		}

		/*bool operator!=(const struct Edge& edg) const
		{
			return !(edg.from->label == this->from->label && edg.to->label == this->to->label && edg.weight == this->weight);
		}*/

	private:
		friend struct Vertex;        //gives "Graph" access to Edge values.
};

class Graph : public GraphBase		//Based off of Adjacency List
{
	public:

		Graph();
		~Graph();

		void addVertex(string label) override;
		void removeVertex(string label) override;
		void addEdge(string label1, string label2, unsigned long weight) override;
		void removeEdge(string label1, string label2) override;
		unsigned long shortestPath(string startLabel, string endLabel, vector<string>& path) override;
		long recursiveSearch(Vertex currVert, string startLabel, string endLabel, int currLen, vector<string>& path);
		bool nodeInPath(string label, vector<string>& path);
		void printGraph();

	private:
		list<Vertex> vertices;
		int length;
};

#endif /* GRAPH_H */