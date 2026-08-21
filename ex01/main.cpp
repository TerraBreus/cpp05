#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
#include <exception>

int main(void)
{
	Bureaucrat pigeon("Johny");
	Form pieceOfPaper("Graduation Certificate", 40, 12);

	std::cout << pigeon << std::endl;
	std::cout << pieceOfPaper << std::endl;

	try
	{
		pigeon.incrementGrade(120);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	pigeon.signForm(pieceOfPaper);

	Bureaucrat pig("Jimbo", 41);
	pig.signForm(pieceOfPaper);
}
