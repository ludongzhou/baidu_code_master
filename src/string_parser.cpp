// Copyright 2016 Baidu Inc. All Rights Reserved.
// Author: ludong zhou (zhouludong@baidu.com)
//
// �ַ��������ඨ��

#include "string_parser.h"

namespace wp{
std::string StringParser::to_string(){
    std::string ans;
    for(std::vector<std::string>::iterator iter = result.begin(); iter != result.end(); iter++){
	    std::string ele = *iter;
        ans += ele + ' ';
    }
    return ans;
}

int StringParser::parse(const std::string &word){
    if(word == ""){
        std::cerr << "Error: empty string" << std::endl;
        std::cerr << "Error: can not parse from empty string to string" << std::endl;
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
        std::cerr << "Error: multi-elements in a single string, type: string" << std::endl;
        return 1;
    }
    result = elements;

    return 0;
}

DerivedRegister<StringParser> StringParser::reg("string");
}
