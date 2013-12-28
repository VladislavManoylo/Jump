#ifndef SPRITEPLUS_H
#define SPRITEPLUS_H

#include <SFML\Graphics.hpp>

class SpritePlus : public sf::Sprite
{
public:
	void setFrameSize(int width, int height);
	void setFrame(float x, float y);
	void moveFrame(float dx, float dy);
	
	void setFrameSize(sf::Vector2i size);
	void setFrame(sf::Vector2f position);
	void moveFrame(sf::Vector2f move);
	
	sf::Vector2f getFrame() const;

	SpritePlus();
	SpritePlus(const sf::Sprite &sprite);
	SpritePlus(const sf::Texture &texture);
	SpritePlus(const sf::Texture &texture, const sf::IntRect &rectangle);
};

#endif