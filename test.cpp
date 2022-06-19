#include "test.h"
#include <iostream>
#include "geometry.h"
#include <vector>

int g_iFailureCount = 0;
int g_iSuccessfulTests = 0;
int g_iTestsRun = 0;

void GeometryTest::RunAllTests()
{
	TestEquals();
	
	std::cout << "Tests Succeeded: " << g_iSuccessfulTests;
	std::cout << "Tests Run:" << g_iTestsRun;

}

void GeometryTest::TestEquals()
{
	TVector3 TVector1Data[3] = {{1,2,3},{},{}};
	TVector3 TVector2Data[3] = {{1,2,3},{},{}};
	bool bExpectedResult[3] = {true, false, true};
	for (int i; i < 3; i++)
	{
		if (Equals(TVector1Data[i], TVector2Data[i]) == true)
		{
			g_iSuccessfulTests += 1;
			std::cout << "Equals: Test " << i + 1 << "Succeded" << std::endl;
		}
		else
		{
			std::cout << "Equals: Test " << i + 1<< "Failed" << std::endl;
			std::cout << "Expected Result: " << bExpectedResult[i] << std::endl;
		}
	}
}


