#ifndef EVENT_H
#define EVENT_H

#include <Windows.h>

// ������̺���
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


// ��ʼ��
VOID Init(HWND hWnd, WPARAM wParam, LPARAM lParam);

//˫�������
VOID Render(HWND hWnd);
VOID Render_Start(HWND hWnd);//������Ϸ��ʼ����
VOID Render_Game(HWND hWnd);//������Ϸ����


//��ʱ���¼�
VOID TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);

//hero����
VOID HeroUpdate();

//���θ���
VOID TerrianUpdate();

//��Ϸ״̬����
VOID GameStatusUpdate();

//�ж��Ƿ�����ť
BOOL ButtonClicked(POINT, RECT);

//���̰����¼�����
VOID KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

//�����ɿ��¼�����
VOID KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

//��������¼�
VOID LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

#endif // !EVENT_H
