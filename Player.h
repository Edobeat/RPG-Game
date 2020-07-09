#pragma once
#include "Entity.h"

class Mob;

class Player : public Entity {
	int damage;
	int health;
public:
	Player(); 
	Player(string name, const Point2D& location, int dmg, int h);
	Player(string name, const Point3D& location, int dmg, int h);
	Player(const Player& other);
	Player& operator=(const Player& other);
	virtual ~Player();

	int getDamage() const;
	void setDamage(int newVal);
	int getHealth() const;
	void setHealth(int newVal);


	bool isAlive() const;
	void attack(Player& opp) const;
	void attack(Mob& opp) const;
	virtual unique_ptr <Entity> clone() const;
};