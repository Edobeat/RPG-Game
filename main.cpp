#include <iostream>
#include <algorithm>
#include "Point2D.h"
#include "Point3D.h"
#include "Entity.h"
#include "Player.h"
#include "NPC.h"
#include "Mob.h"
#include "Environment.h"
using namespace std;

//ostream& operator<<(std::ostream& str, const point2d& point)
//{
//	str << "point3d(" << point.getx() << ", " << point.gety() <<", "<<point.getz()<< ')';
//	return str;
//}
int main()
{
	Player player_1("Alice", Point2D(0, 0), 20, 200);

	Environment env;
	env.generateEntities();

	struct Distance
	{
		double distance;
		Entity* entity;
		bool operator<(const Distance& other) const
		{
			return distance < other.distance;
		}
	};

	std::vector<Distance> distances;

	for (std::size_t i = 0; i < env.getSize(); ++i)
	{
		Entity& entity = env.getAt(i);
		if (entity.getType() != Entity::Type::Mob)
			continue;

		if (!entity.isAlive())
			continue;

		distances.push_back(
			Distance{ player_1.getDistanceTo(entity), &entity });
	}

	sort(distances.begin(), distances.end());

	for (Distance& d : distances)
		player_1.attack(static_cast<Mob&>(*d.entity));

	return 0;
}
