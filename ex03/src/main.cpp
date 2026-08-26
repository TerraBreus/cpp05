#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Intern.hpp"

#include <iostream>

int main(void)
{
	Intern jimmy;
	AForm* llls;
	Bureaucrat marcus("Marc", 12);

	llls = jimmy.makeForm("shrubbery creation", "lmao");
	llls->beSigned(marcus);
}
