#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "NonCopyable.h"
#include "NonMovable.h"
#include "ResourceManager.h"

class ResourceHolder : public NonCopyable, public NonMovable
{
public:
	static ResourceHolder& get();

	ResourceManager<sf::Font> fonts;
	ResourceManager<sf::Texture> textures;
	ResourceManager<sf::SoundBuffer> soundBuffers;

private:
	ResourceHolder();
};