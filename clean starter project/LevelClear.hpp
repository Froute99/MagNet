/**************************************************************************************
File Name     :
Project name : MaG+NeT
Author	     : Eunjin Hong
Email	     : chocob0217@gmail.com
Copyright Information :
    "All content 2019 DigiPen (USA) Corporation, all rights reserved."
**************************************************************************************/

#pragma once
#include <engine/Object.h>

class LevelClear : public Object
{
public:
	LevelClear() {}
	~LevelClear() {}

	int  GetClearMagXIndex() const { return magXIndex; }
	void SetClearMagXIndex(int newX) { magXIndex = newX; }
	int  GetClearNetXIndex() const { return netXIndex; }
	void SetClearNetXIndex(int newX) { netXIndex = newX; }

	int  GetClearMagYIndex() const { return magYIndex; }
	void SetClearMagYIndex(int newY) { magYIndex = newY; }
	int  GetClearNetYIndex() const { return netYIndex; }
	void SetClearNetYIndex(int newY) { netYIndex = newY; }

private:
    int magXIndex = 0, magYIndex = 0;
    int netXIndex = 0, netYIndex = 0;
};