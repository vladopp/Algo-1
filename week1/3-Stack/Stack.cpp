#include "Queue.h"

using namespace std;

class Stack : public Queue
{
public:
	double pop();
	double peek();
};

double Stack::pop()
{
	double result = ptr_last->data;
	
	Node* tmp = ptr_last;
	ptr_last = ptr_last->ptr_prev;
	ptr_last->ptr_next = 0;
	delete tmp;
	size--;
	return result;
}

double Stack::peek()
{
	return ptr_last->data;
}

int main()
{
	return 0;
}
