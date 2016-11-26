// Copyright 2016 Baidu Inc. All Rights Reserved.
// Author: ludong zhou (zhouludong@baidu.com)
//
// 词表文件内容读取类定义

#include "parser_driver.h"

namespace wp{

/** \brief 从文档中获取每一列数据的类型
 *
 * \param string 文件地址
 * \return vector<string> 数据类型集合
 *
 */
std::vector<std::string> ParserDriver::get_types(std::string file_path){
    std::ifstream ifs;
    ifs.open(file_path.c_str());
    if(!ifs.is_open()){
        std::cerr << "Error: can not open file, " << file_path << std::endl;
        exit(1);
    }

    std::vector<std::string> types;
    std::string line;
    std::getline(ifs, line, '\n');
    std::istringstream iss(line);
    if(line == ""){
        std::cerr << "Error: no content found" << std::endl;
        exit(2);
    }

    do{
        std::string type;
        iss >> type;
        if(type.length() == 0){
            break;
        }
        types.push_back(type.substr(1, type.length() - 2) );
    }while(iss);

    return types;
}

/** \brief 设置特定列的数据类型
 *
 * \param string 字典文件的位置
 * \param int 列编号，从0开始
 * \param string 列类型
 * \return int 0代表修改成功，其他值表示失败
 *
 */
int ParserDriver::set_type(std::string file_path, int column, std::string newType){
    if(file_path == ""){
        std::cerr << "Error: file path is empty" << std::endl;
        return 1;
    }

    if(newType == ""){
        std::cerr << "Error: new type name is empty" << std::endl;
        return 1;
    }

    std::fstream ifs(file_path.c_str());
    std::string head, line;
    std::getline(ifs, head, '\n');
    std::istringstream iss(head);
    std::vector<std::string> head_vector;

    do{
        std::string type;
        iss >> type;
        if(type.length() == 0){
            break;
        }
        head_vector.push_back(type);
    }while(iss);

    if(head_vector.size() < column || column < 0){
        std::cerr << "Error: column number out of range" << std::endl;
        return 1;
    }

    head_vector[column] = "<" + newType +">";
    std::string new_line = "";
    for(std::vector<std::string>::iterator iter = head_vector.begin();iter != head_vector.end(); iter++){
	    std::string ele = *iter;
        new_line += ele + " ";
    }

    std::ofstream ofs("temp.txt");
    ofs << new_line << std::endl;
    while(std::getline(ifs, line, '\n')){
        line += '\n';
        ofs << line;
    }

    ifs.close();
    ofs.close();
    std::remove(file_path.c_str());
    std::rename("temp.txt", file_path.c_str());
    return 0;
}

/** \brief 获取字典文件中单词的值
 *
 * \param string 字典文件位置
 * \return
 *
 */
std::vector<std::string> ParserDriver::get_content(std::string file_path){
    if(file_path == ""){
        std::cerr << "Error: file path is empty" << std::endl;
        exit(1);
    }

    std::ifstream ifs;
    ifs.open(file_path.c_str());

    if(!ifs.is_open()){
        std::cerr << "Error: can not open file, " << file_path << std::endl;
        exit(1);
    }

    std::vector<std::string> content;
    std::vector<std::string> row;
    std::string dummy, line;
    std::getline(ifs, dummy, '\n');
    while(std::getline(ifs, line, '\n')){
        std::istringstream iss(line);
        row.clear();
        do{
            std::string element;
            iss >> element;
            if(element.length() == 0){
                break;
            }
            row.push_back(element.substr(1, element.size() - 2));
        }while(iss);
        if(row.size() == Utility::_s_split(dummy, ' ').size()){
            content.insert(content.end(), row.begin(), row.end());
        }
    }
    return content;
}
}
