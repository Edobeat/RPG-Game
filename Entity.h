#pragma once
#include <string>
#include "Point2D.h"
#include "Point3D.h"
#include <memory>
using namespace std;


class Entity {
public:
	enum class Type {
		Entity,
		Player,
		NPC,
		Mob
	};
	static unsigned int generateID();
private:
	unsigned int id;
	string name;
	unique_ptr<Point2D> location;
	Type type;
public:
	Entity();
	Entity(Type type);
	Entity(string name, const Point2D& location, Type type);
	Entity(string name, const Point3D& location, Type type);
	Entity(string name, const Point2D& location);
	Entity(string name, const Point3D& location);
	Entity(const Entity& other);
	Entity& operator=(const Entity& other);
	virtual ~Entity() = 0; //pure virtual function

	unsigned int getID() const;
	void setID(unsigned int newVal);
	
	string getName() const;
	void setName(const string newVal);

	Point2D* getLoc() const;
	void setLoc(const Point2D& newLoc);
	Point3D* getLoc3D() const;
	void setLoc(const Point3D& newLoc);

	Type getType() const;
	void setType(Type nType);

	bool isAlive() const;
	
	double getDistanceTo2D(const Entity& obj) const; 
	double getDistanceTo(const Entity& obj) const;
	
	void moveTo(const Point2D& loc);
	void moveTo(const Point3D& loc);
	void moveTo(const Entity& obj);

	virtual unique_ptr <Entity> clone() const = 0;
};