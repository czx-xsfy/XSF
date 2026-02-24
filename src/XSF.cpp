#include "pch.h"
#include "framework.h"
#include "XSF.h"
namespace XSF {
	COLORREF g_DCR = RGB(0, 0, 0);
	void XSF_Window_Init() {
		WNDCLASS windowc = { 0 };
		windowc.lpfnWndProc = XSF_WindowProc;
		windowc.hInstance = GetModuleHandle(NULL);
		windowc.lpszClassName = L"WindowC";
		RegisterClass(&windowc);
	}
	void XSF_Window_Create(int length, int height, std::wstring name, struct XSF_Window& window) {
		window.length = length;
		window.height = height;
		window.name = name;
		window.hwnd = CreateWindowEx(0, L"WindowC", window.name.c_str(), WS_OVERLAPPEDWINDOW, 50, 50, 50 + window.length, 50 + window.height, NULL, NULL, GetModuleHandle(NULL), NULL);
		ShowWindow(window.hwnd, SW_SHOW);
		UpdateWindow(window.hwnd);
	}
	void XSF_Window_Modify(int length, int height, struct XSF_Window& window) {
		window.length = length;
		window.height = height;
		if (window.hwnd != NULL)
		{
			SetWindowPos(window.hwnd, NULL, 50, 50, 50 + window.length, 50 + window.height, SWP_NOZORDER | SWP_SHOWWINDOW);
		}

	}
	void XSF_Window_Close(struct XSF_Window& window) {
		if (window.hMemDC != nullptr&&window.UBD) {
			SelectObject(window.hMemDC, window.holdbmp);
			DeleteObject(window.hbmp);
			DeleteDC(window.hMemDC);
		}
		DestroyWindow(window.hwnd);
	}
	struct XSF_Event g_event;
	LRESULT CALLBACK XSF_WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		g_event.hwnd = hWnd;
		switch (msg)
		{
		case WM_LBUTTONDOWN:
			g_event.type = XSF_EVENT_MOUSE_DOWN;
			g_event.mousex = LOWORD(lParam);
			g_event.mousey = HIWORD(lParam);
			g_event.mouse = XSF_MOUSE_LEFT;
			break;
		case WM_RBUTTONDOWN:
			g_event.type = XSF_EVENT_MOUSE_DOWN;
			g_event.mousex = LOWORD(lParam);
			g_event.mousey = HIWORD(lParam);
			g_event.mouse = XSF_MOUSE_RIGHT;
			break;
		case WM_MBUTTONDOWN:
			g_event.type = XSF_EVENT_MOUSE_DOWN;
			g_event.mousex = LOWORD(lParam);
			g_event.mousey = HIWORD(lParam);
			g_event.mouse = XSF_MOUSE_MIDDLE;
			break;
		case WM_LBUTTONUP:
			g_event.type = XSF_EVENT_MOUSE_UP;
			g_event.mousex = LOWORD(lParam);
			g_event.mousey = HIWORD(lParam);
			g_event.mouse = XSF_MOUSE_LEFT;
			break;
		case WM_RBUTTONUP:
			g_event.type = XSF_EVENT_MOUSE_UP;
			g_event.mousex = LOWORD(lParam);
			g_event.mousey = HIWORD(lParam);
			g_event.mouse = XSF_MOUSE_RIGHT;
			break;
		case WM_MBUTTONUP:
			g_event.type = XSF_EVENT_MOUSE_UP;
			g_event.mousex = LOWORD(lParam);
			g_event.mousey = HIWORD(lParam);
			g_event.mouse = XSF_MOUSE_MIDDLE;
			break;
		case WM_MOUSEMOVE:
			g_event.type = XSF_EVENT_MOUSE_MOVE;
			g_event.mousex = LOWORD(lParam);
			g_event.mousey = HIWORD(lParam);
			break;
		case WM_KEYDOWN:
			g_event.type = XSF_EVENT_KEY_DOWN;
			switch (wParam)
			{
			case VK_ESCAPE:
				g_event.key = XSF_KEY_ESC;
				break;
			case 'A':
				g_event.key = XSF_KEY_A;
				break;
			case 'B':
				g_event.key = XSF_KEY_B;
				break;
			case 'C':
				g_event.key = XSF_KEY_C;
				break;
			case 'D':
				g_event.key = XSF_KEY_D;
				break;
			case 'E':
				g_event.key = XSF_KEY_E;
				break;
			case 'F':
				g_event.key = XSF_KEY_F;
				break;
			case 'G':
				g_event.key = XSF_KEY_G;
				break;
			case 'H':
				g_event.key = XSF_KEY_H;
				break;
			case 'I':
				g_event.key = XSF_KEY_I;
				break;
			case 'J':
				g_event.key = XSF_KEY_J;
				break;
			case 'K':
				g_event.key = XSF_KEY_K;
				break;
			case 'L':
				g_event.key = XSF_KEY_L;
				break;
			case 'M':
				g_event.key = XSF_KEY_M;
				break;
			case 'N':
				g_event.key = XSF_KEY_N;
				break;
			case 'O':
				g_event.key = XSF_KEY_O;
				break;
			case 'P':
				g_event.key = XSF_KEY_P;
				break;
			case 'Q':
				g_event.key = XSF_KEY_Q;
				break;
			case 'R':
				g_event.key = XSF_KEY_R;
				break;
			case 'S':
				g_event.key = XSF_KEY_S;
				break;
			case 'T':
				g_event.key = XSF_KEY_T;
				break;
			case 'U':
				g_event.key = XSF_KEY_U;
				break;
			case 'V':
				g_event.key = XSF_KEY_V;
				break;
			case 'W':
				g_event.key = XSF_KEY_W;
				break;
			case 'X':
				g_event.key = XSF_KEY_X;
				break;
			case 'Y':
				g_event.key = XSF_KEY_Y;
				break;
			case 'Z':
				g_event.key = XSF_KEY_Z;
				break;
			case '0':
				g_event.key = XSF_KEY_0;
				break;
			case '1':
				g_event.key = XSF_KEY_1;
				break;
			case '2':
				g_event.key = XSF_KEY_2;
				break;
			case '3':
				g_event.key = XSF_KEY_3;
				break;
			case '4':
				g_event.key = XSF_KEY_4;
				break;
			case '5':
				g_event.key = XSF_KEY_5;
				break;
			case '6':
				g_event.key = XSF_KEY_6;
				break;
			case '7':
				g_event.key = XSF_KEY_7;
				break;
			case '8':
				g_event.key = XSF_KEY_8;
				break;
			case '9':
				g_event.key = XSF_KEY_9;
				break;
			case VK_SPACE:
				g_event.key = XSF_KEY_SPACE;
				break;
			case VK_UP:
				g_event.key = XSF_KEY_UP;
				break;
			case VK_DOWN:
				g_event.key = XSF_KEY_DOWN;
				break;
			case VK_LEFT:
				g_event.key = XSF_KEY_LEFT;
				break;
			case VK_RIGHT:
				g_event.key = XSF_KEY_RIGHT;
				break;
			case VK_F1:
				g_event.key = XSF_KEY_F1;
				break;
			case VK_F2:
				g_event.key = XSF_KEY_F2;
				break;
			case VK_F3:
				g_event.key = XSF_KEY_F3;
				break;
			case VK_F4:
				g_event.key = XSF_KEY_F4;
				break;
			case VK_F5:
				g_event.key = XSF_KEY_F5;
				break;
			case VK_F6:
				g_event.key = XSF_KEY_F6;
				break;
			case VK_F7:
				g_event.key = XSF_KEY_F7;
				break;
			case VK_F8:
				g_event.key = XSF_KEY_F8;
				break;
			case VK_F9:
				g_event.key = XSF_KEY_F9;
				break;
			case VK_F10:
				g_event.key = XSF_KEY_F10;
				break;
			case VK_F11:
				g_event.key = XSF_KEY_F11;
				break;
			case VK_F12:
				g_event.key = XSF_KEY_F12;
				break;
			case VK_OEM_COMMA:
				g_event.key = XSF_KEY_COMMA;
				break;
			case VK_OEM_PERIOD:
				g_event.key = XSF_KEY_PERIOD;
				break;
			case VK_OEM_2:
				g_event.key = XSF_KEY_SLASH;
				break;
			case VK_OEM_5:
				g_event.key = XSF_KEY_BACKSLASH;
				break;
			case VK_OEM_1:
				g_event.key = XSF_KEY_SEMICOLON;
				break;
			case VK_OEM_7:
				g_event.key = XSF_KEY_APOSTROPHE;
				break;
			case VK_OEM_3:
				g_event.key = XSF_KEY_GRAVE;
				break;
			case VK_OEM_PLUS:
				g_event.key = XSF_KEY_EQUALS;
				break;
			case VK_OEM_MINUS:
				g_event.key = XSF_KEY_MINUS;
				break;
			case VK_TAB:
				g_event.key = XSF_KEY_TAB;
				break;
			case VK_CAPITAL:
				g_event.key = XSF_KEY_CAPS_LOCK;
				break;
			case VK_RETURN:
				g_event.key = XSF_KEY_ENTER;
				break;
			case VK_BACK:
				g_event.key = XSF_KEY_BACKSPACE;
				break;
			case VK_LSHIFT:
				g_event.key = XSF_KEY_LEFT_SHIFT;
				break;
			case VK_RSHIFT:
				g_event.key = XSF_KEY_RIGHT_SHIFT;
				break;
			case VK_LCONTROL:
				g_event.key = XSF_KEY_LEFT_CTRL;
				break;
			case VK_RCONTROL:
				g_event.key = XSF_KEY_RIGHT_CTRL;
				break;
			case VK_LMENU:
				g_event.key = XSF_KEY_LEFT_ALT;
				break;
			case VK_RMENU:
				g_event.key = XSF_KEY_RIGHT_ALT;
				break;
			case VK_DELETE:
				g_event.key = XSF_KEY_DELETE;
				break;
			case VK_LWIN:
				g_event.key = XSF_KEY_LEFT_SUPER;
				break;
			case VK_RWIN:
				g_event.key = XSF_KEY_RIGHT_SUPER;
				break;
			default:
				g_event.key = XSF_KEY_NONE;
				break;
			}
			break;
			case WM_KEYUP:
				g_event.type = XSF_EVENT_KEY_UP;
				switch (wParam)
				{
				case VK_ESCAPE:
					g_event.key = XSF_KEY_ESC;
					break;
				case 'A':
					g_event.key = XSF_KEY_A;
					break;
				case 'B':
					g_event.key = XSF_KEY_B;
					break;
				case 'C':
					g_event.key = XSF_KEY_C;
					break;
				case 'D':
					g_event.key = XSF_KEY_D;
					break;
				case 'E':
					g_event.key = XSF_KEY_E;
					break;
				case 'F':
					g_event.key = XSF_KEY_F;
					break;
				case 'G':
					g_event.key = XSF_KEY_G;
					break;
				case 'H':
					g_event.key = XSF_KEY_H;
					break;
				case 'I':
					g_event.key = XSF_KEY_I;
					break;
				case 'J':
					g_event.key = XSF_KEY_J;
					break;
				case 'K':
					g_event.key = XSF_KEY_K;
					break;
				case 'L':
					g_event.key = XSF_KEY_L;
					break;
				case 'M':
					g_event.key = XSF_KEY_M;
					break;
				case 'N':
					g_event.key = XSF_KEY_N;
					break;
				case 'O':
					g_event.key = XSF_KEY_O;
					break;
				case 'P':
					g_event.key = XSF_KEY_P;
					break;
				case 'Q':
					g_event.key = XSF_KEY_Q;
					break;
				case 'R':
					g_event.key = XSF_KEY_R;
					break;
				case 'S':
					g_event.key = XSF_KEY_S;
					break;
				case 'T':
					g_event.key = XSF_KEY_T;
					break;
				case 'U':
					g_event.key = XSF_KEY_U;
					break;
				case 'V':
					g_event.key = XSF_KEY_V;
					break;
				case 'W':
					g_event.key = XSF_KEY_W;
					break;
				case 'X':
					g_event.key = XSF_KEY_X;
					break;
				case 'Y':
					g_event.key = XSF_KEY_Y;
					break;
				case 'Z':
					g_event.key = XSF_KEY_Z;
					break;
				case '0':
					g_event.key = XSF_KEY_0;
					break;
				case '1':
					g_event.key = XSF_KEY_1;
					break;
				case '2':
					g_event.key = XSF_KEY_2;
					break;
				case '3':
					g_event.key = XSF_KEY_3;
					break;
				case '4':
					g_event.key = XSF_KEY_4;
					break;
				case '5':
					g_event.key = XSF_KEY_5;
					break;
				case '6':
					g_event.key = XSF_KEY_6;
					break;
				case '7':
					g_event.key = XSF_KEY_7;
					break;
				case '8':
					g_event.key = XSF_KEY_8;
					break;
				case '9':
					g_event.key = XSF_KEY_9;
					break;
				case VK_SPACE:
					g_event.key = XSF_KEY_SPACE;
					break;
				case VK_UP:
					g_event.key = XSF_KEY_UP;
					break;
				case VK_DOWN:
					g_event.key = XSF_KEY_DOWN;
					break;
				case VK_LEFT:
					g_event.key = XSF_KEY_LEFT;
					break;
				case VK_RIGHT:
					g_event.key = XSF_KEY_RIGHT;
					break;
				case VK_F1:
					g_event.key = XSF_KEY_F1;
					break;
				case VK_F2:
					g_event.key = XSF_KEY_F2;
					break;
				case VK_F3:
					g_event.key = XSF_KEY_F3;
					break;
				case VK_F4:
					g_event.key = XSF_KEY_F4;
					break;
				case VK_F5:
					g_event.key = XSF_KEY_F5;
					break;
				case VK_F6:
					g_event.key = XSF_KEY_F6;
					break;
				case VK_F7:
					g_event.key = XSF_KEY_F7;
					break;
				case VK_F8:
					g_event.key = XSF_KEY_F8;
					break;
				case VK_F9:
					g_event.key = XSF_KEY_F9;
					break;
				case VK_F10:
					g_event.key = XSF_KEY_F10;
					break;
				case VK_F11:
					g_event.key = XSF_KEY_F11;
					break;
				case VK_F12:
					g_event.key = XSF_KEY_F12;
					break;
				case VK_OEM_COMMA:
					g_event.key = XSF_KEY_COMMA;
					break;
				case VK_OEM_PERIOD:
					g_event.key = XSF_KEY_PERIOD;
					break;
				case VK_OEM_2:
					g_event.key = XSF_KEY_SLASH;
					break;
				case VK_OEM_5:
					g_event.key = XSF_KEY_BACKSLASH;
					break;
				case VK_OEM_1:
					g_event.key = XSF_KEY_SEMICOLON;
					break;
				case VK_OEM_7:
					g_event.key = XSF_KEY_APOSTROPHE;
					break;
				case VK_OEM_3:
					g_event.key = XSF_KEY_GRAVE;
					break;
				case VK_OEM_PLUS:
					g_event.key = XSF_KEY_EQUALS;
					break;
				case VK_OEM_MINUS:
					g_event.key = XSF_KEY_MINUS;
					break;
				case VK_TAB:
					g_event.key = XSF_KEY_TAB;
					break;
				case VK_CAPITAL:
					g_event.key = XSF_KEY_CAPS_LOCK;
					break;
				case VK_RETURN:
					g_event.key = XSF_KEY_ENTER;
					break;
				case VK_BACK:
					g_event.key = XSF_KEY_BACKSPACE;
					break;
				case VK_LSHIFT:
					g_event.key = XSF_KEY_LEFT_SHIFT;
					break;
				case VK_RSHIFT:
					g_event.key = XSF_KEY_RIGHT_SHIFT;
					break;
				case VK_LCONTROL:
					g_event.key = XSF_KEY_LEFT_CTRL;
					break;
				case VK_RCONTROL:
					g_event.key = XSF_KEY_RIGHT_CTRL;
					break;
				case VK_LMENU:
					g_event.key = XSF_KEY_LEFT_ALT;
					break;
				case VK_RMENU:
					g_event.key = XSF_KEY_RIGHT_ALT;
					break;
				case VK_DELETE:
					g_event.key = XSF_KEY_DELETE;
					break;
				case VK_LWIN:
					g_event.key = XSF_KEY_LEFT_SUPER;
					break;
				case VK_RWIN:
					g_event.key = XSF_KEY_RIGHT_SUPER;
					break;
				default:
					g_event.key = XSF_KEY_NONE;
					break;
				}
				break;
		case WM_CLOSE:
			g_event.type = XSF_EVENT_CLOSE;
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		case WM_PAINT:
			ValidateRect(hWnd, NULL);
			break;
		default:
			break;
		}
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	bool XSF_PollEvent(struct XSF_Event& event) {
		g_event.type = XSF_EventType::XSF_EVENT_NONE;
		g_event.key = XSF_Key::XSF_KEY_NONE;
		g_event.mouse = XSF_MouseButton::XSF_MOUSE_NONE;
		if (PeekMessage(&g_event.msg, NULL, 0, 0,PM_REMOVE)) {
			if (g_event.msg.message != WM_QUIT) {
				TranslateMessage(&g_event.msg);
				DispatchMessage(&g_event.msg);
			}
		}
		if (g_event.type != XSF_EventType::XSF_EVENT_NONE && g_event.hwnd != nullptr) {
			event = g_event;
			return true;
		}
		return false;
	}
	void XSF_DrawRect(int x1, int y1, int x2, int y2, struct XSF_Window& window) {
		if (window.hwnd != nullptr) {
			HDC dc = window.UBD ? window.hMemDC : GetDC(window.hwnd);
			HPEN hNewPen = CreatePen(PS_SOLID, 2, g_DCR);
			HPEN hOldPen = (HPEN)SelectObject(dc, hNewPen);
			Rectangle(dc, x1, y1, x2, y2);
			SelectObject(dc, hOldPen);
			DeleteObject(hNewPen);
			if (!window.UBD) {
				ReleaseDC(window.hwnd, dc);
			}
		}
	}
	void XSF_DrawSolidRect(int x1, int y1, int x2, int y2, struct XSF_Window& window) {
		if (window.hwnd != nullptr) {
			HDC dc = window.UBD ? window.hMemDC : GetDC(window.hwnd);
			HPEN hNewPen = CreatePen(PS_SOLID, 2, g_DCR);
			HPEN hOldPen = (HPEN)SelectObject(dc, hNewPen);
			HBRUSH hBlackBrush = CreateSolidBrush(g_DCR);
			HBRUSH hOldBrush = (HBRUSH)SelectObject(dc, hBlackBrush);
			Rectangle(dc, x1, y1, x2, y2);
			SelectObject(dc, hOldPen);
			DeleteObject(hNewPen);
			SelectObject(dc, hOldBrush);
			DeleteObject(hBlackBrush);
			if (!window.UBD) {
				ReleaseDC(window.hwnd, dc);
			}
		}
	}
	void XSF_DrawCircle(int x, int y, int r, XSF_Window& window) {
		if (window.hwnd != nullptr) {
			HDC dc = window.UBD ? window.hMemDC : GetDC(window.hwnd);
			HPEN hNewPen = CreatePen(PS_SOLID, 2, g_DCR);
			HPEN hOldPen = (HPEN)SelectObject(dc, hNewPen);
			Ellipse(dc, x, y, x + 2 * r, y + 2 * r);
			SelectObject(dc, hOldPen);
			DeleteObject(hNewPen);
			if (!window.UBD) {
				ReleaseDC(window.hwnd, dc);
			}
		}
	}
	void XSF_DrawSolidCircle(int x, int y, int r, XSF_Window& window) {
		if (window.hwnd != nullptr) {
			HDC dc = window.UBD ? window.hMemDC : GetDC(window.hwnd);
			HPEN hNewPen = CreatePen(PS_SOLID, 2, g_DCR);
			HPEN hOldPen = (HPEN)SelectObject(dc, hNewPen);
			HBRUSH hNewBrush = CreateSolidBrush(g_DCR);
			HBRUSH hOldBrush = (HBRUSH)SelectObject(dc, hNewBrush);
			Ellipse(dc, x, y, x + 2 * r, y + 2 * r);
			SelectObject(dc, hOldPen);
			DeleteObject(hNewPen);
			SelectObject(dc, hOldBrush);
			DeleteObject(hNewBrush);
			if (!window.UBD) {
				ReleaseDC(window.hwnd, dc);
			}
		}
	}
	void XSF_DrawLine(int x1, int y1, int x2, int y2, struct XSF_Window& window) {
		if (window.hwnd != nullptr) {
			HDC dc = window.UBD ? window.hMemDC : GetDC(window.hwnd);
			HPEN hNewPen = CreatePen(PS_SOLID, 2, g_DCR);
			HPEN hOldPen = (HPEN)SelectObject(dc, hNewPen);
			MoveToEx(dc, x1, y1, NULL);
			LineTo(dc, x2, y2);
			SelectObject(dc, hOldPen);
			DeleteObject(hNewPen);
			if (!window.UBD) {
				ReleaseDC(window.hwnd, dc);
			}
		}
	}
	void XSF_DrawEllipse(int x, int y, int rx, int ry, XSF_Window& window) {
		if (window.hwnd != nullptr) {
			HDC dc = window.UBD ? window.hMemDC : GetDC(window.hwnd);
			HPEN hNewPen = CreatePen(PS_SOLID, 2, g_DCR);
			HPEN hOldPen = (HPEN)SelectObject(dc, hNewPen);
			Ellipse(dc, x, y, x + 2 * rx, y + 2 * ry);
			SelectObject(dc, hOldPen);
			DeleteObject(hNewPen);
			if (!window.UBD) {
				ReleaseDC(window.hwnd, dc);
			}
		}
	}
	void XSF_DrawSolidEllipse(int x, int y, int rx, int ry, XSF_Window& window) {
		if (window.hwnd != nullptr) {
			HDC dc = window.UBD ? window.hMemDC : GetDC(window.hwnd);
			HPEN hNewPen = CreatePen(PS_SOLID, 2, g_DCR);
			HPEN hOldPen = (HPEN)SelectObject(dc, hNewPen);
			HBRUSH hNewBrush = CreateSolidBrush(g_DCR);
			HBRUSH hOldBrush = (HBRUSH)SelectObject(dc, hNewBrush);
			Ellipse(dc, x, y, x + 2 * rx, y + 2 * ry);
			SelectObject(dc, hOldPen);
			DeleteObject(hNewPen);
			SelectObject(dc, hOldBrush);
			DeleteObject(hNewBrush);
			if (!window.UBD) {
				ReleaseDC(window.hwnd, dc);
			}
		}
	}
	void XSF_DrawPolygon(POINT* points, int n, struct XSF_Window& window) {
		if (window.hwnd != nullptr) {
			HDC dc = window.UBD ? window.hMemDC : GetDC(window.hwnd);
			HPEN hNewPen = CreatePen(PS_SOLID, 2, g_DCR);
			HPEN hOldPen = (HPEN)SelectObject(dc, hNewPen);
			Polygon(dc, points, n);
			SelectObject(dc, hOldPen);
			DeleteObject(hNewPen);
			if (!window.UBD) {
				ReleaseDC(window.hwnd, dc);
			}
		}
	}
	void XSF_DrawSolidPolygon(POINT* points, int n, struct XSF_Window& window) {
		if (window.hwnd != nullptr) {
			HDC dc = window.UBD ? window.hMemDC : GetDC(window.hwnd);
			HPEN hNewPen = CreatePen(PS_SOLID, 2, g_DCR);
			HPEN hOldPen = (HPEN)SelectObject(dc, hNewPen);
			HBRUSH hNewBrush = CreateSolidBrush(g_DCR);
			HBRUSH hOldBrush = (HBRUSH)SelectObject(dc, hNewBrush);
			Polygon(dc, points, n);
			SelectObject(dc, hOldBrush);
			DeleteObject(hNewBrush);
			SelectObject(dc, hOldPen);
			DeleteObject(hNewPen);
			if (!window.UBD) {
				ReleaseDC(window.hwnd, dc);
			}
		}
	}
	void XSF_ClearDraw(struct XSF_Window& window) {
		if (window.hwnd != nullptr) {
			HDC dc = window.UBD ? window.hMemDC : GetDC(window.hwnd);
			HBRUSH hNewBrush = CreateSolidBrush(RGB(255,255,255));
			HBRUSH hOldBrush = (HBRUSH)SelectObject(dc, hNewBrush);
			RECT clientRect;
			GetClientRect(window.hwnd, &clientRect);
			FillRect(dc, &clientRect, hNewBrush);
			SelectObject(dc, hOldBrush);
			DeleteObject(hNewBrush);
			if (!window.UBD) {
				ReleaseDC(window.hwnd, dc);
			}
		}
	}
	HBITMAP XSF_LoadBMP(const WCHAR* fp,int x,int y) {
		HBITMAP hBmp = (HBITMAP)LoadImage(NULL,fp,IMAGE_BITMAP,x,y,LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		return hBmp;
	}
	void XSF_DrawBMP(struct XSF_Window& window, HBITMAP hBmp, int x, int y) {
		if(window.hwnd != nullptr){
			HDC dc = window.UBD ? window.hMemDC : GetDC(window.hwnd);
			HDC hMemDC = CreateCompatibleDC(dc);
			HBITMAP hOldBmp = (HBITMAP)SelectObject(hMemDC, hBmp);
			BITMAP img;
			GetObject(hBmp, sizeof(BITMAP), &img);
			int w = img.bmWidth;
			int h = img.bmHeight;
			BitBlt(dc,x,y,w,h,hMemDC,0,0,SRCCOPY);
			SelectObject(hMemDC, hOldBmp);
			DeleteDC(hMemDC);
			if (!window.UBD) {
				ReleaseDC(window.hwnd, dc);
			}
		}
	}
	void XSF_SetColor(COLORREF color) {
		g_DCR = color;
	}
	void XSF_UnLoadBMP(HBITMAP hBmp[], int s) {
		if (hBmp != nullptr && s > 0) {
			for (int i = 0; i < s; i++) {
				DeleteObject(hBmp[i]);
			}
		}
	}
	void XSF_PlayWAV(const WCHAR* fp, bool l) {
		if (l) {
			PlaySound(fp, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		}
		else {
			PlaySound(fp, NULL, SND_FILENAME | SND_ASYNC);
		}
	}
	void XSF_StopSound() {
		PlaySound(NULL, NULL, SND_PURGE);
	}
	void XSF_DrawText(const WCHAR* text, int x, int y,struct XSF_Window& window) {
		if (window.hwnd != nullptr) {
			HDC dc = window.UBD ? window.hMemDC : GetDC(window.hwnd);
			COLORREF oldColor = SetTextColor(dc, g_DCR);
			TextOut(dc, x, y, text, lstrlen(text));
			SetTextColor(dc, oldColor);
			if (!window.UBD) {
				ReleaseDC(window.hwnd, dc);
			}
		}
	}
	void XSF_DoubleBufferBegin(struct XSF_Window& window) {
		RECT clientRect;
		GetClientRect(window.hwnd, &clientRect);
		HDC hdc = GetDC(window.hwnd);
		window.hMemDC = CreateCompatibleDC(hdc);
		int width = clientRect.right - clientRect.left;
		int height = clientRect.bottom - clientRect.top;
		window.hbmp = CreateCompatibleBitmap(hdc, width, height);
		window.holdbmp = (HBITMAP)SelectObject(window.hMemDC, window.hbmp);
		ReleaseDC(window.hwnd, hdc);
		window.UBD = 1;
		XSF_ClearDraw(window);
		XSF_DoubleBufferFlip(window);
	}
	void XSF_DoubleBufferFlip(struct XSF_Window& window) {
		RECT clientRect;
		GetClientRect(window.hwnd, &clientRect);
		HDC hdc = GetDC(window.hwnd);
		int width = clientRect.right - clientRect.left;
		int height = clientRect.bottom - clientRect.top;
		BitBlt(hdc,0, 0,width, height,window.hMemDC,0, 0,SRCCOPY);
		ReleaseDC(window.hwnd, hdc);
	}
}
