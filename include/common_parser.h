// Copyright 2016 Baidu Inc. All Rights Reserved.
// Author: ludong zhou (zhouludong@baidu.com)
//
// �����������࣬�������͵Ľ������̳��Դ���

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
