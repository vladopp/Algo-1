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
	int size();
	int capacity();
	void remove(int index);
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
	capcity = other.capacity;
	size = other.size;
	arr = new double[capacity];
	for(int i=0; i<size; i++)
	{
		arr[i] = other.arr[i];
	}
}


Vector& Vector::operator =(const Vector& other)
{
	capcity = other.capacity;
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
		arr[index] = valuel
	}
	else if (size == capacity)
	{
		tmp = new double[2*capacity];
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


void add(double value)
{
	if(size != capacity)
	{
		arr[size] = value;
		size++;
	}
	else
	{
		tmp = new double[2*capacity];
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

double get(int index)
{
	return arr[index];
}


int size()
{
	return size;
}


int capacity()
{
	return capacity;
}


void remove(int index)
{
	for(int i=index; i<size; i++)
	{
		arr[i] = arr[i+1];
	}
	size--;
}

