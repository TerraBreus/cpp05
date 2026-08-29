#include "../inc/Bureaucrat.hpp"

#include <iostream>
#include <exception>

#define GREEN "\033[42m"
#define RED "\033[41m"
#define RESET "\033[0m"

static void section(const std::string& title)
{
	std::cout << std::endl
		<< GREEN
		<< "==================== " << title << " ===================="
		<< RESET
		<< std::endl;
}

int main(void)
{
	section("Simple Construction and Insertion Operator");
	try
	{
		Bureaucrat a("Alice");
		std::cout << a << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Unexpected: " << e.what() << std::endl;
	}

	section("Copy constructor / assignment");
	{
		Bureaucrat original("Copycat");
		Bureaucrat copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy:     " << copy << std::endl;

		Bureaucrat another("Another");
		another = original;
		std::cout << "After assignment: " << another << std::endl;
	}

	section("Increment (grade goes 150 -> 1)");
	{
		Bureaucrat brat("Climber");
		std::cout << brat << std::endl;
		try
		{
			for (int i = 0; i < 149; i++)
				brat.incrementGrade();
			std::cout << "After 149 increments: " << brat << std::endl;
			brat.incrementGrade();
			std::cerr << RED << "ERROR: no throw at top" << RESET << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << RED 
				<< "Caught : " 
				<< RESET 
				<< e.what() 
				<< std::endl;
		}
	}

	section("Decrement (grade goes 150 -> 151)");
	{
		Bureaucrat brat("Magnus Midtbo");
		std::cout << brat << std::endl;
		try
		{ 
			brat.decrementGrade();
			std::cerr << "ERROR: no throw at bottom" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << RED 
				<< "Caught : " 
				<< RESET 
				<< e.what() 
				<< std::endl;
		}
	}
	return (0);
}
