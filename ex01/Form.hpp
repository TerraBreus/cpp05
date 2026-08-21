class Form {
	private:
	public:
		Form(std::string name, int sign_grade, int sign_exec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form(void);

		const std::string getName();
		bool getSignatureState();
		int getGradeForSignature();
		int getGradeForExection();

		void beSigned(Bureaucrat& b);

		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw() {
				return "Grade too low for form!";
			}
		};
		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw() {
				return "Grade too high!";
			}
		};
};
