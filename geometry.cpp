#include "geometry.h"
#include <cmath>
#include <algorithm>

/***********************************************
* Equals: Compares 2 Vectors are both equal
* @author: William Clark
* @parameter: _krA Vector A
*			  _krB Vector B
* @return: True if both vector A & B are equal else False
************************************************/
bool Equals(const TVector3& _krA, const TVector3& _krB)
{
	return _krA.m_fX == _krB.m_fX && _krA.m_fY == _krB.m_fY && _krA.m_fZ == _krB.m_fZ;
}

/***********************************************
* Add: Adds Vector B to Vector A
* @author: William Clark
* @parameter: _krA Vector A
*			  _krB Vector B
* @return: Vector _rResultant  A + B
************************************************/
TVector3& Add(const TVector3& _krA, const TVector3& _krB, TVector3& _rResultant)
{
	_rResultant.m_fX = _krA.m_fX + _krB.m_fX;
	_rResultant.m_fY = _krA.m_fY + _krB.m_fY;
	_rResultant.m_fZ = _krA.m_fZ + _krB.m_fZ;
	return _rResultant;
}

/***********************************************
* Subtract: Subrtracts Vector B to Vector A
* @author: William Clark
* @parameter: _krA Vector A
*			  _krB Vector B
* @return: Vector _rResultant  A - B
************************************************/
TVector3& Subtract(const TVector3& _krA, const TVector3& _krB, TVector3& _rResultant)
{
	_rResultant.m_fX = _krA.m_fX - _krB.m_fX;
	_rResultant.m_fY = _krA.m_fY - _krB.m_fY;
	_rResultant.m_fZ = _krA.m_fZ - _krB.m_fZ;
	return _rResultant;
}

/***********************************************
* Scale: Scales Vector A by a value
* @author: William Clark
* @parameter: _krA Vector A
*			  _kfScalar Vector Multiplier
* @return: Vector _rResultant  A * Scalar
************************************************/
TVector3& ScaleVector(const TVector3& _krA, const float _kfScalar, TVector3& _rResultant)
{
	_rResultant.m_fX = _krA.m_fX * _kfScalar;
	_rResultant.m_fY = _krA.m_fY * _kfScalar;
	_rResultant.m_fZ = _krA.m_fZ * _kfScalar;
	return _rResultant;
}


/***********************************************
* Magnitude: Gets length of a Vector
* @author: William Clark
* @parameter: _krA Vector A
* @return: Length of Vector A
************************************************/
float Magnitude(const TVector3& _krA)
{
	return sqrtf(powf(_krA.m_fX, 2) + powf(_krA.m_fY, 2) + powf(_krA.m_fZ, 2));
}

/***********************************************
* DotProduct: finds Dot Product of 2 Vectors
* @author: William Clark
* @parameter: _krA Vector A
*			  _kfB Vector B
* @return: Dot Product of A * B
************************************************/
float DotProduct(const TVector3& _krA, const TVector3& _krB)
{
	return ((_krA.m_fX * _krB.m_fX) + (_krA.m_fY * _krB.m_fY) + (_krA.m_fZ * _krB.m_fZ));
}

/***********************************************
* CrossProduct: finds Cross Product of 2 Vectors
* @author: William Clark
* @parameter: _krA Vector A
*			  _kfB Vector B
* @return: _rResultant Cross Product A x B
************************************************/
TVector3& CrossProduct(const TVector3& _krA, const TVector3& _krB, TVector3& _rResultant)
{
	_rResultant.m_fX = (_krA.m_fY * _krB.m_fZ) - (_krA.m_fZ * _krB.m_fY);
	_rResultant.m_fY = (_krA.m_fZ * _krB.m_fX) - (_krA.m_fX * _krB.m_fZ);
	_rResultant.m_fZ = (_krA.m_fX * _krB.m_fY) - (_krA.m_fY * _krB.m_fX);
	return _rResultant;
}

/***********************************************
* Normalize: Normalize Vector to Length of 1
* @author: William Clark
* @parameter: _krA Vector A
* @return: _rResultant Normalized Vector A
************************************************/
TVector3& Normalise(const TVector3& _krA, TVector3& _rResultant)
{
	const float fMag = Magnitude(_krA);
	_rResultant.m_fX = _krA.m_fX / fMag;
	_rResultant.m_fY = _krA.m_fY / fMag;
	_rResultant.m_fZ = _krA.m_fZ / fMag;
	return _rResultant;
}

/***********************************************
* Projection: Vector projection of one vector over another
* @author: William Clark
* @parameter: _krA Vector A
*			  -krB Vector B
* @return: _rResultant Projected Vector
************************************************/
TVector3& Projection(const TVector3& _krA, const TVector3& _krB, TVector3& _rResultant)
{
	const float fProjMultiPr = (DotProduct(_krA, _krB)) / (powf(Magnitude(_krB), 2));
	_rResultant.m_fX = fProjMultiPr * _krB.m_fX;
	_rResultant.m_fY = fProjMultiPr * _krB.m_fY;
	_rResultant.m_fZ = fProjMultiPr * _krB.m_fZ;
	return _rResultant;
}

/***********************************************
* ComputeAngleBetween2D: Calculate Angle between 2 2D vectors
* @author: William Clark
* @parameter: _krA Vector A
*			  _krB Vector B
* @return: Angle between 2D vector A & B (in Radians)
************************************************/
float ComputeAngleBetween(const TVector2& _krA, const TVector2& _krB)
{
	const float fADotB = _krA.m_fX * _krB.m_fX + _krA.m_fY * _krB.m_fY;
	const float fMagA = sqrt(powf(_krA.m_fX, 2) + powf(_krA.m_fY, 2));
	const float fMagB = sqrt(powf(_krB.m_fX, 2) + powf(_krB.m_fY, 2));
	return acos(fADotB / (fMagA * fMagB));
}

/***********************************************
* ComputeAngleBetween2D: Calculate Angle between 2 3D vectors
* @author: William Clark
* @parameter: _krA Vector A
*			  _krB Vector B
* @return: Angle between 3D vector A & B (in Radians)
************************************************/
float ComputeAngleBetween(const TVector3& _krA, const TVector3& _krB)
{
	const float fADotB = DotProduct(_krA, _krB);
	const float fMagA = Magnitude(_krA);
	const float fMagB = Magnitude(_krB);
	return acos(fADotB / (fMagA * fMagB));
}

/***********************************************
* ComputeDistancePointToLine: Calculate distance from a given 3D point to a given 3D line
* @author: William Clark
* @parameter: _krLine 3D Line
*			  _krPoint Point in 3D Space
* @return: Distance from point in space to a 3D Line 
************************************************/
float ComputeDistancePointToLine(const T3DLine& _krLine, const TVector3& _krPoint)
{
	TVector3 resultant{};
	const TVector3 pointToLine = {
		(_krPoint.m_fX - _krLine.m_v3q.m_fX), (_krPoint.m_fY - _krLine.m_v3q.m_fY), (_krPoint.m_fZ - _krLine.m_v3q.m_fZ)
	};
	return Magnitude(CrossProduct(pointToLine, _krLine.m_v3v, resultant)) / Magnitude(_krLine.m_v3v);
}

/***********************************************
* ComputeDistancePointToPlane: Calculate distance from a given 3D point to a given 3D Plane
* @author: William Clark
* @parameter: _krPlane 3D Plane
*			  _krPoint Point in 3D Space
* @return: Distance from point in space to a 3D Plane
************************************************/
float ComputeDistancePointToPlane(const TPlane& _krPlane, const TVector3& _krPoint)
{
	const T3DLine line{_krPoint, _krPlane.m_v3normal};
	TVector3 v3IntersectionPoint{};
	IsLinePlaneIntersection(line, _krPlane, v3IntersectionPoint);
	TVector3 v3DifVector{};
	Subtract(v3IntersectionPoint, _krPoint, v3DifVector);
	return Magnitude(v3DifVector);
}

/***********************************************
* ComputeDistancePointToSphere: Calculate distance from a given 3D point to center sphere 
* @author: William Clark
* @parameter: _krSphere 3D Sphere
*			  _krPoint Point in 3D Space
* @return: Distance from point in space to a center of sphere
************************************************/
float ComputeDistancePointToSphere(const TSphere& _krSphere, const TVector3& _krPoint)
{
	return sqrt((_krSphere.m_v3center.m_fX - _krPoint.m_fX) * (_krSphere.m_v3center.m_fX - _krPoint.m_fX) +
		(_krSphere.m_v3center.m_fY - _krPoint.m_fY) * (_krSphere.m_v3center.m_fY - _krPoint.m_fY) +
		(_krSphere.m_v3center.m_fZ - _krPoint.m_fZ) * (_krSphere.m_v3center.m_fZ - _krPoint.m_fZ));
}

/***********************************************
* ComputeDistanceCircleToCircle: Calculate distance from the center of a circle to the center of another circle
* @author: William Clark
* @parameter: _krCircle1 Circle 1
*			  _krCircle2 Circle 2
* @return: Distance from the center of Circle1 to the center of Circle2
************************************************/
float ComputeDistanceCircleToCircle(const TCircle& _krCircle1, const TCircle& _krCircle2)
{
	return sqrtf(powf((_krCircle1.m_v2center.m_fX - _krCircle2.m_v2center.m_fX), 2) + powf((_krCircle1.m_v2center.m_fY - _krCircle2.m_v2center.m_fY), 2));
}

/***********************************************
* ComputeDistanceCircleToTriangle: Calculate distance from the center of a circle to the center of a triangle
* @author: William Clark
* @parameter: _krCircle	Circle
*			  _krTriangle Triangle
* @return: Distance from the center of Circle to the center of Triangle
************************************************/
float ComputeDistanceCircleToTriangle(const TCircle& _krCircle, const TTriangle2& _krTriangle)
{
	const float fTriCentreX = (_krTriangle.m_v2p1.m_fX + _krTriangle.m_v2p2.m_fX + _krTriangle.m_v2p3.m_fX) / 3;
	const float fTriCentreY = (_krTriangle.m_v2p1.m_fY + _krTriangle.m_v2p2.m_fY + _krTriangle.m_v2p3.m_fY) / 3;
	const float fVDiffX = fTriCentreX - _krCircle.m_v2center.m_fX;
	const float fVDiffY = fTriCentreY - _krCircle.m_v2center.m_fY;
	return sqrtf(powf(fVDiffX, 2) + powf(fVDiffY, 2));
}

/***********************************************
* ComputeLineSphereIntersection: Calculate number of intersection points of a through a sphere & the intersection points
* @author: William Clark
* @parameter: _krLine
*			  _krSphere
*			  _rv3IntersectionPoint1 Default is Empty as this is calculated
*			  _rv3IntersectionPoint2 Default is Empty as this is calculated
* @return: Enumeration of the calculated number of intersections & points Line intersects
************************************************/
EIntersections ComputeLineSphereIntersection(const T3DLine& _krLine, const TSphere& _krSphere, TVector3& _rv3IntersectionPoint1, TVector3& _rv3IntersectionPoint2)
{
	TVector3 Normalized = Normalise(_krLine.m_v3v, Normalized);

	// A = u * u = ||u||^2
	const float fA =
		_krLine.m_v3v.m_fX * _krLine.m_v3v.m_fX +
		_krLine.m_v3v.m_fY * _krLine.m_v3v.m_fY +
		_krLine.m_v3v.m_fZ * _krLine.m_v3v.m_fZ;

	// B = 2[u * (o - C)]
	const float fB =
		(2 * _krLine.m_v3v.m_fX * _krLine.m_v3q.m_fX) - (2 * _krLine.m_v3v.m_fX * _krSphere.m_v3center.m_fX) +
		(2 * _krLine.m_v3v.m_fY * _krLine.m_v3q.m_fY) - (2 * _krLine.m_v3v.m_fY * _krSphere.m_v3center.m_fY) +
		(2 * _krLine.m_v3v.m_fZ * _krLine.m_v3q.m_fZ) - (2 * _krLine.m_v3v.m_fZ * _krSphere.m_v3center.m_fZ);

	//c = (o - c)^2 - r^2 = ||o - c||^2 - r^2
	const float fC =
		(_krLine.m_v3q.m_fX * _krLine.m_v3q.m_fX) + (_krSphere.m_v3center.m_fX * _krSphere.m_v3center.m_fX) - (2 * _krLine.m_v3q.m_fX * _krSphere.m_v3center.m_fX) +
		(_krLine.m_v3q.m_fY * _krLine.m_v3q.m_fY) + (_krSphere.m_v3center.m_fY * _krSphere.m_v3center.m_fY) - (2 * _krLine.m_v3q.m_fY * _krSphere.m_v3center.m_fY) +
		(_krLine.m_v3q.m_fZ * _krLine.m_v3q.m_fZ) + (_krSphere.m_v3center.m_fZ * _krSphere.m_v3center.m_fZ) - (2 * _krLine.m_v3q.m_fZ * _krSphere.m_v3center.m_fZ) -
		(_krSphere.m_fRadius * _krSphere.m_fRadius);

	// If the discriminant is negative
	if ((fB * fB) - (4 * fA * fC) < 0)
	{
		return INTERSECTION_NONE;
	}

	float fT1;
	// If there is one intersection (discriminant is 0)
	if (fB * fB - 4 * fA * fC == 0)
	{
		fT1 = -fB / (2 * fA);

		_rv3IntersectionPoint1.m_fX = (_krLine.m_v3v.m_fX * fT1) + _krLine.m_v3q.m_fX;
		_rv3IntersectionPoint1.m_fY = (_krLine.m_v3v.m_fY * fT1) + _krLine.m_v3q.m_fY;
		_rv3IntersectionPoint1.m_fZ = (_krLine.m_v3v.m_fZ * fT1) + _krLine.m_v3q.m_fZ;

		_rv3IntersectionPoint1 = _rv3IntersectionPoint2;

		return INTERSECTION_ONE;
	}

	fT1 = (-fB / (2 * fA)) + sqrt((fB * fB) - ((4 * fA * fC))) / (2 * fA);
	const float fT2 = (-fB / (2 * fA)) - sqrt((fB * fB) - ((4 * fA * fC))) / (2 * fA);

	_rv3IntersectionPoint1.m_fX = (_krLine.m_v3v.m_fX * fT1) + _krLine.m_v3q.m_fX;
	_rv3IntersectionPoint1.m_fY = (_krLine.m_v3v.m_fY * fT1) + _krLine.m_v3q.m_fY;
	_rv3IntersectionPoint1.m_fZ = (_krLine.m_v3v.m_fZ * fT1) + _krLine.m_v3q.m_fZ;

	_rv3IntersectionPoint2.m_fX = (_krLine.m_v3v.m_fX * fT2) + _krLine.m_v3q.m_fX;
	_rv3IntersectionPoint2.m_fY = (_krLine.m_v3v.m_fY * fT2) + _krLine.m_v3q.m_fY;
	_rv3IntersectionPoint2.m_fZ = (_krLine.m_v3v.m_fZ * fT2) + _krLine.m_v3q.m_fZ;

	return INTERSECTION_TWO;
}

/***********************************************
* IsLinePlaneIntersection: Calculate if line is intersecting through a 3D plane
* @author: William Clark
* @parameter: _krLine
*			  _krPlane
*			  _rv3IntersectionPoint Default is Empty as this is calculated
* @return: If Line intersected Plane, & Point it intersects
************************************************/
bool IsLinePlaneIntersection(const T3DLine& _krLine, const TPlane& _krPlane, TVector3& _rv3IntersectionPoint)
{
	const float fDenominator = DotProduct(_krPlane.m_v3normal, _krLine.m_v3v);
	if (fDenominator == 0)
	{
		return false;
	}
	const float _fD = -DotProduct(_krPlane.m_v3normal, _krPlane.m_v3point);
	const float _fT = -(DotProduct(_krPlane.m_v3normal, _krLine.m_v3q) + _fD) / fDenominator;
	_rv3IntersectionPoint.m_fX = _krLine.m_v3q.m_fX + _fT * _krLine.m_v3v.m_fX;
	_rv3IntersectionPoint.m_fY = _krLine.m_v3q.m_fY + _fT * _krLine.m_v3v.m_fY;
	_rv3IntersectionPoint.m_fZ = _krLine.m_v3q.m_fZ + _fT * _krLine.m_v3v.m_fZ;
	return true;
}

/***********************************************
* IsIntersection: Calculate if given line is intersecting through another given line
* @author: William Clark
* @parameter: _krLine1	Line1
*			  _krLine2	Line2
* @return: If Line1 intersected Line2
************************************************/
bool IsIntersection(const T3DLine& _krLine1, const T3DLine& _krLine2)
{
	// Can we calculate an intersection
	TVector3 v3L2VCrossL1V{};
	CrossProduct(_krLine2.m_v3v, _krLine1.m_v3v, v3L2VCrossL1V);
	if (Equals(v3L2VCrossL1V, {0, 0, 0}))
	{
		return false;
	}

	// Do the intersections match for both line equations
	TVector3 v3Intersection1{};
	TVector3 v3Intersection2{};
	ComputeIntersectionBetweenLines(_krLine1, _krLine2, v3Intersection1);
	ComputeIntersectionBetweenLines(_krLine2, _krLine1, v3Intersection2);

	return Equals(v3Intersection1, v3Intersection2);
}

/***********************************************
* ComputeIntersectionBetweenLines: Calculate intersection point of two lines
* @author: William Clark
* @parameter: _krLine1	Line1
*			  _krLine2	Line2
*			  _rIntersectionPoint - Default is empty as this is calculated
* @return: Calculated intersection point of Line1 & Line2
************************************************/
TVector3& ComputeIntersectionBetweenLines(const T3DLine& _krLine1, const T3DLine& _krLine2, TVector3& _rIntersectionPoint)
{
	TVector3 v3L1QCrossL2V{};
	TVector3 v3L2VCrossL2Q{};
	TVector3 v3L2VCrossL1V{};
	CrossProduct(_krLine1.m_v3q, _krLine2.m_v3v, v3L1QCrossL2V);
	CrossProduct(_krLine2.m_v3v, _krLine2.m_v3q, v3L2VCrossL2Q);
	CrossProduct(_krLine2.m_v3v, _krLine1.m_v3v, v3L2VCrossL1V);

	// Work out 't' using formula with non-zero denominator
	float fT;
	if (v3L2VCrossL1V.m_fX != 0)
	{
		fT = (v3L1QCrossL2V.m_fX + v3L2VCrossL2Q.m_fX) / v3L2VCrossL1V.m_fX;
	}
	else if (v3L2VCrossL1V.m_fY != 0)
	{
		fT = (v3L1QCrossL2V.m_fY + v3L2VCrossL2Q.m_fY) / v3L2VCrossL1V.m_fY;
	}
	else if (v3L2VCrossL1V.m_fZ != 0)
	{
		fT = (v3L1QCrossL2V.m_fZ + v3L2VCrossL2Q.m_fZ) / v3L2VCrossL1V.m_fZ;
	}
	else
	{
		return _rIntersectionPoint;
	}

	_rIntersectionPoint.m_fX = _krLine1.m_v3q.m_fX + fT * _krLine1.m_v3v.m_fX;
	_rIntersectionPoint.m_fY = _krLine1.m_v3q.m_fY + fT * _krLine1.m_v3v.m_fY;
	_rIntersectionPoint.m_fZ = _krLine1.m_v3q.m_fZ + fT * _krLine1.m_v3v.m_fZ;

	return _rIntersectionPoint;
}

/***********************************************
* IsInFieldOfView: Checks if an object is within view of camera
* @author: William Clark
* @parameter: _krCameraPosition		Where camera is positioned in the 2D world
*			  _krCameraDirection	Direction Camera is facing
*			  _kfFieldOfViewInRadians	Angle in radian the camera can see
*			  _krObjectPosition		Object position in a 2D world
* @return: If Object is in view of camera
************************************************/
bool IsInFieldOfView(const TVector2& _krCameraPosition, const TVector2& _krCameraDirection, const float _kfFieldOfViewInRadians, const TVector2& _krObjectPosition)
{
	const float fObjectThetaInRadians = atan2((_krObjectPosition.m_fY - _krCameraPosition.m_fY),
	                                          (_krObjectPosition.m_fX - _krCameraPosition.m_fX));
	const float fCameraDirectionInRadians = atan2(_krCameraDirection.m_fY, _krCameraDirection.m_fX);

	if (fObjectThetaInRadians >= (fCameraDirectionInRadians + _kfFieldOfViewInRadians / 2))
	{
		return false;
	}
	else if (fObjectThetaInRadians <= fCameraDirectionInRadians - (_kfFieldOfViewInRadians / 2))
	{
		return false;
	}

	return true;
}

/***********************************************
* FindTriangleNormal: Calculates normal vector of a 3D triangle
* @author: William Clark
* @parameter: _krTriangle - Triangle
*			  _rNormal - Normalized Triangle Vector
* @return: Normalized Vector of given Triangle
************************************************/
TVector3& FindTriangleNormal(const TTriangle3& _krTriangle, TVector3& _rNormal)
{
	// Get surface normal vector with Counter Clockwise Winding
	TVector3 v3TriSide1{};
	TVector3 v3TriSide2{};
	Subtract(_krTriangle.m_v3p2, _krTriangle.m_v3p1, v3TriSide1);
	Subtract(_krTriangle.m_v3p3, _krTriangle.m_v3p1, v3TriSide2);
	return CrossProduct(v3TriSide1, v3TriSide2, _rNormal);
}

/***********************************************
* IsSurfaceLit: Calculates if a point on a surface is lit by a light source
* @author: William Clark
* @parameter: _krPointOnSurface - Point on Surface
*			  _krLightSourcePosition - Position of light source
*			  _krSurface - Surface
* @return: If Point on a given surface is lit by a light source
************************************************/
bool IsSurfaceLit(const TVector3& _krPointOnSurface, const TVector3& _krLightSourcePosition, const TTriangle3& _krSurface)
{
	// Get vector to light source
	TVector3 v3VecToLight{};
	Subtract(_krLightSourcePosition, _krPointOnSurface, v3VecToLight);

	// Get surface normal vector (Counter Clockwise Winding)
	TVector3 v3SurNormal{};
	FindTriangleNormal(_krSurface, v3SurNormal);

	return DotProduct(v3VecToLight, v3SurNormal) > 0;
}

/***********************************************
* RotateTriangleAroundPoint: Rotates a 2D Triangle around a 2D rotation point
* @author: William Clark
* @parameter: _krTriangle - Triangle to rotate
*			  _kfRotAngleInRadians - Angle in radians to rotate triangle
*			  _krRotAroundPoint - point to rotate triangle around
*			  _rRotatedTriangle - resultant of the rotated triangle
* @return: Triangle rotated by an angle, around a point
************************************************/
TTriangle2& RotateTriangleAroundPoint(const TTriangle2& _krTriangle, const float _kfRotAngleInRadians, const TVector2& _krRotAroundPoint, TTriangle2& _rRotatedTriangle)
{
	// Convert TVector2 to TVector3 by zeroing the Z axis
	auto kTriangleV3Point1 = TVector3{_krTriangle.m_v2p1.m_fX, _krTriangle.m_v2p1.m_fY, 0};
	auto kTriangleV3Point2 = TVector3{_krTriangle.m_v2p2.m_fX, _krTriangle.m_v2p2.m_fY, 0};
	auto kTriangleV3Point3 = TVector3{_krTriangle.m_v2p3.m_fX, _krTriangle.m_v2p3.m_fY, 0};

	//Resultant ZValue zeroed
	auto RotatedTriangleV3Point1 = TVector3{_rRotatedTriangle.m_v2p1.m_fX, _rRotatedTriangle.m_v2p1.m_fY, 0};
	auto RotatedTriangleV3Point2 = TVector3{_rRotatedTriangle.m_v2p2.m_fX, _rRotatedTriangle.m_v2p2.m_fY, 0};
	auto RotatedTriangleV3Point3 = TVector3{_rRotatedTriangle.m_v2p3.m_fX, _rRotatedTriangle.m_v2p3.m_fY, 0};

	// Rotation Point ZValue zeroed
	const auto kV3RotAroundPoint = TVector3{_krRotAroundPoint.m_fX, _krRotAroundPoint.m_fY, 0};

	// Translate triangle so that the rotation point is at origin
	Subtract(kTriangleV3Point1, kV3RotAroundPoint, RotatedTriangleV3Point1);
	Subtract(kTriangleV3Point2, kV3RotAroundPoint, RotatedTriangleV3Point2);
	Subtract(kTriangleV3Point3, kV3RotAroundPoint, RotatedTriangleV3Point3);

	// Rotate coordinate system
	constexpr TVector2 v2I{1, 0};
	constexpr TVector2 v2J{0, 1};
	const TVector2 v2IPrime{v2I.m_fX * cos(_kfRotAngleInRadians), v2I.m_fX * sin(_kfRotAngleInRadians)};
	const TVector2 v2JPrime{-v2J.m_fY * sin(_kfRotAngleInRadians), v2J.m_fY * cos(_kfRotAngleInRadians)};

	// Place triangle points in new coordinate system
	_rRotatedTriangle.m_v2p1.m_fX = _rRotatedTriangle.m_v2p1.m_fX * v2IPrime.m_fX + _rRotatedTriangle.m_v2p1.m_fY * v2JPrime.m_fX;
	_rRotatedTriangle.m_v2p1.m_fY = _rRotatedTriangle.m_v2p1.m_fX * v2IPrime.m_fY + _rRotatedTriangle.m_v2p1.m_fY * v2JPrime.m_fY;
	_rRotatedTriangle.m_v2p2.m_fX = _rRotatedTriangle.m_v2p2.m_fX * v2IPrime.m_fX + _rRotatedTriangle.m_v2p2.m_fY * v2JPrime.m_fX;
	_rRotatedTriangle.m_v2p2.m_fY = _rRotatedTriangle.m_v2p2.m_fX * v2IPrime.m_fY + _rRotatedTriangle.m_v2p2.m_fY * v2JPrime.m_fY;
	_rRotatedTriangle.m_v2p3.m_fX = _rRotatedTriangle.m_v2p3.m_fX * v2IPrime.m_fX + _rRotatedTriangle.m_v2p3.m_fY * v2JPrime.m_fX;
	_rRotatedTriangle.m_v2p3.m_fY = _rRotatedTriangle.m_v2p3.m_fX * v2IPrime.m_fY + _rRotatedTriangle.m_v2p3.m_fY * v2JPrime.m_fY;

	// Translate triangle such that the rotation point is restored to its original position
	Add(RotatedTriangleV3Point1, kV3RotAroundPoint, kTriangleV3Point1);
	Add(RotatedTriangleV3Point2, kV3RotAroundPoint, kTriangleV3Point2);
	Add(RotatedTriangleV3Point3, kV3RotAroundPoint, kTriangleV3Point3);

	return _rRotatedTriangle;
}
