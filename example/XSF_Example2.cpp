#include"XSF.h"
using namespace XSF;
bool g_lb = 0;
bool win = 0;
int main() {
    XSF_Window window;
    XSF_Window window2;
    XSF_Event event;
    XSF_Window_Init();
    XSF_Window_Create(800, 600, L"²âÊÔ´°¿Ú", window);
	XSF_Window_Create(400, 300, L"²âÊÔ´°¿Ú2", window2);
    XSF_DoubleBufferBegin(window);
	XSF_DoubleBufferBegin(window2);
    bool running = true;
    int x = 75, y = 75;
    XSF_DrawSolidRect(50, 50, 100, 100, window);
    XSF_DrawRect(300, 300, 350, 350, window);
    XSF_DoubleBufferFlip(window);
    while (running) {
        while (XSF_PollEvent(event)) {
            switch (event.type) {
            case XSF_EVENT_MOUSE_DOWN:
                switch (event.mouse) {
                case XSF_MOUSE_LEFT:
                    g_lb = 1;
                    break;
                }
                break;
            case XSF_EVENT_MOUSE_MOVE:
                if (event.hwnd == window.hwnd) {
                    if (g_lb && !win) {
                        x = event.mousex;
                        y = event.mousey;
                        XSF_ClearDraw(window);
                        XSF_DrawSolidRect(x - 25, y - 25, x + 25, y + 25, window);
                        XSF_DrawRect(300, 300, 350, 350, window);
                        if (x <= 350 && x >= 300 && y >= 300 && y <= 350) {
                            win = 1;
                            XSF_ClearDraw(window);
                            XSF_DrawText(L"win!", 390, 290, window);
                            XSF_DrawText(L"°´Enter¼ü½áÊø. . .", 350, 310, window);
                        }
                    }
                }
                else if (event.hwnd == window2.hwnd) {
                    XSF_DrawSolidRect(50, 50, 100, 200, window2);
                }
                break;
            case XSF_EVENT_MOUSE_UP:
                switch (event.mouse) {
                case XSF_MOUSE_LEFT:
                    g_lb = 0;
                    break;
                }
                break;
            case XSF_EVENT_CLOSE:
                running = false;
                break;
            case XSF_EVENT_KEY_DOWN:
                switch (event.key) {
                case XSF_KEY_ENTER:
                    if (win) {
                        running = false;
                    }
                    break;
                }
            }
            XSF_DoubleBufferFlip(window);
            XSF_DoubleBufferFlip(window2);
        }
    }
    XSF_Window_Close(window);
	XSF_Window_Close(window2);
    return 0;
}