[返回索引](docs.md)

# XSF_Render_Init

签名:
```
void XSF_Render_Init(XSF_Window window, XSF_Render& render)
```

说明：创建 D2D Factory 并基于 window.hwnd 创建 HwndRenderTarget，保存到 render 结构中以用于 XSF_DrawImage 等 D2D 绘制函数。

示例：
```cpp
XSF_Render render;
XSF_Render_Init(w, render);
```

