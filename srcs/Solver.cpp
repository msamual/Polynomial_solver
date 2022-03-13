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
    double a = odds[2], b = odds[1], c = odds[0];

	if (!a && !b && c == 0)
		std::cout << "any real number is a solution" << std::endl;
    if (!a && !b)
        std::cout << "There is no decision" << std::endl;
    else if ((!a && !c) || (!b && !c))
        std::cout << "The solution is:\n0" << std::endl;
    else if (!a)
        std::cout << "The solution is:\n" <<  -c / b << std::endl;
    else
    {
        D = b * b - (4 * a * c);
        if (D < 0)
            std::cout << "There is no decision" << std::endl;
		if (D < 0)
		{
			std::cout << "Discriminant is strictly negative, the two complex solutions are:" << std::endl;
			this->complex_solve(a, b);
		}
        else if (D == 0)
        {
			std::cout << "Discriminant is zero, only one solution is:" << std::endl;
            std::cout << -b / (2 * a) << std::endl;
        }
        else
        {
            std::cout << "Discriminant is strictly positive, the two solutions are:" << std::endl;
            std::cout << (-b - sqrt(D)) / (2 * a) << std::endl;
            std::cout << (-b + sqrt(D)) / (2 * a) << std::endl;
        }
    }

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
        coef = 1  * (minus ? -1 : 1);
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
    else if (right)
        parse(exp, true);
    else
        parse(exp, false);
}

int     Solver::get_max_degree()
{
    std::map<int, double>::iterator it;

    it = odds.end();
    while (--it != odds.begin())
    {
        if (it->second)
            return it->first;
    }
    return 0;
}

void    Solver::print_reduced_form()
{
    std::map<int, double>::iterator it;
    int                             degree = this->get_max_degree();

    std::cout << "Reduced form: ";
    for(it = odds.begin(); it != odds.end(); ++it)
    {
        if (it->second || it->first <= degree)
        {
            if (odds.begin() == it)
                std::cout << it->second;
            else
                std::cout << (it->second < 0 ? '-' : '+') << ' ' << abs(it->second);
            if (it->first)
                std::cout << " * X^" << it->first;
            std::cout << ' ';
        }
    }
    std::cout << "= 0" << std::endl;
    std::cout << "Polynomial degree: " << degree << std::endl;
    if (degree > 2)
    {
        std::cout << "The polynomial degree is strictly greater than 2, I can't solve." << std::endl;
        exit(0);
    }
}

void 	Solver::complex_solve(double a, double b)
{
	ComplexNumber	sqrD(sqrt(abs(this->D)), 1);
	ComplexNumber	res1 = (-b + ;
	ComplexNumber	res2 = (-b / (2 * a)) - (sqrD / (2 * a));

	std::cout << res1 << std::endl;
	std::cout << res2 << std::endl;
}