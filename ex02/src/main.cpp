#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"


int main(void)
{
	PresidentialPardonForm ffs("Katinka");
	Bureaucrat James("James", 1);
	
	ffs.execute(James);
}
