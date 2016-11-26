// Copyright 2016 Baidu Inc. All Rights Reserved.
// Author: ludong zhou (zhouludong@baidu.com)
//
// �ʱ��ļ����ݶ�ȡ����������ȡ�ʱ����ݺ���Ӧ�����Ͳ�����

#ifndef PARSER_DRIVER_H
#define PARSER_DRIVER_H

#include "utility.h"

namespace wp{

class ParserDriver{
public:
    ParserDriver(){};

    virtual ~ParserDriver(){};

    std::vector<std::string> get_types(std::string file_path);

    int set_type(std::string file_path, int column, std::string type);

    std::vector<std::string> get_content(std::string file_path);

};
}
#endif // PARSER_DRIVER_H
