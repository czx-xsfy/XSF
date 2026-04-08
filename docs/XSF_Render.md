[返回索引](docs.md)

# XSF_Render

结构体签名：
```
struct XSF_Render {
  ID2D1Factory* Factory;
  ID2D1HwndRenderTarget* RT;
};
```

字段说明：
- Factory：D2D 工厂（ID2D1Factory*），用于创建渲染目标等 D2D 对象。
- RT：窗口级渲染目标（ID2D1HwndRenderTarget*），用于使用 Direct2D 绘制位图。

说明：通过 XSF_Render_Init 从 XSF_Window 初始化。调用完毕后请通过 XSF_Render_UnInit 释放内部对象。

