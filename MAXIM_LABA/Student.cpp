#include "STUDENT.h"

STUDENT::STUDENT()
{
}

STUDENT::STUDENT(const std::vector<int> _Academic_performance,
	const std::string		_Name_of_student,
	const std::string		_Name_of_course,
	const int				_Number_of_student)
{
	Number_of_student = _Number_of_student;
	Name_of_student = _Name_of_student;
	Name_of_course = _Name_of_course;
	Academic_performance = _Academic_performance;

}

STUDENT::~STUDENT()
{
}

std::vector<int> STUDENT::getAcademicPerformance() const
{
	return this->Academic_performance;
}

std::string STUDENT::getNameOfStudent() const
{
	return this->Name_of_student;
}

std::string STUDENT::getNameOfCourse() const
{
	return this->Name_of_course;
}

int STUDENT::getNumberOfStudent() const
{
	return this->Number_of_student;
}

void STUDENT::setAcademicPerformance(const std::vector<int>& _Academic_performance)
{
	Academic_performance = _Academic_performance;
}

void STUDENT::setNameOfStudent(const std::string& _Name_of_student)
{
	Name_of_student = _Name_of_student;
}

void STUDENT::setNameOfCourse(const std::string& _Name_of_course)
{
	Name_of_course = _Name_of_course;
}

void STUDENT::setNumberOfStudent(const int& _Number_of_student)
{
	Number_of_student = _Number_of_student;
}

void STUDENT::printFullInfo()
{
	std::cout << "Student's number: " << Number_of_student << std::endl;
	std::cout << "Student's name: " << Name_of_student << std::endl;
	std::cout << "Name of course: " << Name_of_course << std::endl;
	std::cout << "Student's academic performance: ";

	for (int i = 0; i < Academic_performance.size(); i++)
		std::cout << Academic_performance[i] << " ";

	std::cout << std::endl << "------------------" << std::endl;
}

void STUDENT::printInfoWithAverangeScore()
{
	std::cout << "Student's name: " << Name_of_student << std::endl;
	std::cout << "Name of course: " << Name_of_course << std::endl;
	std::cout << std::endl << "------------------" << std::endl;
}

void STUDENT::printInfoFromTheCourse()
{
	std::cout << "Student's name: " << Name_of_student << std::endl;
	std::cout << "Student's academic performance: ";

	for (int i = 0; i < Academic_performance.size(); i++)
		std::cout << Academic_performance[i] << " ";

	std::cout << std::endl << "------------------" << std::endl;
}