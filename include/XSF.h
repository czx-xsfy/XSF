#pragma once
#include <wincodec.h>
#include <string>
#include<windows.h>
#include <mmsystem.h>
#include <d2d1.h>
#include<optional>
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d2d1.lib")
namespace XSF {
	enum XSF_MessageType {
		XSF_OK,
		XSF_OKCancel,
		XSF_AbortRetryIgnore,
		XSF_YesNO,
		XSF_YesNoCancel,
		XSF_RetryCancel,
		XSF_CancelTryContinue
	};
	enum XSF_Language
	{
		XSF_LANG_SYSTEM = 0,
		XSF_LANG_CHS = MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED),
		XSF_LANG_CHT = MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_TRADITIONAL),
		XSF_LANG_EN_US = MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
		XSF_LANG_EN_UK = MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_UK),
		XSF_LANG_FRENCH = MAKELANGID(LANG_FRENCH, SUBLANG_FRENCH),
		XSF_LANG_GREEK = MAKELANGID(LANG_GREEK, SUBLANG_DEFAULT),
		XSF_LANG_GERMAN = MAKELANGID(LANG_GERMAN, SUBLANG_GERMAN)
	};
	enum XSF_MessageReturn {
		XSF_ReturnNone,
		XSF_ReturnOK,
		XSF_ReturnCancel,
		XSF_ReturnAbort,
		XSF_ReturnRetry,
		XSF_ReturnIgnore,
		XSF_ReturnYes,
		XSF_ReturnNo,
		XSF_ReturnTryAgain,
		XSF_ReturnContinue,
	};
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
		XSF_MOUSE_MIDDLE,
		XSF_MOUSE_BLCLK
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
	struct XSF_Image {
		IWICBitmap* Bitmap = nullptr;
		float width = 0;
		float height = 0;
	};
	struct XSF_Render {
		ID2D1Factory* Factory = nullptr;
		ID2D1HwndRenderTarget* RT = nullptr;
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
	void XSF_LoadImage(std::wstring fp, float width, float height, XSF_Image& Image);
	void XSF_DrawImage(XSF_Image Image, float x, float y, XSF_Render& render);
	void XSF_SetColor(COLORREF color);
	void XSF_UnLoadImage(XSF_Image& Image);
	void XSF_PlayWAV(std::wstring fp, bool l);
	void XSF_StopSound();
	void XSF_DrawText(std::wstring text, int x, int y, struct XSF_Window& window);
	void XSF_SetFont(std::wstring font);
	void XSF_DestroyFont();
	void XSF_DoubleBufferBegin(struct XSF_Window& window);
	void XSF_DoubleBufferFlip(struct XSF_Window& window);
	void XSF_Image_Init(); 
	void XSF_Image_UnInit();
	void XSF_Render_Init(XSF_Window window, XSF_Render& render);
	int XSF_MessageBox(std::optional<XSF_Window>& window, std::wstring text, std::wstring caption, int message_type, int language);
}