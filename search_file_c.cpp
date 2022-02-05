//
// Created by osipo on 05.02.2022.
//

#include "search_file_c.h"


search_file_c::search_file_c(std::string path, std::string extension)
{
    this -> extension = extension;
    this -> path = path;

    try
    {
        //    std::filesystem::directory_iterator iterator(dirPath);                   // Обработка только текущей директории
        std::filesystem::recursive_directory_iterator iterator(path);               // Рекурсивная обработка директорий, конечно, можно было вынести и как параметр класса

        for (; iterator != std::filesystem::end(iterator); iterator++)
        {
            if (iterator->path().extension() == extension)
            {
                files.push_back(iterator->path().string());
            }
        }
    }
    catch(std::filesystem::filesystem_error const& ex)
    {
        std::cout
            << "what():  " << ex.what() << '\n'
            << "path1(): " << ex.path1() << '\n'
            << "code().message():  " << ex.code().message() << '\n';
    }
}



void search_file_c::print_file_path()
{
    std::cout <<"Выводим список найденых файлов:" << std::endl;

    for (std::vector<std::string>::const_iterator i = files.begin(); i != files.end(); ++i)
    {
        std::cout << *i << std::endl;
    }

}

std::vector<std::string> search_file_c::get_file_path()
{
    return files;
}