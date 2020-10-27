#include "lab03.h"
#include <string>
using namespace std;
#define PI 3.14159265358979323846;

bool ellipse::check(int valueR, int valuer)
{
	if (valueR <= 0 || valuer <= 0)
	{
		return false;
	}
	return valueR > valuer ? true : false;
}
void ellipse::foo()
{
	ellipse b;
	ellipse c(b);
}

int ellipse::Getr()
{

	return r;
}
void ellipse::countSquare()
{
	S = r * R*PI;
}

int ellipse::GetR()
{
	return R;
}
int ellipse::GetCentreX() {
	return centreX;
}
int ellipse::GetCentreY() {
	return centreY;
}
string ellipse::GetName()
{
	return name;
}

void ellipse::Setr(int valuer)
{
	r = valuer;
}
void ellipse::SetR(int valueR)
{
	R = valueR;
}
void ellipse::SetCentreX(int valuex)
{
	centreX = valuex;
}
void ellipse::SetCentreY(int valuey)
{
	centreY = valuey;
}
void ellipse::SetName(string setname)
{
	name = setname;
}
void ellipse::SetSize(int valuesize)
{
	size = valuesize;
	delete[] arr;
	//int*temp = new int[size];
	//arr = temp;
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

void ellipse::printInfo()
{
	S = r * R*PI;
	cout << "name is " << name << endl << "r = " << r << endl << "R = " << R << endl << "S = " << S << endl
		<< "It's centre is located in (" << centreX << "," << centreY << ")" << endl << endl;
}

void ellipse::inputName()
{
	string setname;
	cout << "input name of ellipse: " << endl;
	cin >> setname;
	SetName(setname);
}
void ellipse::inputradiuses()
{
	int valuer;
	int valueR;
	cout << "\t\t\t\t\tnote: r must be less than R" << endl;
	do
	{
		cout << "input smaller radius: " << endl;
		cin >> valuer;

		cout << "input bigger radius: " << endl;
		cin >> valueR;

		if (!check(valueR, valuer))
		{
			cout << endl << "values are invalid,try again" << endl;
		}
	} while (!check(valueR, valuer));
	Setr(valuer);
	SetR(valueR);
}
void ellipse::inputCentreCoordinates()
{
	int valuex, valuey;
	cout << "input the x-coordinate of centre" << endl;
	cin >> valuex;
	SetCentreX(valuex);
	cout << "input the y-coordinate of centre" << endl;
	cin >> valuey;
	SetCentreY(valuey);
}

void ellipse::inputSize()
{
	int valuesize;
	cout << "input size of array" << endl;
	cin >> valuesize;

	SetSize(valuesize);
}
void ellipse::createArray()
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}
void ellipse::printArray()
{
	if (arr != nullptr)
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}

void ellipse::addToRadiuses()
{
	int valuer, valueR, addvaluer, addvalueR;
	cout << "\t\t\t\t\tnote: r must be less than R" << endl;
	do {
		valuer = Getr();
		valueR = GetR();
		cout << "input value to add to smaller radius: " << endl;
		cin >> addvaluer;
		valuer += addvaluer;

		cout << "input value to add to bigger radius: " << endl;
		cin >> addvalueR;
		valueR += addvalueR;
		if (!check(valueR, valuer))
		{
			cout << endl << "values are invalid,try again" << endl;
		}
	} while (!check(valueR, valuer));
	Setr(valuer);
	SetR(valueR);
}
void ellipse::addToCoordinates()
{
	int valuex, valuey, addvaluex, addvaluey;
	valuex = GetCentreX();
	valuey = GetCentreY();

	cout << "input value to add to the x-coordinate" << endl;
	cin >> addvaluex;
	valuex += addvaluex;
	SetCentreX(valuex);

	cout << "input value to add to the y-coordinate" << endl;
	cin >> addvaluey;
	valuey += addvaluey;
	SetCentreY(valuey);
}

void ellipse::subFromCoordinates()
{
	int valuex, valuey, subvaluex, subvaluey;
	valuex = GetCentreX();
	valuey = GetCentreY();

	cout << "input value to sub from the x-coordinate" << endl;
	cin >> subvaluex;
	valuex -= subvaluex;
	SetCentreX(valuex);

	cout << "input value to sub from the y-coordinate" << endl;
	cin >> subvaluey;
	valuey -= subvaluey;
	SetCentreY(valuey);
}
void ellipse::subFromRadiuses()
{
	int valuer, valueR, subvaluer, subvalueR;
	cout << "\t\t\t\t\tnote: r must be less than R" << endl;
	do {
		valuer = Getr();
		valueR = GetR();
		cout << "input value to sub from smaller radius: " << endl;
		cin >> subvaluer;
		valuer -= subvaluer;

		cout << "input value to sub from bigger radius: " << endl;
		cin >> subvalueR;
		valueR -= subvalueR;
		if (!check(valueR, valuer))
		{
			cout << endl << "values are invalid,try again" << endl;
		}
	} while (!check(valueR, valuer));
	SetR(valueR);
	Setr(valuer);
}

bool ellipse::operator >(const ellipse& other)
{
	return (this->r > other.r && this->R > other.R);
}
ellipse ellipse::operator+(const ellipse& other)
{
	ellipse temp;
	temp.r = this->r + other.r;
	temp.R = this->R + other.R;
	return temp;
}

ellipse& ellipse::operator ++()
{
	this->r += 1;
	this->R += 1;

	return *this;
}
ellipse& ellipse::operator ++(int value)
{
	ellipse	temp(*this);
	this->r+=2;
	this->R+=2;

	return temp;
}
ellipse::operator double()
{
	return S;
}
