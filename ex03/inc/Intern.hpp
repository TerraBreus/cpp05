#include "AForm.hpp"
#include <string>

class Intern {
	private:
		
	public:
		Intern(void);
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern(void);

		AForm* makeForm(std::string form, std::string target) const;
};
