// Copyright 2016 Baidu Inc. All Rights Reserved.
// Author: ludong zhou (zhouludong@baidu.com)
//
// int类型解析类定义

#include "int_parser.h"

namespace wp{

int IntParser::parse(const std::string &word){
    if(word == ""){
        std::cerr << "Error: empty string" << std::endl;
        std::cerr << "Error: can not parse from empty string to int" << std::endl;
        return 1;
    }
    int begin_index = word.find(':');
    if(begin_index == std::string::npos){
        begin_index = 0;
    }
    else{
        begin_index += 1;
    }

    std::string data = word.substr(begin_index, word.length() - begin_index);
    std::vector<std::string> elements = Utility::_s_split(data, ',');
    
    if(elements.size() != 1 && begin_index == 0){
        std::cerr << "Error: multi-elements in a single string, type: int" << std::endl;
        return 1;
    }


    for(std::vector<std::string>::iterator iter = elements.begin(); iter != elements.end(); iter++){
	    std::string ele = *iter;

        char *ptr = NULL;
        errno = 0;
        int temp = (int) strtol(ele.c_str(), &ptr, 10);

        if (*ptr != '\0') {
            std::cerr << "Error: can not parse from" << ele << "to int" << std::endl;
            return 1;
        }

        if (errno == ERANGE || temp > INT_MAX || temp < INT_MIN) {
            std::cerr << "Error: out of range from" << ele << "to int" << std::endl;
            return 1;
        }

        result.push_back(temp);
    }
    return 0;
}

std::string IntParser::to_string(){
    std::string ans;
    for(std::vector<int>::iterator iter = result.begin(); iter != result.end(); iter++){
	    int ele = *iter;
	    std::stringstream ss;
	    ss << ele;
        ans += ss.str() + ' ';
    }
    return ans;
}

DerivedRegister<IntParser> IntParser::reg("int");
}
