## 库编译
cmake ..
make
make install


添加ssl库选项
使用 -DLWS_WITH_SSL 来启用 OpenSSL 支持，并使用 -DOPENSSL_ROOT_DIR 来指定 OpenSSL 的根目录
cmake -DLWS_WITH_SSL=ON -DOPENSSL_ROOT_DIR=/path/to/openssl ..