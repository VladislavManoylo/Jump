#include "Board.h"

sf::Vector2i screenToBoard(sf::Vector2i screenPos)
{
	screenPos.x -= MARGIN_LEFT;
	screenPos.y -= MARGIN_TOP;

	screenPos.x /= SQUARE_LENGTH;
	screenPos.y /= SQUARE_LENGTH;

	return screenPos;
}
sf::Vector2i boardToScreen(sf::Vector2i boardPos)
{
	boardPos.x *= SQUARE_LENGTH;
	boardPos.y *= SQUARE_LENGTH;

	boardPos.x += MARGIN_LEFT;
	boardPos.y += MARGIN_TOP;

	return boardPos;
}

void Board::highlightSquare (sf::Vector2i position, sf::Color color)
{
	position = boardToScreen(position);
	sf::Vector2f pos(position.x, position.y);

	sf::RectangleShape shape(SQUARE_SIZE);
	shape.setFillColor(color);
	shape.setPosition(pos);

	highLights_.push_back(shape);
}
void Board::highlightSquare (int x, int y, sf::Color color)
{
	highlightSquare(sf::Vector2i(x, y), color);
}
void Board::removeHighlights ()
{
	highLights_.clear();
}

void Board::switchPlayers()
{
	board_.rotate(180);
}

void Board::draw (sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(board_, states);

	for (const sf::RectangleShape& shape: highLights_)
		target.draw(shape);
}
sf::Vector2i Board::click(sf::Vector2i mousePos) const
{
	return screenToBoard(mousePos);
}

Board::Board()
{
	textureBoard_.loadFromFile(FILE_BOARD);
	board_.setTexture(textureBoard_);
}