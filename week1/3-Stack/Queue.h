using namespace std;

//--------------Node------------------
class Node
{
public:
	Node(double data);
private:
	double data;
	Node* ptr_next;
	Node* ptr_prev;
friend class Stack;
friend class Queue;
};

Node::Node(double data)
{
	this->data = data;
	ptr_next = 0;
	ptr_prev = 0;
}

//----------------Queue----------------
class Queue
{
public:
	Queue();
	~Queue();
	void push(double data);
	double pop();
	double peek();
	int siz();
protected:
	int size;
	Node* ptr_first;
	Node* ptr_last;
};

Queue::Queue()
{
	ptr_first = 0;
	ptr_last = 0;
	size = 0;
}

Queue::~Queue()
{
	while(ptr_first != ptr_last)
	{
		Node* tmp = ptr_first;
		ptr_first = ptr_first->ptr_next;
		ptr_first->ptr_prev = 0;
		delete tmp;
	}
	delete ptr_first;
	ptr_first = ptr_last = 0;
}

void Queue::push(double data)
{
	Node* newNode = new Node(data);
	newNode->ptr_prev = ptr_last;
	ptr_last = newNode;
	size++;
}

double Queue::pop()
{
	double result = ptr_first->data;
	
	Node* tmp = ptr_first;
	ptr_first = ptr_first->ptr_next;
	ptr_first->ptr_prev = 0;
	delete tmp;
	size--;
	return result;
}

double Queue::peek()
{
	return ptr_first->data;
}

int Queue::siz()
{
	return size;
}

