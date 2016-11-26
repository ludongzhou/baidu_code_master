// Copyright 2016 Baidu Inc. All Rights Reserved.
// Author: ludong zhou (zhouludong@baidu.com)
//
// �ʱ��ļ����ݶ�ȡ�ඨ��

#include "parser_driver.h"

namespace wp{

/** \brief ���ĵ��л�ȡÿһ�����ݵ�����
 *
 * \param string �ļ���ַ
 * \return vector<string> �������ͼ���
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

/** \brief �����ض��е���������
 *
 * \param string �ֵ��ļ���λ��
 * \param int �б�ţ���0��ʼ
 * \param string ������
 * \return int 0�����޸ĳɹ�������ֵ��ʾʧ��
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

/** \brief ��ȡ�ֵ��ļ��е��ʵ�ֵ
 *
 * \param string �ֵ��ļ�λ��
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
