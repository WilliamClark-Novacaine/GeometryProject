#pragma once

class GeometryTest
{
public:
    void RunAllTests();
private:
    void TestEquals();
    void TestAdd();
    void TestSubtract();
    void TestScaleVector();
    void TestMagnitude();
    void TestDotProduct();
    void TestCrossProduct();
    void TestNormalise();
    void TestProjection();
    void TestComputeAngleBetween();
    void TestComputeAngleBetween();
    void TestComputeDistancePointToLine();
    void TestComputeDistancePointToPlane();
    void TestComputeDistancePointToSphere();
    void TestComputeDistanceCircleToCircle();
    void TestComputeDistanceCircleToTriangle();
    void TestComputeLineSphereIntersection();
    void TestIsLinePlaneIntersection();
    void TestIsIntersection();
    void TestComputeIntersectionBetweenLines();
    void TestIsInFieldOfView();
    void TestFindTriangleNormal();
    void TestIsSurfaceLit();
    void TestRotateTriangleAroundPoint();
};
