<<<<<<< HEAD
#include <iostream>
#include <algorithm>

using namespace std;

int zero_quadruplets_count(vector<int> a,vector<int>  b,vector<int>  c,vector<int>  d)
{
    int cnt = 0;

    vector<int> perm;
    for(int i=0; i<a.size(); i++)
    {
        for(int j=0; j<b.size(); j++)
        {
            perm.push_back(a[i]+b[j]);
        }
    }

    sort(perm.begin(), perm.end());

    for(int i=0; i<c.size(); i++)
    {
        for(int j=0; j<d.size(); j++)
        {
            int sum = -(c[i]+d[j]);
            cnt += upper_bound(perm.begin(), perm.end(), sum) - lower_bound(perm.begin(), perm.end(), sum);
        }
    }

    return cnt;
}

int main()
{
    vector<int> a = {5, 3, 4};
    vector<int> b = {-2, -1, 6};
    vector<int> c = {-1, -2, 4};
    vector<int> d = {-1, -2, 7};
    cout << zero_quadruplets_count(a, b, c, d) << endl;
	return 0;
}
=======
class Quadruplets {
public:

  // Returns the number of quadruplets that sum to zero.
  int zeroQuadrupletsCount(int* a, int* b, int* c, int* d, int size) {
    // ...
  }
};
>>>>>>> fbe0c9dc0375af8dd22c8245cdcd2a23c2418388
