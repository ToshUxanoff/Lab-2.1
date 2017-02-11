//Вариант №7. Лаба 2.

#include "stdafx.h"
#include "iostream"
#include "math.h"

class Quadratic
{
private:
	float a = 0;
	float b = 0;
	float c = 0;
public:
	Quadratic(float ain, float bin, float cin)
	{
		if (ain == 0)
		{
			std::cout << "Wrong parameter 'a'" << std::endl;
		}
		else
		{
			a = ain;
			b = bin;
			c = cin;
		}
	
	}
	void Print()
	{
		std::cout
			<< "a= "
			<< a
			<< "\nb= "
			<< b
			<< "\nc= "
			<< c
			<< std::endl;
	}
	float Discriminant()
	{
		float result = (this->b*this->b) - 4*(this->a*this->c);
		return result;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	//Чтобы проверить с целыми корнями, можете ввести a = 1, b = -8, c = -9 (к примеру).
	float a = 1;
	float b = 1;
	float c = -20;
	Quadratic equation1(a, b, c);
	if (equation1.Discriminant() < 0)
	{
		std::cout << "Корней нет (D < 0)" << std::endl;
		system("pause");
		return -1;
	}
	float x1 = -b + (sqrt(equation1.Discriminant())) / (2 * a);
	float x2 = -b - sqrt(equation1.Discriminant()) / (2 * a);
	std::cout << x1-(int)x1 << std::endl;
	std::cout << x2 << std::endl;
	if (x1-(int)x1 != 0 || x2-(int)x2 !=0)
	{
		equation1.Print();
	}
	else 
	{
		std::cout << "Корни целые. Коэффициенты не выводятся." << std::endl;
	}
	system("pause");
	return 0;
}

