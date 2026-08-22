#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"
#include <iostream>
#include <string>

// - - - - - - - - - - - - 
//      C A N O N 
// - - - - - - - - - - - - 

Form::Form(std::string name, int sign_grade, int exec_grade) :
	name_(name), signed_(false), grade_for_signature_(sign_grade), grade_for_execution_(exec_grade)
{
	#ifdef DEBUG
	std::cout << "Form created." << std::endl;
	#endif
}

Form::Form(const Form& other) :
	name_(other.name_),
	grade_for_signature_(other.grade_for_signature_),
	grade_for_execution_(other.grade_for_execution_)
{
	#ifdef DEBUG
	std::cout << "Form duplicated." << std::endl;
	#endif
	*this = other;
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->signed_ = other.signed_;
	}
	return *this;
}

Form::~Form(void)
{
	#ifdef DEBUG
	std::cout << "Form destroyed." << std::endl;
	#endif
}

// - - - - - - - - - - - - 
// 	    G E T T E R S
// - - - - - - - - - - - -

const std::string Form::getName() const
{
	return (this->name_);
}

bool Form::getSignatureState() const
{
	return (this->signed_);
}

int Form::getGradeForSignature() const
{
	return (this->grade_for_signature_);
}

int Form::getGradeForExecution() const
{
	return (this->grade_for_execution_);
}

// - - - - - - - - - - - - - - - 
// M E M B E R F U N C T I O N S
// - - - - - - - - - - - - - - -

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->grade_for_signature_)
		throw (Form::GradeTooLowException());
	this->signed_ = true;
}

// - - - - - - - - - - - - 
//  Others.
// - - - - - - - - - - - -

std::ostream& operator<<(std::ostream& o, Form& f)
{
	std::cout << "Form with name: " << f.getName() << std::endl;
	std::cout << "Signature State: " << f.getSignatureState() << std::endl;
	std::cout << "Grade needed for Execution " << f.getGradeForExecution() << std::endl;
	std::cout << "Grade needed for Signature " << f.getGradeForSignature();
	return (o);
}
