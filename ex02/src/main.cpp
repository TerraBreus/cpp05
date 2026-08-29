#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

#include <iostream>
#include <exception>
#include <cstdlib>

static void section(const std::string& title)
{
	std::cout << std::endl
		<< "==================== " << title << " ===================="
		<< std::endl;
}

static void tryExecute(AForm& f, const Bureaucrat& b)
{
	try
	{
		f.execute(b);
	}
	catch (AForm::FormNotSignedException& e)
	{
		std::cout << "FormNotSignedException: " << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException& e)
	{
		std::cout << "GradeTooLowException: " << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException& e)
	{
		std::cout << "GradeTooHighException: " << e.what() << std::endl;
	}
	catch (ShrubberyCreationForm::FileNotOpenException& e)
	{
		std::cout << "FileNotOpenException: " << e.what() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "std::exception: " << e.what() << std::endl;
	}
}

static void trySign(AForm& f, const Bureaucrat& b)
{
	try
	{
		f.beSigned(b);
		std::cout << b.getName() << " signed " << f.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException& e)
	{
		std::cout << "beSigned GradeTooLowException: " << e.what() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "beSigned exception: " << e.what() << std::endl;
	}
}

int main(void)
{
	std::srand(42);

	section("Presidential Pardon Form (sign 25, exec 5)");
	{
		PresidentialPardonForm f("Katinka");
		std::cout << f << std::endl;

		Bureaucrat tooLow("Peon", 100);
		Bureaucrat mid("Manager", 20);
		Bureaucrat boss("President", 1);

		trySign(f, tooLow);   // fails: 100 > 25
		tryExecute(f, boss);  // fails: not signed
		trySign(f, mid);      // ok: 20 <= 25
		tryExecute(f, boss);  // ok
		tryExecute(f, tooLow);// fails: 100 > 5 (grade too low)
	}

	section("Robotomy Request Form (sign 72, exec 45)");
	{
		RobotomyRequestForm f("Jeremy");
		std::cout << f << std::endl;

		Bureaucrat junior("Junior", 100);
		Bureaucrat senior("Senior", 40);
		Bureaucrat boss("Boss", 1);

		tryExecute(f, boss);  // not signed
		trySign(f, junior);   // fails: 100 > 72
		trySign(f, senior);   // ok
		for (int i = 0; i < 5; i++)
			tryExecute(f, boss); // ok, random success/fail
		tryExecute(f, junior);  // fails: 100 > 45
	}

	section("Shrubbery Creation Form (sign 145, exec 137)");
	{
		ShrubberyCreationForm f("garden");
		std::cout << f << std::endl;

		Bureaucrat low("Lowly", 149);
		Bureaucrat boss("Boss", 1);

		trySign(f, low);      // ok: 149 <= 145? no -> 149 > 145 fails
		trySign(f, boss);     // ok
		tryExecute(f, low);   // fails: 149 > 137
		tryExecute(f, boss);  // ok -> writes garden_shrubbery
	}

	section("Polymorphic handling via AForm pointer");
	{
		AForm* forms[3];
		forms[0] = new PresidentialPardonForm("A");
		forms[1] = new RobotomyRequestForm("B");
		forms[2] = new ShrubberyCreationForm("C");

		Bureaucrat boss("Boss", 1);
		for (int i = 0; i < 3; i++)
		{
			trySign(*forms[i], boss);
			tryExecute(*forms[i], boss);
			delete forms[i];
		}
	}

	section("Copy of a concrete form through base reference");
	{
		PresidentialPardonForm src("Target");
		PresidentialPardonForm copy(src);
		Bureaucrat boss("Boss", 1);
		trySign(copy, boss);
		tryExecute(copy, boss);
	}

	section("Self-assignment / copy of Bureaucrat");
	{
		Bureaucrat a("A", 10);
		Bureaucrat b(a);
		Bureaucrat& bref = b;
		bref = b;
		std::cout << a << " | " << b << std::endl;
	}

	return (0);
}
