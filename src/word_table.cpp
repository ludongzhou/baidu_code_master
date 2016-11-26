// Copyright 2016 Baidu Inc. All Rights Reserved.
// Author: ludong zhou (zhouludong@baidu.com)
//
// 词表解析读取工具类定义

#include "word_table.h"

namespace wp{

/** \brief 获得字典中的一行数据
 *
 * \return 使用vector存储的一行数据
 *
 */

int WordTable::get_row(std::vector<CommonParser*> &row_result){
    int type_num = types.size();
    //std::vector<CommonParser*> row_result;

    if(_index == content.size()){
        return 0;
    }

    std::vector<std::string> row;
    for(int i = 0; i < type_num; i++){
        row.push_back(this->content[_index++]);
    }

    for(int i = 0; i < type_num; i++){
        CommonParser* common = BaseFactory::create_instance(types[i]);
        if(common == 0){
            std::cerr << "Error: parse failed. type: not found named: " + types[i] << std::endl;

            row_result.clear();
            return 1;
        }
        else{
            int flag = common->parse(row[i]);
            if(flag != 0){
                std::cerr  << "Error: parse failed. type: " + types[i] + " to string: " + row[i] << std::endl;
                
                row_result.clear();
                return 1;
            }
            row_result.push_back(common);
        }
    }
    return 0;
}
}
