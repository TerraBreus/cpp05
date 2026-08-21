#include "Bureaucrat.hpp"

#include <iostream>

Bureaucrat::Bureaucrat() : name_("Undefined"), grade_(150) {
	std::cout << "Undefined Pigeon created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : name_(name) , grade_(150) {

	std::cout << "Pigeon named " << name_ << " created." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name) {
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) 
	: name_(other.name_), grade_(other.grade_) {
	std::cout << "Pigeon cloning device activated... Copying " << other.name_ << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->grade_ = other.grade_;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Pigeon named " << name_ << " destroyed" << std::endl;
}

const std::string Bureaucrat::getName() const {
	return (this->name_);
}

int Bureaucrat::getGrade() const {
	return (this->grade_);
}

void Bureaucrat::incrementGrade() {
	if (this->grade_ - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	this->grade_--;
}

void Bureaucrat::incrementGrade(unsigned int inc) {
	if (this->grade_ - inc < 1)
		throw (Bureaucrat::GradeTooHighException());
	this->grade_ -= inc;
}

void Bureaucrat::decrementGrade() {
	if (this->grade_ + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->grade_++;
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (o);
}
