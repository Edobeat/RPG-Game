#pragma once
#include "Entity.h"


class NPC : public Entity {
private:
public:
	NPC();
	NPC(string name, const Point2D& location);
	NPC(string name, const Point3D& location);
	NPC(const NPC& other);
	NPC& operator=(const NPC& other);
	virtual ~NPC();

	bool isAlive() const;
	virtual unique_ptr <Entity> clone() const;
};