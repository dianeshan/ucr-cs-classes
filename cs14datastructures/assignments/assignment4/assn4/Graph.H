/*
 * cs014_20sumA
 * Graph.H
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <list>
#include <queue>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include "Vertex.H"

using namespace std;

class Graph
{
public:
	Graph() {}
	Graph(ifstream &ifs)
	{
		/* implement overloaded constructor */
		build_graph(ifs); //invoke from overloaded Graph constructor
	}
	~Graph() {}
	void build_graph(ifstream &ifs)
	{
		/* implement build_graph */
		int nodes;
		int edges;
		int pindex;
		int nindex;
		string n;	 //node = vertex label
		string ep;	 //edge parent
		string en;	 //edge neighbor
		string edge; //final edge

		ifs >> nodes; //first line of input file is number of nodes which = vertices
		ifs >> edges; //second line of input file is number of edges

		for (int i = 0; i < nodes; i++) //add all the vertices to the vector
		{
			ifs >> n;
			Vertex v(n); //create a vertex with passing in input from file as label
			vindex.insert({n, i});
			vertices.push_back(v);
		}

		for (int j = 0; j < edges; j++)
		{			   //get all the edges
			ifs >> ep; //first one we get from file is the parent
			ifs >> en; //second one in that line is the neighbor

			edge = ep + "->" + en;	//final edge
			edgesv.push_back(edge); //add the edges to edge vector

			pindex = vindex.at(ep); //assign parent index with where the parent is

			nindex = vindex.at(en);

			vertices.at(pindex).neighbors.push_back(nindex);
		}
	}

	void output_graph()
	{
		/* implement output_graph */
		ofstream ofs("graph.dot");
		if (!ofs)
		{
			cout << "output.dot could not be opened." << endl;
			exit(1);
		}
		ofs << "digraph G {" << endl
			<< endl;
		ofs << "rankdir=\"LR\";" << endl
			<< endl;
		int counter = 0;

		for (unsigned int i = 0; i < vertices.size(); i++)
		{
			if (counter == 0)
			{
				ofs << vertices.at(i).label << " [color = lightblue, style = filled, label = " << vertices.at(i).label << "];" << endl;
			}
			else if (counter < (vertices.size() / 2))
			{
				ofs << vertices.at(i).label << " [color = red, style = filled, label = " << vertices.at(i).label << "];" << endl;
			}
			else
			{
				ofs << vertices.at(i).label << " [color = lightgreen, style = filled, label = " << vertices.at(i).label << " d: " << vertices.at(i).distance << "];" << endl;
			}
			counter++;
		}
		ofs << endl;

		for (unsigned int i = 0; i < edgesv.size(); i++)
		{
			ofs << edgesv.at(i) << ";" << endl;
		}
		ofs << endl;

		ofs << "}" << endl;

		ofs.close();
	}

	void bfs()
	{ /* implement bfs */
		queue<Vertex> frontier;
		vector<Vertex> discovered;
		vector<int> dist;
		Vertex current;

		frontier.push(vertices.at(0)); //first vertex
		discovered.push_back(vertices.at(0));
		dist.push_back(vertices.at(0).distance);

		while (!frontier.empty())
		{
			current = frontier.front();
			frontier.pop();
			current.visit = true;
			for (list<int>::iterator it = current.neighbors.begin(); it != current.neighbors.end(); it++)
			{
				if (vertices.at(*it).distance == 0 && vertices.at(*it).visit == false)
				{
					vertices.at(*it).setDistance(current.distance + 1);
					frontier.push(vertices.at(*it));
				}
			}
		}
	}

private:
	vector<Vertex> vertices;
	vector<string> edgesv;
	map<string, int> vindex;
};

#endif /* GRAPH_H_ */
