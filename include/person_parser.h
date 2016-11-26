// Copyright 2016 Baidu Inc. All Rights Reserved.
// Author: ludong zhou (zhouludong@baidu.com)
//
// 用户自定义类型解析类：PersonParser声明

#ifndef STRING_PARSER_H
#define STRING_PARSER_H

#include "common_parser.h"
#include "factory.h"
#include "person.h"
#include "utility.h"

namespace wp{

class PersonParser : public CommonParser{
public:
    PersonParser() {};

    virtual ~PersonParser() {};

    virtual int parse(const std::string &word);

    virtual std::string to_string();

private:
    static DerivedRegister<PersonParser> reg;
    
    std::vector<Person> result;
};
}
#endif // STRINGPARSER_H
