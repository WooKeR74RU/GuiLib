#include "Text.h"

#include "ResourceHolder.h"
#include "Colors.h"

namespace util
{
	Text::Text()
	{
		setFont(ResourceHolder::get().fonts.get("RobotoMono-Regular"));
		setCharacterSize(50);
		setFillColor(colors::White);
		setOutlineThickness(1);
		setOutlineColor(colors::Black);
	}
	sf::FloatRect Text::getRect() const
	{
		float w = getLocalBounds().width + 2 * getLocalBounds().left;
		float h = getLocalBounds().height + 2 * getLocalBounds().top;
		return sf::FloatRect(getPosition(), sf::Vector2f(w, h));
	}
	void Text::alignX(const Rectangle& rect)
	{
		float x = rect.getPosition().x + rect.getLocalBounds().width / 2 - getLocalBounds().width / 2 - getLocalBounds().left;
		float y = getPosition().y;
		setPosition(sf::Vector2f(x, y));
	}
	void Text::alignY(const Rectangle& rect)
	{
		float x = getPosition().x;
		float y = rect.getPosition().y + rect.getLocalBounds().height / 2 - getLocalBounds().height / 2 - getLocalBounds().top;
		setPosition(sf::Vector2f(x, y));
	}
	void Text::align(const Rectangle& rect)
	{
		alignX(rect);
		alignY(rect);
	}

	const std::wstring& getTestString()
	{
		static std::wstring res;
		if (res.empty())
		{
			for (wchar_t c = L'A'; c <= L'Z'; c++)
				res.push_back(c);
			for (wchar_t c = L'a'; c <= L'z'; c++)
				res.push_back(c);
		}
		return res;
	}
	float getMeanCharacterWidth(const Text& text)
	{
		Text tmp(text);
		tmp.setString(getTestString());
		return tmp.getLocalBounds().width / tmp.getString().getSize();
	}
	float getMaxLineHeight(const Text& text)
	{
		Text tmp(text);
		tmp.setString(getTestString());
		return tmp.getRect().height;
	}
}