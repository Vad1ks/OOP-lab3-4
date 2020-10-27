#include "lab03.h"
#include <string>

ellipse operator+(int value,ellipse&other)
{
	ellipse temp;
	temp.r = other.r + value;
	temp.R = other.R + value;
	return temp;
}
ellipse operator+(ellipse&other, int value)
{
	ellipse temp;
	temp.r = other.r + value;
	temp.R = other.R + value;
	return temp;
}

int main()
{
	ellipse b("Vadym", 1, 2, 1, 1, 5);
	b.printInfo();
	b = 3 + b;
	b.printInfo();

	system("pause");
	return 0;
}
