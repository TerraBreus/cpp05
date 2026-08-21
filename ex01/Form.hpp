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
};
