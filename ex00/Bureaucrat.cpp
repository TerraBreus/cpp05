#include "Bureaucrat.hpp"

#include <iostream>

Bureaucrat::Bureaucrat() : _name("Undefined"), _grade(150) {
	std::cout << "Undefined Pigeon created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name) , _grade(150) {

	std::cout << "Pigeon named " << _name << " created." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) 
	: _name(other._name), _grade(other._grade) {
	std::cout << "Pigeon cloning device activated... Copying " << other._name << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Pigeon named " << _name << " destroyed" << std::endl;
}

const std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {
	if (this->_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade++;
}

