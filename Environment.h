#pragma once
#include <vector>
#include "Entity.h"
#include "Player.h"
#include "Mob.h"
#include "NPC.h"
using namespace std;

class Environment {
	vector<unique_ptr<Entity>> entities;
public:
	Environment();
	Environment(vector<unique_ptr<Entity>> newvec);
	Environment(const Environment& other);
	Environment& operator=(const Environment& other);
	~Environment();
	unsigned int getSize() const;
	void add(const Entity& newMember);
	Entity& getAt(unsigned int index) const;
	void removeAt(unsigned int index);
	void generateEntities();
	void destroyEnities();
	Entity* getClosestAliveEntity(Player pl, Entity::Type t) const;
};