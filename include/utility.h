// Copyright 2016 Baidu Inc. All Rights Reserved.
// Author: ludong zhou (zhouludong@baidu.com)
//
// 通用函数定义，按照设定分隔符分割字符串

#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <map>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cerrno>

namespace wp{

class Utility{

public:
    Utility(){};

    static std::vector<std::string> _s_split(const std::string &s, char delim){
        std::stringstream ss(s);
        std::string item;
        std::vector<std::string> tokens;

        while (getline(ss, item, delim)){
            tokens.push_back(item);
        }

        return tokens;
    }
};
}
#endif // UTILITY_H
