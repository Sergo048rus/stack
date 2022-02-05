//
// Created by osipo on 05.02.2022.
//

#include "stack_use_c.h"

bool compareInterval(f_stack_t i1, f_stack_t i2)
{
    return (i1.stack > i2.stack);
}

std::vector<std::string> stack_use_c::split(const std::string &s, char delim)
{
    std::stringstream ss(s);
    std::string item;
    std::vector<std::string> elems;
    while (std::getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}

stack_use_c::stack_use_c(std::vector<std::string> file_path)
{
    this -> file_path = file_path;
}
void stack_use_c::printResult(print_i &print_result)
{
    print_result.printStackUse(stack);
}


void stack_use_c::parseFiles()
{
    int count = 0;
    std::string t;

    std::vector<std::string> f_name;
    std::cout<<"Количество файлов: "<< file_path.size() << std::endl;
    for (std::vector<std::string>::const_iterator i = file_path.begin(); i != file_path.end(); ++i)
    {
        file_su.open(*i);
        if(!file_su) // если файл не был открыт
        {
            std::cout<<"Ошибка, не удается открыть файл: "<< *i << std::endl;
        }
        else
        {
            while(file_su)
            {
                f_stack_t buffer_v;
                std::vector<std::string> spl;


                getline(file_su, t);
                spl = split(t, '\t');

                count++;
                if (spl.size() == 3)
                {
                    f_name = split(spl[0], ':');
                    if (f_name.size() >= 4)
                    {
                        buffer_v.func = "";
                        for(uint32_t k = 3; k < f_name.size(); k++)
                        {
                            buffer_v.func += f_name[k];
                        }
                    }

                    std::istringstream iss (spl[1], std::istringstream::in);
                    iss >> buffer_v.stack;

                    stack.push_back(buffer_v);
                }
            }
            file_su.close();
        }
    }
    sort(stack.begin(), stack.end(), compareInterval);
}

