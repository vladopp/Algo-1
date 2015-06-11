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
	int max = *max_element(vec.begin(), vec.begin() + vec.size());
	int min = *min_element(vec.begin(), vec.begin() + vec.size());

	int* arr = new int[max-min+1];
	for(int i=0; i<vec.size(); i++)
	{
		arr[vec[i]-min]++;
	}
	vector<int> sorted;
	for(int i=0; i<=(max-min); i++)
	{
		while(arr[i])
		{
			sorted.push_back(min+i);
			arr[i]--;
		}
	}
	vec = sorted;
	delete[] arr;
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