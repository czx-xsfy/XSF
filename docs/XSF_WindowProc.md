[返回索引](docs.md)

# XSF_WindowProc

签名:
```
LRESULT CALLBACK XSF_WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
```

说明：窗口过程回调，内部将 Win32 消息转换为 XSF_Event 并写入全局 g_event。通常不直接调用，但可参考其处理逻辑实现自定义窗口行为。

示例：此函数由系统调用，无需用户直接调用。

