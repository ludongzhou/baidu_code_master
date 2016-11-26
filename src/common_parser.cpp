// Copyright 2016 Baidu Inc. All Rights Reserved.
// Author: ludong zhou (zhouludong@baidu.com)
//
// 解析器公共类，各种类型的解析器继承自此类

#include "common_parser.h"

namespace wp{

std::string CommonParser::to_string(){
	return "CommonParser: not initialized";
}

int CommonParser::parse(const std::string &word){
	return -1;
}

};