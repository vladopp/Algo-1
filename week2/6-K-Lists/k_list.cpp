#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
  int value;
  Node* next;
};

class KLists {
public:

static inline bool comp(const int& a, const int& b)
{
    return (a<=b);
}

  // Merge K sorted lists.
    Node merge(vector<Node> lists) {
    vector<int> too_slow;
    for(int i=0; i<lists.size(); i++)
    {
       while(lists[i].next)
       {
           too_slow.push_back(lists[i].value);
           lists[i] = *(lists[i].next);
       }
       too_slow.push_back(lists[i].value);
    }
    sort(too_slow.begin(), too_slow.end());
    }
};

int main()
{

    return 0;
}
