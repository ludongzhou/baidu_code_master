// Copyright 2016 Baidu Inc. All Rights Reserved.
// Author: ludong zhou (zhouludong@baidu.com)
//
// int类型解析类声明

#ifndef INT_PARSER_H
#define INT_PARSER_H

#include "common_parser.h"
#include "factory.h"

namespace wp{

class IntParser : public CommonParser{
public:
    IntParser(){};

    virtual ~IntParser(){};

    virtual int parse(const std::string &word);

    virtual std::string to_string();

private:
    static DerivedRegister<IntParser> reg;
    
    std::vector<int> result;
};
}
#endif // INT_PARSER_H
