#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() : name_("anonymous"), grade_(Bureaucrat::minGrade_) {}

Bureaucrat::Bureaucrat(const std::string &name) : name_(name), grade_(Bureaucrat::minGrade_) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name_(name) {
	setGrade(grade);
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name_(other.name_), grade_(other.grade_) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		grade_ = other.grade_;
	}
	return *this;
}

const std::string &Bureaucrat::getName() const {
	return name_;
}

int Bureaucrat::getGrade() const {
	return grade_;
}

void Bureaucrat::setGrade(int grade) {
	if (Bureaucrat::isTooHighGrade(grade))
		throw GradeTooHighException();
	if (Bureaucrat::isTooLowGrade(grade))
		throw GradeTooLowException();
	grade_ = grade;
}

bool Bureaucrat::isTooHighGrade(int grade) {
	return grade < Bureaucrat::maxGrade_;
}

bool Bureaucrat::isTooLowGrade(int grade) {
	return grade > Bureaucrat::minGrade_;
}

void Bureaucrat::incrementGrade() {
	if (Bureaucrat::isTooHighGrade(this->getGrade() - 1))
		throw GradeTooHighException();
	--grade_;
}

void Bureaucrat::decrementGrade() {
	if (Bureaucrat::isTooLowGrade(this->getGrade() + 1))
		throw GradeTooLowException();
	++grade_;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
