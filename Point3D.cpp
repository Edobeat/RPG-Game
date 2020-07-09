#include "Point3D.h"
#include <cmath>

Point3D::Point3D() : Point2D(), z(0)
{
}

Point3D::Point3D(double xVal, double yVal, double zVal) : Point2D(xVal, yVal), z(zVal)
{
}

Point3D::Point3D(const Point3D& other)
{
	*this = other;
}

Point3D& Point3D::operator=(const Point3D& other)
{
	if (this != &other)
	{
		setX(other.getX());
		setY(other.getY());
		setZ(other.getZ());
	}
	return *this;
}

Point3D::~Point3D()
{
}

double Point3D::getZ() const
{
	return z;
}

void Point3D::setZ(double newVal)
{
	z = newVal;
}

double Point3D::getDistanceTo(const Point3D& other) const
{
	double xDiff = getX() - other.getX();
	double yDiff = getY() - other.getY();
	double zDiff = getZ() - other.getZ();

	return sqrt(pow(xDiff, 2) + pow(yDiff, 2) + pow(zDiff, 2));
}
