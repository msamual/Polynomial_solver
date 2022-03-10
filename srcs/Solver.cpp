//
// Created by Sergey Uryashev on 10.03.2022.
//

#include "../includes/Solver.hpp"

Solver::Solver() : D(-1)
{}

Solver::Solver(std::string exp)
{
    exp = remove_spaces(exp);
    this->parse(exp.data(), false);
    print_reduced_form();
    this->solve();
}

Solver::Solver(const Solver& other) : odds(other.odds), D(other.D)
{}

Solver& Solver::operator=(const Solver &other)
{
    this->D = other.D;
    this->odds = other.odds;
    return *this;
}

void    Solver::solve()
{
    int a = odds.at(2), b = odds.at(1), c = odds.at(0);


}

void    Solver::parse(const char *exp, bool right)
{
    bool    minus = right;
    int     i = 0;
    double  coef;

    if (strlen(exp) == 0)
        return ;
    if (exp[0] == '-')
        minus = !minus;
    if (exp[0] == '-' || exp[0] == '+')
        ++exp;
    if (find_char("0123456789.", *exp))
        coef = std::stod(exp) * (minus ? -1 : 1);
    else
        coef = 0;
    while (find_char("0123456789.", *exp))
        ++exp;
    if (*exp == '*')
        ++exp;
    if (find_char("Xx", *exp))
    {
        ++exp;
        if (*exp != '^')
            i = 1;
        else if (std::isdigit(*(exp + 1)))
            i = std::stoi(++exp);
        else
            puterror("incorrect syntax near [X^]");
        while(std::isdigit(*exp))
            ++exp;
    }
    if (this->odds.find(i) == odds.end())
        this->odds[i] = 0;
    this->odds[i] += coef;
    if (*exp == '=')
        parse(++exp, true);
    else
        parse(exp, false);
}

void    Solver::print_reduced_form()
{
    bool minus = false;
    std::map<int, double>::iterator it;
    std::cout << "Reduced form: ";

    for(it = odds.begin(); it != odds.end(); ++it)
    {
        if (odds.begin() == it)
            std::cout << it->second;
        else
            std::cout << (minus ? '-' : '+') << ' ' << std::abs(it->second);
        std::cout << " * X^" << it->first << ' ';
    }
    std::cout << "= 0" << std::endl;
    it--;
    std::cout << "Polynomial degree: " << it->first << std::endl;
    if (it->first > 2)
        std::cout << "The polynomial degree is strictly greater than 2, I can't solve." << std::endl;
    exit(0);
}