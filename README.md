# XSF — 轻量多媒体窗口库

面向 Windows 的轻量级 C++ 图形与多媒体窗口库，提供窗口管理、双缓冲绘图、基本图形/文本绘制、图片加载与 WAV 播放、以及键盘/鼠标事件轮询。适合快速开发小型图形化工具与教学示例。

## 目录结构

```
XSF/
├─ docs/           # 文档资料（可选）
├─ example/        # 示例程序
├─ include/        # 对外头文件（XSF.h）
├─ lib/            # 编译产物（Debug/Release）
├─ src/            # 源代码实现（XSF.cpp）
├─ LICENSE         # BSD-3-Clause 许可
└─ README.md       # 本文件
```

## 快速开始
1) 在项目中添加包含目录：`XSF/include`，并链接 `XSF.lib`（或将 XSF 源直接加入工程）。

2) 最小示例：

```cpp
#include "XSF.h"
using namespace XSF;

int main(){
    XSF_Init();
    XSF_Window w;
    XSF_Window_Create(800,600,L"XSF 示例", w);

    XSF_Event ev;
    while(true){
        while(XSF_PollEvent(ev)){
            if(ev.type==XSF_EVENT_CLOSE) goto _exit;
        }
        XSF_DoubleBufferBegin(w);
        // 绘制示例
        XSF_SetColor(RGB(255,0,0));
        XSF_DrawRect(10,10,200,100,w);
        XSF_DrawText(L"Hello XSF", 20, 20, w);
        XSF_DoubleBufferFlip(w);
    }
_exit:
    XSF_Window_Close(w);
    XSF_UnInit();
    return 0;
}
```

详细 API 参考请见 docs/index.html

## API 概览（位于 include/XSF.h）

主要类型：
- XSF::XSF_Window — 窗口与双缓冲句柄集合
- XSF::XSF_Event — 事件结构（键盘 / 鼠标 / 关闭）
- XSF::XSF_Image — 图片句柄（IWICBitmap）
- XSF::XSF_Render — D2D 渲染目标封装

主要函数：
- XSF_Init(), XSF_UnInit() — 全局初始化/反初始化
- XSF_Window_Init() — 窗口系统初始化
- XSF_Window_Create/Modify/Close — 窗口管理
- XSF_PollEvent(XSF_Event&) — 轮询事件
- XSF_DoubleBufferBegin/XSF_DoubleBufferFlip — 双缓冲操作
- 绘图：XSF_DrawRect / XSF_DrawSolidRect / XSF_DrawCircle / XSF_DrawSolidCircle / XSF_DrawLine / XSF_DrawEllipse / XSF_DrawSolidEllipse / XSF_DrawPolygon / XSF_DrawSolidPolygon
- 图像：XSF_LoadImage(const WCHAR* fp, float width, float height, XSF_Image& Image) / XSF_DrawImage(XSF_Image Image, float x, float y, XSF_Render& render) / XSF_UnLoadImage(XSF_Image& Image)
- 音频：XSF_PlayWAV(const WCHAR* fp, bool loop) / XSF_StopSound()
- 文本：XSF_DrawText(const WCHAR* text, int x, int y, XSF_Window& window)
- 颜色：XSF_SetColor(COLORREF color)
- 渲染初始化：XSF_Render_Init(XSF_Window window, XSF_Render& render)

详见 include/XSF.h 中的函数与枚举（如 XSF_EventType、XSF_Key、XSF_MouseButton）。

## 构建（简要）
- Visual Studio：新建 Win32/Windows 桌面项目，配置 x64 平台，添加 include 目录并链接 d2d1.lib、winmm.lib 和 XSF.lib。
- MinGW：将 src/ 下代码编译为静态库并链接所需系统库（视 MinGW 环境而定）。

## 示例与调试
- example/ 中包含若干示例程序，建议先编译并运行以熟悉接口。

## 许可
本项目采用 BSD-3-Clause 许可证（详见 LICENSE）。


---
如需更详细的 API 文档或把 README 转为 docs/ 下的更完整文档，可再提要求.
