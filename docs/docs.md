# XSF 核心功能清单
## 一、窗口管理模块
| 接口名称 | 功能描述 | 关键说明 |
|----------|----------|----------|
| `XSF_Window_Init()` | 初始化窗口模块 | 全局必须调用1次，用于注册窗口类等底层准备 |
| `XSF_Window_Create(int length, int height, std::wstring name, XSF_Window& window)` | 创建多媒体窗口 | 传入窗口宽高、标题，输出初始化后的窗口对象；自动创建双缓冲绘图环境 |
| `XSF_Window_Modify(int length, int height, XSF_Window& window)` | 调整窗口尺寸 | 动态修改已创建窗口的宽高，同步更新双缓冲缓冲区大小 |
| `XSF_Window_Close(XSF_Window& window)` | 关闭窗口并释放资源 | 释放窗口句柄、内存DC、位图等底层资源，避免内存泄漏 |

## 二、双缓冲绘图模块
| 接口名称 | 功能描述 | 使用规范 |
|----------|----------|----------|
| `XSF_DoubleBufferBegin(XSF_Window& window)` | 开始双缓冲绘图 | 所有绘图操作前必须调用，切换至后台缓冲区（避免闪烁） |
| `XSF_DoubleBufferFlip(XSF_Window& window)` | 提交绘图内容 | 所有绘图完成后调用，将后台缓冲区内容刷新到屏幕 |
| `XSF_ClearDraw(XSF_Window& window)` | 清空绘图区域 | 可选，用于场景切换或重绘前清除画布残留内容 |

## 三、图形绘制模块
| 接口名称 | 功能描述 | 参数说明 |
|----------|----------|----------|
| `XSF_SetColor(COLORREF color)` | 设置绘图颜色 | 支持 `RGB()` 宏定义颜色（例：`RGB(255,0,0)` 为红色），全局生效 |
| `XSF_DrawLine(int x1, int y1, int x2, int y2, XSF_Window& window)` | 绘制空心直线 | (x1,y1)：起点坐标；(x2,y2)：终点坐标 |
| `XSF_DrawRect(int x1, int y1, int x2, int y2, XSF_Window& window)` | 绘制空心矩形 | (x1,y1)：左上角坐标；(x2,y2)：右下角坐标 |
| `XSF_DrawSolidRect(int x1, int y1, int x2, int y2, XSF_Window& window)` | 绘制实心矩形 | 参数同空心矩形，填充颜色为当前设置的绘图颜色 |
| `XSF_DrawCircle(int x, int y, int r, XSF_Window& window)` | 绘制空心圆形 | (x,y)：圆心坐标；r：半径 |
| `XSF_DrawSolidCircle(int x, int y, int r, XSF_Window& window)` | 绘制实心圆形 | 参数同空心圆形，填充颜色为当前设置的绘图颜色 |
| `XSF_DrawEllipse(int x, int y, int rx, int ry, XSF_Window& window)` | 绘制空心椭圆 | (x,y)：中心坐标；rx：水平半径；ry：垂直半径 |
| `XSF_DrawSolidEllipse(int x, int y, int rx, int ry, XSF_Window& window)` | 绘制实心椭圆 | 参数同空心椭圆，填充颜色为当前设置的绘图颜色 |
| `XSF_DrawPolygon(POINT* points, int n, XSF_Window& window)` | 绘制空心多边形 | points：顶点坐标数组；n：顶点数量（需≥3） |
| `XSF_DrawSolidPolygon(POINT* points, int n, XSF_Window& window)` | 绘制实心多边形 | 参数同空心多边形，填充颜色为当前设置的绘图颜色 |

## 四、资源操作模块
| 接口名称 | 功能描述 | 参数说明 |
|----------|----------|----------|
| `XSF_LoadBMP(const WCHAR* fp, int x, int y)` | 加载BMP图片 | fp：宽字符格式的图片路径（例：`L"res/image.bmp"`）；x/y：预留绘制位置 |
| `XSF_DrawBMP(XSF_Window& window, HBITMAP hBmp, int x, int y)` | 绘制BMP图片 | hBmp：`XSF_LoadBMP` 返回的图片句柄；x/y：图片左上角绘制坐标 |
| `XSF_UnLoadBMP(HBITMAP hBmp[], int s)` | 释放BMP资源 | hBmp：图片句柄数组；s：数组长度（需与加载的图片数量一致） |
| `XSF_PlayWAV(const WCHAR* fp, bool l)` | 播放WAV音频 | fp：宽字符格式的音频路径；l：是否循环播放（true=循环，false=单次） |
| `XSF_StopSound()` | 停止音频播放 | 停止所有正在播放的WAV音频 |

## 五、文本绘制模块
| 接口名称 | 功能描述 | 参数说明 |
|----------|----------|----------|
| `XSF_DrawText(const WCHAR* text, int x, int y, XSF_Window& window)` | 绘制文本 | text：宽字符格式文本（例：`L"Hello XSF"`）；x/y：文本左上角坐标 |

## 六、事件响应模块
### 1. 枚举类型（事件/按键/鼠标定义）
| 枚举名称 | 包含项 | 功能说明 |
|----------|--------|----------|
| `XSF_EventType` | `XSF_EVENT_CLOSE`（窗口关闭）、`XSF_EVENT_KEY_DOWN/UP`（键盘按下/松开）、`XSF_EVENT_MOUSE_DOWN/UP/MOVE`（鼠标按下/松开/移动）等 | 定义所有支持的事件类型 |
| `XSF_Key` | 字母（A-Z）、数字（0-9）、方向键、功能键（F1-F12）、控制键（Ctrl/Alt/Shift等） | 定义所有支持的键盘按键 |
| `XSF_MouseButton` | `XSF_MOUSE_LEFT`（左键）、`XSF_MOUSE_RIGHT`（右键）、`XSF_MOUSE_MIDDLE`（中键） | 定义支持的鼠标按键 |

### 2. 事件接口
| 接口名称 | 功能描述 | 使用说明 |
|----------|----------|----------|
| `XSF_Event_Init(XSF_Window& window)` | 初始化事件模块 | 窗口创建后调用，用于启用事件监听 |
| `XSF_PollEvent(XSF_Event& event)` | 轮询获取事件 | 主循环中持续调用，返回当前触发的事件；`event` 结构体包含事件类型、按键/鼠标信息、坐标等 |

### 3. 事件结构体（`XSF_Event`）关键成员
- `type`：事件类型（`XSF_EventType` 枚举）
- `key`：触发事件的键盘按键（仅键盘事件有效）
- `mouse`：触发事件的鼠标按键（仅鼠标事件有效）
- `mousex/mousey`：鼠标坐标（仅鼠标事件有效）
- `window`：触发事件的窗口对象