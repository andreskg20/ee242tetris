#include "Game.h"
#include "Vector2d.h"
#include "Keyboard.h"
#include "Color.h"

#include "TetrisGame.h"
#include "Wall.h"




// Create the game window
TetrisGame::TetrisGame() : Game("Tetris-ish", 640, 480), done(false)
{
	// create the walls
	topWall = new Wall(Vector2d(0, 0), Vector2d(639, 1), Vector2d(0, 1));
	bottomWall = new Wall(Vector2d(0, 478), Vector2d(639, 479), Vector2d(0, -1));
	leftWall = new Wall(Vector2d(0, 1), Vector2d(1, 478), Vector2d(-1, 0));
	rightWall = new Wall(Vector2d(638, 1), Vector2d(639, 478), Vector2d(1, 0));
}


TetrisGame::~TetrisGame()
{
	delete topWall;
	delete bottomWall;
	delete leftWall;
	delete rightWall;
}


// Per-frame update for game play
void TetrisGame::update(double dt)
{
	// is game over?
	if (!player->isAlive) {
		Key response;

		// post message to user and get response
		do {
			response = Game::createMessage("Play again (Y/N)?",
				Vector2d(175, 200), 40, Color::Yellow);
		} while ((response != Key::Y) && (response != Key::N));

		if (response == Key::Y) {
			//reset
		}

		else {
			// game is over
			done = true;
		}
	}
}

// Whether or not the game is over
bool TetrisGame::isOver() const
{
	return done;
}