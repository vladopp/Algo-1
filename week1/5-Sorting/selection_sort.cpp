#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>

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


int minpos(const vector<int> &vec, int start_pos)
{
	int min = vec[start_pos];
	int min_pos = start_pos;
	for(int i = start_pos+1; i<vec.size(); i++)
	{
		if(min>vec[i])
		{
			min = vec[i];
			min_pos = i;
		}
	}
	return min_pos;
}

void sort(vector<int> &vec)
{
	for(int i=0; i<vec.size(); i++)
	{
		int min_pos = minpos(vec, i);
		if (min_pos != i)
			swap(vec[min_pos], vec[i]);
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