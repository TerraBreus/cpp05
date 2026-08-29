#include "../inc/AForm.hpp"
#include <string>
#include <exception>

class ShrubberyCreationForm : public AForm {
	private:
		const std::string target_;

	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm(void);

		void executeAction() const;

		class FileNotOpenException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "File did not open/create correctly!";
				}
		};
};
