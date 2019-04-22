/**
    Name: Ethan Sam 
	Date: 4/22/2019
	Professor: Ioannis Stamos
	Class: CSCI 335
	
	file: CreateGraphAndTest.cpp

	
	
 Few comments describing the CreateGraphAndTest Program
**/ 
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


/*

You will read a directed graph from a text file. Below is an example:
Graph1.txt
5
1 2 0.2 4 10.1 5 0.5
2 1 1.5
3 2 100.0 4 50.2
4
5 2 10.5 3 13.9


For each vertex you have a list of the adjacent vertices with positive edge weights. For instance, in
the above example, vertex 1 is connected to vertex 2 (edge weight 0.2), to vertex 4 (edge weight
10.1) and to vertex 5 (edge weight 0.5). Vertex 2 is connected to vertex 1 (edge weight 1.5), vertex
4 has no outgoing edges, etc.

*/
void TestFunctionForGraph(const string &words_filename, const string &query_filename)
{
  cout << "TestFunctionForQueue..." << endl;
  cout << "Input file: " << words_filename << endl;
  cout << "Test filename: " << query_filename << endl; 
  
  //Opens file to input 
  
  ifstream file_input;  
  string line_from_file; 
  file_input.open(words_filename);
  int get_numberofvertices = 0;
  //Get the number of nodes 
  
  file_input>>get_numberofvertices;

  Graph Test(get_numberofvertices);
  //Get the line of 
  while(getline(file_input,line_from_file))
  { 
	/*We want iteration to be 1 because we want to read the number of vertices from the beginning 
	 *of the first line
	 */
  	int iteration = 1; 
  	int vertex = 0;
    int connectedVertex = 0;
    double weightOfEdge = 0;
	//The line from the file in "line_from_file"
    stringstream streamObject(line_from_file);
    while(streamObject)
    {	
		//5<
		//1 2 0.2 4 10.1 5 0.5
		//AKA: the first input determines the number of vertices
		//Therefore it is read only once
    	if(iteration ==1)
		{
		//5
		//1< 2 0.2 4 10.1 5 0.5
    	streamObject>>vertex;
		}
		//5
		//1 2< 0.2 4 10.1 5 0.5
		//^^This is the connected vertex^^
    	streamObject>>connectedVertex;
		//5
		//1 2 0.2< 4 10.1 5 0.5
		//^^This is the weight of the edge connecting the two previous vertexes^^
    	streamObject>>weightOfEdge;
    	if(streamObject)
		{
    	Test.AddEdge(vertex,connectedVertex,weightOfEdge);
    	iteration++;
		}
    }


  }
  
  cout<<"Successful input."<<endl;

  int vertex1 =0;
  int vertex2 =0;
  ifstream checkfile; 
  checkfile.open(query_filename);
  //Check that we are not at the end of file
  while(!(checkfile.eof()))
  {
  	checkfile>>vertex1;
  	checkfile>>vertex2;
  	double weightOfEdge = Test.CheckConnection(vertex1,vertex2);
  	if(weightOfEdge>0)
  	{
  		cout<< vertex1<<" "<<vertex2<<": Connected, weight of edge is "<<(weightOfEdge/1.0)<<endl;
  	}

  	else
  		cout<< vertex1<<" "<<vertex2<<": Not Connected "<<endl;

  }
} 




/*
We have graphs1 -graphs3
*/

int main(int argc, char **argv) 
{
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <InputFile> <SearchFile>" << endl;
    return 0;
  }
  
  const string words_filename(argv[1]);
  const string query_filename(argv[2]);
  TestGraphInsert(words_filename, query_filename);    

  return 0;
}


//----------------------------------------------------------------