// cpp_math_test.cpp : main project file.

#include <iostream>
#include "UnitTest.h"
#include "SimpleVector2D.h"

using namespace prj::math;
using namespace prj::unit_test;

class TestSimpleVector2D : public UnitTest
{
public :
	void Constructors(void)
	{
		std::cout << "TestSimpleVector2D::Constructor Begin";
		SimpleVector2D * pv3;
		SimpleVector2D v1;
		SimpleVector2D v2(1.0, 2.0);
		pv3 = new SimpleVector2D(v2);


		Check(v1.GetX() == 0.0 && v1.GetY() == 0.0,"Error in the default constuctor");

		Check(v2.GetX() == 1.0 && v2.GetY() == 2.0, "Error in the constructor with 2 parameter");

		Check(pv3->GetX() == 1.0 && pv3->GetY() == 2.0, "Error in the constuctor with copy poarameter");

		std::cout << "TestSimpleVector2D::Constructor End";
	}

	void Run()
	{
		try
		{
			Constructors();
		}
		catch (...)
		{
		}
	}
};

int main(void)
{
	TestSimpleVector2D T1;
	T1.Run();
    return 0;
}
