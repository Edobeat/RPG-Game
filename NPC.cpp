#include "NPC.h"

NPC::NPC() : Entity(Entity::Type::NPC)
{
}

NPC::NPC(string name, const Point2D& location) :Entity(name, location, Type::NPC)
{
}

NPC::NPC(string name, const Point3D& location) :Entity(name, location, Type::NPC)
{
}

NPC::NPC(const NPC& other)
{
	*this = other;
}

NPC& NPC::operator=(const NPC& other)
{
	if (this != &other)
	{
		setID(generateID());
		setName(other.getName());
		setType(other.getType());
		const Point3D* otherloc = other.getLoc3D();
		if (otherloc) setLoc(*otherloc);
		else setLoc(*other.getLoc());
	}
	return *this;
}

NPC::~NPC()
{
}

bool NPC::isAlive() const
{
	return true;
}

unique_ptr<Entity> NPC::clone() const
{
	return make_unique<NPC>(*this);
}


