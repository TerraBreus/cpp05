#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

#include <iostream>
#include <exception>

static void section(const std::string& title)
{
	std::cout << std::endl
		<< "==================== " << title << " ===================="
		<< std::endl;
}

static void makeBureaucrat(const std::string& name, int grade)
{
	try
	{
		Bureaucrat b(name, grade);
		std::cout << "Created: " << b << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Bureaucrat(" << name << ", " << grade
			<< ") -> GradeTooHighException: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Bureaucrat(" << name << ", " << grade
			<< ") -> GradeTooLowException: " << e.what() << std::endl;
	}
}

static void makeForm(const std::string& name, int sign, int exec)
{
	try
	{
		Form f(name, sign, exec);
		std::cout << "Created:" << std::endl << f << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cout << "Form(" << name << ", " << sign << ", " << exec
			<< ") -> GradeTooHighException: " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << "Form(" << name << ", " << sign << ", " << exec
			<< ") -> GradeTooLowException: " << e.what() << std::endl;
	}
}

int main(void)
{
	section("Bureaucrat grade edge cases");
	makeBureaucrat("ValidHigh", 1);
	makeBureaucrat("ValidLow", 150);
	makeBureaucrat("TooHigh", 0);
	makeBureaucrat("TooLow", 151);
	makeBureaucrat("Negative", -42);

	section("Form grade edge cases");
	makeForm("Valid", 40, 12);
	makeForm("SignTooLow", 151, 12);
	makeForm("ExecTooLow", 40, 200);
	makeForm("SignTooHigh", 0, 12);
	makeForm("ExecTooHigh", 40, -5);
	makeForm("BothInvalid", 0, 200);

	section("Successful sign");
	{
		Bureaucrat boss("Boss", 1);
		Form contract("Employment", 50, 25);
		boss.signForm(contract);
		std::cout << contract << std::endl;
	}

	section("Failed sign (grade too low)");
	{
		Bureaucrat intern("Intern", 140);
		Form secret("TopSecret", 10, 5);
		intern.signForm(secret);
		std::cout << "Secret signed state: " << secret.getSignatureState() << std::endl;
	}

	section("Signing an already signed form");
	{
		Bureaucrat boss("Boss", 1);
		Form contract("Employment", 50, 25);
		boss.signForm(contract);
		boss.signForm(contract); // re-sign: beSigned sets true again, no throw
		std::cout << "Signed state: " << contract.getSignatureState() << std::endl;
	}

	section("incrementGrade(unsigned int) edge cases");
	{
		Bureaucrat b("Climber", 100);
		std::cout << b << std::endl;
		try
		{
			b.incrementGrade(99); // 100 -> 1
			std::cout << "After +99: " << b << std::endl;
			b.incrementGrade(1);  // 1 -> 0 throws
		}
		catch (Bureaucrat::GradeTooHighException& e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Unexpected: " << e.what() << std::endl;
		}
	}

	section("incrementGrade(unsigned int) exact overflow");
	{
		Bureaucrat b("Edge", 10);
		try
		{
			b.incrementGrade(10); // 10 -> 0, must throw (not reach 0)
		}
		catch (Bureaucrat::GradeTooHighException& e)
		{
			std::cout << "Caught: " << e.what() << " (grade stayed " << b.getGrade() << ")" << std::endl;
		}
	}

	section("Form copy constructor");
	{
		Form original("Original", 50, 25);
		Form copy(original);
		std::cout << "Copy:" << std::endl << copy << std::endl;
	}

	section("Bureaucrat copy + independent grade");
	{
		Bureaucrat a("A", 50);
		Bureaucrat b(a);
		b.decrementGrade();
		std::cout << "A: " << a << std::endl;
		std::cout << "B: " << b << std::endl;
	}

	return (0);
}
