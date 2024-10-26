## 库编译
./config
make

如果安装到linux上
sudo make install

可以提前配置路径
./config --prefix=/path/to/custom/installation/directory
make
make install

版本验证
curl --version

指定openssl库时
./configure --with-ssl=/path/to/openssl
使用cmake时
cmake -DOPENSSL_ROOT_DIR=/usr/local/openssl -DOPENSSL_LIBRARIES=/usr/local/openssl/lib ..


绑定证书时
./configure --with-ca-bundle=/path/to/ca-bundle.crt


## 使用库编译