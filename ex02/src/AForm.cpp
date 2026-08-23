#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <iostream>
#include <string>

// - - - - - - - - - - - - 
//      C A N O N 
// - - - - - - - - - - - - 

AForm::AForm(std::string name, int sign_grade, int exec_grade) :
	name_(name), signed_(false), grade_for_signature_(sign_grade), grade_for_execution_(exec_grade)
{
	if (grade_for_signature_ > 150 || grade_for_execution_ > 150)
		throw (AForm::GradeTooLowException());
	if (grade_for_signature_ < 1 || grade_for_execution_ < 1)
		throw (AForm::GradeTooHighException());
	#ifdef DEBUG
	std::cout << "AForm created." << std::endl;
	#endif
}

AForm::AForm(const AForm& other) :
	name_(other.name_),
	grade_for_signature_(other.grade_for_signature_),
	grade_for_execution_(other.grade_for_execution_)
{
	if (grade_for_signature_ > 150 || grade_for_execution_ > 150)
		throw (AForm::GradeTooLowException());
	if (grade_for_signature_ < 1 || grade_for_execution_ < 1)
		throw (AForm::GradeTooHighException());
	#ifdef DEBUG
	std::cout << "AForm duplicated." << std::endl;
	#endif
	*this = other;
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		this->signed_ = other.signed_;
	}
	return *this;
}

AForm::~AForm(void)
{
	#ifdef DEBUG
	std::cout << "AForm destroyed." << std::endl;
	#endif
}

// - - - - - - - - - - - - 
// 	    G E T T E R S
// - - - - - - - - - - - -

const std::string AForm::getName() const
{
	return (this->name_);
}

bool AForm::getSignatureState() const
{
	return (this->signed_);
}

int AForm::getGradeForSignature() const
{
	return (this->grade_for_signature_);
}

int AForm::getGradeForExecution() const
{
	return (this->grade_for_execution_);
}

// - - - - - - - - - - - - - - - 
// M E M B E R F U N C T I O N S
// - - - - - - - - - - - - - - -

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->grade_for_signature_)
		throw (AForm::GradeTooLowException());
	this->signed_ = true;
}

void AForm::execute(const Bureaucrat& b) const
{
	if (this->signed_ != true)
		throw (AForm::FormNotSignedException());
	if (this->grade_for_execution_ > b.getGrade())
		throw (AForm::GradeTooLowException());
	this->executeAction();
}

// - - - - - - - - - - - - 
//  Others.
// - - - - - - - - - - - -

std::ostream& operator<<(std::ostream& o, AForm& f)
{
	std::cout << "AForm with name: " << f.getName() << std::endl;
	std::cout << "Signature State: " << f.getSignatureState() << std::endl;
	std::cout << "Grade needed for Execution " << f.getGradeForExecution() << std::endl;
	std::cout << "Grade needed for Signature " << f.getGradeForSignature();
	return (o);
}
