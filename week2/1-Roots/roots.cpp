#include <iostream>
#include <climits>
#include <iomanip>

using namespace std;

double square_root(int number)
{
	double lo = 0;
	double hi = number;
	double mid = (lo + (hi-lo)) / 2;
	
	while(true)
	{
		if(mid*mid < number && (mid+0.000001)*(mid+0.000001) >= number) 
			break;

		mid = lo + (hi-lo)/ 2;
		if(mid*mid > number)
			hi = mid - 0.000001;
		else if(mid*mid < number)
			lo = mid + 0.000001;
		else
			return mid;
		//cout << mid* mid << endl;
		//cout << mid << endl;
	}

	return mid + 0.000001;
}

int main()
{
	int a;
	cin >> a;
	cout << fixed;
	cout << setprecision(5) << square_root(a) << endl;
	return 0;
}
