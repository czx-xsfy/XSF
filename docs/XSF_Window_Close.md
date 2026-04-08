[返回索引](docs.md)

# XSF_Window_Close

签名:
```
void XSF_Window_Close(XSF_Window& window)
```

说明：关闭窗口并释放与双缓冲相关的 HDC/HBITMAP。如果 window.UBD 为 true，会恢复旧位图并删除内存 DC。

示例：
```cpp
XSF_Window_Close(w);
```

