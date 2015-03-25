// cpp_math_test.cpp : main project file.

#include "stdafx.h"

#include "UnitTest.h"
#include "SimpleVector2D.h"

using namespace System;
using namespace prj::math_lib;
using namespace prj::unit_test;

class TestSimpleVector2D : public UnitTest
{
public :
	void Constructors(void)
	{
		Console::WriteLine(L"TestSimpleVector2D::Constructor Begin");

		SimpleVector2D v1;
		Check(v1.GetX() == 0.0 && v1.GetY() == 0.0,"Error in the default constuctor");

		SimpleVector2D v2(2.0, 2.0);
		Check(v2.GetX() == 1.0 && v2.GetY() == 2.0, "Error in the constuctor with 2 parameter");
		Console::WriteLine(L"TestSimpleVector2D::Constructor End");
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

int main(array<System::String ^> ^args)
{
    Console::WriteLine(L"Hello World");

	TestSimpleVector2D T1;
	T1.Run();
    return 0;
}
