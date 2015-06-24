#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class KMin {
public:

  // Finds the k-th minimum element in an unsorted collection.
  int kthMinimum(vector<int> numbers, int k) {
    int* arr = new int[k];
    for(int i=0; i<k; i++)
    {
        arr[i] = numbers[i];
    }
    make_heap(arr, arr+k);
    for(int i=k; i<numbers.size(); i++)
    {
        if(numbers[i]<arr[0])
        {
            arr[0] = numbers[i];
            make_heap(arr, arr+k);
        }
    }
    int res = arr[0];
    delete[] arr;
    return  res;
  }
};


int main()
{
    vector<int> asd = {10, 2, 8, 6, 1, 5};
    KMin test;
    cout << test.kthMinimum(asd, 3);
    return 0;
}
