#pragma once

#include <SFML/Graphics.hpp>

namespace util
{
	class ToggleKey
	{
	public:
		ToggleKey(sf::Keyboard::Key key, sf::Time delay = sf::seconds(0.2f));
		bool isKeyPressed();

	private:
		sf::Keyboard::Key key;
		sf::Clock delayTimer;
		sf::Time delay;
	};
}