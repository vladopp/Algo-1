<<<<<<< HEAD
class Vector
{
public:
	Vector();
	Vector(const Vector& other);
	~Vector();
	Vector& operator =(const Vector& other);
	void insert(int index, double value);
	void add(double value);
	double get(int index);
	int siz();
	int cap();
	void remove(int index);
	double pop();
private:
	double* arr;
	int size;
	int capacity;
};


Vector::Vector()
{	
	arr = new double[512];
	size = 0;
	capacity = 512;
}


Vector::~Vector()
{
	size = 0;
	capacity = 0;
	delete[] arr;
	arr=0;
}


Vector::Vector(const Vector& other)
{
	capacity = other.capacity;
	size = other.size;
	arr = new double[capacity];
	for(int i=0; i<size; i++)
	{
		arr[i] = other.arr[i];
	}
}


Vector& Vector::operator =(const Vector& other)
{
	capacity = other.capacity;
	size = other.size;
	arr = new double[capacity];
	for(int i=0; i<size; i++)
	{
		arr[i] = other.arr[i];
	}
	return *this;
}


void Vector::insert(int index, double value)
{
	if(size < index && index < capacity)
	{
		arr[index] = value;
	}
	else if(size != capacity)
	{
		for(int i=size; i!=index-1; i--)
		{
			arr[i+1] = arr[i];
		}
		arr[index] = value;
	}
	else if (size == capacity)
	{
		double* tmp = new double[2*capacity];
		for(int i=0; i<size; i++)
		{
			tmp[i] = arr[i];
		}
		
		delete[] arr;
		arr = tmp;
		capacity *= 2;
		
		this->insert(index, value);
	}
}


void Vector::add(double value)
{
	if(size != capacity)
	{
		arr[size] = value;
		size++;
	}
	else
	{
		double* tmp = new double[2*capacity];
		for(int i=0; i<size; i++)
		{
			tmp[i] = arr[i];
		}
		
		delete[] arr;
		arr = tmp;
		capacity *= 2;
		
		arr[size] = value;
		size++;
	}
}

double Vector::get(int index)
{
	return arr[index];
}


int Vector::siz()
{
	return size;
}


int Vector::cap()
{
	return capacity;
}


void Vector::remove(int index)
{
	for(int i=index; i<size; i++)
	{
		arr[i] = arr[i+1];
	}
	size--;
}


double Vector::pop()
{
	if(size)
	{
		size--;
		return arr[size];
	}
}


int main()
{
	return 0;
}
=======
template<class T>
class Vector {
public:

  // Adds value at a specific index in the Vector.
  // Complexity: O(n)
  void insert(int index, T value) {
    // ...
  }

  // Adds value to the end of the Vector.
  // Complexity: O(1)
  void add(T value) {
    // ...
  }

  // Returns value at a specific index in the Vector
  // Complexity: O(1)
  T get(int index) {
    // ...
  }

  // Removes element at the specific index
  // Complexity: O(n)
  void remove(int index) {
    // ...
  }

  // Removes element at the last index
  // Complexity: O(1)
  T pop() {
    // ...
  }

  // Returns the number of elements in the Vector.
  // Complexity: O(1)
  int size() {
    // ...
  }

  // Returns the total capacity of the Vector.
  // Complexity: O(1)
  int capacity() {
    // ...
  }
};
>>>>>>> fbe0c9dc0375af8dd22c8245cdcd2a23c2418388
