// Copyright 2016 Baidu Inc. All Rights Reserved.
// Author: ludong zhou (zhouludong@baidu.com)
//
// 词表解析读取工具类声明

#ifndef WORD_TABLE_H
#define WORD_TABLE_H

#include "factory.h"

namespace wp{

class WordTable{
public:
    WordTable(){ _index = 0; };

    virtual ~WordTable(){};

    std::vector<std::string> get_types(){ return types; }

    std::vector<std::string> get_content(){ return content; }

    //std::vector<CommonParser*> get_row();

    int get_row(std::vector<CommonParser*> &row_result);

    std::string get_type(int column){ return types[column]; };

    void set_types(std::vector<std::string> types){ this->types = types; }

    void set_content(std::vector<std::string> content){ this->content = content; }

private:
    std::vector<std::string> types;

    std::vector<std::string> content;

    int _index;
};
}
#endif // WORD_TABLE_H
