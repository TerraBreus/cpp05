#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

#include <vector>
#include <iostream>

Intern::Intern(void) {

}

Intern::Intern(const Intern& other) {
	*this = other;
}

Intern& Intern::operator=(const Intern& other) {
	if (this != &other) {
		
	}
	return *this;
}

Intern::~Intern(void) {
}

AForm* Intern::makeForm(std::string form, std::string target) const {
	std::vector<std::string> possibleForms = {
		"shrubbery creation",
		"presidential pardon",
		"robotomy request"};
	int i = 0;
	while (i < 4)
	{
		if (form == possibleForms[i])
			break;
		i++;
	}
	switch (i)
	{
		case (0) :
		{
			std::cout << "Intern creates Shrubbery Creation Form." << std::endl;
			return new ShrubberyCreationForm(target);
		}
		case (1) :
		{
			std::cout << "Intern creates Presidential Pardon Form." << std::endl;
			return new PresidentialPardonForm(target);
		}
		case (2) :
		{
			std::cout << "Intern creates Robotomy Request Form." << std::endl;
			return new RobotomyRequestForm(target);
		}
		default :
		{
			std::cout << "Form: " + target + " doesn't exist." << std::endl;
		}
	}
	return (nullptr);
}
