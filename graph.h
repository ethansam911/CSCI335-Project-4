/**
    Name: Ethan Sam 
	Date: 4/22/2019
	Professor: Ioannis Stamos
	Class: CSCI 335
	
	header file: graph.h

	
	
 Few comments describing the graph header file
**/ 
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <Queue>
#include <list>
using namespace std;



class Graph 
{
/*
Represent a graph using an adjacency list. In order to test your implementation you will also read a
second text file (let us call it AdjacencyQueries.txt) that will contain a set of pair of vertices. Your
program (name it CreateGraphAndTest) will have to first create the graph by reading it from text
file Graph1.txt. It will then open the file AdjacenyQueries.txt and for each pair of vertices in it you
will cout whether the vertices are adjacent or not, and if they are you will cout the weight of the
edge that connects them.
*/
public:
/*
Set the vectors to the number of vertexes
We make a vertex object for each vertex
*/

Graph(int& numberofvectors)
{
	numvectors = numberofvectors;
	list_Vertex.resize(numvectors);
	indegrees.resize(numvectors);
	//auto & guarantees that you are sharing the variable with 
	//something else. It is always a reference and never to a temporary.
	// temporary  meaning if the function returns by value
	//We iterate through this linked list
		for(auto& i : list_Vertex)
		{
		//for each node in the linkedlist, we make a new Vertex object 	
			i = new Vertex;
		}

		for(int i = 0; i < numvectors; ++i)
		{
			list_Vertex[i]->Vertexnumber = i+1;
		}
	}
	
	/*
	inputs adjacent edge to the adjacency list and sets indegress for each 
	adjacent vertex.
	*/
	void AddEdge(int& vertex1, int& vertex2, double& weight)	
	{	//Struct Adjacency inside struct Vertex
		//Vertex2 is the new adjacent vertex
		Vertex::Adjacency a;
		a.AdjacencyNumber = vertex2;
		a.weight = weight;
		//Looks to the previous vertex in the list_Vertex vector 
		//and the  linokedList Aj  
		// points to the Adjacency linkedlist 
		list_Vertex[vertex1-1]->Aj.push_back(a);
		indegrees[vertex2-1]+=1;
	}


/*
	Returns the weight of Vertex if it is connected.
	If disconnected, return -1
	*/
	double CheckConnection(int vertex1, int vertex2)
	{	
	//check is a pointer to a vertex object
	//vector<Vertex*> list_Vertex;  a vector of pointers to vertex objects
	// check->
		Vertex* check = list_Vertex[vertex1-1];
    //It's good practice to use const auto& because
		const auto& checklist = check->Aj;
		//iterate through the linkedlist
		for(auto i = checklist.begin(); i!= checklist.end();i++)
		{
			if(i->AdjacencyNumber == vertex2)
			{
				return i->weight/1.0;
			}
		}

		return -1;
	}

//We have a nested struct
private: 
	struct Vertex
	{
	//Adjacency is of the struct Vertex 
		struct Adjacency
		{	
		//Part of the Adjacency struct
		int AdjacencyNumber;
		double weight;
		//Adjacency defaults to int, double, and of adjacency itself
		Adjacency() : AdjacencyNumber{}, weight{} {}
		};
		//Part of the Vertex Struct
		//Linked List of Adjacency objects
		list<Adjacency> Aj;
		int Vertexnumber;
		bool visited;
		int distance;
		Vertex* path;
		
		Vertex() : Aj{}, Vertexnumber {}, visited {}, distance {}, path{nullptr} {}

	};
	//Compares distaces of Vertexes.
	struct compare{
		//If node l1 is further than node l2, return true
		bool operator()(const Vertex* l1, Vertex* l2)
		{
			return l1->distance > l2->distance;
		}
	};
	int numvectors;
	//Contains the number of edges pointing to a particular node
	vector<int> indegrees;
	//A vector of vertex pointers (Vertex is a node)
	vector<Vertex*> list_Vertex;
};

#endif
