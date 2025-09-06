
# 进程、线程、锁、原子操作、信号通知

---

## 锁

### 1. 手动操作

```cpp
mtx.lock();
mtx.unlock(); // std::mutex 的成员函数
```

- 手动控制：需要显式调用 lock()/unlock()。
- 异常安全：异常时需保证解锁，推荐 try-catch 或 lock_guard。
- 资源管理：开发者需自己管理锁，易出错。

---

### 2. 自动锁

```cpp
std::unique_lock<std::mutex> lock(mtx); // 作用域锁定
std::lock_guard<std::mutex> guard(mtx); // 自动释放锁
```

- unique_lock 可手动加解锁，lock_guard 只自动释放。

---

### 3. wait 等待

- wait 执行时会释放所有锁，直到条件满足（返回 true）才重新获取锁。
- std::lock_guard<std::mutex> lock(mtx); 获取锁保护作用区。
- 与 wait 配合时，锁状态不影响 wait 执行。

```cpp
cv.wait(lock, []{ return is_ready; }); // 条件变量等待
cv.notify_all(); // 唤醒所有等待线程
```

- 锁被其他线程占用，wait 阻塞，notify 后或 wait_for 超时再继续。
- 锁被释放，条件满足，继续执行。

---

## 线程

- 分离线程：

```cpp
t1.detach(); // 分离
if (t2.joinable()) {
    t2.join(); // 等待线程结束
}
```

- 注册信号 signal：
    - 注册后主线程会等待所有线程执行完。
    - 不注册，主线程退出，其他线程立即死亡。
