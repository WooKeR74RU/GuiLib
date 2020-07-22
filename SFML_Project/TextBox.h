#pragma once

#include <functional>

#include "Widget.h"
#include "Rectangle.h"
#include "Text.h"

namespace gui
{
	class TextBox : public Widget
	{
	public:
		TextBox(float width, const std::wstring& label);

		void setWidth(float width);
		void setBorder(const sf::Vector2f& border);
		void setIndent(float indent);
		void setTexture(const sf::Texture& texture);
		void setLabel(const std::wstring& str);
		void setBaseString(const std::wstring& str);

		void handleEvent(sf::Event event, const sf::RenderWindow& window) override;
		void render(sf::RenderTarget& renderer) override;
		void setPosition(const sf::Vector2f& position) override;
		sf::Vector2f getSize() const override;

	private:
		void update();

		static bool isValidCharacter(wchar_t c);
		static bool isBackspace(wchar_t c);
		static bool isEnter(wchar_t c);

		sf::Vector2f position;
		float width;
		util::Rectangle background;
		util::Text label;
		util::Rectangle inputField;
		util::Text text;
		bool isActive;
		sf::Vector2f border;
		float indent;
		std::wstring fullText;
		std::wstring baseString;
		float textMeanCharWidth;
		float textMaxLineHeight;
	};
}