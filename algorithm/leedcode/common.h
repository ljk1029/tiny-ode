
#ifndef __COMMON_H_
#define __COMMON_H_

#include <iostream>
#include <iomanip>
#include <vector>


void print_end(char type_line, int cnt = 20) {
    for(int i=0; i<cnt; i++) {
        std::cout << type_line;
    }
    std::cout << std::endl;
}

void print_dbg(std::vector<std::vector<char>>& board) {
    print_end('*');
    for(auto r:board ) {
        for(auto c:r) {
            std::cout << c;
        }
        std::cout << std::endl;
    }
    print_end('-');
}

void print_dbg(std::vector<std::vector<int>>& board) {
    print_end('*');
    for(auto r:board ) {
        for(auto c:r) {
            std::cout << std::setw(4) << c;
        }
        std::cout << std::endl;
    }
    print_end('-');
}

void print_dbg(std::vector<int>& board) {
    print_end('*');
    for(auto c:board) {
        std::cout << std::setw(4) << c;
    }
    std::cout << std::endl;
    print_end('-');
}

void print_dbg(int board) {
    print_end('*');
    std::cout << std::setw(4) << board;
    std::cout << std::endl;
    print_end('-');
}

void print_dbg(std::vector<std::vector<std::string>>& board) {
    print_end('*');
    for(auto r: board) {
       for(auto c: r) {
            std::cout << c << " " ;
       }
       std::cout << std::endl;
    }
    print_end('-');
}

void print_dbg(std::vector<std::string>& board) {
    print_end('*');
    for(auto r: board) {
        std::cout << r << " " ;
    }
    std::cout << std::endl;
    print_end('-');
}

#endif
