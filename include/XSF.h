#pragma once
#include <string>
#include<Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
namespace XSF {
	struct XSF_Window
	{
		int length = 0;
		int height = 0;
		std::wstring name = L"";
		HWND hwnd = nullptr;
		HDC hMemDC = nullptr;
		HBITMAP hbmp = nullptr;
		HBITMAP holdbmp = nullptr;
		bool UBD = 0;
	};
	void XSF_Window_Create(int length, int height, std::wstring name, struct XSF_Window& window);
	void XSF_Window_Modify(int length, int height, struct XSF_Window& window);
	void XSF_Window_Close(struct XSF_Window& window);
    void XSF_Window_Init();
	enum XSF_EventType {
		XSF_EVENT_NONE,
		XSF_EVENT_CLOSE,
		XSF_EVENT_KEY_DOWN,
		XSF_EVENT_KEY_UP,
		XSF_EVENT_MOUSE_DOWN,
		XSF_EVENT_MOUSE_UP,
		XSF_EVENT_MOUSE_MOVE
	};
	enum XSF_Key {
		XSF_KEY_NONE,
		XSF_KEY_ESC,
		XSF_KEY_A,
		XSF_KEY_B,
		XSF_KEY_C,
		XSF_KEY_D,
		XSF_KEY_E,
		XSF_KEY_F,
		XSF_KEY_G,
		XSF_KEY_H,
		XSF_KEY_I,
		XSF_KEY_J,
		XSF_KEY_K,
		XSF_KEY_L,
		XSF_KEY_M,
		XSF_KEY_N,
		XSF_KEY_O,
		XSF_KEY_P,
		XSF_KEY_Q,
		XSF_KEY_R,
		XSF_KEY_S,
		XSF_KEY_T,
		XSF_KEY_U,
		XSF_KEY_V,
		XSF_KEY_W,
		XSF_KEY_X,
		XSF_KEY_Y,
		XSF_KEY_Z,
		XSF_KEY_0,
		XSF_KEY_1,
		XSF_KEY_2,
		XSF_KEY_3,
		XSF_KEY_4,
		XSF_KEY_5,
		XSF_KEY_6,
		XSF_KEY_7,
		XSF_KEY_8,
		XSF_KEY_9,
		XSF_KEY_SPACE,
		XSF_KEY_UP,
		XSF_KEY_DOWN,
		XSF_KEY_LEFT,
		XSF_KEY_RIGHT,
		XSF_KEY_F1,
		XSF_KEY_F2,
		XSF_KEY_F3,
		XSF_KEY_F4,
		XSF_KEY_F5,
		XSF_KEY_F6,
		XSF_KEY_F7,
		XSF_KEY_F8,
		XSF_KEY_F9,
		XSF_KEY_F10,
		XSF_KEY_F11,
		XSF_KEY_F12,
		XSF_KEY_COMMA,
		XSF_KEY_PERIOD,
		XSF_KEY_SLASH,
		XSF_KEY_BACKSLASH,
		XSF_KEY_SEMICOLON,
		XSF_KEY_APOSTROPHE,
		XSF_KEY_GRAVE,
		XSF_KEY_EQUALS,
		XSF_KEY_MINUS,
		XSF_KEY_TAB,
		XSF_KEY_CAPS_LOCK,
		XSF_KEY_ENTER,
		XSF_KEY_BACKSPACE,
		XSF_KEY_LEFT_SHIFT,
		XSF_KEY_RIGHT_SHIFT,
		XSF_KEY_LEFT_CTRL,
		XSF_KEY_RIGHT_CTRL,
		XSF_KEY_LEFT_ALT,
		XSF_KEY_RIGHT_ALT,
		XSF_KEY_DELETE,
		XSF_KEY_LEFT_SUPER,
		XSF_KEY_RIGHT_SUPER
	};
	enum XSF_MouseButton {
		XSF_MOUSE_NONE,
		XSF_MOUSE_LEFT,
		XSF_MOUSE_RIGHT,
		XSF_MOUSE_MIDDLE
	};
	struct XSF_Event {
		XSF_EventType type = XSF_EVENT_NONE;
		XSF_Key key = XSF_KEY_NONE;
		XSF_MouseButton mouse = XSF_MOUSE_NONE;
		int mousex = 0;
		int mousey = 0;
		MSG msg = { 0 };
		HWND hwnd = nullptr;
	};
	LRESULT CALLBACK XSF_WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	bool XSF_PollEvent(struct XSF_Event& event);
	void XSF_DrawRect(int x1, int y1, int x2, int y2,struct XSF_Window& window);
	void XSF_DrawSolidRect(int x1, int y1, int x2, int y2, struct XSF_Window& window);
	void XSF_DrawCircle(int x, int y, int r, XSF_Window& window);
	void XSF_DrawSolidCircle(int x, int y, int r, XSF_Window& window);
	void XSF_ClearDraw(struct XSF_Window& window);
	void XSF_DrawLine(int x1, int y1, int x2, int y2, struct XSF_Window& window);
	void XSF_DrawEllipse(int x, int y, int rx, int ry, XSF_Window& window);
	void XSF_DrawSolidEllipse(int x, int y, int rx, int ry, XSF_Window& window);
	void XSF_DrawPolygon(POINT* points, int n, struct XSF_Window& window);
	void XSF_DrawSolidPolygon(POINT* points, int n, struct XSF_Window& window);
	HBITMAP XSF_LoadBMP(const WCHAR* fp,int x,int y);
	void XSF_DrawBMP(struct XSF_Window& window, HBITMAP hBmp, int x, int y);
	void XSF_SetColor(COLORREF color);
	void XSF_UnLoadBMP(HBITMAP hBmp[], int s);
	void XSF_PlayWAV(const WCHAR* fp, bool l);
	void XSF_StopSound();
	void XSF_DrawText(const WCHAR* text, int x, int y, struct XSF_Window& window);
	void XSF_DoubleBufferBegin(struct XSF_Window& window);
	void XSF_DoubleBufferFlip(struct XSF_Window& window);
}