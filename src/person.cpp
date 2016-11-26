// Copyright 2016 Baidu Inc. All Rights Reserved.
// Author: ludong zhou (zhouludong@baidu.com)
//
// �û��Զ������;�����Person����

#include "person.h"

namespace wp{

int wp::Person::parse(const std::string &word){
    if(word == ""){
        std::cerr << "Error: empty string" << std::endl;
        std::cerr << "Error: can not parse from empty string to person" << std::endl;
        return 1;
    }

    std::vector<std::string> elements;
    std::stringstream ss(word);
    std::string item;
    while (getline(ss, item, '|')){
        elements.push_back(item);
    }
    if(elements.size() != 2){
        std::cerr << "Error: Person missing element" << std::endl;
    }
    else{
        if (elements[0] == "" ){
            std::cerr << "Error: empty person name" << std::endl;
            return 1;
        }
        this->name = elements[0];
        std::string ele = elements[1];

        char *ptr = NULL;
        errno = 0;
        int temp = (int) strtol(ele.c_str(), &ptr, 10);

        if (*ptr != '\0') {
            std::cerr << "Error: can not parse from" << ele << "to int" << std::endl;
            return 1;
        }

        if (errno == ERANGE || temp > 200 || temp < 0) {
            std::cerr << "Error: age out of range: " << temp << std::endl;
            return 1;
        }

        this->age = temp;

    }
    return 0;
}

std::string Person::to_string(){
    std::stringstream ss;
    ss << age;
    return "Name: " + name + "; Age: " + ss.str() + '.';
}
}
