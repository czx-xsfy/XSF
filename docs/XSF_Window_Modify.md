[返回索引](docs.md)

# XSF_Window_Modify

签名:
```
void XSF_Window_Modify(int length, int height, XSF_Window& window)
```

说明：修改已创建窗口的大小并更新内部记录；若 window.hwnd 为 NULL 则不执行窗口定位。

示例：
```cpp
XSF_Window_Modify(1024, 768, w);
```

