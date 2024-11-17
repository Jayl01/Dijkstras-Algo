#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include "GraphBase.hpp"
#include <list>

using namespace std;

struct Edge		//Represents connection lines
{
	public:
		string to;
		string from;
		int weight;

		Edge();
		Edge(string fromVal, string toVal, int weightVal);

	private:
		friend class Graph;        //gives "Graph" access to Edge values.
};

struct Vertex		//Represents graph points
{
public:
	string label;
	Vertex();

private:
	list<Edge> edges;
	friend class Graph;        //gives "Graph" access to Edge values.
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

	private:
		Vertex startingVertex;
		int length;
};

#endif /* GRAPH_H */