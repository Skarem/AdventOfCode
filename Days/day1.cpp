#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "days.hpp"

int day1()
{
    int sum = 0;

    std::ifstream input_file;
    std::string input_path = "../Inputs/";
    input_file.open(input_path + "day1.txt");

    if (input_file.is_open())
    {
        std::string input_line;
        std::vector<std::string> input;

        while (std::getline(input_file, input_line))
        {
            char first = 0, last = 0;
            bool first_time = true;

            for (char c : input_line)
            {
                if (c >= '0' && c <= '9')
                {
                    if (first_time)
                    {
                        first = c;
                        first_time = false;
                    }
                    last = c;
                }
            }
            sum += (first - '0') * 10 + (last - '0');
        }
        input_file.close(); 
    }
    else 
    {
        std::cerr << "Error opening file" << std::endl;
    }
    return sum;
}