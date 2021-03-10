#include <Game.hpp>

Game::Game()
{
	initialise();
}

Game::~Game()
{
}

void Game::run()
{
	while (window.isOpen())
	{
		handleEvents();
		update();
		render();
	}
}

void Game::initialise()
{
	videoMode = sf::VideoMode::getDesktopMode();
	window.create(videoMode, "SFML", sf::Style::Fullscreen);
	window.setVerticalSyncEnabled(true);
}

void Game::handleEvents()
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
		}
	}
}

void Game::update()
{
}

void Game::render()
{
	window.clear(sf::Color::Black);

	//Draw here.

	window.display();
}