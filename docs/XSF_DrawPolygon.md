[返回索引](docs.md)

# XSF_DrawPolygon

签名:
```
void XSF_DrawPolygon(POINT* points, int n, XSF_Window& window)
```

说明：绘制多边形，points 为顶点数组，n 为顶点数（>=3）。

示例：
```cpp {% raw %}
POINT pts[3] = {{10,10},{100,10},{50,80}};
XSF_DrawPolygon(pts, 3, w);
```

