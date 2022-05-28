/*
 * cs014_20sumA
 * Vertex.H
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include <string>
#include <list>

using namespace std;

class Vertex
{
public:
	Vertex()
	{
		/* implement constructor*/
		label = "";
		distance = 0;
		visit = false;
	}

	Vertex(const string &s)
	{
		label = s;
		distance = 0;
		visit = false;
	}

	~Vertex() {}
	string label;
	int distance;
	bool visit;
	list<int> neighbors;
	void setDistance(const int d)
	{
		this->distance = d;
	}
};

#endif /* VERTEX_H_ */
