#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

vector<int> generate()
{
	int size = 13;
	vector<int> rand_vec;
	for(int i=0; i<size; i++)
	{
		rand_vec.push_back(rand() % 30);
	}
	return rand_vec;
}


void sort(vector<int> &vec)
{
	if(vec.size()>1)
	{
		for(int i=1; i<vec.size(); i++)
		{
			if(vec[i]<vec[i-1])
			{
				for(int z=0; z<=i; z++)
				{
					if(vec[z]>vec[i])
					{
						vec.insert(vec.begin()+z, vec[i]);
						vec.erase(vec.begin()+i+1);
						break;
					}
				}
			}
		}
	}
}


int main()
{
	vector<int> test;
	srand(time(0));
	test = generate();

	for(int i=0; i<test.size(); i++)
	{
		cout << test[i] << " ";
	}
	cout << endl;

	sort(test);

	for(int i=0; i<test.size(); i++)
	{
		cout << test[i] << " ";
	}
	cout << endl;

	return 0;
}