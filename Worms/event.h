#ifndef EVENT_H
#define EVENT_H

#include <Windows.h>

// 窗体过程函数
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


// 初始化
VOID Init(HWND hWnd, WPARAM wParam, LPARAM lParam);

//双缓冲绘制
VOID Render(HWND hWnd);
VOID Render_Start(HWND hWnd);//绘制游戏开始界面
VOID Render_Game(HWND hWnd);//绘制游戏界面


//定时器事件
VOID TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);

//hero更新
VOID HeroUpdate();

//地形更新
VOID TerrianUpdate();

//游戏状态更新
VOID GameStatusUpdate();

//判断是否点击按钮
BOOL ButtonClicked(POINT, RECT);

//键盘按下事件处理
VOID KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

//键盘松开事件处理
VOID KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

//左鼠标点击事件
VOID LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

#endif // !EVENT_H
