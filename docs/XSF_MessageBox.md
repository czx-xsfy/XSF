[返回索引](docs.md)

# XSF_MessageBox

签名:
```
int XSF_MessageBox(std::optional<XSF_Window> window, std::wstring text, std::wstring caption, int message_type, int language)
```

说明：MessageBoxEx 的轻量封装，可传入 optional 窗口作为父窗口句柄；返回 MessageBoxEx 的返回码。

示例：
```cpp
int rc = XSF_MessageBox(std::nullopt, L"确认退出？", L"提示", MB_OKCANCEL, XSF_LANG_SYSTEM);
```

