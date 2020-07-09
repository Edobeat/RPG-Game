#include "Point2D.h"
#include <cmath>

Point2D::Point2D() : x(0), y(0)
{
}

Point2D::Point2D(double xVal, double yVal) : x(xVal), y(yVal)
{
}

Point2D::Point2D(const Point2D& other)
{

}

Point2D& Point2D::operator=(const Point2D& other)
{
	if(this!=&other)
	{
		setX(other.getX());
		setY(other.getY());
	}
	return *this;
}

Point2D::~Point2D()
{
}

double Point2D::getX() const
{
	return x;
}

double Point2D::getY() const
{
	return y;
}

void Point2D::setX(double newVal)
{
	x = newVal;
}

void Point2D::setY(double newVal)
{
	y = newVal;
}

double Point2D::getDistanceTo(const Point2D& other)
{
	double xDiff = getX() - other.getX();
	double yDiff = getY() - other.getY();
	return sqrt(pow(xDiff, 2) + pow(yDiff, 2));
}

