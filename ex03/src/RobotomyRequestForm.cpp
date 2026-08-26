#include "../inc/RobotomyRequestForm.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("Robotomy Request Form", 72, 45), target_(target) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other), target_(other.target_) {
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

void RobotomyRequestForm::executeAction() const {
	std::cout << "BBBBbbbBrrrRRRRrrrrr" << std::endl;
	if (std::rand() % 2)
	{
		std::cout << "Robotomy on " + this->target_ \
			+ " performed succesfully!" << std::endl;
	}
	else 
	{
		std::cout << "Robotomy on " + this->target_ \
			+ " failed with regret." << std::endl;
	}
}

