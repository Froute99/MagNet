/**************************************************************************************
File Name    : Index.cpp
Project name : MaG+NeT
Author	     : Junghak Kim
Email	     : dbh99619@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#include "Character.h"
#include "Index.hpp"
#include "CreateObject.h"
#include <engine/State.h>

Index::Index(int new_width, int new_height)
	: width(new_width), height(new_height)
{
	index = new int*[width];
	for (int i = 0; i < width; i++)
	{
		index[i] = new int[height];
	}

	InitializeIndex();
}


bool Index::IsObject(int xIndex, int yIndex)	// Characters can move through CLEAR_MAG and CLEAR_NET index.
{
	return (index[xIndex][yIndex] != EMPTY && (index[xIndex][yIndex] != CLEAR_MAG) && (index[xIndex][yIndex] != CLEAR_NET));
}


void Index::InitializeIndex() const
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			index[x][y] = EMPTY;
		}
	}
}


void Index::InitializeMapTile(int tileX, int tileY)
{
    for (int y = 0; y < tileY; y++)
    {
        for (int x = 0; x < tileX; x++)
        {
            CreateTile(static_cast<float>(x), static_cast<float>(y));
        }
    }
}
