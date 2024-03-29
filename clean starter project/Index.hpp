/**************************************************************************************
File Name    : Index.hpp
Project name : MaG+NeT
Author	     : Junghak Kim
Email	     : dbh99619@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#pragma once

namespace MapColor
{
    const SDL_Color BLACK = { 0, 0, 0, 255 };
    const SDL_Color CLEAR_MAG_COLOR = { 150, 21, 38 ,255 };
    const SDL_Color CLEAR_NET_COLOR = { 29, 6, 132 ,255 };
}
class Object;

class Index
{
public:
    enum LEVEL_COMPONENT { EMPTY = 0, BOX, WALL, MAG, NET, CLEAR_MAG, CLEAR_NET };
	Index(int width, int height);
	Index() = default;
	~Index() = default;
	bool IsObject(int xIndex, int yIndex);
	void InitializeIndex() const;
    void InitializeMapTile(int tileX, int tileY);

	int GetWidth() const { return width; }
	int GetHeight() const { return height; }

	int GetIndex(int x, int y) { return index[x][y]; }
	void SetIndex(int x, int y, int value) { index[x][y] = value; }

private:
	int** index;
	int width, height;
};
