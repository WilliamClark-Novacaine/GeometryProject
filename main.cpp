#include <iostream>
#include "test.h"

int main()
{
	const auto CTests = new GeometryTest;
	CTests->RunAllTests();
	return 0;
}