#ifndef ITEM_H
#define ITEM_H

#include "global.h"


//// ȫ�ֱ���

// ����λͼ���
HBITMAP m_hBackgroundBmp;
HBITMAP m_hHeroBmp;
HBITMAP m_hGameStartButtonBmp;

// ����Ӣ�ۡ����������Ρ���ť
Hero          m_hero;
Terrian       m_terrian[MAX_TERRIAN_NUM];
GameButton    m_gameStartButton;

// ������Ϸ״̬
GameStatus gameStatus;

#endif