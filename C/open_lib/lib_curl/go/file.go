package main

import (
    "fmt"
    "io"
    "net/http"
    "os"
)

func downloadFileHandler(w http.ResponseWriter, r *http.Request) {
    // 打开本地文件以供下载
    file, err := os.Open("output.txt")
    if err != nil {
        http.Error(w, "File not found", http.StatusNotFound)
        return
    }
    defer file.Close()

    // 设置响应头，指定文件名
    w.Header().Set("Content-Disposition", "attachment; filename=output.txt")

    // 将文件内容传输给客户端
    _, err = io.Copy(w, file)
    if err != nil {
        http.Error(w, "Internal server error", http.StatusInternalServerError)
        return
    }
}

func main() {
    http.HandleFunc("/download", downloadFileHandler)
    fmt.Println("Server is running on :8080")
	
    // 启动 HTTP 服务器，监听端口 8080
    err := http.ListenAndServe(":8080", nil)
    if err != nil {
        fmt.Println("Error:", err)
    }
}
