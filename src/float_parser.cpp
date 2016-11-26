// Copyright 2016 Baidu Inc. All Rights Reserved.
// Author: ludong zhou (zhouludong@baidu.com)
//
// float类型解析类定义

#include "float_parser.h"

namespace wp{

int FloatParser::parse(const std::string &word){
    if(word == ""){
        std::cerr << "Error: empty string" << std::endl;
        std::cerr << "Error: can not parse from empty string to float" << std::endl;
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
        std::cerr << "Error: multi-elements in a single string, type: float" << std::endl;
        return 1;
    }
    
    for(std::vector<std::string>::iterator iter = elements.begin(); iter != elements.end(); iter++){
	    std::string ele = *iter;
        char * ptr = NULL;
        errno = 0;
        float temp = strtof(ele.c_str(), &ptr);
        if(*ptr != '\0' or errno == ERANGE){
            std::cerr << "Error: can not parse from" << ele << " to float " << std::endl;
            return 1;
        }
        result.push_back(std::atof(ele.c_str()));
    }

    return 0;
}

std::string FloatParser::to_string(){
    std::string ans;
    std::stringstream ss;
    for(std::vector<float>::iterator iter = result.begin(); iter != result.end();iter++){
	   float ele = *iter;
        ss << std::fixed << std::setprecision(2) << ele;
        ans += ss.str() + " ";
    }
    return ans;
}

DerivedRegister<FloatParser> FloatParser::reg("float");
}
