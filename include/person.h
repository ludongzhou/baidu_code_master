// Copyright 2016 Baidu Inc. All Rights Reserved.
// Author: ludong zhou (zhouludong@baidu.com)
//
// �û��Զ������;�����Person����

#ifndef PERSON_H
#define PERSON_H

#include "factory.h"
#include "utility.h"
#include <cstdlib>

namespace wp{

class Person{
public:
    Person(){};

    Person(std::string person_name, int person_age): name(person_name), age(person_age){};

    virtual ~Person(){};

    virtual int parse(const std::string &word);

    std::string to_string();

private:
    std::string name;
    int age;
};
}

#endif // PERSON_H
