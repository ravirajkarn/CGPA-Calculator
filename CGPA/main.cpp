/**
 * @file main.cpp
 * @author Sumit Kumar (ravirajkarn@outlook.com)
 * @brief This is simple console CGPA calculator.
 * @version 0.1
 * @date 2024-07-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <fmt/core.h>
#include <fmt/color.h>
#include <cmath>
#include "classs.h"
#include <vector>

int main()
{
    int size = 94; // length of header and boundary 
    Child Student; // basic/personal information about student.
    size_t maximum = 12; // maximum length of subject entered. 
    float total_points = 0;  // total points to calculate CGPA.
    std::vector<Subject> subjects; // data of each subject.
    int no_of_subject; // how may subject user will enter.


    //* Input module
    header(size);
    give_pdetail(Student); // take users personal detail
    fmt::print("How many subject are there? ");
    std::cin >> no_of_subject;

    for (int i = 0; i < no_of_subject; i++)
    {
        std::string subj_name;
        int full_marks, marks_obtain;

        take_subj_info(subj_name, full_marks, marks_obtain); // gathering information about each subject.
        subjects.push_back(Subject(subj_name, full_marks, marks_obtain)); // storing information of each subject.
        maximum = (((subj_name.size()) > (maximum)) ? (subj_name.size()) : (maximum)); // storing the maximum length of subject.
    }
    

    //* Output module
    clear();
    header(size);
    fmt::print(fmt::bg(fmt::color::light_coral), "{0: <{1}}\n", " ",size);
    fmt::print(fmt::bg(fmt::color::light_coral) | fmt::emphasis::bold, "{0: ^{1}}\n", "REPORT CARD", size);
    fmt::print(fmt::bg(fmt::color::light_coral) | fmt::fg(fmt::color::white) | fmt::emphasis::underline, "{: <{}}\n", " ", size);
    fmt::print(fmt::bg(fmt::color::light_coral), "{1:>10}Name: {0:<{2}}\n", Student.name, " ", size - 16);
    fmt::print(fmt::bg(fmt::color::light_coral), "{0:>10}Class: {1:<}{0:>{2}}rollno: {3}{0:>10}\n","" , Student.classs, (size - 2 * 10 - 15 - Student.classs.size() - Student.rollno.size())  ,Student.rollno);
    fmt::print(fmt::bg(fmt::color::light_coral), "{1:>10}School: {0:<{2}}\n", Student.school, " ", size - 18);
    fmt::print(fmt::bg(fmt::color::light_coral), "{2:>{3}}Weight: {0}{2:>{4}}Present: {1}{2:>{3}}\n", Student.weight, Student.present, " ", 10, (size - 2 * 10 - 17 - Student.weight.size() - std::to_string(Student.present).size()));
    fmt::print(fmt::bg(fmt::color::light_coral) | fmt::fg(fmt::color::white_smoke) | fmt::emphasis::underline, "{0:>{1}}\n", ".", size);

    int x = (size -19 -47 -maximum);
    fmt::print(fmt::bg(fmt::color::light_coral) | fmt::emphasis::underline, "| {0:>6} | {1:^{2}} | {3:^12} | {4:^14} | {5:^8} | {6:^7} |\n", "", "Subject", maximum + x, "Full Marks", "Marks Obtain", "Points", "Grade");
    int i(0);
    for (const auto& subject : subjects)
    {
        i++;
        fmt::print(fmt::bg(fmt::color::light_coral) | fmt::emphasis::underline, "| {0:>5}) | {1:<{2}} | {3:^12} | {4:^14} | {5:^8.2} | {6:^7} |\n", i+1, subject.name() , maximum + x, subject.full_mark(), subject.score(), subject.point(), ptog(subject.point()));
        total_points =  total_points + subject.point();
    }
    
    
    fmt::print(fmt::bg(fmt::color::light_coral), "{0: <{1}}\n", " ",size);
    fmt::print(fmt::bg(fmt::color::light_coral), "{0: >{1}}{2: <{1}}\n", "CGPA: ",size/2,(static_cast<float>(total_points/no_of_subject)));
    fmt::print(fmt::bg(fmt::color::light_coral), "{0: <{1}}\n", " ",size);
    return 0;
}