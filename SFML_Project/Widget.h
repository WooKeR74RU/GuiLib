#pragma once

#include <SFML/Graphics.hpp>

namespace gui
{
	class Widget
	{
	public:
		virtual void handleEvent(sf::Event event, const sf::RenderWindow& window) = 0;
		virtual void render(sf::RenderTarget& renderer) = 0;
		virtual void setPosition(const sf::Vector2f& pos) = 0;
		virtual sf::Vector2f getSize() const = 0;
	};
}