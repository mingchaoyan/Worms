#include "event.h"
#include "global.h"
#include "item.h"


VOID Init(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// 加载背景位图
	m_hBackgroundBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BACKGROUND));

	// 加载Hero位图
	m_hHeroBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_HERO));

	// 加载开始游戏按钮位图
	m_hGameStartButtonBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_START));

	// 创建英雄
	m_hero = CreateHero(150, 450 - HERO_SIZE_Y, HERO_SIZE_X, HERO_SIZE_Y, m_hHeroBmp, 0, HERO_MAX_FRAME_NUM);

	// 创建地形
	m_terrian[0] = CreateTerrian(100, 450, 600, 100, NULL);

	// 创建游戏开始按钮
	m_gameStartButton = CreateGameButton(200, 200, GAME_START_BUTTON_SIZE_X, GAME_START_BUTTON_SIZE_Y, m_hGameStartButtonBmp, 0);


	//设定初始游戏状态
	gameStatus.status=0;
	gameStatus.hBmp = m_hBackgroundBmp;

}

VOID Render(HWND hWnd)
{
	//判断游戏状态
	switch(gameStatus.status)
	{
	case 0:
		//绘制开始界面
		Render_Start(hWnd);
		break;
	case 1:
		//绘制游戏界面
		Render_Game(hWnd);
		break;
	default:
		break;
	}
}


VOID Render_Start(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	// 开始绘制
	hdc = BeginPaint(hWnd, &ps);

	HDC	hdcBmp, hdcBuffer;
	HBITMAP	cptBmp;

	cptBmp = CreateCompatibleBitmap(hdc, WNDWIDTH, WNDHEIGHT);
	hdcBmp = CreateCompatibleDC(hdc);
	hdcBuffer = CreateCompatibleDC(hdc);
	

	// 绘制背景到缓存
	SelectObject(hdcBuffer, cptBmp);
	SelectObject(hdcBmp, gameStatus.hBmp);
	BitBlt(hdcBuffer, 0, 0, WNDWIDTH, WNDHEIGHT,
		hdcBmp, 0, 0, SRCCOPY);

	// 绘制开始按钮
	SelectObject(hdcBmp, m_gameStartButton.hBmp);
	TransparentBlt(hdcBuffer, m_gameStartButton.pos.x, m_gameStartButton.pos.y, m_gameStartButton.size.cx, m_gameStartButton.size.cy,
		hdcBmp, 0, 0,
		m_gameStartButton.size.cx, m_gameStartButton.size.cy, RGB(255, 255, 255));

	// 最后将所有的信息绘制到屏幕上
	BitBlt(hdc, 0, 0, WNDWIDTH, WNDHEIGHT, hdcBuffer, 0, 0, SRCCOPY);

	// 回收资源所占的内存
	DeleteObject(cptBmp);
	DeleteDC(hdcBuffer);
	DeleteDC(hdcBmp);

	// 结束绘制
	EndPaint(hWnd, &ps);
}

VOID Render_Game(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	// 开始绘制
	hdc = BeginPaint(hWnd, &ps);

	HDC	hdcBmp, hdcBuffer;
	HBITMAP	cptBmp;

	cptBmp = CreateCompatibleBitmap(hdc, WNDWIDTH, WNDHEIGHT);
	hdcBmp = CreateCompatibleDC(hdc);
	hdcBuffer = CreateCompatibleDC(hdc);
	

	// 绘制背景到缓存
	SelectObject(hdcBuffer, cptBmp);
	SelectObject(hdcBmp, gameStatus.hBmp);
	BitBlt(hdcBuffer, 0, 0, WNDWIDTH, WNDHEIGHT,
		hdcBmp, 0, 0, SRCCOPY);

	// 绘制Hero到缓存
	SelectObject(hdcBmp, m_hero.hBmp);
	TransparentBlt(
		hdcBuffer, m_hero.pos.x, m_hero.pos.y,
		m_hero.size.cx, m_hero.size.cy,
		hdcBmp, 0, 0, 66, 62,
		RGB(255, 255, 255)
	);

	// 绘制地形
	SelectObject(hdcBuffer, GetStockObject(NULL_PEN));
	HBRUSH terrianBrush = CreateSolidBrush(RGB(223, 169, 103));
	SelectObject(hdcBuffer, terrianBrush);
	int k;
	for (k = 0; k < MAX_TERRIAN_NUM; ++k)
	{
		Terrian *terrian = &m_terrian[k];
		Rectangle(hdcBuffer, terrian->pos.x, terrian->pos.y,
			terrian->pos.x + terrian->size.cx, terrian->pos.y + terrian->size.cy);
	}
	DeleteObject(terrianBrush);

	// 绘制分数
	TCHAR	szDist[13];
	SetTextColor(hdcBuffer, RGB(0, 0, 0));
	SetBkMode(hdcBuffer, TRANSPARENT);
	wsprintf(szDist, _T("0 : 0"));
	TextOut(hdcBuffer, WNDWIDTH - 100, 15, szDist, _tcslen(szDist));

	// 最后将所有的信息绘制到屏幕上
	BitBlt(hdc, 0, 0, WNDWIDTH, WNDHEIGHT, hdcBuffer, 0, 0, SRCCOPY);

	// 回收资源所占的内存
	DeleteObject(cptBmp);
	DeleteDC(hdcBuffer);
	DeleteDC(hdcBmp);

	// 结束绘制
	EndPaint(hWnd, &ps);
}

VOID TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	HeroUpdate();
	TerrianUpdate();
	GameStatusUpdate();
	InvalidateRect(hWnd, NULL, FALSE);
}

VOID HeroUpdate()
{
	m_hero.pos.x += m_hero.vel.x;
	m_hero.pos.y += m_hero.vel.y;

	// TODO
	//更新英雄位置、动作
}

VOID TerrianUpdate() 
{
	// TODO
	//更新地形
}

VOID GameStatusUpdate()
{
	// TODO
	//更新游戏状态
}

BOOL ButtonClicked(POINT ptMouse, POINT buttonPos, SIZE buttonSize)
{
	RECT rectButton;
	rectButton.left = buttonPos.x;
	rectButton.top = buttonPos.y;
	rectButton.right = buttonPos.x + buttonSize.cx;
	rectButton.bottom = buttonPos.y + buttonSize.cy;

	return PtInRect(&rectButton, ptMouse);
}

VOID KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// TODO
	switch (wParam)
	{
	case 'W':
		m_hero.vel.y = -HERO_VEL_Y;
		break;
	case 'S':
		m_hero.vel.y = HERO_VEL_Y;
		break;
	case 'A':
		m_hero.vel.x = -HERO_VEL_X;
		break;
	case 'D':
		m_hero.vel.x = HERO_VEL_X;
		break;
	default:
		break;
	}
}

VOID KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// TODO
	switch (wParam)
	{
	case 'W':
		m_hero.vel.y = 0;
		break;
	case 'S':
		m_hero.vel.y = 0;
		break;
	case 'A':
		m_hero.vel.x = 0;
		break;
	case 'D':
		m_hero.vel.x = 0;
		break;
	default:
		break;
	}
}

VOID LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	POINT ptMouse; // 鼠标点击的坐标
	ptMouse.x = LOWORD(lParam);
	ptMouse.y = HIWORD(lParam);

	//如果点击了游戏开始图标
	if (gameStatus.status==0 && ButtonClicked(ptMouse, m_gameStartButton.pos, m_gameStartButton.size))
	{
		// 启动计时器
		SetTimer(hWnd, TIMER_ID, TIMER_ELAPSE, NULL);
		// 停止计时器
		//KillTimer(hWnd, TIMER_ID);

		// 更改游戏状态
		gameStatus.status=1;

		InvalidateRect(hWnd, NULL, TRUE);//第三个参数设为TRUE，重画整个画布。
	}
}
