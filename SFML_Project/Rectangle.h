#pragma once

#include <SFML/Graphics.hpp>

namespace util
{
	class Rectangle : public sf::RectangleShape
	{
	public:
		Rectangle();
		bool isRolledOn(const sf::RenderWindow& window) const;
		bool isClicked(sf::Event, const sf::RenderWindow& window) const;
	};
}