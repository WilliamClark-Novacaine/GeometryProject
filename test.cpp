#include "test.h"
#include <iostream>
#include "geometry.h"
#include <vector>

int g_iFailureCount = 0;
int g_iSuccessCount = 0;
int g_iNumTestsRun = 0;

inline const char* BoolToString(bool _b)
{
	return _b ? "true" : "false";
}

void GeometryTest::RunAllTests()
{
	TestEquals();
	TestAdd();
	TestSubtract();
	TestScaleVector();
	TestMagnitude();
	TestDotProduct();
	TestCrossProduct();
	TestNormalise();
	TestProjection();
	TestComputeAngleBetween2D();
	TestComputeAngleBetween3D();
	TestComputeDistancePointToLine();
	TestComputeDistancePointToPlane();
	TestComputeDistancePointToSphere();
	TestComputeDistanceCircleToCircle();
	TestComputeDistanceCircleToTriangle();
	TestComputeLineSphereIntersection();
	TestIsLinePlaneIntersection();
	TestIsIntersection();
	TestComputeIntersectionBetweenLines();
	TestIsInFieldOfView();
	TestFindTriangleNormal();
	TestIsSurfaceLit();
	TestRotateTriangleAroundPoint();
	
	std::cout << "Tests Succeeded: " << g_iSuccessCount << std::endl;
	std::cout << "Tests Failed: " << g_iFailureCount << std::endl;
	std::cout << "Tests Run:" << g_iNumTestsRun << std::endl;

}

void GeometryTest::TestEquals() const
{
	constexpr TVector3 kv3VectorAData[3] = {{1,2,3},{1, 3, 0},{0.007f, 0.0063f, 0.000012f} };
	constexpr TVector3 kv3VectorBData[3] = {{1,2,3},{1, 2.9999999f, 0.00000001f},{0.2f, 1.4f, 8.f}};
	constexpr bool kbExpectedSuccess[3] = {true, true, false};
	std::cout << "EQUALS TESTS:\n";
	for (int i = 0; i < std::size(kv3VectorAData); i++)
	{
		if (const bool kbGivenResult = Equals(kv3VectorAData[i], kv3VectorBData[i]) == kbExpectedSuccess[i])
		{
			std::cout << "Test " << i + 1 << " Succeeded!" << " Expected Result: " << BoolToString(kbExpectedSuccess[i]) << std::endl;
			g_iSuccessCount++;
		}
		else
		{
			std::cout << "Test " << i + 1<< " Failed" << std::endl;
			std::cout << "Given Result: " << BoolToString(kbGivenResult) << std::endl;
			std::cout << "Expected Result: " << BoolToString(kbExpectedSuccess[i]) << std::endl;
			g_iFailureCount++;
		}
		g_iNumTestsRun++;
	}
		std::cout << std::endl;
}

void GeometryTest::TestAdd() const
{
	TVector3 rResultant{};
	constexpr TVector3 kv3VectorAData[3] = { {1,2,3},{1, 3, 0},{0.007f, 0.0063f, 0.000012f} };
	constexpr TVector3 kv3VectorBData[3] = { {1,2,3},{1, 2.9999999f, 0.00000001f},{0.2f, 1.4f, 8.f} };
	constexpr TVector3 kv3ValidationData[3] = { {2,4,6}, {2, 6, 0}, {8,4,2} };
	constexpr bool kbExpectedSuccess[3] = { true, true, false };
	std::cout << "ADD TESTS:\n";
	for (int i = 0; i < std::size(kv3VectorAData); i++)
	{
		Add(kv3VectorAData[i], kv3VectorBData[i], rResultant);
		if (Equals(rResultant, kv3ValidationData[i]) == kbExpectedSuccess[i])
		{
			std::cout << "Test " << i + 1 << " Succeeded!" << " Expected Result: " << kv3ValidationData[i].m_fX << "," << kv3ValidationData[i].m_fY << "," << kv3ValidationData[i].m_fZ << std::endl;
			g_iSuccessCount++;
		}
		else
		{
			std::cout << "Test " << i + 1 << " Failed" << std::endl;
			std::cout << "Given Result: " << rResultant.m_fX << "," << rResultant.m_fY << "," << rResultant.m_fZ << std::endl;
			std::cout << "Expected Result: " << kv3ValidationData[i].m_fX << "," << kv3ValidationData[i].m_fY << "," << kv3ValidationData[i].m_fZ << std::endl;
			g_iFailureCount++;
		}
		g_iNumTestsRun++;
	}
	std::cout << std::endl;
}

void GeometryTest::TestSubtract() const
{
	TVector3 rResultant{};
	constexpr TVector3 kv3VectorAData[3] = { {1,2,3},{1, 3, 0},{0.007f, 0.00633333f, 8.000012f} };
	constexpr TVector3 kv3VectorBData[3] = { {1,2,3},{1, 2.9999999f, 1.f},{0.2f, 1.4f, 8.f} };
	constexpr TVector3 kv3ValidationData[3] = { {0,0,0}, {0, 0, -1}, {-0.193f,-1.39366667f,0.000012f} };
	constexpr bool kbExpectedSuccess[3] = { true, true, true };
	std::cout << "SUBTRACT TESTS:\n";
	for (int i = 0; i < std::size(kv3VectorAData); i++)
	{
		Subtract(kv3VectorAData[i], kv3VectorBData[i], rResultant);
		if (Equals(rResultant, kv3ValidationData[i]) == kbExpectedSuccess[i])
		{
			std::cout << "Test " << i + 1 << " Succeeded!" << " Expected Result: " << kv3ValidationData[i].m_fX << "," << kv3ValidationData[i].m_fY << "," << kv3ValidationData[i].m_fZ << std::endl;
			g_iSuccessCount++;
		}
		else
		{
			std::cout << "Test " << i + 1 << " Failed" << std::endl;
			std::cout << "Given Result: " << rResultant.m_fX << "," << rResultant.m_fY << "," << rResultant.m_fZ << std::endl;
			std::cout << "Expected Result: " << kv3ValidationData[i].m_fX << "," << kv3ValidationData[i].m_fY << "," << kv3ValidationData[i].m_fZ << std::endl;
			g_iFailureCount++;
		}
		g_iNumTestsRun++;
	}
	std::cout << std::endl;
}

void GeometryTest::TestScaleVector() const
{
	TVector3 rResultant{};
	constexpr TVector3 kv3VectorAData[3] = { {1,2,3},{6, 3, 1},{0.007f, 0.00633333f, 8.000012f} };
	constexpr float kfScalar[3] = {3, 4, -6};
	constexpr TVector3 kv3ValidationData[3] = { {3,6,9}, {24, 12, 4}, {-0.042f,-0.038f,-48.000072f} };
	constexpr bool kbExpectedSuccess[3] = { true, true, true };
	std::cout << "SCALE VECTOR TESTS:\n";
	for (int i = 0; i < std::size(kv3VectorAData); i++)
	{
		ScaleVector(kv3VectorAData[i], kfScalar[i], rResultant);
		if (Equals(rResultant, kv3ValidationData[i]) == kbExpectedSuccess[i])
		{
			std::cout << "Test " << i + 1 << " Succeeded!" << " Expected Result: " << kv3ValidationData[i].m_fX << "," << kv3ValidationData[i].m_fY << "," << kv3ValidationData[i].m_fZ << std::endl;
			g_iSuccessCount++;
		}
		else
		{
			std::cout << "Test " << i + 1 << " Failed" << std::endl;
			std::cout << "Given Result: " << rResultant.m_fX << "," << rResultant.m_fY << "," << rResultant.m_fZ << std::endl;
			std::cout << "Expected Result: " << kv3ValidationData[i].m_fX << "," << kv3ValidationData[i].m_fY << "," << kv3ValidationData[i].m_fZ << std::endl;
			g_iFailureCount++;
		}
		g_iNumTestsRun++;
	}
	std::cout << std::endl;
}

void GeometryTest::TestMagnitude() const
{
	constexpr TVector3 kv3VectorAData[3] = { {1,2,3},{6, 3, -1},{0.007f, 0.00633333f, 8.000012f}};
	constexpr float kfComparisonData[3] = { 3.7416573f , 6.782329f, 8.000017569f};
	constexpr bool kbExpectedSuccess[3] = { true, true, true };
	std::cout << "MAGNITUDE TESTS:\n";
	for (int i = 0; i < std::size(kv3VectorAData); i++)
	{
		const float kfMagnitudeResult = Magnitude(kv3VectorAData[i]);
		if (fabsf(kfMagnitudeResult - kfComparisonData[i]) < 0.001f == kbExpectedSuccess[i])
		{
			std::cout << "Test " << i + 1 << " Succeeded!" << " Expected Result: " << BoolToString(kbExpectedSuccess[i]) << std::endl;
			g_iSuccessCount++;
		}
		else
		{
			std::cout << "Test " << i + 1 << " Failed" << std::endl;
			std::cout << "Given Result: " << kfMagnitudeResult << std::endl;
			std::cout << "Expected Result: " << kfComparisonData[i] << std::endl;
			g_iFailureCount++;
		}
		g_iNumTestsRun++;
	}
	std::cout << std::endl;
}

void GeometryTest::TestDotProduct() const
{
	constexpr TVector3 kv3VectorAData[3] = { {1,2,3},{6, 3, -1},{0.007f, 0.00633333f, 8.000012f}};
	constexpr TVector3 kv3VectorBData[3] = { {1,2,3},{1, 2.9999999f, 1.f},{0.2f, 1.4f, 8.f} };
	constexpr float kfComparisonData[3] = { 14.f , 14.f, 64.0103683f };
	constexpr bool kbExpectedSuccess[3] = { true, true, true };
	std::cout << "DOT PRODUCT TESTS:\n";
	for (int i = 0; i < std::size(kv3VectorAData); i++)
	{
		const float kfDotProdResult = DotProduct(kv3VectorAData[i], kv3VectorBData[i]);
		if (fabsf(kfDotProdResult - kfComparisonData[i]) < 0.001f == kbExpectedSuccess[i])
		{
			std::cout << "Test " << i + 1 << " Succeeded!" << " Expected Result: " << BoolToString(kbExpectedSuccess[i]) << std::endl;
			g_iSuccessCount++;
		}
		else
		{
			std::cout << "Test " << i + 1 << " Failed" << std::endl;
			std::cout << "Given Result: " << kfDotProdResult << std::endl;
			std::cout << "Expected Result: " << kfComparisonData[i] << std::endl;
			g_iFailureCount++;
		}
		g_iNumTestsRun++;
	}
	std::cout << std::endl;
}

void GeometryTest::TestCrossProduct() const
{
	TVector3 rResultant{};
	constexpr TVector3 kv3VectorAData[3] = { {1,2,3},{6, 3, -1},{0.007f, 0.00633333f, 8.000012f} };
	constexpr TVector3 kv3VectorBData[3] = { {1,2,3},{1, 2.9999999f, 1.f},{0.2f, 1.4f, 8.f} };
	constexpr TVector3 kv3ValidationData[3] = {{0,0,0},{6.f,-7, 15},{-11.14935f, 1.5440024f, 0.008533334f}};
	constexpr bool kbExpectedSuccess[3] = { true, true, true };
	std::cout << "CROSS PRODUCT TESTS:\n";
	for (int i = 0; i < std::size(kv3VectorAData); i++)
	{
		CrossProduct(kv3VectorAData[i], kv3VectorBData[i], rResultant);
		if (Equals(rResultant, kv3ValidationData[i]) == kbExpectedSuccess[i])
		{
			std::cout << "Test " << i + 1 << " Succeeded!" << " Expected Result: " << kv3ValidationData[i].m_fX << "," << kv3ValidationData[i].m_fY << "," << kv3ValidationData[i].m_fZ << std::endl;
			g_iSuccessCount++;
		}
		else
		{
			std::cout << "Test " << i + 1 << " Failed" << std::endl;
			std::cout << "Given Result: " << rResultant.m_fX << "," << rResultant.m_fY << "," << rResultant.m_fZ << std::endl;
			std::cout << "Expected Result: " << kv3ValidationData[i].m_fX << "," << kv3ValidationData[i].m_fY << "," << kv3ValidationData[i].m_fZ << std::endl;
			g_iFailureCount++;
		}
		g_iNumTestsRun++;
	}
	std::cout << std::endl;
}

void GeometryTest::TestNormalise() const
{
	TVector3 rResultant{};
	constexpr TVector3 kv3VectorAData[3] = { {-1,2,4},{8, 3, -1},{-0.007f, 0.000333f, 8.212f} };
	constexpr TVector3 kv3ValidationData[3] = { {-0.21821f,0.43643f,0.8728715f},{0.929981f, 0.348743f, -0.11624764f},{-0.00085f, 0.0000, 1} };
	constexpr bool kbExpectedSuccess[3] = { true, true, true };
	std::cout << "NORMALISE TESTS:\n";
	for (int i = 0; i < std::size(kv3VectorAData); i++)
	{
		Normalise(kv3VectorAData[i], rResultant);
		if (Equals(rResultant, kv3ValidationData[i]) == kbExpectedSuccess[i])
		{
			std::cout << "Test " << i + 1 << " Succeeded!" << " Expected Result: " << kv3ValidationData[i].m_fX << "," << kv3ValidationData[i].m_fY << "," << kv3ValidationData[i].m_fZ << std::endl;
			g_iSuccessCount++;
		}
		else
		{
			std::cout << "Test " << i + 1 << " Failed" << std::endl;
			std::cout << "Given Result: " << rResultant.m_fX << "," << rResultant.m_fY << "," << rResultant.m_fZ << std::endl;
			std::cout << "Expected Result: " << kv3ValidationData[i].m_fX << "," << kv3ValidationData[i].m_fY << "," << kv3ValidationData[i].m_fZ << std::endl;
			g_iFailureCount++;
		}
		g_iNumTestsRun++;
	}
	std::cout << std::endl;
}

void GeometryTest::TestProjection() const
{
	TVector3 rResultant{};
	constexpr TVector3 kv3VectorAData[3] = { {-1,2,4},{8, 3, -1},{-0.7f, -0.33f, -8.212f} };
	constexpr TVector3 kv3VectorBData[3] = { {1,2,3},{1, 2.9999999f, 1.f},{0.2f, 1.4f, 8.f} };
	constexpr TVector3 kv3ValidationData[3] = { {1.071428571f, 2.1428571f, 3.2142857142f},{1.4545454f, 4.36363636363f, 1.454545454f},{-0.2009f, -1.4063f, -8.036f} };
	constexpr bool kbExpectedSuccess[3] = { true, true, true };
	std::cout << "PROJECTION TESTS:\n";
	for (int i = 0; i < std::size(kv3VectorAData); i++)
	{
		Projection(kv3VectorAData[i], kv3VectorBData[i], rResultant);
		if (Equals(rResultant, kv3ValidationData[i]) == kbExpectedSuccess[i])
		{
			std::cout << "Test " << i + 1 << " Succeeded!" << " Expected Result: " << kv3ValidationData[i].m_fX << "," << kv3ValidationData[i].m_fY << "," << kv3ValidationData[i].m_fZ << std::endl;
			g_iSuccessCount++;
		}
		else
		{
			std::cout << "Test " << i + 1 << " Failed" << std::endl;
			std::cout << "Given Result: " << rResultant.m_fX << "," << rResultant.m_fY << "," << rResultant.m_fZ << std::endl;
			std::cout << "Expected Result: " << kv3ValidationData[i].m_fX << "," << kv3ValidationData[i].m_fY << "," << kv3ValidationData[i].m_fZ << std::endl;
			g_iFailureCount++;
		}
		g_iNumTestsRun++;
	}
	std::cout << std::endl;
}

void GeometryTest::TestComputeAngleBetween2D() const
{
	constexpr TVector2 kv3VectorAData[3] = { {-1.f,2.f},{-2.f, 3.f},{-1.00000004f, 0.00013478f} };
	constexpr TVector2 kv3VectorBData[3] = { {-1.f,2.f},{3.f, 2.f},{4.00004f, -0.13478f} };
	constexpr float kfValidationData[3] = { 0, 1.57079f, 3.10804f};
	constexpr bool kbExpectedSuccess[3] = { true, true, true };
	std::cout << "ANGLE BETWEEN 2D TESTS:\n";
	for (int i = 0; i < std::size(kv3VectorAData); i++)
	{
		const float kfResultant = ComputeAngleBetween(kv3VectorAData[i], kv3VectorBData[i]);
		if (fabsf(kfResultant - kfValidationData[i]) < 0.001f == kbExpectedSuccess[i])
		{
			std::cout << "Test " << i + 1 << " Succeeded!" << " Expected Result: " << kfValidationData[i] << std::endl;
			g_iSuccessCount++;
		}
		else
		{
			std::cout << "Test " << i + 1 << " Failed" << std::endl;
			std::cout << "Given Result: " << kfResultant <<std::endl;
			std::cout << "Expected Result: " << kfValidationData[i] << std::endl;
			g_iFailureCount++;
		}
		g_iNumTestsRun++;
	}
	std::cout << std::endl;
}

void GeometryTest::TestComputeAngleBetween3D() const
{
	constexpr TVector3 kv3VectorAData[3] = { {-1.f,2.f,3.f},{-2.f, 3.f, -1.f},{-1.00000004f, 0.00013478f, -8.2f} };
	constexpr TVector3 kv3VectorBData[3] = { {-1.f,2.f,3.f},{3.f, 2.f, -1.f},{4.00004f, -0.13478f, -8.f} };
	constexpr float kfValidationData[3] = { 0, 1.4993f, 0.585175f };
	constexpr bool kbExpectedSuccess[3] = { true, true, true };
	std::cout << "ANGLE BETWEEN 3D TESTS:\n";
	for (int i = 0; i < std::size(kv3VectorAData); i++)
	{
		const float kfResultant = ComputeAngleBetween(kv3VectorAData[i], kv3VectorBData[i]);
		if (fabsf(kfResultant - kfValidationData[i]) < 0.001f == kbExpectedSuccess[i])
		{
			std::cout << "Test " << i + 1 << " Succeeded!" << " Expected Result: " << kfValidationData[i] << std::endl;
			g_iSuccessCount++;
		}
		else
		{
			std::cout << "Test " << i + 1 << " Failed" << std::endl;
			std::cout << "Given Result: " << kfResultant << std::endl;
			std::cout << "Expected Result: " << kfValidationData[i] << std::endl;
			g_iFailureCount++;
		}
		g_iNumTestsRun++;
	}
	std::cout << std::endl;
}

void GeometryTest::TestComputeDistancePointToLine()
{
	constexpr T3DLine kT3DLineTest = {{8, 4.6f, 6}, {1,2.0002f,3}};
	constexpr TVector3 kv3PointTest = { 4,-8.004f,5.3f };
	constexpr float kfValidationData = {10.26304f};
	const float kfResultant = ComputeDistancePointToLine(kT3DLineTest, kv3PointTest);
	std::cout << "DISTANCE BETWEEN POINT TO LINE TEST:\n";
	if (fabsf(kfResultant - kfValidationData) < 0.001f == true)
	{
		std::cout << "Test " << 1 << " Succeeded!" << " Expected Result: " << kfValidationData << std::endl;
		g_iSuccessCount++;
	}
	else
	{
		std::cout << "Test " << 1 << " Failed" << std::endl;
		std::cout << "Given Result: " << kfResultant << std::endl;
		std::cout << "Expected Result: " << kfValidationData << std::endl;
		g_iFailureCount++;
	}
	g_iNumTestsRun++;
	std::cout << std::endl;
	
}

void GeometryTest::TestComputeDistancePointToPlane()
{
	constexpr TPlane kTPlaneTest = { {0.4f, 1.002f, 3.8f}, { 4,-4,3}};
	constexpr TVector3 kv3PointTest = {1, 3, 8};
	constexpr float kfValidationData = {6.28172f};
	const float kfResultant = ComputeDistancePointToPlane(kTPlaneTest, kv3PointTest);
	std::cout << "DISTANCE BETWEEN POINT TO PLANE TEST:\n";
	if (fabsf(kfResultant - kfValidationData) < 0.001f == true)
	{
		std::cout << "Test " << 1 << " Succeeded!" << " Expected Result: " << kfValidationData << std::endl;
		g_iSuccessCount++;
	}
	else
	{
		std::cout << "Test " << 1 << " Failed" << std::endl;
		std::cout << "Given Result: " << kfResultant << std::endl;
		std::cout << "Expected Result: " << kfValidationData << std::endl;
		g_iFailureCount++;
	}
	g_iNumTestsRun++;
	std::cout << std::endl;
}

void GeometryTest::TestComputeDistancePointToSphere()
{
	constexpr TSphere kTSphereTest = { {0.4f, 1.002f, 3.8f}, 5 };
	constexpr TVector3 kv3PointTest = { 1, 3, 8 };
	constexpr float kfValidationData = { 4.68956f };
	const float kfResultant = ComputeDistancePointToSphere(kTSphereTest, kv3PointTest);
	std::cout << "DISTANCE BETWEEN POINT TO SPHERE TEST:\n";
	if (fabsf(kfResultant - kfValidationData) < 0.001f == true)
	{
		std::cout << "Test " << 1 << " Succeeded!" << " Expected Result: " << kfValidationData << std::endl;
		g_iSuccessCount++;
	}
	else
	{
		std::cout << "Test " << 1 << " Failed" << std::endl;
		std::cout << "Given Result: " << kfResultant << std::endl;
		std::cout << "Expected Result: " << kfValidationData << std::endl;
		g_iFailureCount++;
	}
	g_iNumTestsRun++;
	std::cout << std::endl;
}

void GeometryTest::TestComputeDistanceCircleToCircle()
{
	constexpr TCircle kTCircleATest = { {2, 5}, 4 };
	constexpr TCircle kTCircleBTest = { {- 4, -6}, 8};
	constexpr float kfValidationData = { 12.529964086f };
	const float kfResultant = ComputeDistanceCircleToCircle(kTCircleATest, kTCircleBTest);
	std::cout << "DISTANCE BETWEEN CIRCLE TO CIRCLE TEST:\n";
	if (fabsf(kfResultant - kfValidationData) < 0.001f == true)
	{
		std::cout << "Test " << 1 << " Succeeded!" << " Expected Result: " << kfValidationData << std::endl;
		g_iSuccessCount++;
	}
	else
	{
		std::cout << "Test " << 1 << " Failed" << std::endl;
		std::cout << "Given Result: " << kfResultant << std::endl;
		std::cout << "Expected Result: " << kfValidationData << std::endl;
		g_iFailureCount++;
	}
	g_iNumTestsRun++;
	std::cout << std::endl;
}

void GeometryTest::TestComputeDistanceCircleToTriangle()
{
	constexpr TCircle kTCircleTest = { {2, 5}, 4 };
	constexpr TTriangle2 kTTriangleTest = { {4, 2}, {3, 7}, {8, 5} };
	constexpr float kfValidationData = { 3.01846f };
	const float kfResultant = ComputeDistanceCircleToTriangle(kTCircleTest, kTTriangleTest);
	std::cout << "DISTANCE BETWEEN CIRCLE TO TRIANGLE TEST:\n";
	if (fabsf(kfResultant - kfValidationData) < 0.001f == true)
	{
		std::cout << "Test " << 1 << " Succeeded!" << " Expected Result: " << kfValidationData << std::endl;
		g_iSuccessCount++;
	}
	else
	{
		std::cout << "Test " << 1 << " Failed" << std::endl;
		std::cout << "Given Result: " << kfResultant << std::endl;
		std::cout << "Expected Result: " << kfValidationData << std::endl;
		g_iFailureCount++;
	}
	g_iNumTestsRun++;
	std::cout << std::endl;
}

void GeometryTest::TestComputeLineSphereIntersection()
{
	TVector3 v3Intersection1{};
	TVector3 v3Intersection2{};
	constexpr TSphere kTSphereTest = { {2, 5, 10}, 8 };
	constexpr T3DLine kTLineTest = { {0, 1, 2}, {8, 7, 2}};
	constexpr TVector3 kv3ValidIntersectionsData[2] = {{6.52967f, 6.71346f, 3.63242f}, {1.67545f, 2.46602f, 2.41886f} };
	const EIntersections kEResultant = ComputeLineSphereIntersection(kTLineTest, kTSphereTest,v3Intersection1, v3Intersection2);
	std::cout << "LINE SPHERE INTERSECTION TEST:\n";
	if (Equals(v3Intersection1, kv3ValidIntersectionsData[0]) && Equals(v3Intersection2, kv3ValidIntersectionsData[1]) == true)
	{
		std::cout << "Test " << 1 << " Succeeded!" << " Expected Result: " << "Intersection 1: " << kv3ValidIntersectionsData[0].m_fX << ", " << kv3ValidIntersectionsData[0].m_fY << ", " << kv3ValidIntersectionsData[0].m_fZ << std::endl;
		std::cout << "\t\t\t\t   " << "Intersection 2: " << kv3ValidIntersectionsData[1].m_fX << ", " << kv3ValidIntersectionsData[1].m_fY << ", " << kv3ValidIntersectionsData[1].m_fZ << std::endl;
		g_iSuccessCount++;
	}
	else
	{
		std::cout << "Test " << 1 << " Failed" << std::endl;
		std::cout << "Given Result: " << "   Intersections 1: " << v3Intersection1.m_fX << ", " << v3Intersection1.m_fY << ", " << v3Intersection1.m_fZ << std::endl;
		std::cout << "\t\t" << " Intersection 2: " << v3Intersection2.m_fX << "," << v3Intersection2.m_fY << ", " << v3Intersection2.m_fZ << std::endl;
		std::cout << "Expected Result: " << "Intersection 1: " << kv3ValidIntersectionsData[0].m_fX << ", " << kv3ValidIntersectionsData[0].m_fY << ", " << kv3ValidIntersectionsData[0].m_fZ << std::endl;
		std::cout << "\t\t" << " Intersection 2: " << kv3ValidIntersectionsData[1].m_fX << ", " << kv3ValidIntersectionsData[1].m_fY << ", " << kv3ValidIntersectionsData[1].m_fZ << std::endl;
		g_iFailureCount++;
	}
	g_iNumTestsRun++;
	std::cout << std::endl;
}

void GeometryTest::TestIsLinePlaneIntersection()
{
	TVector3 IntersectionPoint = {};
	constexpr T3DLine TLineTest = { {0, -1, 0},{0, 1, -5} };
	constexpr TPlane kTPlaneTest = { {0, 11, 0},{1, 0, 1} };
	std::cout << "IS LINE PLANE INTERSECTION TEST:\n";
	if (const bool kbResultant = IsLinePlaneIntersection(TLineTest, kTPlaneTest, IntersectionPoint) == true)
	{
		std::cout << "Test " << 1 << " Succeeded!" << " Expected Result: " << BoolToString(true) << std::endl;
		g_iSuccessCount++;
	}
	else
	{
		std::cout << "Test " << 1 << " Failed" << std::endl;
		std::cout << "Given Result: " << kbResultant << std::endl;
		std::cout << "Expected Result: " << BoolToString(true) << std::endl;
		g_iFailureCount++;
	}
	g_iNumTestsRun++;
	std::cout << std::endl;
}

void GeometryTest::TestIsIntersection()
{
	TVector3 IntersectionPoint = {};
	constexpr T3DLine kTLine1Test = { {0, 0, 0},{1, 5, 20} };
	constexpr T3DLine kTLine2Test = { {0, 0, 0},{1, 5, 8} };
	std::cout << "IS INTERSECTION TEST:\n"; 
	if (const bool kbResultant = IsIntersection(kTLine1Test, kTLine2Test) == true)
	{
		std::cout << "Test " << 1 << " Succeeded!" << " Expected Result: " << BoolToString(true) << std::endl;
		g_iSuccessCount++;
	}
	else
	{
		std::cout << "Test " << 1 << " Failed" << std::endl;
		std::cout << "Given Result: " << kbResultant << std::endl;
		std::cout << "Expected Result: " << BoolToString(true) << std::endl;
		g_iFailureCount++;
	}
	g_iNumTestsRun++;
	std::cout << std::endl;
}

void GeometryTest::TestComputeIntersectionBetweenLines()
{
	TVector3 v3Intersection{};
	constexpr T3DLine kTLine1Test = { {8, 7, 2}, {2, 7, 8} };
	constexpr T3DLine kTLine2Test = { {2, 7, 8}, {8, 7, 2} };
	constexpr TVector3 kv3ValidIntersectionsData = {10, 14, 10};
	ComputeIntersectionBetweenLines(kTLine1Test, kTLine2Test, v3Intersection);
	std::cout << "INTERSECTION BETWEEN LINES TEST:\n";
	if (Equals(v3Intersection, kv3ValidIntersectionsData) == true)
	{
		std::cout << "Test " << 1 << " Succeeded!" << " Expected Result: " << "Intersection 1: " << kv3ValidIntersectionsData.m_fX << ", " << kv3ValidIntersectionsData.m_fY << ", " << kv3ValidIntersectionsData.m_fZ << std::endl;
		g_iSuccessCount++;
	}
	else
	{
		std::cout << "Test " << 1 << " Failed" << std::endl;
		std::cout << "Given Result: " << "   Intersections: " << v3Intersection.m_fX << ", " << v3Intersection.m_fY << ", " << v3Intersection.m_fZ << std::endl;
		std::cout << "Expected Result : " << "Intersection 1 : " << kv3ValidIntersectionsData.m_fX << ", " << kv3ValidIntersectionsData.m_fY << ", " << kv3ValidIntersectionsData.m_fZ << std::endl;
		g_iFailureCount++;
	}
	g_iNumTestsRun++;
	std::cout << std::endl;
}

void GeometryTest::TestIsInFieldOfView()
{
	constexpr TVector2 kv2CameraDirection{ -1, -1 };
	constexpr TVector2 kv2CameraPosition{ 5, 5 };
	constexpr TVector2 kv2ObjectPosition{ 1, 1 };
	std::cout << "IS IN FOV TEST:\n";
	if (const bool kbResultant = IsInFieldOfView(kv2CameraPosition, kv2CameraDirection, 2.0944f, kv2ObjectPosition) == true)
	{
		std::cout << "Test " << 1 << " Succeeded!" << " Expected Result: " << BoolToString(true) << std::endl;
		g_iSuccessCount++;
	}
	else
	{
		std::cout << "Test " << 1 << " Failed" << std::endl;
		std::cout << "Given Result: " << kbResultant << std::endl;
		std::cout << "Expected Result: " << BoolToString(true) << std::endl;
		g_iFailureCount++;
	}
	g_iNumTestsRun++;
	std::cout << std::endl;
}

void GeometryTest::TestFindTriangleNormal()
{
	constexpr TTriangle3 TTriangleTest = { {4,2,3}, {5,8,2}, {7,6,8} };
	TVector3 kv3TriangleNormal = {};
	constexpr TVector3 kv3ExpectedTriangleNormal = { 34,-8,-14};
	std::cout << "FIND TRIANGLE NORMAL TEST:\n";
	const TVector3 kv3Resultant = FindTriangleNormal(TTriangleTest, kv3TriangleNormal);
	if (Equals( kv3Resultant,kv3ExpectedTriangleNormal) == true)
	{
		std::cout << "Test " << 1 << " Succeeded!" << " Expected Result: " << kv3ExpectedTriangleNormal.m_fX << "," << kv3ExpectedTriangleNormal.m_fY << "," << kv3ExpectedTriangleNormal.m_fZ << std::endl;
		g_iSuccessCount++;
	}
	else
	{
		std::cout << "Test " << 1 << " Failed" << std::endl;
		std::cout << "Given Result: " << kv3Resultant.m_fX << "," << kv3Resultant.m_fY << "," << kv3Resultant.m_fZ << std::endl;
		std::cout << "Expected Result: " << kv3ExpectedTriangleNormal.m_fX << "," << kv3ExpectedTriangleNormal.m_fY << "," << kv3ExpectedTriangleNormal.m_fZ << std::endl;
		g_iFailureCount++;
	}
	g_iNumTestsRun++;
	std::cout << std::endl;
}

void GeometryTest::TestIsSurfaceLit()
{
	constexpr TVector3 kv3PointLight{ 0, 0, 0 };
	constexpr TVector3 kv3LightSourcePosition{ 1, 1, 1 };
	constexpr TTriangle3 kt3Surface{ { 1, -0.8f, 0 }, { 0, 0, 0 }, { -1, -0.80f, 0 } };
	std::cout << "IS SURFACE LIT TEST:\n";
	if (const bool kbResultant = IsSurfaceLit(kv3PointLight, kv3LightSourcePosition, kt3Surface) == true)
	{
		std::cout << "Test " << 1 << " Succeeded!" << " Expected Result: " << BoolToString(true) << std::endl;
		g_iSuccessCount++;
	}
	else
	{
		std::cout << "Test " << 1 << " Failed" << std::endl;
		std::cout << "Given Result: " << kbResultant << std::endl;
		std::cout << "Expected Result: " << BoolToString(true) << std::endl;
		g_iFailureCount++;
	}
	g_iNumTestsRun++;
	std::cout << std::endl;
}

void GeometryTest::TestRotateTriangleAroundPoint()
{
	constexpr TTriangle2 kTTriangleToRotateTest{ { 4, 2 }, { 1, 8 }, { 4, 3 } };
	constexpr float kfRotAngle = 6.8f;
	constexpr TVector2 kv2RotationPoint{ 0, 0 };
	TTriangle2 TRotatedTriangle{};
	constexpr TVector3 kv3ExpectedP1Vector = {4, 2, 0};
	constexpr TVector3 kv3ExpectedP2Vector = {1, 8, 0};
	constexpr TVector3 kv3ExpectedP3Vector = {4, 3, 0};
	std::cout << "ROTATE TRIANGLE AROUND POINT TEST:\n";
	RotateTriangleAroundPoint(kTTriangleToRotateTest, kfRotAngle, kv2RotationPoint, TRotatedTriangle);
	const TVector3 kv3RotatedTriangleP1 = {TRotatedTriangle.m_v2p1.m_fX, TRotatedTriangle.m_v2p1.m_fY, 0};
	const TVector3 kv3RotatedTriangleP2 = {TRotatedTriangle.m_v2p2.m_fX, TRotatedTriangle.m_v2p2.m_fY, 0};
	const TVector3 kv3RotatedTriangleP3 = {TRotatedTriangle.m_v2p3.m_fX, TRotatedTriangle.m_v2p3.m_fY, 0};
	if (Equals(kv3RotatedTriangleP1, kv3ExpectedP1Vector) && Equals(kv3RotatedTriangleP2, kv3ExpectedP2Vector) && Equals(kv3RotatedTriangleP3, kv3ExpectedP3Vector) == true)
	{
		std::cout << "Test " << 1 << " Succeeded!" << " Expected Result: " << kv3ExpectedP1Vector.m_fX << "," << kv3ExpectedP1Vector.m_fY << std::endl;
		std::cout << "\t\t\t\t   " << kv3ExpectedP2Vector.m_fX << "," << kv3ExpectedP2Vector.m_fY << std::endl;
		std::cout << "\t\t\t\t   " << kv3ExpectedP3Vector.m_fX << "," << kv3ExpectedP3Vector.m_fY << std::endl;
		g_iSuccessCount++;
	}
	else
	{
		std::cout << "Test " << 1 << " Failed" << std::endl;
		std::cout << "Given Result: " << TRotatedTriangle.m_v2p1.m_fX << "," << TRotatedTriangle.m_v2p1.m_fY << std::endl;
		std::cout << "\t      "<<TRotatedTriangle.m_v2p2.m_fX << "," << TRotatedTriangle.m_v2p2.m_fY << std::endl;
		std::cout << "\t      "<<TRotatedTriangle.m_v2p3.m_fX << "," << TRotatedTriangle.m_v2p3.m_fY << std::endl;
		std::cout << "Expected Result: " << kv3ExpectedP1Vector.m_fX << "," << kv3ExpectedP1Vector.m_fY << std::endl;
		std::cout << "\t\t "<<kv3ExpectedP1Vector.m_fX << "," << kv3ExpectedP1Vector.m_fY << std::endl;
		std::cout << "\t\t "<<kv3ExpectedP1Vector.m_fX << "," << kv3ExpectedP1Vector.m_fY << std::endl;
		g_iFailureCount++;
	}
	g_iNumTestsRun++;
	std::cout << std::endl;
}