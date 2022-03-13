#include "../includes/Computor.hpp"

std::string	read_from_stdin()
{
	std::string	exp;

	std::cout << "Please input polynomial expression:" << std::endl;
	std::getline(std::cin, exp);
	return exp;
}

int main(int ac, char **av)
{
	std::string input;

	if (ac < 2)
		input = read_from_stdin();
	else
		input = av[1];
	input = remove_spaces(input);
	if (input.size() < 1 || !check_symbols(input) || input == "=")
		puterror("Error: Can't find polynomial expression");
	Solver(input.data());
	return 0;
}