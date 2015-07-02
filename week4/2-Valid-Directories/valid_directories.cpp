#include <iostream>

using namespace std;

class ValidDirectories {
public:

  bool isValid(int** graph, int size) {
    bool* visited = new bool[size];
    for(int i=0; i<size; i++) {
		visited[i] = false;
	}

	return recur(graph, size, visited, 0);
  }

  bool recur(int** graph,int size, bool* &visited, int index)
  {
  	visted[index] = true;
  	for(int i=0; i<size; i++) {
  		if(graph[index][i] == 1 && visited[i] == true)
  			return false;
		else if(graph[index][i] == 1)
			if(recur(graph, size, visited, i)==false)
				return false;
  	}
  	visited[index] = false;
  	return true;	
  }
};


int main()
{
	
	return 0;
}