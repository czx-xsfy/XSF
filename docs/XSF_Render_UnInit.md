[返回索引](docs.md)

# XSF_Render_UnInit

签名:
```
void XSF_Render_UnInit(XSF_Render& render)
```

说明：释放 render 中的 RT 与 Factory，避免 COM 对象泄漏。

示例：
```cpp
XSF_Render_UnInit(render);
```

