#!/bin/bash
# 密钥生产


#生成私钥
openssl genrsa -out ca.key 2048
#提取公钥                                                                                                                                  
openssl rsa -in ca.key -pubout -out ca.pub  