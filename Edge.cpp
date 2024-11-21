#include <string>
#include "Vertex.hpp"
#include "Edge.hpp"
#include <list>
using namespace std;

Edge::Edge()
{
	from = Vertex();
	to = Vertex();
	weight = 0;
}

Edge::Edge(Vertex fromVal, Vertex toVal, unsigned long weightVal)
{
	from = fromVal;
	to = toVal;
	weight = weightVal;
}

Edge::~Edge()
{

}