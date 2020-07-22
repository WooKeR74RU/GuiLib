#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "NonCopyable.h"
#include "Widget.h"
#include "Text.h"
#include "Rectangle.h"

namespace gui
{
	class StackMenu : public NonCopyable
	{
	public:
		StackMenu(const std::wstring& title);
		StackMenu(StackMenu&& other);
		StackMenu& operator=(StackMenu&& other);

		void addWidget(Widget* widget);
		void setPosition(const sf::Vector2f& position);
		void setBorder(const sf::Vector2f& border);
		void setIndent(float indent);
		void setTitle(const std::wstring& title);
		void setTexture(const sf::Texture& texture);

		void handleEvent(sf::Event event, const sf::RenderWindow& window);
		void render(sf::RenderTarget& renderer);

	private:
		void update();
		
		sf::Vector2f position;
		util::Rectangle background;
		util::Text title;
		std::vector<std::unique_ptr<Widget>> widgets;
		sf::Vector2f border;
		float indent;
	};
}