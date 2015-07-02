#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> lookup_names(vector<pair<int, string> > phone_book, vector<int> numbers)
{
    vector<string> names;

    sort(phone_book.begin(), phone_book.end());

    for(int i=0; i<numbers.size(); i++)
    {
        int lo = 0;
        int hi = phone_book.size()-1;
        int mid;
        bool found = false;
        while (lo <= hi)
        {
          mid = lo + (hi-lo)/2;
          if(phone_book[mid].first == numbers[i])
          {
                found = true;
                break;
          }
          else if(phone_book[mid].first < numbers[i])
             lo = mid+1;
          else
             hi = mid-1;
        }
        if(found)
            names.push_back(phone_book[mid].second);
    }

    return names;
}

int main()
{
  int n, m, number;
  string name;
  cin >> n >> m;
  
  vector<pair<int, string> > phone_book(n);
  for(int i=0; i<n; i++) {
    cin >> number;
    cin >> name;
    phone_book.push_back(make_pair(number, name));
  }

  vector<int> numbers(m);
  for(int i=0; i<m; i++) {
    cin >> number;
    numbers.push_back(number);
  }
  
  vector<string> result = lookup_names(phone_book, numbers);
  for(int i=0; i<m; i++) {
    cout << result[i] << endl;
  }
  
  return 0;
}
