#pragma once

#include <SFML/Graphics.hpp>

#include "Text.h"

namespace util
{
	class FPSCounter
	{
	public:
		FPSCounter(sf::Time updateDelay = sf::seconds(0.2f));
		void update();
		void draw(sf::RenderTarget& renderer) const;

	private:
		util::Text text;
		sf::Clock timer;
		float FPS = 0;
		int framesCount = 0;
		sf::Clock updateTimer;
		sf::Time updateDelay;
	};
}