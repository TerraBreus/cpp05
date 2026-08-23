#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

#include <iostream>

int main(void)
{
	PresidentialPardonForm ffs("Katinka");
	Bureaucrat James("James", 1);
	ShrubberyCreationForm uwantsome("lmao");
	RobotomyRequestForm robot("Jaremy");
	
	std::cout << James << std::endl;
	std::cout << uwantsome << std::endl;

	try {
		uwantsome.beSigned(James);
		uwantsome.execute(James);
		robot.beSigned(James);
		robot.execute(James);
		robot.execute(James);
		robot.execute(James);
		robot.execute(James);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
