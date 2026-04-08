[返回索引](docs.md)

# XSF_DrawRect

签名:
```
void XSF_DrawRect(int x1, int y1, int x2, int y2, XSF_Window& window)
```

说明：绘制空心矩形。根据 window.UBD 决定绘制目标（内存 DC 或窗口 DC）。

示例：
```cpp
XSF_DrawRect(10,10,200,100,w);
```

