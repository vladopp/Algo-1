<<<<<<< HEAD
#include <iostream>
#include <climits>

using namespace std;

double square_root(int number)
{
	double lo = 0;
	double hi = number;
	double mid = (lo + (hi-lo)) / 2;
	
	while(true)
	{
		if(mid*mid < number && (mid+0.0001)*(mid+0.0001) > number) 
			break;

		mid = lo + (hi-lo)/ 2;
		if(mid*mid > number)
			hi = mid - 0.0001;
		else
			lo = mid + 0.0001;
		cout << mid* mid << endl;
		cout << mid << endl;
	}

	return mid;
}

int main()
{
	int a;
	cin >> a;
	cout << square_root(a) << endl;
	return 0;
}
=======
class Roots {
public:

  // Finds the square root of a number using binary search.
  double squareRoot(int number) {
    // ...
  }
};
>>>>>>> fbe0c9dc0375af8dd22c8245cdcd2a23c2418388
