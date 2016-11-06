#include "global.h"




Hero CreateHero(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp, int curFrameIndex, int maxFrameSize)
{
	Hero hero;
	hero.hBmp = hBmp;
	hero.pos.x = posX;
	hero.pos.y = posY;
	hero.vel.x = 0;
	hero.vel.y = 0;
	hero.size.cx = sizeX;
	hero.size.cy = sizeY;
	hero.curFrameIndex = curFrameIndex;
	hero.maxFrameSize = maxFrameSize;
	return hero;
}

GameButton CreateGameButton(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp, int status)
{
	GameButton gameButton;
	gameButton.pos.x = posX;
	gameButton.pos.y = posY;
	gameButton.size.cx = sizeX;
	gameButton.size.cy = sizeY;
	gameButton.hBmp = hBmp;
	gameButton.status = status;
	return gameButton;
}

Terrian CreateTerrian(LONG posX, LONG posY, LONG sizeX, LONG sizeY,
	HBITMAP hBlockBmp)
{
	Terrian terrian;
	terrian.pos.x = posX;
	terrian.pos.y = posY;
	terrian.size.cx = sizeX;
	terrian.size.cy = sizeY;
	terrian.hBmp = hBlockBmp;
	return terrian;
}
