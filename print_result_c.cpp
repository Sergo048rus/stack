//
// Created by osipo on 05.02.2022.
//

#include "print_result_c.h"



void print_result_c::printStackUse(std::vector<f_stack_t> data)
{
    f_stack_t buf;
    int count = 0;
    for (std::vector<f_stack_t>::const_iterator i = data.begin(); i != data.end(); ++i)
    {
        count ++;
        buf = *i;
        std::cout  << "Stack use: \t"<< std::setw(10)<< buf.stack <<  "\tF_name:\t" << buf.func << std::endl;
    }
    std::cout<< "Итого: "<< count<<std::endl;
}


void print_result_file_c::printStackUse(std::vector<f_stack_t> data)
{
    std::ofstream fout(out_file_path, std::ios_base::out | std::ios_base::trunc);

    if (!fout) // если файл не был открыт
    {
        std::cout << "Файл не может быть открыт или создан"<<std::endl;

    }
    else
    {
        f_stack_t buf;
        int count = 0;
        for (std::vector<f_stack_t>::const_iterator i = data.begin(); i != data.end(); ++i)
        {
            count ++;
            buf = *i;
            fout  << "Stack use: \t"<< buf.stack <<  "\tF_name:\t" << buf.func << std::endl;
        }
        fout<< "Итого: "<< count<<std::endl;
    }


}