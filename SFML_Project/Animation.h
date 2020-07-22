#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

namespace util
{
	class Animation
	{
	public:
		struct Frame
		{
			Frame(const sf::IntRect& bnds, sf::Time dly);
			sf::IntRect bounds;
			sf::Time delay;
		};

		Animation(unsigned int frameWidth, unsigned int frameHeight);
		void addFrame(unsigned int index, sf::Time delay);
		const sf::IntRect& getFrame();

	private:
		const unsigned int FRAME_WIDTH;
		const unsigned int FRAME_HEIGHT;
		std::vector<Frame> frames;
		unsigned int curFrame = 0;
		sf::Clock timer;
	};
}