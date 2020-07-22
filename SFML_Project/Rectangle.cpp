#include "Rectangle.h"

#include "ResourceHolder.h"
#include "Colors.h"

namespace util
{
	Rectangle::Rectangle()
	{
		setOutlineThickness(1);
		setOutlineColor(colors::Black);
		setTexture(&ResourceHolder::get().textures.get("ice"));
		setFillColor(colors::Transparent75);
	}
	bool Rectangle::isRolledOn(const sf::RenderWindow& window) const
	{
		return getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)));
	}
	bool Rectangle::isClicked(sf::Event event, const sf::RenderWindow& window) const
	{
		return event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && isRolledOn(window);
	}
}