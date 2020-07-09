#include "Mob.h"
#include "Player.h"

Mob::Mob() :Entity(Type::Mob)
{
}

Mob::Mob(string name, const Point2D& location, int dmg, int h) : Entity(name,location,Type::Mob), damage(dmg), health(h)
{
}

Mob::Mob(string name, const Point3D& location, int dmg, int h) : Entity(name, location, Type::Mob), damage(dmg), health(h)
{
}

Mob::Mob(const Mob& other)
{
	*this = other;
}

Mob& Mob::operator=(const Mob& other)
{
	if (this != &other)
	{
		setID(generateID());
		setName(other.getName());
		setType(other.getType());
		const Point3D* otherloc = other.getLoc3D();
		if (otherloc) setLoc(*otherloc);
		else setLoc(*other.getLoc());
		setDamage(other.getDamage());
		setHealth(other.getHealth());
	}
	return *this;
}

Mob::~Mob()
{//
}

int Mob::getDamage() const
{
	return damage;
}

void Mob::setDamage(int newVal)
{
	damage = newVal;
}

int Mob::getHealth() const
{
	return health;
}

void Mob::setHealth(int newVal)
{
	health = newVal;
}

bool Mob::isAlive() const
{
	return health > 0 ? 1 : 0;
}

void Mob::attack(Player& opp)
{
	if (getDistanceTo(opp) < 5) opp.setHealth(opp.getHealth() - getDamage());
}

unique_ptr<Entity> Mob::clone() const
{
	return make_unique<Mob>(*this);
}
