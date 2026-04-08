[返回索引](docs.md)

# XSF_Window_Create

签名:
```
void XSF_Window_Create(int length, int height, std::wstring name, XSF_Window& window)
```

说明：创建并显示一个窗口，设置 window 的长度、高度与 hwnd。

参数：
- length, height：客户区宽高（像素）
- name：窗口标题（宽字符串）
- window：输出窗口对象

示例：
```cpp
XSF_Window w;
XSF_Window_Create(800, 600, L"示例", w);
```

