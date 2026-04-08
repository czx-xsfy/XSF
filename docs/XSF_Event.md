[返回索引](docs.md)

# XSF_Event

结构体签名：
```
struct XSF_Event {
  XSF_EventType type;
  XSF_Key key;
  XSF_MouseButton mouse;
  int mousex;
  int mousey;
  MSG msg;
  HWND hwnd;
};
```

字段说明：
- type：事件类型（XSF_EventType 枚举，如 XSF_EVENT_CLOSE、XSF_EVENT_KEY_DOWN、XSF_EVENT_MOUSE_MOVE 等）。
- key：键盘按键（XSF_Key 枚举）。
- mouse：鼠标按键（XSF_MouseButton 枚举）。
- mousex, mousey：鼠标坐标（相对于窗口客户区）。
- msg：底层 Win32 MSG 结构，包含完整消息元数据。
- hwnd：触发事件的窗口句柄。

说明：XSF_PollEvent 将填充并返回该结构的实例。

