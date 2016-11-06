#ifndef GLOBAL_H
#define GLOBAL_H

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <math.h>
#include "resource.h"


// ����������WNDWIDTH��WNDHEIGHTΪ���ڵĿ�͸�
#define TIMER_ID             1		//��ʱ��ID
#define TIMER_ELAPSE         20		//��ʱ�����(ms)
#define WNDWIDTH             800	//���ڵĿ�
#define WNDHEIGHT            600	//���ڵĸ�
#define TITLEBARHEIGHT       32		//��������

// ������Դ�ĳߴ�
#define HERO_SIZE_X          30
#define HERO_SIZE_Y          30
#define HERO_MAX_FRAME_NUM   3
#define GAME_START_BUTTON_SIZE_X   147
#define GAME_START_BUTTON_SIZE_Y   60

//������Ϸ����
#define MAX_TERRIAN_NUM      1		//���ؿ�����
#define GRAVITY				 10		//����
#define HERO_VEL_X			 2		//Ӣ��ˮƽ�ٶ�
#define HERO_VEL_Y			 4		//Ӣ����ֱ�ٶ�


// Ӣ�۽ṹ�壬Ӣ��λͼ��λ�á���С*/
typedef struct
{
	HBITMAP	hBmp;	//Ӣ��ͼƬ
	POINT	pos;	//Ӣ��
	POINT   vel;
	SIZE	size;
	int     curFrameIndex;
	int     maxFrameSize;
} Hero;

/*���νṹ�壬���η���λ�á���С*/
typedef struct
{
	HBITMAP hBmp;
	POINT	pos;
	SIZE    size;
} Terrian;

/*��ť�ṹ��*/
typedef struct
{
	HBITMAP	hBmp;	//��ťͼƬ
	POINT   pos;	//��ťλ��
	SIZE	size;	//��ť�ߴ�
	int	status;	//��ť״̬
}  GameButton;

/*��Ϸ״̬�ṹ��*/
typedef struct
{
	HBITMAP	hBmp;	//����ͼƬ
	int	status;	//��Ϸ״̬
}  GameStatus;



// ȫ�ֺ���

/*************************************************
Fucntion : ����Ӣ������
Parameter:
posX��posY��ʾ�������Ͻǵ�����
sizeX��sizeY��ʾ���ε�size
hBmp��ʾλͼ���
curFrameIndex��ǰ֡
maxFrameSize���֡��
*************************************************/
Hero CreateHero(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp, int curFrameIndex, int maxFrameSize);

/*************************************************
Fucntion : ������Ϸ״̬
Parameter:
posX��posY��ʾ�������Ͻǵ�����
sizeX��sizeY��ʾ���ε�size
hBmp��ʾλͼ���
*************************************************/
GameButton CreateGameButton(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp, int status);

/*************************************************
Fucntion : ������������
Parameter:
posX��posY��ʾ�������Ͻǵ�����
sizeX��sizeY��ʾ���ε�size
*************************************************/
Terrian CreateTerrian(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

#endif // !GLOBAL_H
