#pragma once
#pragma once
#include<string>
#include<iostream>
#include<vector>

class STUDENT
{
private:
	std::vector<int>	Academic_performance;
	std::string			Name_of_student;
	std::string			Name_of_course;
	int					Number_of_student;

public:
	STUDENT();
	STUDENT(const std::vector<int>	_Academic_performance,
		const std::string		_Name_of_student,
		const std::string		_Name_of_course,
		const int				_Number_of_student);
	~STUDENT();

	std::vector<int>	getAcademicPerformance() const;
	std::string			getNameOfStudent() const;
	std::string			getNameOfCourse() const;
	int					getNumberOfStudent() const;

	void setAcademicPerformance(const std::vector<int>& _Academic_performance);
	void setNameOfStudent(const std::string& _Name_of_student);
	void setNameOfCourse(const std::string& _Name_of_course);
	void setNumberOfStudent(const int& _Number_of_student);

	void printFullInfo();
	void printInfoWithAverangeScore();
	void printInfoFromTheCourse();
};
