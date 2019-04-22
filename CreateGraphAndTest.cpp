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