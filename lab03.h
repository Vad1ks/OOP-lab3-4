#include <iostream>
using namespace std;

class ellipse
{
	string name;
	int r;
	int R;
	int centreX;
	int centreY;
	double S;
	int size;
	int *arr;

	bool check(int valueR, int valuer);
public:
	ellipse(int r, int R)
	{
		this->r = r;
		this->R = R;
	}
	ellipse(string setname, int valuer, int valueR, int valueCentreX, int valueCentreY,int valuesize)
	{
		name = setname;
		r = valuer;
		R = valueR;
		centreX = valueCentreX;
		centreY = valueCentreY;
		size = valuesize;
		this->arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 10;
		}
		cout << "constructor called " << this << endl;
	}
	ellipse()
	{
		name = "empty";
		r = 0;
		R = 0;
		S = 0;
		centreX = 0;
		centreY = 0;
		arr = nullptr;
		cout << "constructor called " << this << endl;
	}


	//copy constructor
	ellipse(const ellipse &other)
	{
		this->size = other.size;
		this->arr = new int[other.size];

		for (int i = 0; i < other.size; i++)
		{
			this->arr[i] = other.arr[i];
		}
		this->r = other.r;
		this->R = other.R;
		cout << "copy constructor called " << this << endl;
	}
	//destructor
	~ellipse()
	{
		cout << "destructor called " << this << endl;
		delete[] arr;
	}
	void foo();
	void countSquare();

	int Getr();
	int GetR();
	int GetCentreX();
	int GetCentreY();
	string GetName();

	void SetSize(int valuesize);
	void Setr(int valuer);
	void SetR(int valueR);
	void SetCentreX(int valuex);
	void SetCentreY(int valuey);
	void SetName(string setname);

	void createArray();
	void printArray();

	void printInfo();

	void inputName();
	void inputradiuses();
	void inputCentreCoordinates();
	void inputSize();

	void addToRadiuses();
	void addToCoordinates();

	void subFromCoordinates();
	void subFromRadiuses();

	friend ellipse operator +(int, ellipse&);
	friend ellipse operator +(ellipse&, int);

	bool operator >(const ellipse& other);
	ellipse operator +(const ellipse& other);
	ellipse& operator ++();
	ellipse& operator ++(int value);
	operator double();
};