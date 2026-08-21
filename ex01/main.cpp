#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
#include <exception>

int main(void)
{
	Bureaucrat Brat("Chat");
	Bureaucrat Bred(Brat);
	Form someform("28a", 140, 140);
	
	std::cout << Bred << std::endl;
	try {
		for (int i = 0; i < 148; i++)
			Brat.incrementGrade();
		someform.beSigned(Brat);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

}
