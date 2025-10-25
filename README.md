# XSF
## XSF图形库
### 示例代码
```cpp
#include"XSF.h"
using namespace XSF;
int main() {
    XSF_Window window;
    XSF_Event event;
    XSF_Window_Init();
	XSF_Window_Create(800, 600, L"测试窗口",window);
    XSF_Event_Init(window);
    bool running = true;
    POINT points[4] = { {100,100},{0,200},{100,200} };
    while (running) {
        while (XSF_PollEvent(event)) {
            switch (event.type) {
            case XSF_EVENT_CLOSE: 
                running = false;
                break;
            case XSF_EVENT_KEY_DOWN:
                switch (event.key) {
                case XSF_KEY_ESC:
                    running = false;
                    break;
				case XSF_KEY_A:
                    XSF_DrawRect(50, 50, 100, 100, window);
                    break;
				case XSF_KEY_B:
                    XSF_DrawSolidRect(150, 150, 200, 200, window);
                    break;
				case XSF_KEY_C:
                    XSF_DrawCircle(250, 250, 25, window);
                    break;
				case XSF_KEY_D:
                    XSF_DrawSolidCircle(350, 350, 25, window);
					break;
				case XSF_KEY_E:
                    XSF_ClearDraw(window);
                    break;
                case XSF_KEY_0:
                    XSF_DrawLine(50, 50, 350, 350, window);
                    break;
                case XSF_KEY_1:
                    XSF_SetColor(RGB(0, 0, 255)); 
                    break;
				case XSF_KEY_2:
					XSF_DrawEllipse(400, 100, 50, 25, window);
                    break;
				case XSF_KEY_3:
                    XSF_DrawSolidEllipse(500, 200, 50, 25, window);
					break;
                case XSF_KEY_4:
                    XSF_DrawPolygon(points, 3,window);
                    break;
                case XSF_KEY_5:
                    XSF_DrawSolidPolygon(points, 3,window);
                    break;
                }
            }
        }
    }
	XSF_Window_Close(window);
	return 0;
}
