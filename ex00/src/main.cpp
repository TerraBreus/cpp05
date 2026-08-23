#include "../inc/Bureaucrat.hpp"

#include <iostream>
#include <exception>

int main(void)
{
	Bureaucrat Brat("Chat");
	Bureaucrat Bred(Brat);
	
	std::cout << Bred << std::endl;
	try {
		Bred.decrementGrade();
		for (int i = 0; i < 151; i++)
			Brat.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

}
