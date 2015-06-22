#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class HeapSort
{
public:
	// Sorts a sequence of integers.
	void sort(int* sequence, int size)
	{
		int* temp = new int[size];
		for(int i=0; i<size; i++)
		{
			temp[i] = sequence[i];
		} 

		int curr = (size / 2) - 1;
		
		for(curr; curr>=0; curr--)
		{
			heapify(temp, curr, size);
		}

		for(int i=0; i<size; i++)
		{
			sequence[i] = temp[0];
			temp[0] = temp[size-i-1];
			heapify(temp, 0, size-i-1);
		}

		delete[] temp;
	}

	void heapify(int* temp, int curr, const int size)
	{
		if(curr*2+1>=size)
			return;
		
		if(curr*2+2 < size)
		{
			if(temp[curr] > temp[curr*2+1] && temp[curr*2+1] < temp[curr*2+2])
			{
				swap(temp[curr], temp[curr*2+1]);
				curr = curr*2+1;
				heapify(temp, curr, size);
			}
			else if(temp[curr] > temp[curr*2+2] && temp[curr*2+2] < temp[curr*2+1])
			{
				swap(temp[curr], temp[curr*2+2]);
				curr = curr*2+2;
				heapify(temp, curr, size);
			}
		}
		else
		{
			if(temp[curr] > temp[curr*2+1])
			{
				swap(temp[curr], temp[curr*2+1]);
				curr = curr*2+1;
				heapify(temp, curr, size); 
			}		
		}
	}
};

int main()
{
	int a[]={2,8,7,96,6,54,68,4};
	HeapSort test;
	test.sort(a,8);


	for(int j=0; j<8; j++)
	{
		cout << a[j] << endl;
	}


	return 0;
}