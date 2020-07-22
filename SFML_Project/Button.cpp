#include "Button.h"

#include <iostream>

namespace gui
{
	Button::Button(const std::wstring& text)
	{
		border = sf::Vector2f(10, 10);
		this->text.setString(text);
		update();
	}
	Button::Button(const sf::Vector2f& size)
	{
		border = sf::Vector2f(10, 10);
		this->size = size;
		update();
	}
	void Button::setFunction(const std::function<void()>& func)
	{
		this->func = func;
	}
	void Button::setText(const std::wstring& str)
	{
		text.setString(str);
		update();
	}
	void Button::setTexture(const sf::Texture& texture)
	{
		rect.setTexture(&texture);
	}
	void Button::setSize(const sf::Vector2f& size)
	{
		this->size = size;
		update();
	}
	void Button::setBorder(const sf::Vector2f& border)
	{
		this->border = border;
		update();
	}

	void Button::handleEvent(sf::Event event, const sf::RenderWindow& window)
	{
		if (rect.isClicked(event, window))
			func();
	}
	void Button::render(sf::RenderTarget& renderer)
	{
		renderer.draw(rect);
		renderer.draw(text);
	}
	void Button::setPosition(const sf::Vector2f& position)
	{
		this->position = position;
		update();
	}
	sf::Vector2f Button::getSize() const
	{
		return rect.getSize();
	}

	void Button::update()
	{
		rect.setPosition(position);
		float w = std::max(text.getRect().width + 2 * border.x, size.x);
		float h = std::max(text.getRect().height + 2 * border.y, size.y);
		rect.setSize(sf::Vector2f(w, h));
		text.align(rect);
	}
}