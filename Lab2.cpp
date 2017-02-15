//Вариант №7. Лаба 2.

#include "stdafx.h"
#include "iostream"
#include "math.h"

class Quadratic
{
private:
	float A = 0;
	float B = 0;
	float C = 0;
public:
	Quadratic()
	{
		A = 1;
		B = 4;
		C = 4;
	}
	Quadratic(float A_in, float B_in, float C_in)
	{
			A = A_in;
			B = B_in;
			C = C_in;
	}
	void Print()
	{
		std::cout
			<< "a= "
			<< A
			<< "\nb= "
			<< B
			<< "\nc= "
			<< C
			<< std::endl;
	}
	float Discriminant()
	{
		float result = (this->B*this->B) - 4*(this->A*this->C);
		return result;
	}
	void Root(float Discrim, float* x1, float* x2)
	{
		if (Discrim == 0)
		{
			*x1 = -B / (2 * A);
			std::cout << "D=0; Only one root :";
		}
		else
		{
			*x1 = (-B + (sqrt(Discrim))) / (2 * A); 
			*x2 = (-B - (sqrt(Discrim))) / (2 * A);
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	//Чтобы проверить с целыми корнями, можете ввести a = 1, b = -8, c = -9 (к примеру).
	float a = 1;
	float b = 1;
	float c = -19;
	Quadratic equation1(a, b, c);

	float dis = equation1.Discriminant();
	if (dis < 0)
	{
		std::cout << "D<0" << std::endl;
		system("pause");
		return 0;
	}
	float x1 = 0;
	float x2 = 0; 
	equation1.Root(dis, &x1, &x2);
	std::cout << x1 << std::endl;
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

