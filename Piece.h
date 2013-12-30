#ifndef PIECE_H
#define PIECE_H

#include<SFML\Graphics.hpp>
#include "SpritePlus.h"

#define BOARD_WIDTH 9
#define BOARD_HEIGHT 8

#define FILE_PIECES	"Images/Pieces.png"

enum pieceType{ANON = -1, SOLDIER, SCOUT, GENERAL, TOWER, RAM, WALL};
enum direction{SET = -1, N, NE, E, SE, S, SW, W, NW};
direction turnRight(direction d, int n);

class Piece : public SpritePlus
{
	int player_;
	pieceType type_;
	sf::Vector2i position_;

	void findTexture();
public:
	void setPlayer(int set);
	void setPiecetype(pieceType set);
	void setPositionOnBoard(int x =0, int y =0);
	void setPositionOnBoard(sf::Vector2i position);

	bool checkSpace(int x, int y) const;
	bool checkSpace(sf::Vector2i position) const;
	bool isAlive() const;
	
	int getPlayer() const;
	pieceType getPieceType() const;
	sf::Vector2i getPositionOnBoard() const;

	void moveOnBoard(direction d);
	void moveOnBoard(int x, int y);
	void jump(direction d);

	Piece(sf::Texture&, int player, pieceType type, int x=0, int y=0);
	Piece(sf::Texture&, int player, pieceType type, sf::Vector2i position = sf::Vector2i());
	Piece(sf::Texture& = sf::Texture());
};

#endif