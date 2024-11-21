#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include "GraphBase.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include <list>

using namespace std;

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
		bool nodeInPath(string label, vector<string>& path);
		void printGraph();

	private:
		list<Vertex> vertices;
		int length;
};

#endif /* GRAPH_H */