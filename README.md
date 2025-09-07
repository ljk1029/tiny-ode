## 相关依赖仓库
- [curl/curl](https://github.com/curl/curl)
- [openssl/openssl](https://github.com/openssl/openssl)
- [warmcat/libwebsockets](https://github.com/warmcat/libwebsockets)
- [apache/brpc](https://github.com/apache/brpc)
- [FFmpeg/FFmpeg](https://github.com/FFmpeg/FFmpeg)
- [eProsima/Fast-DDS](https://github.com/eProsima/Fast-DDS)
- [foonathan/memory](https://github.com/foonathan/memory)
- [commaai/openpilot](https://github.com/commaai/openpilot)
- [ApolloAuto/apollo](https://github.com/ApolloAuto/apollo)
- [tensorflow/tensorflow](https://github.com/tensorflow/tensorflow)   



## 算法说明

- 树的旋转说明
![image](https://github.com/ljk1029/tiny-ode/blob/main/image/img_tree.png)   

- 排序
![image](https://github.com/ljk1029/tiny-ode/blob/main/iamge/img_sort.png)   


## 结构目录
```
tiny-ode-projects/
├── README.md                  # 仓库说明文档，包含项目介绍和学习路径
├── docs/                      # 学习文档
│   ├── syntax-reference.md    # C/C++语法参考笔记
│   └── algorithm-notes.md     # 算法学习笔记
├── syntax/                    # 语法学习相关代码
│   ├── basic/                 # 基础语法
│   │   ├── variables/         # 变量与数据类型
│   │   ├── control-flow/      # 控制流语句
│   │   └── functions/         # 函数
│   ├── intermediate/          # 中级语法
│   │   ├── pointers/          # 指针
│   │   ├── references/        # 引用
│   │   └── classes/           # 类与对象
│   └── advanced/              # 高级语法
│       ├── templates/         # 模板
│       ├── inheritance/       # 继承与多态
│       └── memory/            # 内存管理
├── algorithms/                # 算法实现
│   ├── basic/                 # 基础算法
│   │   ├── sorting/           # 排序算法
│   │   ├── searching/         # 查找算法
│   │   └── recursion/         # 递归算法
│   ├── data-structures/       # 数据结构实现
│   │   ├── array/             # 数组
│   │   ├── linked-list/       # 链表
│   │   ├── stack/             # 栈
│   │   ├── queue/             # 队列
│   │   ├── tree/              # 树
│   │   └── graph/             # 图
│   └── advanced/              # 高级算法
│       ├── dynamic-programming/ # 动态规划
│       ├── greedy/            # 贪心算法
│       └── backtracking/      # 回溯算法
└── projects/                  # 综合项目
    ├── console-apps/          # 控制台应用
    │   ├── calculator/        # 计算器
    │   └── todo-list/         # 待办事项列表
    └── system-programs/       # 系统相关程序
        ├── file-manager/      # 文件管理器
        └── process-monitor/   # 进程监控器
```

## c++工具
###  gtest 安装
-  1、地址:https://github.com/google/googletest.git

-  2、编译 cmake .. / make

-  3、依赖
  拷贝生成静态库
```
  sudo cp *.a /usr/local/lib
```

  拷贝头文件
```
  sudo cp -r include/gtest /usr/local/include
```

-  4、测试代码编译
  g++ -std=c++17 test.cpp -lgtest -lgtest_main -lpthread


## 提交类型
  - feat:     新功能（feature） 
  - fix:      修补bug  
  - refactor: 重构   
  - update:   更新  