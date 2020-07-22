#include "Textbox.h"

#include "Colors.h"

namespace gui
{
	TextBox::TextBox(float width, const std::wstring& label)
	{
		indent = 5;
		border = sf::Vector2f(10, 10);
		isActive = false;
		textMeanCharWidth = util::getMeanCharacterWidth(text);
		textMaxLineHeight = util::getMaxLineHeight(text);
		this->label.setString(label);
		this->width = width;
		update();
	}

	void TextBox::setWidth(float width)
	{
		this->width = width;
		update();
	}
	void TextBox::setTexture(const sf::Texture& texture)
	{
		background.setTexture(&texture);
	}
	void TextBox::setLabel(const std::wstring& str)
	{
		label.setString(str);
		update();
	}
	void TextBox::setBaseString(const std::wstring& str)
	{
		baseString = str;
		update();
	}
	void TextBox::setBorder(const sf::Vector2f& border)
	{
		this->border = border;
		update();
	}
	void TextBox::setIndent(float indent)
	{
		this->indent = indent;
		update();
	}

	void TextBox::handleEvent(sf::Event event, const sf::RenderWindow& window)
	{
		bool updateFlag = false;
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		{
			if (isActive != inputField.isRolledOn(window))
				updateFlag = 1;
			isActive = inputField.isRolledOn(window);
		}
		if (isActive && event.type == sf::Event::TextEntered)
		{
			wchar_t c = event.text.unicode;
			if (isValidCharacter(c))
			{
				updateFlag = 1;
				fullText.push_back(c);
			}
			if (isBackspace(c) && !fullText.empty())
			{
				updateFlag = 1;
				fullText.pop_back();
			}
			if (isEnter(c))
			{
				updateFlag = 1;
				isActive = false;
			}
		}
		if (updateFlag)
			update();
	}
	void TextBox::render(sf::RenderTarget& renderer)
	{
		renderer.draw(background);
		renderer.draw(label);
		renderer.draw(inputField);
		renderer.draw(text);
	}
	void TextBox::setPosition(const sf::Vector2f& position)
	{
		this->position = position;
		update();
	}
	sf::Vector2f TextBox::getSize() const
	{
		return background.getSize();
	}

	void TextBox::update()
	{
		background.setPosition(position);
		float bH = border.y + label.getRect().height + indent + textMaxLineHeight + border.y;
		background.setSize(sf::Vector2f(width, bH));

		inputField.setPosition(position.x + border.x, position.y + border.y + label.getRect().height + indent);
		inputField.setSize(sf::Vector2f(background.getSize().x - 2 * border.x, textMaxLineHeight));

		label.setPosition(0, position.y + border.y);
		label.alignX(background);

		float tX = position.x + border.x + indent;
		float tY = position.y + border.y + label.getRect().height + indent;
		text.setPosition(tX, tY);
		if (fullText.empty())
		{
			if (isActive)
			{
				text.setString(L"|");
				text.setFillColor(colors::White);
			}
			else
			{
				text.setString(baseString);
				text.setFillColor(colors::Transparent50);
			}
		}
		else
		{
			int charCount = (int)((inputField.getSize().x - 2 * indent) / textMeanCharWidth);
			if (isActive)
				fullText.push_back(L'|');
			if (fullText.size() <= charCount)
				text.setString(fullText);
			else
				text.setString(fullText.substr(fullText.size() - charCount, charCount));
			if (isActive)
				fullText.pop_back();
		}
	}

	bool TextBox::isValidCharacter(wchar_t c)
	{
		bool res = false;
		res = res || L'a' <= c && c <= L'z';
		res = res || L'A' <= c && c <= L'Z';
		res = res || L'à' <= c && c <= L'ÿ';
		res = res || L'À' <= c && c <= L'ß';
		res = res || L'0' <= c && c <= L'9';
		res = res || c == L' ';
		return res;
	}
	bool TextBox::isBackspace(wchar_t c)
	{
		return c == L'\b';
	}
	bool TextBox::isEnter(wchar_t c)
	{
		return c == L'\r';
	}
}