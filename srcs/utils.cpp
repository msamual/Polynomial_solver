//
// Created by Sergey Uryashev on 10.03.2022.
//

#include "../includes/Computor.hpp"

void trim(std::string &s)
{
    s.erase(s.find_last_not_of(" \t\n\r\f\v") + 1);
    s.erase(0, s.find_first_not_of(" \t\n\r\f\v"));
}

int puterror(std::string msg)
{
    std::cerr << msg << std::endl;
    exit(0);
}

bool    check_symbols(const std::string &s)
{
    return s.find_first_not_of("0123456789 +*-/=^Xx.") == std::string::npos;
}

std::string remove_spaces(const std::string& str)
{
    std::string result("");

    for(size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] != ' ' && str[i] != '\t')
            result += str[i];
    }
    return result;
}

bool        find_char(const char *str, char c)
{
    while(*str)
    {
        if(*str++ == c)
            return true;
    }
    return false;
}

double      get_coef(const char *str)
{
    std::stringstream ss(str);
    double res;

    ss >> res;
    return res;
}

int         get_power(std::string str)
{
    int res;

    if (str[0] == '*')
        str = str.substr(1);
    if ((str[0] != 'X' && str[0] != 'x') || str[1] != '^'
        || str.find_first_not_of("0123456789", 2) != std::string::npos)
        puterror("incorrect expression[" + str + "]");
    std::stringstream ss(str.substr(2));
    ss >> res;
    return res;
}

double sqrt(const double number)
{
    const double ACCURACY=0.00000001;
    double lower, upper, guess;

    if (number < 1)
    {
        lower = number;
        upper = 1;
    }
    else
    {
        lower = 1;
        upper = number;
    }

    while ((upper-lower) > ACCURACY)
    {
        guess = (lower + upper)/2;
        if(guess*guess > number)
            upper =guess;
        else
            lower = guess;
    }
    return (lower + upper)/2;
}