#pragma once
#include "Point2D.h"

class Point3D : public Point2D {
	double z;
public:
	Point3D();
	Point3D(double xVal, double yVal, double zVal);
	Point3D(const Point3D& other);
	Point3D& operator=(const Point3D& other);
	virtual ~Point3D();

	double getZ() const;
	void setZ(double newVal);

	double getDistanceTo(const Point3D& other) const;
};