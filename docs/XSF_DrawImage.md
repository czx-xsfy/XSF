[返回索引](docs.md)

# XSF_DrawImage

签名:
```
void XSF_DrawImage(XSF_Image Image, float x, float y, XSF_Render& render)
```

说明：在 D2D 渲染目标上绘制由 XSF_LoadImage 加载的图片。需要先对 render 调用 XSF_Render_Init。

示例：
```cpp
XSF_DrawImage(img, 10.0f, 10.0f, render);
```

