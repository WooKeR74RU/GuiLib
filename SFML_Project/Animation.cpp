#include "Animation.h"

namespace util
{
	Animation::Frame::Frame(const sf::IntRect & bnds, sf::Time dly) :
		bounds(bnds),
		delay(dly)
	{ }

	Animation::Animation(unsigned int frameWidth, unsigned int frameHeight) :
		FRAME_WIDTH(frameWidth),
		FRAME_HEIGHT(frameHeight)
	{ }
	void Animation::addFrame(unsigned int index, sf::Time delay)
	{
		frames.push_back(Frame(sf::IntRect(index * FRAME_WIDTH, 0, FRAME_WIDTH, FRAME_HEIGHT), delay));
	}
	const sf::IntRect& Animation::getFrame()
	{
		if (timer.getElapsedTime() >= frames[curFrame].delay)
		{
			timer.restart();
			curFrame++;
			if (curFrame == frames.size())
				curFrame = 0;
		}
		return frames[curFrame].bounds;
	}
}