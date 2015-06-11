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

void merge(vector<int> &vec, int beg, int mid, int end)
{
	int h, i, j ,k;
	h = beg;
	i = 0;
	j = mid+1;

	int* arr = new int[end+1-beg];

	while(h<=mid && j<=end)
	{
		if(vec[h]<=vec[j])
		{
			arr[i] = vec[h];
			h++;
		}
		else
		{
			arr[i]=vec[j];
			j++;
		}
		i++;
	}
	if(h>mid)
	{
		for(k=j; k<=end; k++)
		{
			arr[i] = vec[k];
			i++;
		}
	}
	else
	{
		for(k=h; k<=mid; k++)
		{
			arr[i] = vec[k];
			i++;
		}
	}
	for(k=0; k<=end-beg; k++) 
	{
		vec[k+beg]=arr[k];
	}
	delete[] arr;
}


void sort(vector<int> &vec, int beg, int end)
{
	if(beg == end)
		return;
	int mid = (beg+end)/2;
	sort(vec, beg, mid);
	sort(vec, mid+1, end);
	merge(vec, beg, mid, end);
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

	sort(test, 0, test.size()-1);

	for(int i=0; i<test.size(); i++)
	{
		cout << test[i] << " ";
	}
	cout << endl;

	return 0;
}