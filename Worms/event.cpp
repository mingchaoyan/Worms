#include "event.h"
#include "global.h"
#include "item.h"


VOID Init(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// ���ر���λͼ
	m_hBackgroundBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BACKGROUND));

	// ����Heroλͼ
	m_hHeroBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_HERO));

	// ���ؿ�ʼ��Ϸ��ťλͼ
	m_hGameStartButtonBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_START));

	// ����Ӣ��
	m_hero = CreateHero(150, 450 - HERO_SIZE_Y, HERO_SIZE_X, HERO_SIZE_Y, m_hHeroBmp, 0, HERO_MAX_FRAME_NUM);

	// ��������
	m_terrian[0] = CreateTerrian(100, 450, 600, 100, NULL);

	// ������Ϸ��ʼ��ť
	m_gameStartButton = CreateGameButton(200, 200, GAME_START_BUTTON_SIZE_X, GAME_START_BUTTON_SIZE_Y, m_hGameStartButtonBmp, 0);


	//�趨��ʼ��Ϸ״̬
	gameStatus.status=0;
	gameStatus.hBmp = m_hBackgroundBmp;

}

VOID Render(HWND hWnd)
{
	//�ж���Ϸ״̬
	switch(gameStatus.status)
	{
	case 0:
		//���ƿ�ʼ����
		Render_Start(hWnd);
		break;
	case 1:
		//������Ϸ����
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
	// ��ʼ����
	hdc = BeginPaint(hWnd, &ps);

	HDC	hdcBmp, hdcBuffer;
	HBITMAP	cptBmp;

	cptBmp = CreateCompatibleBitmap(hdc, WNDWIDTH, WNDHEIGHT);
	hdcBmp = CreateCompatibleDC(hdc);
	hdcBuffer = CreateCompatibleDC(hdc);
	

	// ���Ʊ���������
	SelectObject(hdcBuffer, cptBmp);
	SelectObject(hdcBmp, gameStatus.hBmp);
	BitBlt(hdcBuffer, 0, 0, WNDWIDTH, WNDHEIGHT,
		hdcBmp, 0, 0, SRCCOPY);

	// ���ƿ�ʼ��ť
	SelectObject(hdcBmp, m_gameStartButton.hBmp);
	TransparentBlt(hdcBuffer, m_gameStartButton.pos.x, m_gameStartButton.pos.y, m_gameStartButton.size.cx, m_gameStartButton.size.cy,
		hdcBmp, 0, 0,
		m_gameStartButton.size.cx, m_gameStartButton.size.cy, RGB(255, 255, 255));

	// ������е���Ϣ���Ƶ���Ļ��
	BitBlt(hdc, 0, 0, WNDWIDTH, WNDHEIGHT, hdcBuffer, 0, 0, SRCCOPY);

	// ������Դ��ռ���ڴ�
	DeleteObject(cptBmp);
	DeleteDC(hdcBuffer);
	DeleteDC(hdcBmp);

	// ��������
	EndPaint(hWnd, &ps);
}

VOID Render_Game(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	// ��ʼ����
	hdc = BeginPaint(hWnd, &ps);

	HDC	hdcBmp, hdcBuffer;
	HBITMAP	cptBmp;

	cptBmp = CreateCompatibleBitmap(hdc, WNDWIDTH, WNDHEIGHT);
	hdcBmp = CreateCompatibleDC(hdc);
	hdcBuffer = CreateCompatibleDC(hdc);
	

	// ���Ʊ���������
	SelectObject(hdcBuffer, cptBmp);
	SelectObject(hdcBmp, gameStatus.hBmp);
	BitBlt(hdcBuffer, 0, 0, WNDWIDTH, WNDHEIGHT,
		hdcBmp, 0, 0, SRCCOPY);

	// ����Hero������
	SelectObject(hdcBmp, m_hero.hBmp);
	TransparentBlt(
		hdcBuffer, m_hero.pos.x, m_hero.pos.y,
		m_hero.size.cx, m_hero.size.cy,
		hdcBmp, 0, 0, 66, 62,
		RGB(255, 255, 255)
	);

	// ���Ƶ���
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

	// ���Ʒ���
	TCHAR	szDist[13];
	SetTextColor(hdcBuffer, RGB(0, 0, 0));
	SetBkMode(hdcBuffer, TRANSPARENT);
	wsprintf(szDist, _T("0 : 0"));
	TextOut(hdcBuffer, WNDWIDTH - 100, 15, szDist, _tcslen(szDist));

	// ������е���Ϣ���Ƶ���Ļ��
	BitBlt(hdc, 0, 0, WNDWIDTH, WNDHEIGHT, hdcBuffer, 0, 0, SRCCOPY);

	// ������Դ��ռ���ڴ�
	DeleteObject(cptBmp);
	DeleteDC(hdcBuffer);
	DeleteDC(hdcBmp);

	// ��������
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
	//����Ӣ��λ�á�����
}

VOID TerrianUpdate() 
{
	// TODO
	//���µ���
}

VOID GameStatusUpdate()
{
	// TODO
	//������Ϸ״̬
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
	POINT ptMouse; // �����������
	ptMouse.x = LOWORD(lParam);
	ptMouse.y = HIWORD(lParam);

	//����������Ϸ��ʼͼ��
	if (gameStatus.status==0 && ButtonClicked(ptMouse, m_gameStartButton.pos, m_gameStartButton.size))
	{
		// ������ʱ��
		SetTimer(hWnd, TIMER_ID, TIMER_ELAPSE, NULL);
		// ֹͣ��ʱ��
		//KillTimer(hWnd, TIMER_ID);

		// ������Ϸ״̬
		gameStatus.status=1;

		InvalidateRect(hWnd, NULL, TRUE);//������������ΪTRUE���ػ�����������
	}
}
