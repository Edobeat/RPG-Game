#include "Environment.h"
#include "Player.h"
#include "Mob.h"
#include "NPC.h"

Environment::Environment() 
{
}

Environment::Environment(vector<unique_ptr<Entity>> newvec)
{
	for (unsigned int i = 0; i < newvec.size(); i++)
	{
		entities.push_back(newvec[i]->clone());
	}
}

Environment::Environment(const Environment& other)
{
	*this = other;
}

Environment& Environment::operator=(const Environment& other)
{
	if (this != &other)
	{
		entities.clear();
		for (unsigned int i = 0; i < other.entities.size(); i++)
		{
			entities.push_back(other.entities[i]->clone());
		}
	}
	return *this;
}

Environment::~Environment()
{
	//entities.clear();
}

unsigned int Environment::getSize() const
{
	return entities.size();
}

void Environment::add(const Entity& newMember)
{
	entities.push_back(newMember.clone());
}

Entity& Environment::getAt(unsigned int index) const
{
	return *entities[index];
}

void Environment::removeAt(unsigned int index)
{
	entities.erase(entities.begin() + index);
}

void Environment::generateEntities()
{
	add(Player("TheLegend26", Point3D(15, 16, 17), 100, 150));
	add(Mob("Warewolf", Point3D(10, 1, 7), 40, 30));
	add(NPC("Mini Mentor", Point3D(5, 10, 3))); 
	add(Mob("Cow", Point2D(20, -30), 2, 150));
	add(Mob("Chicken", Point2D(-5, 6), 0, 50));
	add(Mob("Sheep", Point2D(2, -3), 1, 100));

	add(Player("Player2", Point2D(6, -6), 5, 100));
}

void Environment::destroyEnities()
{
	entities.clear();
}

Entity* Environment::getClosestAliveEntity(Player pl, Entity::Type t) const
{
	vector<unique_ptr<Entity>> tmp;
	for (size_t i = 0; i < entities.size(); i++)
	{
		if (entities[i]->getType() == t && entities[i]->isAlive()) {
			tmp.push_back(entities[i]->clone());
		}
	}
	for (size_t i = 0; i < tmp.size()-1; i++)
	{
		if (pl.getDistanceTo(*tmp[i]) > pl.getDistanceTo(*tmp[i + 1])) tmp[i].swap(tmp[i + 1]);
	}
	return tmp[0].get();
}
