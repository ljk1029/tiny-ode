
## CodeLLDB安装

### 必须编译成Debug模式
    '''
    mkdir build
    cd build
    cmake .. -DCMAKE_BUILD_TYPE=Debug
    cmake --build . --config Debug
    '''

### 验证是否debug
    readelf -S test | grep debug


### vscode配置C++调试环境
    安装 VS Code lldb调试插件CodeLLDB
    安装 VS Code调试插件CMake Tools
    创建调试启动文件
    【Run(Ctrl + Shift + D)】-> 【create a launch.json file】-> 【LLDB】

### launch.json
    '''
    {
        "version": "0.2.0",
        "configurations": [
            {
                "type": "lldb",
                "request": "launch",
                "name": "windows",
                "program": "${workspaceFolder}/build/Debug/test.exe",
                "args": [],
                "cwd": "${workspaceFolder}"
            },
            {
                "type": "lldb",
                "request": "launch",
                "name": "linux",
                "program": "${workspaceFolder}/build/test",
                "args": [],
                "cwd": "${workspaceFolder}"
            }
        ]
    }
    '''






### 参考
    https://blog.csdn.net/itas109/article/details/122677006