#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int zero_quadruplets_count(vector<int>& a,vector<int>& b,vector<int>& c,vector<int>& d)
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
	int n, tmp;
	cin >> n;
    vector<int> a, b, c,d;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		a.push_back(tmp);
	}
	for(int i=0; i<n; i++) {
		cin >> tmp;
		b.push_back(tmp);
	}
	for(int i=0; i<n; i++) {
		cin >> tmp;
		c.push_back(tmp);
	}
	for(int i=0; i<n; i++) {
		cin >> tmp;
		d.push_back(tmp);
	}
    cout << zero_quadruplets_count(a, b, c, d) << endl;
	return 0;
}
