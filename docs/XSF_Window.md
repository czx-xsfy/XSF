[返回索引](docs.md)

# XSF_Window

结构体签名：
```
struct XSF_Window {
  int length;
  int height;
  std::wstring name;
  HWND hwnd;
  HDC hMemDC;
  HBITMAP hbmp;
  HBITMAP holdbmp;
  bool UBD;
};
```

字段说明：
- length, height：窗口客户区尺寸（像素）。
- name：窗口标题（宽字符串）。
- hwnd：Win32 窗口句柄（HWND）。
- hMemDC：双缓冲时的内存设备上下文（HDC），若未启用则为 nullptr。
- hbmp：用于双缓冲的兼容位图句柄。
- holdbmp：双缓冲期间保存的原始位图句柄（用于恢复）。
- UBD：是否已开启双缓冲（1 已启用，0 未启用）。

使用场景：该结构由窗口创建/管理函数返回/填充，传入绘图函数以指定绘图目标。

