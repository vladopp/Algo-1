#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_b[366];

vector<int> birthdays_count(vector<int>& birthdays,const vector<pair<int, int> >& ranges)
{
	vector<int> results;
	sort(birthdays.begin(), birthdays.end());
	int cnt = 0;
	int index = 0;
	for(int i=0; i<birthdays.size(); i++)
	{
        if(birthdays[i] > index)
        {
            count_b[index] = cnt;
            index++;
            i--;
        }
        else if(birthdays[i] == index)
        {
            while(birthdays[i] == index)
            {
                cnt++;
                i++;
            }
            i--;
            count_b[index] = cnt;
        }
	}

    while(index!=366)
    {
        count_b[index] = cnt;
        index++;
    }

	for(int i=0; i<ranges.size(); i++)
    {
        if(ranges[i].first == 0)
            results.push_back(count_b[ranges[i].second]);
        else
            results.push_back(count_b[ranges[i].second] - count_b[ranges[i].first - 1]);
    }
	return results;
}

int main()
{
    int n, m, birthday, first, last;
    cin >> n >> m;

    vector<int> b(n);
    for(int i=0; i<n; i++) {
        cin >> birthday;
        b[i] = birthday;
    }
    

    vector<pair<int, int> > r(m);
    for(int i=0; i<m; i++) {
        cin >> first >> last;
        r[i] = make_pair(first, last);
    }

    vector<int> result = birthdays_count(b, r);
    for(int  i=0; i<result.size(); i++)
    {
        cout << result[i] << endl;
    }

	return 0;
}
