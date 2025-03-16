#include "Form.h"
#include "Bureaucrat.h"

Form::Form() : name_("anonymous"), gradeToSign_(Bureaucrat::minGrade_),
				gradeToExecute_(Bureaucrat::minGrade_), isSigned_(false) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) 
			: name_(name), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute), isSigned_(false) {
	if (isTooHighGrade(gradeToSign) || isTooHighGrade(gradeToExecute))
		throw GradeTooHighException();
	if (isToLowGrade(gradeToSign) || isToLowGrade(gradeToExecute))
		throw GradeTooLowException();
}

Form::Form(const Form &other) : name_(other.name_), gradeToSign_(other.gradeToSign_),
				gradeToExecute_(other.gradeToExecute_), isSigned_(other.isSigned_) {}

Form &Form::operator=(const Form &other) {
	if (this != &other) {
		isSigned_ = other.isSigned_;
	}
	return *this;
}

Form::~Form() {}

const std::string &Form::getName() const {
	return name_;
}

int Form::getGradeToSign() const {
	return gradeToSign_;
}

int Form::getGradeToExecute() const {
	return gradeToExecute_;
}

bool Form::isSigned() const {
	return isSigned_;
}

void Form::setIsSigned(bool isSigned){
	isSigned_ = isSigned;
}

bool Form::isTooHighGrade(int grade) {
	return grade < Bureaucrat::maxGrade_;
}

bool Form::isToLowGrade(int grade) {
	return grade > Bureaucrat::minGrade_;
}

bool Form::isEnoughGradeToSign(int grade) const {
	return grade <= gradeToSign_;
}

bool Form::isEnoughGradeToExecute(int grade) const {
	return grade <= gradeToExecute_;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (!isEnoughGradeToSign(bureaucrat.getGrade()))
		throw GradeTooLowException();
	setIsSigned(true);
}

const char *Form::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "Form " << form.getName() << " requires grade " << form.getGradeToSign()
		<< " to sign and grade " << form.getGradeToExecute() << " to execute";
	if (form.isSigned())
		os << " and is signed";
	else
		os << " and is not signed";
	return os;
}


