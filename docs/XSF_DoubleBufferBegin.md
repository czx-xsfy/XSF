[返回索引](docs.md)

# XSF_DoubleBufferBegin

签名:
```
void XSF_DoubleBufferBegin(XSF_Window& window)
```

说明：创建兼容内存 DC 与位图，设置 window.UBD = true，并清空缓冲。用于避免闪烁的双缓冲绘制流程。

示例：
```cpp
XSF_DoubleBufferBegin(w);
// 绘制...
XSF_DoubleBufferFlip(w);
```

