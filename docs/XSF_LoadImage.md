[返回索引](docs.md)

# XSF_LoadImage

签名:
```
void XSF_LoadImage(std::wstring fp, float width, float height, XSF_Image& Image)
```

说明：使用 WIC 解码并转换为 IWICBitmap（32bpp PBGRA），并根据 width/height 参数设置 Image.width/height（0 表示使用原始尺寸）。

示例：
```cpp
XSF_Image img;
XSF_LoadImage(L"res/pic.png", 0, 0, img);
```

