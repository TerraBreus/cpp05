#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Intern.hpp"

#include <iostream>
#include <exception>
#include <string>

static void section(const std::string& title)
{
	std::cout << std::endl
		<< "==================== " << title << " ===================="
		<< std::endl;
}

static void process(Intern& intern, const std::string& form, const std::string& target)
{
	std::cout << "-- request: \"" << form << "\" target=\"" << target << "\"" << std::endl;
	AForm* f = intern.makeForm(form, target);
	if (f == NULL)
	{
		std::cout << "Intern returned NULL, nothing to do." << std::endl;
		return;
	}
	try
	{
		std::cout << *f << std::endl;
		Bureaucrat boss("Boss", 1);
		f->beSigned(boss);
		f->execute(boss);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception while using form: " << e.what() << std::endl;
	}
	delete f;
}

int main(void)
{
	std::srand(7);

	Intern jimmy;

	section("Valid forms via Intern");
	process(jimmy, "shrubbery creation", "home");
	process(jimmy, "presidential pardon", "Zaphod");
	process(jimmy, "robotomy request", "Marvin");

	section("Invalid form name (returns NULL)");
	process(jimmy, "unknown form", "nowhere");
	process(jimmy, "ROBOTOMY REQUEST", "caseSensitive");

	section("Sign failure scenario");
	{
		AForm* f = jimmy.makeForm("presidential pardon", "Citizen");
		if (f)
		{
			Bureaucrat peon("Peon", 100); // 100 > 25 -> cannot sign
			try
			{
				f->beSigned(peon);
			}
			catch (std::exception& e)
			{
				std::cout << "Expected: " << e.what() << std::endl;
			}
			// execute without sign should also throw
			try
			{
				f->execute(peon);
			}
			catch (std::exception& e)
			{
				std::cout << "Expected on execute: " << e.what() << std::endl;
			}
			delete f;
		}
	}

	section("Intern copy / assignment (no crash)");
	{
		Intern other(jimmy);
		Intern third;
		third = other;
		AForm* f = third.makeForm("shrubbery creation", "copyTest");
		if (f)
		{
			Bureaucrat boss("Boss", 1);
			f->beSigned(boss);
			f->execute(boss);
			delete f;
		}
	}

	section("Self-assignment of Intern");
	{
		Intern self;
		Intern& selfref = self;
		selfref = self;
		std::cout << "Intern self-assignment ok." << std::endl;
	}

	return (0);
}
