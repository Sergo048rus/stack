//
// Created by osipo on 05.02.2022.
//

#ifndef UNTITLED1_SEARCH_FILE_C_H
#define UNTITLED1_SEARCH_FILE_C_H

#include <string>
#include <iostream>
#include <filesystem>
#include <stdio.h>
#include <vector>
#include <unistd.h>


namespace fs = std::filesystem;


class search_file_c
{
private:
    std::vector<std::string> files;         // Вектор путей найденных файлов
    std::string extension;
    std::string path;
public:
    search_file_c(std::string path, std::string extension);

    std::vector<std::string> get_file_path();             // Возвращает files
    void print_file_path();                              // Печатает все найденные файлы




};




#endif //UNTITLED1_SEARCH_FILE_C_H
