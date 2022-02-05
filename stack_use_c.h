//
// Created by osipo on 05.02.2022.
//

#ifndef UNTITLED1_STACK_USE_C_H
#define UNTITLED1_STACK_USE_C_H

#include "print_result_c.h"
#include <fstream>
#include <string>
#include <sstream>
#include "format.h"
#include <bits/stdc++.h>

class stack_use_c
{
private:
    std::vector<f_stack_t> stack;
    std::vector<std::string> file_path;
    std::ifstream file_su;
    std::vector<std::string> split(const std::string &s, char delim);
public:
    stack_use_c(std::vector<std::string>);
    void printResult(print_i &print_result);
    void parseFiles();                              // Обращается к файлам по их пути и добавляет в структуру информацию о используемом стеке





};







#endif //UNTITLED1_STACK_USE_C_H
