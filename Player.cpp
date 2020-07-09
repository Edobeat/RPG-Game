#include "Player.h"
#include "Mob.h"
Player::Player() : Entity(Type::Player), damage(0), health(1)
{
}
Player::Player(string name, const Point2D& location, int dmg, int h) : Entity(name, location, Type::Player), damage(dmg), health(h)
{
}

Player::Player(string name, const Point3D& location, int dmg, int h) : Entity(name, location, Type::Player), damage(dmg), health(h)
{
}

Player::Player(const Player& other)
{
	*this = other;
}

Player& Player::operator=(const Player& other)
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

Player::~Player()
{//
}

int Player::getDamage() const
{
	return damage;
}

void Player::setDamage(int newVal)
{
	damage = newVal;
}

int Player::getHealth() const
{
	return health;
}

void Player::setHealth(int newVal)
{
	health = newVal;
}

bool Player::isAlive() const
{
	return health>0 ? 1 : 0;
}

void Player::attack(Player& opp) const
{
	if (getDistanceTo(opp) < 5) opp.setHealth(opp.getHealth() - getDamage());
}

void Player::attack(Mob& opp) const
{
	if (getDistanceTo(opp) < 5) opp.setHealth(opp.getHealth() - getDamage());
}

unique_ptr<Entity> Player::clone() const
{
	return make_unique<Player>(*this);
}
