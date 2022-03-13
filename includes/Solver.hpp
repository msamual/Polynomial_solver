//
// Created by Sergey Uryashev on 10.03.2022.
//

#ifndef POLYNOMIAL_SOLVER_SOLVER_H
#define POLYNOMIAL_SOLVER_SOLVER_H

# include "Computor.hpp"

class Solver {

private:
    std::map<int, double>   odds;
    double                  D;

public:
    Solver();
    Solver(std::string exp);
    Solver(const Solver& other);

    Solver& 	operator=(const Solver& other);

    void 		parse(const char *exp, bool right);
    void 		print_reduced_form();
    void 		solve();
    int  		get_max_degree();
	void 		complex_solve(double a, double b);
};

#endif //POLYNOMIAL_SOLVER_SOLVER_H
