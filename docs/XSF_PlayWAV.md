[返回索引](docs.md)

# XSF_PlayWAV

签名:
```
void XSF_PlayWAV(std::wstring fp, bool loop)
```

说明：使用 PlaySound 播放 WAV 文件。loop=true 时使用 SND_LOOP。

示例：
```cpp
XSF_PlayWAV(L"res/sound.wav", false);
```

