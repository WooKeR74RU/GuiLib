#include "ToggleKey.h"

namespace util
{
	ToggleKey::ToggleKey(sf::Keyboard::Key key, sf::Time delay) :
		key(key),
		delay(delay)
	{ }
	bool ToggleKey::isKeyPressed()
	{
		if (delayTimer.getElapsedTime() > delay && sf::Keyboard::isKeyPressed(key))
		{
			delayTimer.restart();
			return true;
		}
		return false;
	}
}