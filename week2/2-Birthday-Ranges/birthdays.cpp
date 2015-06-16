#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_b[366];

vector<int> birthdays_count(vector<int> birthdays, vector<pair<int, int> > ranges)
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
    vector<int> b = {1,2,3,4,4,5,6,7,8,9};
    vector<pair<int, int> > r = {make_pair(4,5), make_pair(5, 8), make_pair(20, 30), make_pair(0, 4)};
    vector<int> result = birthdays_count(b, r);
    for(int  i=0; i<result.size(); i++)
    {
        cout << result[i] << endl;
    }
	return 0;
}
