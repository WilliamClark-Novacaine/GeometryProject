#include "test.h"
#include <iostream>
#include "geometry.h"
#include <vector>

int g_iFailureCount = 0;
int g_iSuccessCount = 0;
int g_iNumTestsRun = 0;

void GeometryTest::RunAllTests()
{
	TestAdd();
	
	std::cout << "Tests Succeeded: " << g_iSuccessCount;
	std::cout << "Tests Failed: " << g_iFailureCount;
	std::cout << "Tests Run:" << g_iNumTestsRun;

}

void GeometryTest::TestEquals() const
{
	constexpr TVector3 kv3Vector1Data[3] = {{1,2,3},{1, 3, 0},{0.007f, 0.0063f, 0.000012f} };
	constexpr TVector3 kv3Vector2Data[3] = {{1,2,3},{1, 2.999999f, 0.0000001f},{0.2f, 1.4f, 8.f}};
	constexpr bool kbExpectedResult[3] = {true, true, false};
	for (int i = 0; i < std::size(kv3Vector1Data); i++)
	{
		if (Equals(kv3Vector1Data[i], kv3Vector2Data[i]) == kbExpectedResult[i])
		{
			std::cout << "Equals: Test " << i + 1 << " Succeeded" << std::endl;
			g_iSuccessCount++;
		}
		else
		{
			std::cout << "Equals: Test " << i + 1<< " Failed" << std::endl;
			std::cout << "Expected Result: " << kbExpectedResult[i] << std::endl;
			g_iFailureCount++;
		}
		g_iNumTestsRun++;
	}
}

void GeometryTest::TestAdd()
{
	constexpr TVector3 v3TestVectorA{ 4,6,3 };
	constexpr TVector3 v3TestVectorB{ 1,2,3 };
	TVector3 Resultant1{ 0, 0, 0 };
	Add(v3TestVectorA, v3TestVectorB, Resultant1);
	if (Equals(Resultant1, {2,4,6}) == true)
	{
		std::cout << "Equals: Test " << 1 << " Succeeded" << std::endl;
		g_iSuccessCount++;
	}
	else
	{
		std::cout << "Equals: Test " << 1 << " Failed" << std::endl;
		std::cout << "Expected Result: " << true << std::endl;
		g_iFailureCount++;
	}
}

void GeometryTest::TestSubtract()
{
}

void GeometryTest::TestScaleVector()
{
}

void GeometryTest::TestMagnitude()
{
}

void GeometryTest::TestDotProduct()
{
}

void GeometryTest::TestCrossProduct()
{
}

void GeometryTest::TestNormalise()
{
}

void GeometryTest::TestProjection()
{
}

void GeometryTest::TestComputeAngleBetween2D()
{
}

void GeometryTest::TestComputeAngleBetween3D()
{
}

void GeometryTest::TestComputeDistancePointToLine()
{
}

void GeometryTest::TestComputeDistancePointToPlane()
{
}

void GeometryTest::TestComputeDistancePointToSphere()
{
}

void GeometryTest::TestComputeDistanceCircleToCircle()
{
}

void GeometryTest::TestComputeDistanceCircleToTriangle()
{
}

void GeometryTest::TestComputeLineSphereIntersection()
{
}

void GeometryTest::TestIsLinePlaneIntersection()
{
}

void GeometryTest::TestIsIntersection()
{
}

void GeometryTest::TestComputeIntersectionBetweenLines()
{
}

void GeometryTest::TestIsInFieldOfView()
{
}

void GeometryTest::TestFindTriangleNormal()
{
}

void GeometryTest::TestIsSurfaceLit()
{
}

void GeometryTest::TestRotateTriangleAroundPoint()
{
}


