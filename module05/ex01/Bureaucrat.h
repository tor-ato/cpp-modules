#ifndef CPP_MODULES_BUREAUCRAT_H
#define CPP_MODULES_BUREAUCRAT_H

#include <string>
#include <ostream>

class Form;

class Bureaucrat {
public:
	static const int maxGrade_ = 1;
	static const int minGrade_ = 150;

	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};

	Bureaucrat();

	Bureaucrat(const std::string &name);

	Bureaucrat(const std::string &name, int grade);

	virtual ~Bureaucrat();

	Bureaucrat(const Bureaucrat &other);

	Bureaucrat &operator=(const Bureaucrat &other);

	void setGrade(int grade);

	const std::string &getName() const;

	int getGrade() const;

	void incrementGrade();

	void decrementGrade();

	void signForm(Form &form) const;

private:
	const std::string name_;
	int grade_;

	static bool isTooHighGrade(int grade);

	static bool isTooLowGrade(int grade);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif //CPP_MODULES_BUREAUCRAT_H
