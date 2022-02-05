//
// Created by osipo on 05.02.2022.
//

#ifndef UNTITLED1_PRINT_RESULT_C_H
#define UNTITLED1_PRINT_RESULT_C_H

#include <string>
#include <iostream>
#include <vector>
#include "format.h"
#include <fstream>
#include <iomanip>

class print_i
{
public:
    void virtual printStackUse(std::vector<f_stack_t> data) = 0;
};



class print_result_c : public print_i
{
public:

    void printStackUse(std::vector<f_stack_t> data) override;


};

class print_result_file_c : public print_i
{
private:
    std::string out_file_path;
public:

    void printStackUse(std::vector<f_stack_t> data) override;

    void config(std::string out_file_path)
    {
        this -> out_file_path = out_file_path;
    }
};



#endif //UNTITLED1_PRINT_RESULT_C_H
