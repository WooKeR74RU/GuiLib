#include "FPSCounter.h"

#include "Colors.h"

namespace util
{
	FPSCounter::FPSCounter(sf::Time updateDelay) :
		updateDelay(updateDelay)
	{
		text.setPosition(10, 10);
		text.setCharacterSize(15);
		text.setOutlineThickness(2);
		text.setOutlineColor(colors::Green);
	}
	void FPSCounter::update()
	{
		framesCount++;
		if (updateTimer.getElapsedTime() > updateDelay)
		{
			FPS = framesCount / timer.restart().asSeconds();
			framesCount = 0;
			updateTimer.restart();
			text.setString("FPS: " + std::to_string((int)FPS));
		}
	}
	void FPSCounter::draw(sf::RenderTarget& renderer) const
	{
		renderer.draw(text);
	}
}