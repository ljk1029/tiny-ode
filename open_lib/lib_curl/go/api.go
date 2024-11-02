package main

import (
    "fmt"
    "net/http"
)

func handler(w http.ResponseWriter, r *http.Request) {
	switch r.Method {
	case http.MethodGet:
		// GET
		fmt.Fprintln(w, "处理 GET 请求")
	case http.MethodPost:
		// POST
		fmt.Fprintln(w, "处理 POST 请求")
	default:
		// 处理其他请求
		fmt.Fprintln(w, "不支持的请求方法")
	}
}

func main() {
	// 将 handler 函数与根路径 "/" 绑定 这里是url后面资源定位
    http.HandleFunc("/", handler) 
   
	// 启动 HTTP 服务器，监听端口 8080
    err := http.ListenAndServe(":8080", nil)
    if err != nil {
        fmt.Println("Error:", err)
    }
}
