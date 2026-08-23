#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		const std::string target_;

	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm(void);

		void executeAction() const;
};
