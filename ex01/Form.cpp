// - - - - - - - - - - - - 
//      C A N O N 
// - - - - - - - - - - - - 

Form::Form(std::string name, int sign_grade, int exec_grade) :
	name_(name), signed_(false), grade_for_signature_(sign_grade), grade_for_execution_(exec_grade)
{
	std::cout << "Form created." << std::endl;
}

Form::Form(const Form& other) :
	name_(other.name_),
	grade_for_signature_(other.grade_for_signature_),
	grade_for_execution_(other.grade_for_execution_)
{
	std::cout << "Form duplicated." << std::endl;
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
	std::cout << "Form destroyed." << std::endl;
}

