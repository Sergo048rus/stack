#include <string>
#include <iostream>
#include <filesystem>


#include "search_file_c.h"
#include "stack_use_c.h"


namespace fs = std::filesystem;



int main(int argc, char* argv[])
{
    std::filesystem::path dirPath;
    print_result_c print_result;
    print_result_file_c print_result_file;
    if (argc > 1)
    {
        std::cout <<"Введеный путь: " << argv[1]<<std::endl;
        dirPath = argv[1];
    } else
    {
        std::cout << "Not arguments" << std::endl;
        dirPath =  std::filesystem::current_path();
    }

    std::string extension = ".su";                                                      // Определяем расширение для поиска файлов

    search_file_c search_file(dirPath,extension);

//    search_file.print_file_path();                                                    // Печать путей к файлам

    stack_use_c stack_use(search_file.get_file_path());

    stack_use.parseFiles();
    stack_use.printResult(print_result);                                            // Печать в консоль


    print_result_file.config("C:/Users/osipo/Desktop/Sob/task1/res.txt");
    stack_use.printResult(print_result_file);                                       // Печать в файл

}

//E:\tester\cube\Debug
//C:/Users/osipo/Desktop/Sob/task1