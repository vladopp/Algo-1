#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Median {
public:

static bool comp(const int& a,const int& b)
{
	return a>b;
}

  //inserts the number and returns the median
 	int insert(int number)
 	{
 		if(empty)
 		{
 			median = number;
 			empty = false;
 		}
 		else
 		{
 			if(number>median)
 			{
 				min.push_back(number);
 				push_heap(min.begin(), min.end(), comp);
 				if(min.size() - max.size() > 0)
 				{
 					max.push_back(median);
 					push_heap(max.begin(), max.end());
 					median = min[0];
 					pop_heap(min.begin(), min.end(), comp);
 					min.erase(min.end()-1);
 				}
 			}
 			else
 			{
 				max.push_back(number);
 				push_heap(max.begin(), max.end());
 				if(max.size() - min.size() > 1)
 				{
 					min.push_back(median);
 					push_heap(min.begin(), min.end(), comp);
 					median = max[0];
 					pop_heap(max.begin(), max.end());
 					max.erase(max.end()-1);
 				}
 			}
 		}
 		return median;
 	}
 private:
 	int median;
 	vector<int> max;
 	vector<int> min;
 	bool empty = true;
};

int  main()
{
	Median test;
	cout << test.insert(5) << endl;
	cout << test.insert(6) << endl;
	cout << test.insert(7) << endl;
	cout << test.insert(4) << endl;
	cout << test.insert(3) << endl;
	cout << test.insert(10) << endl;
	cout << test.insert(20) << endl;
	cout << test.insert(30) << endl;
	cout << test.insert(40) << endl;
	cout << test.insert(50) << endl;	
	return 0;
}