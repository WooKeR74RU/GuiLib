#pragma once

#include <functional>
#include <memory>

#include "Widget.h"
#include "Rectangle.h"
#include "Text.h"

namespace gui
{
	class Button : public Widget
	{
	public:
		Button(const std::wstring& text);
		Button(const sf::Vector2f& size);

		void setFunction(const std::function<void(void)>& func);
		void setText(const std::wstring& str);
		void setTexture(const sf::Texture& texture);
		void setSize(const sf::Vector2f& size);
		void setBorder(const sf::Vector2f& border);

		void handleEvent(sf::Event event, const sf::RenderWindow& window) override;
		void render(sf::RenderTarget& renderer) override;
		void setPosition(const sf::Vector2f& pos) override;
		sf::Vector2f getSize() const override;

	private:
		void update();
		
		sf::Vector2f position;
		sf::Vector2f size;
		util::Rectangle rect;
		util::Text text;
		std::function<void(void)> func;
		sf::Vector2f border;
	};
}