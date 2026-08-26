#include "../inc/ShrubberyCreationForm.hpp"
#include <string>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("ShrubberyCreationForm", 145, 137), target_(target) {
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : 
	AForm(other), target_(other.target_) {
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

void ShrubberyCreationForm::executeAction() const {
	std::string const filename = this->target_ + "_shrubbery";
	std::ofstream outfile(filename.c_str());

	if (!outfile.is_open())
		throw (ShrubberyCreationForm::FileNotOpenException()); 

	outfile << "Pretend there is a tree here\n";
	outfile.close();
}
