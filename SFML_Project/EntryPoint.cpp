#include <SFML/Graphics.hpp>
#include <iostream>

#include "FPSCounter.h"
#include "ToggleKey.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 900), "GUI Test", sf::Style::Close);
	window.setVerticalSyncEnabled(true);

	util::ToggleKey toggle(sf::Keyboard::Space);
	bool isUpdateActive = true;
	util::FPSCounter counter;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (toggle.isKeyPressed())
			isUpdateActive = !isUpdateActive;
		if (isUpdateActive)
			counter.update();

		window.clear();

		counter.draw(window);

		window.display();
	}

	return 0;
}