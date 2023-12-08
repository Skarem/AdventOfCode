#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

#include "days.hpp"

int day2()
{
    int sum = 0;
    std::vector<std::pair<std::string, int>> dict = 
    {
        {"one",     1},
        {"two",     2},
        {"three",   3},
        {"four",    4},
        {"five",    5},
        {"six",     6},
        {"seven",   7},
        {"eight",   8},
        {"nine",    9}
    };

    std::ifstream input_file;
    std::string input_path = "../Inputs/";
    input_file.open(input_path + "day2.txt");

    if (input_file.is_open())
    {
        std::string input_line;
        std::vector<std::string> input;
        int line = 1;

        while (std::getline(input_file, input_line))
        {
            std::vector<std::pair<int, int>> numbers;

            // Go throught normal numbers
            for (int i = 0; i < input_line.length(); i++)
            {
                if (input_line[i] >= '0' && input_line[i] <= '9')
                {
                    numbers.push_back(std::make_pair(i, input_line[i] - '0'));
                }
            }

            // Go through letter numbers
            for (auto num : dict)
            {
                for (int i = 0; i < input_line.length() - num.first.length() + 1; i++)
                {
                    if (num.first == input_line.substr(i, num.first.length()))
                    {
                        numbers.push_back(std::make_pair(i, num.second));
                    }
                }
            }

            std::sort(numbers.begin(), numbers.end());

            int first, last;
            bool first_time = true;

            for (auto &num : numbers)
            {
                if (first_time)
                {
                    first = num.second;
                    first_time = false;
                }
                last = num.second;
            }
            sum += first * 10 + last;
        }
        input_file.close();
    }
    else 
    {
        std::cerr << "Error opening file" << std::endl;
    }
    return sum;
}