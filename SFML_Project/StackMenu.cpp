#include "StackMenu.h"

#include "ResourceHolder.h"

namespace gui
{
	StackMenu::StackMenu(const std::wstring& title)
	{
		indent = 15;
		border = sf::Vector2f(25, 25);
		this->title.setString(title);
		update();
	}
	StackMenu::StackMenu(StackMenu&& other) :
		widgets(std::move(other.widgets)),
		background(std::move(other.background)),
		title(std::move(other.title)),
		indent(other.indent),
		border(other.border)
	{ }
	StackMenu& StackMenu::operator=(StackMenu&& other)
	{
		widgets = std::move(other.widgets);
		background = std::move(other.background);
		title = std::move(other.title);
		indent = other.indent;
		border = other.border;
		return *this;
	}

	void StackMenu::addWidget(Widget* widget)
	{
		widgets.push_back(std::unique_ptr<Widget>(widget));
		update();
	}
	void StackMenu::setPosition(const sf::Vector2f& position)
	{
		this->position = position;
		update();
	}
	void StackMenu::setBorder(const sf::Vector2f& border)
	{
		this->border = border;
		update();
	}
	void StackMenu::setIndent(float indent)
	{
		this->indent = indent;
		update();
	}
	void StackMenu::setTitle(const std::wstring& text)
	{
		title.setString(text);
		update();
	}
	void StackMenu::setTexture(const sf::Texture& texture)
	{
		background.setTexture(&texture);
	}

	void StackMenu::handleEvent(sf::Event event, const sf::RenderWindow& window)
	{
		for (int i = 0; i < widgets.size(); i++)
			widgets[i]->handleEvent(event, window);
	}
	void StackMenu::render(sf::RenderTarget& renderer)
	{
		renderer.draw(background);
		renderer.draw(title);
		for (int i = 0; i < widgets.size(); i++)
			widgets[i]->render(renderer);
	}

	void StackMenu::update()
	{
		background.setPosition(position);
		title.setPosition(0, position.y + border.y);
		float maxWidth = title.getRect().width;
		float x = position.x + border.x;
		float y = title.getPosition().y + title.getRect().height + indent;
		for (int i = 0; i < widgets.size(); i++)
		{
			if (maxWidth < widgets[i]->getSize().x)
				maxWidth = widgets[i]->getSize().x;
			widgets[i]->setPosition(sf::Vector2f(x, y));
			y += widgets[i]->getSize().y + indent;
		}
		float width = maxWidth + 2 * border.x;
		float height = y - indent - position.y + border.y;
		background.setSize(sf::Vector2f(width, height));
		title.alignX(background);
	}
}