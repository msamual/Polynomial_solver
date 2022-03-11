//
// Created by Sergey Uryashev on 10.03.2022.
//

#ifndef POLYNOMIAL_SOLVER_COMPUTOR_HPP
#define POLYNOMIAL_SOLVER_COMPUTOR_HPP

#include <iostream>
#include <sstream>
#include <map>

#include "Solver.hpp"

void        trim(std::string &s);
int         puterror(std::string msg);
bool        check_symbols(const std::string &s);
std::string remove_spaces(const std::string& str);
bool        find_char(const char *str, char c);
double      get_coef(std::string& str);
int         get_power(std::string str);
double      sqrt(const double number);


#endif //POLYNOMIAL_SOLVER_COMPUTOR_HPP
