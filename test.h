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
    static void TestComputeDistanceCircleToCircle();
    static void TestComputeDistanceCircleToTriangle();
    static void TestComputeLineSphereIntersection();
    static void TestIsLinePlaneIntersection();
    static void TestIsIntersection();
    static void TestComputeIntersectionBetweenLines();
    static void TestIsInFieldOfView();
    static void TestFindTriangleNormal();
    static void TestIsSurfaceLit();
    static void TestRotateTriangleAroundPoint();
};
