#ifndef _CLASSS_H_
#define _CLASSS_H_

#include <fmt/core.h>
#include <iostream>
#include <vector>

#ifdef _WIN32
        #include <windows.h> 
    #else
        #include <cstdlib>
#endif

/**
 * @brief class to store the data of each Subject.
 */
class Subject
{
private:
    std::string subject_name;
    int marks_scored, full_marks;

public:
    Subject(std::string name, int full, int marks_obtain);
    std::string name() const { return subject_name; }
    int score() const { return marks_scored; }
    int full_mark() const { return full_marks; }
    float point() const;
    ~Subject() = default;
};

/**
 * @brief Construct a new Subject::Subject object
 *
 * @param name name of Subject.
 * @param full total marks of the paper.
 * @param marks_obtain how much marks you obtain?
 */
Subject::Subject(std::string name, int full, int marks_obtain)
{
    this->subject_name = name;
    this->marks_scored = marks_obtain;
    this->full_marks = full;
}

/**
 * @brief output point of the Subject.
 *
 * @return char
 */
float Subject::point() const
{
    return ((static_cast<float>(this->marks_scored) / this->full_marks) * 10.0f);
}

/**
 * @brief clear the console
 */
void clear()
{
    #ifdef _WIN32
        COORD topLeft = {0, 0};
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO screen;
        DWORD written;

        GetConsoleScreenBufferInfo(console, &screen);
        FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
        FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
        SetConsoleCursorPosition(console, topLeft);
    #else
        std::system("clear"); // Unix (Linux and macOS)
    #endif
}

/**
 * @brief starting output:- header.
 * 
 * @param length size or length of header.
 */
void header(int length)
{
    fmt::print(fmt::fg(fmt::color::gray), "\n{0:*<{1}}\n*", "*", length);
    fmt::print(fmt::bg(fmt::color::sky_blue) | fmt::fg(fmt::color::white_smoke) | fmt::emphasis::bold, "{0:^{1}}", "CGPA Calculator", length - 2);
    fmt::print(fmt::fg(fmt::color::gray), "*\n");
    fmt::print(fmt::fg(fmt::color::gray), "{0:*<{1}}\n", "*", length);
}

/**
 * @brief personal data of students. Data Structure
 */
struct Child
{
    std::string name;  // name of the child.
    std::string classs; // class of the child.
    std::string school; // school of the child read.
    std::string rollno; // rollno of the child.
    std::string weight; // weight of the child.
    int present; // How many days do child go to school.
};

/**
 * @brief this will take detail of student and store in Student class.
 *
 * @param Student This where detail will store.
 * @return true if successfully able to take the input.
 * @return false if use decline to give details.
 */
bool give_pdetail(Child &Student)
{
    std::string detail = "No";
    std::vector<std::string> correct{"True", "T", "true", "YES", "yes", "Yes", "YEs", "Y"};

    fmt::print("Do you want give personal detail?(yes/no): ");
    std::cin >> detail;

    switch (detail[0])
    {
    case 'y':
    case 'Y':
    case 'T':
    case 't':
        for (const std::string &value : correct)
        {
            if ( value == detail)
            {
                std::cout << "Name: ";
                std::cin.ignore();
                std::getline(std::cin, Student.name);
                std::cout << "Class: ";
                std::cin >> Student.classs;
                std::cout << "Roll No.: ";
                std::cin >> Student.rollno;
                std::cout << "School: ";
                std::cin.ignore();
                std::getline(std::cin, Student.school);
                std::cout << "Number of present: ";
                std::cin >> Student.present;
                std::cout << "Weight: ";
                std::cin >> Student.weight;
                return true;
            }
        }
        break;
    default:
        Student.name = "ABC";
        Student.classs = "X";
        Student.rollno = "1";
        Student.school = "xyz";
        Student.present = 220;
        Student.weight = "85.0";
        return false;
        break;
    }
    return false;
}

/**
 * @brief points to grade
 *
 * @param grade input points.
 * @return char grade of students.
 */
char ptog(float grade)
{
    if (grade > 9)
        return 'S';
    else if (grade > 8)
        return 'A';
    else if (grade > 7)
        return 'B';
    else if (grade > 6)
        return 'C';
    else if (grade > 5.6)
        return 'D';
    else if (grade >= 5)
        return 'E';
    else
        return 'F';
}

/**
 * @brief take detail of a subject
 * 
 * @param subject_name  name of the subject you want to add.
 * @param full_marks full marks in the subject.
 * @param marks_scored marks you scored.
 */
void take_subj_info(std::string& subject_name, int& full_marks, int& marks_scored)
{
    fmt::print("Enter subject name           : ");
    std::cin.ignore();
    std::getline(std::cin, subject_name);

    fmt::print("Enter full marks of the paper: ");
    std::cin >> full_marks;

    fmt::print("Enter marks obtain           : ");
    std::cin >> marks_scored;   
}

#endif