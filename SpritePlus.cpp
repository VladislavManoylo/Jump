#include "SpritePlus.h"

void SpritePlus::setFrameSize(int width, int height)
{
	int left = getTextureRect().left,
		top = getTextureRect().top;
	setTextureRect(sf::IntRect(left, top, width, height));
}
void SpritePlus::setFrame(float x, float y)
{
	float width = getTextureRect().width,
		height = getTextureRect().height;
	setTextureRect(sf::IntRect(x * width, y * height, width, height));
}
void SpritePlus::moveFrame(float dx, float dy)
{
	setFrame(getFrame().x + dx, getFrame().y + dy);
}

void SpritePlus::setFrameSize(sf::Vector2i size)
{
	setFrameSize(size.x, size.y);
}
void SpritePlus::setFrame(sf::Vector2f position)
{
	setFrame(position.x, position.y);
}
void SpritePlus::moveFrame(sf::Vector2f move)
{
	moveFrame(move.x, move.y);
}
	
sf::Vector2f SpritePlus::getFrame() const
{
	float left = getTextureRect().left,
		top = getTextureRect().top,
		width = getTextureRect().width,
		height = getTextureRect().height;

	return sf::Vector2f(left/width, top/height);
}

SpritePlus::SpritePlus()	
	:sf::Sprite(){};
SpritePlus::SpritePlus(const sf::Sprite &sprite)	
	:sf::Sprite(sprite){};
SpritePlus::SpritePlus(const sf::Texture &texture)	
	:sf::Sprite(texture){};
SpritePlus::SpritePlus(const sf::Texture &texture, const sf::IntRect &rectangle)
	:sf::Sprite(texture, rectangle){};