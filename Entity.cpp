#include "Entity.h"

using namespace std;

unsigned int Entity::generateID()
{
	static unsigned int n = 0;
	return n++;
}

Entity::Entity()
{
	id=generateID();
	name = "";
	location = make_unique<Point2D>();
	type = Type::Entity;
}

Entity::Entity(Type type) : Entity()
{
	this->type = type;
}

Entity::Entity(string name, const Point2D& location, Type type)
{
	id = generateID();
	this->name = name;
	this->type = type;
	this->location = make_unique<Point2D>(location);
}

Entity::Entity(string name, const Point3D& location, Type type)
{
	id = generateID();
	this->name = name;
	this->type = type;
	this->location = make_unique<Point3D>(location);
}

Entity::Entity(string name, const Point2D& location)
{
	id = generateID();
	this->name = name;
	this->location = make_unique<Point2D>(location);
}

Entity::Entity(string name, const Point3D& location)
{
	id = generateID();
	this->name = name;
	this->location = make_unique<Point3D>(location);
}

Entity::Entity(const Entity& other)
{
	*this = other;
}

Entity& Entity::operator=(const Entity& other)
{
	if (this != &other)
	{
		setID(generateID());
		setName(other.getName());
		setType(other.getType());
		const Point3D* otherLoc = other.getLoc3D();
		if (otherLoc) location = make_unique<Point3D>(*otherLoc);
		else location = make_unique<Point2D>(*other.getLoc());
	}
	return *this;
}

Entity::~Entity()
{
}

unsigned int Entity::getID() const
{
	return id;
}

void Entity::setID(unsigned int newVal)
{
	id = newVal;
}

string Entity::getName() const
{
	return name;
}

void Entity::setName(const string newVal)
{
	name = newVal;
}

Point2D* Entity::getLoc() const
{
	return location.get();
}

void Entity::setLoc(const Point2D& newLoc)
{
	location = make_unique	<Point2D>(newLoc);
}

Point3D* Entity::getLoc3D() const
{
	return dynamic_cast<Point3D*>(location.get());
}

void Entity::setLoc(const Point3D& newLoc)
{
	location = make_unique<Point3D>(newLoc);
}

Entity::Type Entity::getType() const
{
	return type;
}

void Entity::setType(Type nType)
{
	type = nType;
}

bool Entity::isAlive() const
{
	return true;
}

double Entity::getDistanceTo2D(const Entity& obj) const
{
	return location->getDistanceTo(*obj.getLoc());
}

double Entity::getDistanceTo(const Entity& obj) const
{
	const Point3D* thisLoc = getLoc3D();
	const Point3D* objLoc = obj.getLoc3D();
	if (thisLoc && objLoc) return thisLoc->getDistanceTo(*objLoc);
	else return getDistanceTo2D(obj);
}

void Entity::moveTo(const Point2D& loc)
{
	location=make_unique<Point2D>(loc);
}

void Entity::moveTo(const Point3D& loc)
{
	location = make_unique<Point3D>(loc);
}

void Entity::moveTo(const Entity& obj)
{
	const Point3D* thisLoc = getLoc3D();
	const Point3D* objLoc = obj.getLoc3D();
	if (thisLoc && objLoc) location = make_unique<Point3D>(*obj.getLoc3D());
	else location=make_unique<Point2D>(*obj.getLoc());
}
