#gcc -D__KERNEL__ -DMODULE -DLINUX -I /usr/local/src/linux2.4/include -c -o hello.o hello.c
# gcc -D__KERNEL__ -DMODULE -DLINUX -I /usr/src/linux-hwe-5.19-headers-5.19.0-32/include \
#     -c -o hello.o test.c

gcc -Wall -Werror -O2 -o my_module.ko test.c -I /usr/src/linux-hwe-5.19-headers-5.19.0-46/include \
     -I /usr/src/linux-headers-5.19.0-46-generic/arch/x86/include/generated/ \
     -I /usr/src/linux-hwe-5.19-headers-5.19.0-46/arch/x86/include/
