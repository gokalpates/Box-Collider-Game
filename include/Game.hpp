#pragma once

#include <SFML.hpp>

//Game Class.
class Game
{
public:
	//Constructor and Destructor.
	Game();
	virtual ~Game();

	//Main game loop.
	void run();

private:
	//This function used in constructor and it intialises data members.
	void initialise();

	//These functions used in run function as utility functions.
	void handleEvents();
	void update();
	void render();

	//Basic data members to create a window and handle events.
	sf::RenderWindow window;
	sf::VideoMode videoMode;
	sf::Event event;

};