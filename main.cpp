#include <fstream>
#include <iostream>

std::vector<std::string> tokenise(std::string txt_line, char separator)
{
    std::vector<std::string> tokens;

    

    return tokens;
}

std::string get_line_txt(std::ifstream txt_file)
{
    std::string line;
    while(std::getline(txt_file, line))
    {
        std::cout << line << std::endl;
    }
    return line;
}

std::ifstream open_txt_file(std::string file_path)
{
    std::ifstream txt_file{file_path};
    if(txt_file.is_open())
    {
        std::cout << "File " << file_path << " open" << std::endl;
    }
    else
    {
        std::cout << "Could not open " << file_path << std::endl;
    }
    return txt_file;
}

int main()
{
    std::string file_path = "books/frankenstein.txt";
    std::string line = get_line_txt(open_txt_file(file_path));

    return 0;
}