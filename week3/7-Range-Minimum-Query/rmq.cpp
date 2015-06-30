#include <iostream>
#include <climits>

using namespace std;

class RMQ {
public:
  int size;
  int *Tree;

  RMQ(int size) {
    int sz=1;
    while(sz<size) // get biggest power of two, greater or equal to size
      sz*=2;

    this->size=sz;
    sz*=2;
    Tree = new int[sz];
    for(int i=0;i<sz;i++)
      Tree[i] = INT_MAX;
  }

  // sets the value at index
  void set(int index, int value) {
    index+=size;
    Tree[index]=value;
    index/=2;

    while(index>0) {
      if(Tree[index]>value)
        Tree[index]=value;
      else
        return;
      index/=2;
    }
  }

  // returns the minimum value in a range
  int min(int startIndex, int endIndex) {
    startIndex+=size;
    endIndex+=size;
    int Min = INT_MAX;

    if(endIndex == startIndex)
      return Min > Tree[endIndex] ? Tree[endIndex] : Min;

    while(endIndex > startIndex) {

      if(endIndex%2==0) {
        Min = (Min > Tree[endIndex] ? Tree[endIndex] : Min);
        endIndex/=2;
        endIndex--;
      }
      else {
        endIndex/=2;
        Min = (Min > Tree[endIndex] ? Tree[endIndex] : Min);
      }

      if(startIndex%2) {
        Min = (Min > Tree[startIndex] ? Tree[startIndex] : Min);
        startIndex/=2;
        startIndex++;
      }
      else {
        startIndex/=2;
        Min = (Min > Tree[startIndex] ? Tree[startIndex] : Min);
      }
    }

    return Min;
  }
};

int main()
{
  int n,q;
  cin >> n >> q;

  RMQ rmq(n);

  for(int i=0;i<n;i++) {
    int temp;
    cin >> temp;
    rmq.set(i,temp);
  }

  for(int i=0;i<q;i++) {
    string s;
    int a,b;
    cin >> s >> a >> b;
    if(s=="min")
      cout << rmq.min(a,b) << endl;
    else {
      rmq.set(a,b);
    }
  }

  return 0;
}