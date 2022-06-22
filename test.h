#pragma once

class GeometryTest
{
public:
    void RunAllTests();
private:
	void TestEquals() const;
	void TestAdd() const;
	void TestSubtract() const;
	void TestScaleVector() const;
	void TestMagnitude() const;
	void TestDotProduct() const;
	void TestCrossProduct() const;
	void TestNormalise() const;
	void TestProjection() const;
	void TestComputeAngleBetween2D() const;
	void TestComputeAngleBetween3D() const;
    static void TestComputeDistancePointToLine();
    static void TestComputeDistancePointToPlane();
    static void TestComputeDistancePointToSphere();
	void TestComputeDistanceCircleToCircle() const;
	void TestComputeDistanceCircleToTriangle() const;
	void TestComputeLineSphereIntersection() const;
	void TestIsLinePlaneIntersection() const;
	void TestIsIntersection() const;
	void TestComputeIntersectionBetweenLines() const;
	void TestIsInFieldOfView() const;
	void TestFindTriangleNormal() const;
	void TestIsSurfaceLit() const;
	void TestRotateTriangleAroundPoint() const;
};
