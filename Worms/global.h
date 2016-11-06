#ifndef GLOBAL_H
#define GLOBAL_H

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <math.h>
#include "resource.h"


// 定义宏变量，WNDWIDTH、WNDHEIGHT为窗口的宽和高
#define TIMER_ID             1		//计时器ID
#define TIMER_ELAPSE         20		//计时器间隔(ms)
#define WNDWIDTH             800	//窗口的宽
#define WNDHEIGHT            600	//窗口的高
#define TITLEBARHEIGHT       32		//标题栏高

// 定义资源的尺寸
#define HERO_SIZE_X          30
#define HERO_SIZE_Y          30
#define HERO_MAX_FRAME_NUM   3
#define GAME_START_BUTTON_SIZE_X   147
#define GAME_START_BUTTON_SIZE_Y   60

//定义游戏常量
#define MAX_TERRIAN_NUM      1		//最大地块数量
#define GRAVITY				 10		//重力
#define HERO_VEL_X			 2		//英雄水平速度
#define HERO_VEL_Y			 4		//英雄竖直速度


// 英雄结构体，英雄位图、位置、大小*/
typedef struct
{
	HBITMAP	hBmp;	//英雄图片
	POINT	pos;	//英雄
	POINT   vel;
	SIZE	size;
	int     curFrameIndex;
	int     maxFrameSize;
} Hero;

/*地形结构体，地形方块位置、大小*/
typedef struct
{
	HBITMAP hBmp;
	POINT	pos;
	SIZE    size;
} Terrian;

/*按钮结构体*/
typedef struct
{
	HBITMAP	hBmp;	//按钮图片
	POINT   pos;	//按钮位置
	SIZE	size;	//按钮尺寸
	int	status;	//按钮状态
}  GameButton;

/*游戏状态结构体*/
typedef struct
{
	HBITMAP	hBmp;	//背景图片
	int	status;	//游戏状态
}  GameStatus;



// 全局函数

/*************************************************
Fucntion : 创建英雄人物
Parameter:
posX、posY表示矩形左上角的坐标
sizeX、sizeY表示矩形的size
hBmp表示位图句柄
curFrameIndex当前帧
maxFrameSize最大帧率
*************************************************/
Hero CreateHero(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp, int curFrameIndex, int maxFrameSize);

/*************************************************
Fucntion : 创建游戏状态
Parameter:
posX、posY表示矩形左上角的坐标
sizeX、sizeY表示矩形的size
hBmp表示位图句柄
*************************************************/
GameButton CreateGameButton(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp, int status);

/*************************************************
Fucntion : 创建单个地形
Parameter:
posX、posY表示矩形左上角的坐标
sizeX、sizeY表示矩形的size
*************************************************/
Terrian CreateTerrian(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

#endif // !GLOBAL_H
