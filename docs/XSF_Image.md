[返回索引](docs.md)

# XSF_Image

结构体签名：
```
struct XSF_Image {
  IWICBitmap* Bitmap;
  float width;
  float height;
};
```

字段说明：
- Bitmap：IWICBitmap*，WIC 解码并存储的位图资源句柄（需在 UnLoad 时 Release）。
- width, height：图像逻辑宽高（像素），由加载/缩放逻辑设置。

说明：通过 XSF_LoadImage 加载并填充该结构，通过 XSF_DrawImage 在 XSF_Render 上渲染。

