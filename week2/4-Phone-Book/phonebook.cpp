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
    vector<pair<int, string> > phone_book = {make_pair(887123, "Gosho"), make_pair(123, "Pesho")};
    vector<int> numbers = {887123, 555};
    vector<string> result= lookup_names(phone_book, numbers);
    cout << result[0] << endl;
    return 0;
}
