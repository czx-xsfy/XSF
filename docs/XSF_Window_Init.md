[返回索引](docs.md)

# XSF_Window_Init

签名:
```
void XSF_Window_Init()
```

说明：注册窗口类（WindowC）。通常在程序开始时调用一次，用于创建窗口前的类注册（CreateWindowEx 也可在未显式调用时正常工作）。

示例：
```cpp
XSF_Window_Init();
```

