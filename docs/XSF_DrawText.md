[返回索引](docs.md)

# XSF_DrawText

签名:
```
void XSF_DrawText(std::wstring text, int x, int y, XSF_Window& window)
```

说明：在窗口或内存 DC 上绘制文本，使用全局字体句柄 g_hFont（需先调用 XSF_SetFont）。

示例：
```cpp
XSF_SetFont(L"微软雅黑");
XSF_DrawText(L"Hello", 20, 20, w);
```

