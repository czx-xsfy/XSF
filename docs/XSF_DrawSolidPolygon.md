[返回索引](docs.md)

# XSF_DrawSolidPolygon

签名:
```
void XSF_DrawSolidPolygon(POINT* points, int n, XSF_Window& window)
```

说明：绘制填充多边形，使用当前颜色。

示例：
```cpp {% raw %}
POINT pts[4] = {{10,10},{120,10},{120,120},{10,120}};
XSF_DrawSolidPolygon(pts,4,w);
```


