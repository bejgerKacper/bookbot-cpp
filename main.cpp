#include <fstream>
#include <iostream>

std::vector<std::string> tokenise(std::string txt_line, std::string separator)
{
    std::vector<std::string> tokens;
    std::string token;
    signed int start, end;
    start = txt_line.find_first_not_of(separator, 0);
    do
    {
        end = txt_line.find_first_of(separator, start);
        if(start == txt_line.length() || start == end) break;
        if(end >= 0) token = txt_line.substr(start, end - start);
        else token = txt_line.substr(start, txt_line.length() - start);
        tokens.push_back(token);
        start = end + 1;
      // find_first_not_of returns std::string::npos
    } while (end != std::string::npos);
    return tokens;
}

std::string get_line_txt(std::ifstream txt_file)
{
    std::string txt_line;
    while(std::getline(txt_file, txt_line))
    {
        std::cout << txt_line << std::endl;
    }
    return txt_line;
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
    std::vector<std::string> tokens = tokenise(line, " ");
    return 0;
}