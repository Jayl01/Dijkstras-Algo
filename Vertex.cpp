#include <string>
#include "Vertex.hpp"
#include "Edge.hpp"
#include <list>
using namespace std;

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

Vertex::~Vertex()
{

}