[返回索引](docs.md)

# XSF_SetFont

签名:
```
void XSF_SetFont(std::wstring font)
```

说明：创建并设置全局字体 g_hFont（CreateFontW），后续文本绘制将使用该字体。若已创建则不重复创建。

示例：
```cpp
XSF_SetFont(L"微软雅黑");
```

