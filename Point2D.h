#pragma once

class Point2D {
	double x;
	double y;
public:
	Point2D();
	Point2D(double xVal, double yVal);
	Point2D(const Point2D& other);
	Point2D& operator=(const Point2D& other);
	virtual ~Point2D();

	double getX() const;
	double getY() const;
	void setX(double newVal);
	void setY(double newVal);

	double getDistanceTo(const Point2D& other);
};