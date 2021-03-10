#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	srand(time(NULL));

	int gameDifficulty;

	std::cout << "While in game press esc to return desktop!\n";
	std::cout << "Enter the game difficulty (1 to 15): ";

again:
	std::cin >> gameDifficulty;
	if (gameDifficulty <= 0 || gameDifficulty > 15)
	{
		std::cout << "Invalid game difficulty try again:";
		goto again;
	}

	sf::RenderWindow mainWindow(sf::VideoMode::getDesktopMode(), "SFML!", sf::Style::Fullscreen);
	mainWindow.setVerticalSyncEnabled(true);

	sf::RectangleShape background(sf::Vector2f((float)(mainWindow.getSize().x), (float)(mainWindow.getSize().y)));
	background.setFillColor(sf::Color(255, 128, 0));

	sf::RectangleShape player(sf::Vector2f((float)(mainWindow.getSize().x / 16), (float)(mainWindow.getSize().y) / 6));
	player.setFillColor(sf::Color::Black);
	player.setOrigin(sf::Vector2f(player.getSize().x / 2, player.getSize().y / 2));

	std::vector<sf::RectangleShape> asteroids;

	sf::Time timeElapsed, secondsToGenerate = sf::seconds(0.8);
	sf::Clock clock;
	sf::Clock totalTime;
	while (mainWindow.isOpen())
	{
		sf::Event e;
		while (mainWindow.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				mainWindow.close();
			}
			else if (e.type == sf::Event::KeyPressed)
			{
				if (e.key.code == sf::Keyboard::Escape)
				{
					mainWindow.close();
				}
			}
		}

		if (timeElapsed > secondsToGenerate)
		{
			for (size_t i = 0; i < gameDifficulty; i++)
			{
				sf::RectangleShape rectToPush(sf::Vector2f(50.f, 50.f));
				rectToPush.setFillColor(sf::Color::Blue);
				rectToPush.setPosition((float)(rand() % mainWindow.getSize().x), 0.f);
				asteroids.push_back(rectToPush);
			}
			timeElapsed = timeElapsed.Zero;
		}

		sf::Vector2i mousePosition = sf::Mouse::getPosition();
		player.setPosition(sf::Vector2f((float)(mousePosition.x), (float)(mousePosition.y)));

		mainWindow.clear(sf::Color::Black);

		mainWindow.draw(background);
		mainWindow.draw(player);

		for (size_t i = 0; i < asteroids.size(); i++)
		{
			mainWindow.draw(asteroids.at(i));
			asteroids.at(i).rotate((float)(rand() % gameDifficulty));
			asteroids.at(i).move(0.f, (float)(gameDifficulty * 1.25));
		}

		mainWindow.display();

		for (size_t i = 0; i < asteroids.size(); i++)
		{
			if (player.getGlobalBounds().intersects(asteroids.at(i).getGlobalBounds()))
				mainWindow.close();
		}

		for (size_t i = 0; i < asteroids.size(); i++)
		{
			if (!background.getGlobalBounds().intersects(asteroids.at(i).getGlobalBounds()))
				asteroids.erase(asteroids.begin() + i);
		}
		timeElapsed += clock.restart();
	}

	sf::Time score = totalTime.restart();
	std::cout << "Your score is: " << score.asSeconds() << " seconds in difficulty " << gameDifficulty << "." << std::endl;
	system("pause");
}