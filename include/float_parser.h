// Copyright 2016 Baidu Inc. All Rights Reserved.
// Author: ludong zhou (zhouludong@baidu.com)
//
// float类型解析类声明

#ifndef FLOAT_PARSER_H
#define FLOAT_PARSER_H

#include "common_parser.h"
#include "factory.h"
#include <cstdlib>

namespace wp{

class FloatParser : public CommonParser{
public:
    FloatParser(){};

    virtual ~FloatParser(){};

    virtual int parse(const std::string &word);

    virtual std::string to_string();

private:
    static DerivedRegister<FloatParser> reg;

    std::vector<float> result;
};
}
#endif // FLOATPARSER_H
