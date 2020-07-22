#pragma once

#include <SFML/Graphics.hpp>

#include "Rectangle.h"

namespace util
{
	class Text : public sf::Text
	{
	public:
		Text();
		sf::FloatRect getRect() const;
		void alignX(const Rectangle& rect);
		void alignY(const Rectangle& rect);
		void align(const Rectangle& rect);
	};

	const std::wstring& getTestString();
	float getMeanCharacterWidth(const Text& text);
	float getMaxLineHeight(const Text& text);
}