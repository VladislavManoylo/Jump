#ifndef BOARD_H
#define BOARD_H

#include <SFML\Graphics.hpp>
#include <vector>
#include "SpritePlus.h"

#define MARGIN_LEFT 0
#define MARGIN_TOP 0
#define SQUARE_LENGTH 60
#define SQUARE_SIZE sf::Vector2f(60,60)

#define FILE_BOARD "Images/board.png"

sf::Vector2i screenToBoard(sf::Vector2i screenPos);
sf::Vector2i boardToScreen(sf::Vector2i boardPos);

class Board : public sf::Drawable
{
	sf::Texture textureBoard_;
	sf::Sprite board_;
	std::vector <sf::RectangleShape> highLights_;

public:
	void highlightSquare (sf::Vector2i position, sf::Color color);
	void highlightSquare (int x, int y, sf::Color color);	
	void removeHighlights ();

	void switchPlayers();

	virtual void draw (sf::RenderTarget &target, sf::RenderStates states) const;

	sf::Vector2i click(sf::Vector2i mousePos) const;
	Board();
};

#endif