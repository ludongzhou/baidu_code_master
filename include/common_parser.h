// Copyright 2016 Baidu Inc. All Rights Reserved.
// Author: ludong zhou (zhouludong@baidu.com)
//
// 解析器公共类，各种类型的解析器继承自此类

#ifndef COMMON_PARSER_H
#define COMMON_PARSER_H

#include "utility.h"

namespace wp{

class CommonParser{

public:
    CommonParser() {};

    virtual ~CommonParser() {};

    virtual std::string to_string();

    virtual int parse(const std::string &word);

};

}

#endif // COMMONPARSER_H
