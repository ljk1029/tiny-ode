
CC = gcc
CFLAGS = -Wall -g

MD5_SRC = test_md5.c my_md5.c
MD5_TARGET = test_md5

SHA256_SRC = test_sha256.c my_sha256.c
SHA256_TARGET = test_sha256

all: $(MD5_TARGET) $(SHA256_TARGET)

$(MD5_TARGET): $(MD5_SRC)
	$(CC) $(CFLAGS) -o $(MD5_TARGET) $(MD5_SRC)

$(SHA256_TARGET): $(SHA256_SRC)
	$(CC) $(CFLAGS) -o $(SHA256_TARGET) $(SHA256_SRC)

clean:
	rm -f $(MD5_TARGET) $(SHA256_TARGET)