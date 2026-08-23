#include "../inc/AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
	private:
		const std::string target_;
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm(void);

		void executeAction() const;
};

