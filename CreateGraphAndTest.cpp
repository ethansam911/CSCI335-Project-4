/**
    Name: Ethan Sam 
	Date: 4/22/2019
	Professor: Ioannis Stamos
	Class: CSCI 335
	
	Header file: CreateGraphAndTest.cpp
	
	
	This spell_check program checks for three cases:
	
	Removed chaarcters (in every position)
	Added characters( from a-z) in every position
	Swapped characters (from index = 0 to the total 
	of the string)
	
	
 Few comments describing the Spell Check Program
**/ 

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
  string line;
  file_input.open(words_filename);
  int get_numberofvertices = 0;
  
  file_input>>get_numberofvertices;

  Graph Test(get_numberofvertices);
  //Get the line of 
  while(getline(file_input,line))
  { 

  	int iteration = 1;
  	int vertex = 0;
    int connectedVertex = 0;
    double weight = 0;
    stringstream strStream(line);
    while(strStream)
    {
    	if(iteration ==1)
    		strStream>>vertex;
    	strStream>>connectedVertex;
    	strStream>>weight;
    	if(strStream)
    		Test.AddEdge(vertex,connectedVertex,weight);
    	iteration++;
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
  	double weight = Test.CheckConnection(vertex1,vertex2);
  	if(weight>0)
  	{
  		cout<< vertex1<<" "<<vertex2<<": Connected, weight of edge is "<<(weight/1.0)<<endl;
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