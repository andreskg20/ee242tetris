#pragma once

#include "MovingThing.h"
#include "Thing.h"

class Player : public MovingThing
{
public:
	Player();
	~Player();

	void handleCollision(const Thing* other);

	void move(double dt)

};
