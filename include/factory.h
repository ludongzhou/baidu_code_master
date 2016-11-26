// Copyright 2016 Baidu Inc. All Rights Reserved.
// Author: ludong zhou (zhouludong@baidu.com)
//
// C++反射工厂类，根据类名称生成相应的类实例

#ifndef FACTORY_H_INCLUDED
#define FACTORY_H_INCLUDED

#include "common_parser.h"

namespace wp{

template<typename T> CommonParser * createT(){
    return new T;
}

struct BaseFactory{

    typedef std::map<std::string, CommonParser*(*)()> _s_map_type;

    static CommonParser * create_instance(std::string const& s){
        _s_map_type::iterator it = get_map()->find(s);

        if(it == get_map()->end()){
            std::cout << "type not found: " << s << std::endl;
            return 0;
        }

        return it->second();
    }

protected:
    static _s_map_type * get_map(){
        if(!map){
            map = new _s_map_type;
        }
        return map;
    }

private:
    static _s_map_type * map;
};

template<typename T>
struct DerivedRegister : BaseFactory{
    DerivedRegister(std::string const& s){
        get_map()->insert(std::make_pair(s, &createT<T>));
    }
};
}

#endif // FACTORY_H_INCLUDED
