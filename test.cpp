#include "test.h"
#include <iostream>
#include "geometry.h"
#include <vector>

int g_iFailureCount = 0;
int g_iSuccessfulTests = 0;
int g_iTestsRun = 0;

void RunAllTests()
{
	TestEqual();
	std::cout << "Tests Succeeded: " << g_iSuccessfulTests;
	std::cout << "Tests Run:" << g_iTestsRun;

}

void TestEqual()
{
	if (Equals(TVector3{ 1, 2, 3 }, TVector3{ 1, 2, 3 }) == true)
	{
		g_iSuccessfulTests += 1;
		std::cout << "Equals(TVector3{ 1, 2, 3 }, TVector3{ 1, 2, 3 }" << "Succeded" << std::endl;
	}
	else
	{
		std::cout << "Equals(TVector3{ 1, 2, 3 }, TVector3{ 1, 2, 3 }" << "Failed" << std::endl;
	}
}


