#include "AForm.h"
#include "Bureaucrat.h"

AForm::AForm() : name_("anonymous"), gradeToSign_(Bureaucrat::minGrade_),
				gradeToExecute_(Bureaucrat::minGrade_), isSigned_(false) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecut) 
			: name_(name), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecut), isSigned_(false) {
	if (isTooHighGrade(gradeToSign) || isTooHighGrade(gradeToExecut))
		throw GradeTooHighException();
	if (isToLowGrade(gradeToSign) || isToLowGrade(gradeToExecut))
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : name_(other.name_), gradeToSign_(other.gradeToSign_),
				gradeToExecute_(other.gradeToExecute_), isSigned_(other.isSigned_) {}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other) {
		isSigned_ = other.isSigned_;
	}
	return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const {
	return name_;
}

int AForm::getGradeToSign() const {
	return gradeToSign_;
}

int AForm::getGradeToExecute() const {
	return gradeToExecute_;
}

bool AForm::isSigned() const {
	return isSigned_;
}

void AForm::setIsSigned(bool isSigned){
	isSigned_ = isSigned;
}

bool AForm::isTooHighGrade(int grade) {
	return grade < Bureaucrat::maxGrade_;
}

bool AForm::isToLowGrade(int grade) {
	return grade > Bureaucrat::minGrade_;
}

bool AForm::isEnoughGradeToSign(int grade) const {
	return grade <= gradeToSign_;
}

bool AForm::isEnoughGradeToExecute(int grade) const {
	return grade <= gradeToExecute_;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (!isEnoughGradeToSign(bureaucrat.getGrade()))
		throw GradeTooLowException();
	setIsSigned(true);
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "form is not signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm) {
	os << "AForm " << AForm.getName() << " requires grade " << AForm.getGradeToSign()
		<< " to sign and grade " << AForm.getGradeToExecute() << " to excute";
	if (AForm.isSigned())
		os << " and is signed";
	else
		os << " and is not signed";
	return os;
}
