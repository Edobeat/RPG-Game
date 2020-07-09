#pragma once
#include "Entity.h"

class Player;
 
class Mob : public Entity
{
	int damage;
	int health; 
public:
	Mob();
	Mob(string name, const Point2D& location, int dmg, int h);
	Mob(string name, const Point3D& location, int dmg, int h);
	Mob(const Mob& other);
	Mob& operator=(const Mob& other);
	virtual ~Mob();

	int getDamage() const;
	void setDamage(int newVal);
	int getHealth() const;
	void setHealth(int newVal);

	bool isAlive() const;
	void attack(Player& opp);
	virtual unique_ptr <Entity> clone() const;
};
