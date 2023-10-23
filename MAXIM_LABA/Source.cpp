#include"STUDENT.h"
#include<fstream>
#include<algorithm>
#include<Windows.h>

bool compareByTheCourse(const  STUDENT& Object_A, const STUDENT& Object_B) {
	// Ищем первое число в строке 1
	std::string str1 = Object_A.getNameOfCourse();
	size_t pos1 = str1.find_first_of("0123456789");
	int num1 = std::stoi(str1.substr(pos1));

	// Ищем первое число в строке 2
	std::string str2 = Object_B.getNameOfCourse();
	size_t pos2 = str2.find_first_of("0123456789");
	int num2 = std::stoi(str2.substr(pos2));

	// Сравниваем числа
	return num1 < num2;
}

double getAverageMark(std::vector<int> Academic_performance) {
	double sum = 0;

	for (int i = 0; i < Academic_performance.size(); i++)
		sum += Academic_performance[i];

	return sum / Academic_performance.size();
}

int main() {
	setlocale(LC_ALL, "");

	std::vector<STUDENT>	Student_List;
	int						s = 0;
	int						n = 0;

	while (n != 8) {
		std::cout << "1. Console input\n";
		std::cout << "2. File input\n";
		std::cout << "3. Sort info by increase number of course\n";
		std::cout << "4. Information with averange score\n";
		std::cout << "5. Information from the course\n";
		std::cout << "6. All information\n";
		std::cout << "7. Delete information\n";
		std::cout << "8. Exit\n";

		std::cin >> n;

		switch (n) {
		case 1:
		{
			std::vector<int>	Academic_performance;
			std::string			Name_of_student;
			std::string			Name_of_course;
			int					Students_in_the_group = 0;
			int					Number_of_student = 0;
			int					Number_of_marks = 0;

			std::cout << "Enter number of students in the group: ";
			std::cin >> Students_in_the_group;
			std::cout << std::endl << "------------------" << std::endl;

			for (int i = 0; i < Students_in_the_group; i++) {
				std::cout << "Enter number of student: ";
				std::cin >> Number_of_student;
				std::cout << std::endl;

				std::cin.ignore();
				std::cout << "Enter the name of student: ";
				getline(std::cin, Name_of_student);
				std::cout << std::endl;

				std::cout << "Enter the name of course: ";
				getline(std::cin, Name_of_course);
				std::cout << std::endl;

				std::cout << "Enter academic performance of student: ";
				std::cout << std::endl;
				std::cout << "Enter number of marks: ";
				std::cout << std::endl;
				std::cin >> Number_of_marks;

				for (int j = 0; j < Number_of_marks; j++) {
					int Mark;
					std::cin >> Mark;
					Academic_performance.push_back(Mark);
				}

				std::cout << std::endl << "------------------" << std::endl;

				Student_List.push_back(STUDENT(Academic_performance,
					Name_of_student,
					Name_of_course,
					Number_of_student));
				Academic_performance.clear();
				s++;
			}
			break;
		}
		case 2:
		{
			std::ifstream		in("input.txt");
			std::vector<int>	Academic_performance;
			std::string			Name_of_student;
			std::string			Name_of_course;
			int					Students_in_the_group = 0;
			int					Number_of_student = 0;
			int					Number_of_marks = 0;

			in >> Students_in_the_group;

			for (int i = 0; i < Students_in_the_group; i++) {
				in >> Number_of_student;
				in.ignore();
				getline(in, Name_of_student);
				getline(in, Name_of_course);

				in >> Number_of_marks;

				for (int j = 0; j < Number_of_marks; j++) {
					int Mark;
					in >> Mark;
					Academic_performance.push_back(Mark);
				}

				Student_List.push_back(STUDENT(Academic_performance,
					Name_of_student,
					Name_of_course,
					Number_of_student));
				Academic_performance.clear();
				s++;
			}
			in.close();
			break;
		}
		case 3:
		{
			// Сортируем с помощью компаратора
			std::sort(Student_List.begin(), Student_List.end(), compareByTheCourse);

			for (int i = 0; i < Student_List.size(); i++)
				Student_List[i].printFullInfo();
			break;
		}
		case 4:
		{
			double Min_Mark;
			std::cout << "Enter the minimun averange mark: ";
			std::cout << std::endl;
			std::cin >> Min_Mark;

			int count = 0;
			int _Students_in_the_group = Student_List.size();

			for (int i = 0; i < _Students_in_the_group; i++)
				if (getAverageMark(Student_List[i].getAcademicPerformance()) >= Min_Mark) {
					Student_List[i].printInfoWithAverangeScore();
					count++;
				}

			if (count == 0)
				std::cout << "No files" << std::endl;
			break;
		}
		case 5:
		{
			std::string Selected_Course;
			int			count = 0;

			std::cout << "Enter the course: ";
			std::cin >> Selected_Course;
			std::cout << std::endl;

			for (int i = 0; i < s; i++) {
				bool flag = false;

				if (Selected_Course == Student_List[i].getNameOfCourse())
					flag = true;
				else {
					flag = false;
					continue;
				}

				if (flag == true) {
					Student_List[i].printInfoFromTheCourse();
					count++;
				}
			}

			if (count == 0)
				std::cout << "No files" << std::endl;
			break;
		}
		case 6:
		{
			for (int i = 0; i < Student_List.size(); i++)
				Student_List[i].printFullInfo();
			break;
		}
		case 7:
		{
			int number_info;

			std::cout << "Enter information, which u'll delete: ";
			std::cin >> number_info;

			//Если мы ввели число больше количества пунктов в массиве
			//или массив пуст выводим ошибку
			if (number_info > s || Student_List.empty())
				std::cout << "!@#$%^&" << std::endl;
			else {
				//иначе итератор ставим на начало массива и через
				//цикл ищем нужный нам пунк и удаляем его
				auto iter = Student_List.cbegin();

				for (int i = 0; i < number_info; i++)
					iter++;

				Student_List.erase(iter);
				s--;
			}
			break;
		}
		case 8:
		{
			return 0;
		}
		}

		system("pause");
		system("cls");
	}

	return 0;
}