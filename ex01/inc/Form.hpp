#pragma once

#include <string>
#include <exception>

class Bureaucrat;

class Form {
	private:
		const std::string name_;
		bool signed_;
		const int grade_for_signature_;
		const int grade_for_execution_;
		
	public:
		Form(std::string name, int sign_grade, int sign_exec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form(void);

		const std::string getName() const;
		bool getSignatureState() const;
		int getGradeForSignature() const;
		int getGradeForExecution() const;

		void beSigned(const Bureaucrat& b);

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade too low for form!";
				}
		};
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade too high for form!";
				}
		};
};

std::ostream& operator<<(std::ostream& o, Form& f);
