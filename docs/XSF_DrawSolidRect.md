[返回索引](docs.md)

# XSF_DrawSolidRect

签名:
```
void XSF_DrawSolidRect(int x1, int y1, int x2, int y2, XSF_Window& window)
```

说明：绘制实心矩形，使用当前全局颜色（XSF_SetColor 设置）。

示例：
```cpp
XSF_SetColor(RGB(0,255,0));
XSF_DrawSolidRect(20,20,120,80,w);
```

