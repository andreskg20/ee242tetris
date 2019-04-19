#pragma once

#include "Game.h"
#include "Wall.h"


class TetrisGame : public Game
{
public:
	TetrisGame();
	~TetrisGame();

	void update(double dt);

	bool isOver() const;

private:
	Wall *topWall;
	Wall *bottomWall;
	Wall *leftWall;
	Wall *rightWall;

	Player *player;

	bool done;
	bool run;
};


