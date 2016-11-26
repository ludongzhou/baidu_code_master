// Copyright 2016 Baidu Inc. All Rights Reserved.
// Author: ludong zhou (zhouludong@baidu.com)
//
// ×Ö·û´®½âÎöÀàÉùÃ÷

#ifndef STRING_PARSER_H
#define STRING_PARSER_H

#include "common_parser.h"
#include "factory.h"

namespace wp{

class StringParser : public CommonParser{
public:
    StringParser(){};

    virtual ~StringParser(){};

    virtual int parse(const std::string &word);

    std::string to_string();

private:
    static DerivedRegister<StringParser> reg;

    std::vector<std::string> result;
};
}
#endif // STRING_PARSER_H
