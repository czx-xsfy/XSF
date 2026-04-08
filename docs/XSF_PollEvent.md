[返回索引](docs.md)

# XSF_PollEvent

签名:
```
bool XSF_PollEvent(XSF_Event& event)
```

说明：非阻塞轮询事件，内部使用 PeekMessage/TranslateMessage/DispatchMessage。若有事件返回 true 并填充 event。

示例：
```cpp
XSF_Event ev;
while(XSF_PollEvent(ev)){
  // 处理 ev
}
```

