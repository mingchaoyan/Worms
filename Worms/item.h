#ifndef ITEM_H
#define ITEM_H

#include "global.h"


//// 全局变量

// 声明位图句柄
HBITMAP m_hBackgroundBmp;
HBITMAP m_hHeroBmp;
HBITMAP m_hGameStartButtonBmp;

// 声明英雄、建筑、地形、按钮
Hero          m_hero;
Terrian       m_terrian[MAX_TERRIAN_NUM];
GameButton    m_gameStartButton;

// 声明游戏状态
GameStatus gameStatus;

#endif