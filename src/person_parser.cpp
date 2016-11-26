// Copyright 2016 Baidu Inc. All Rights Reserved.
// Author: ludong zhou (zhouludong@baidu.com)
//
// �û��Զ������ͽ����ࣺPersonParser����

#include "person_parser.h"

namespace wp{

std::string PersonParser::to_string(){
    std::string ans;
    for(std::vector<wp::Person>::iterator iter = result.begin(); iter != result.end(); iter++){
	    wp::Person ele = *iter;
        ans += ele.to_string() + ' ';
    }
    return ans;
}

int PersonParser::parse(const std::string &word){
    if(word == ""){
        std::cerr << "Error: empty string" << std::endl;
        std::cerr << "Error: can not parse from empty string to person" << std::endl;
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
        std::cerr << "Error: multi-elements in a single string, type: person" << std::endl;
        return 1;
    }

    for(std::vector<std::string>::iterator iter = elements.begin(); iter != elements.end(); iter++){
	    std::string ele = *iter;
        Person temp;
        int flag = temp.parse(ele);
        if(flag != 0){
            return 1;
        }
        result.push_back(temp);
    }
    
    return 0;
}

DerivedRegister<PersonParser> PersonParser::reg("person");
}
