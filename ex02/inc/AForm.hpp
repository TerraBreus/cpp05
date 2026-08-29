#pragma once

#include <string>
#include <exception>

class Bureaucrat;

class AForm {
	private:
		const std::string name_;
		bool signed_;
		const int grade_for_signature_;
		const int grade_for_execution_;
		
	public:
		// (DE)CONSTRUCTORS
		AForm(std::string name, int sign_grade, int sign_exec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm(void);

		// GETTERS
		const std::string getName() const;
		bool getSignatureState() const;
		int getGradeForSignature() const;
		int getGradeForExecution() const;

		// MEMBER FUNCTIONS
		void execute(const Bureaucrat& b) const;
		void beSigned(const Bureaucrat& b);

		// VIRTUAL FUNCTIONS
		// Pure virtual function (const = 0)
		// Making AForm completely abstract.
		virtual void executeAction() const = 0;

		// EXCEPTIONS
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade too low for form!";
				}
		};
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade too high!";
				}
		};
		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Form not signed!";
				}
		};
};

std::ostream& operator<<(std::ostream& o, AForm& f);
