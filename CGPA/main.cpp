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

int main()
{
    int size = 94 ;
    static int no_of_subject;
    Child Student;
    size_t maximum = 12;
    float total_points = 0;

    //* Input module
    header(size);
    give_pdetail(Student); // take users personal detail

    fmt::print("How many subject are there? ");
    std::cin >> no_of_subject;
    subject subj[no_of_subject];

    for (int i = 0; i < no_of_subject; i++)
    {
        subj[i].init();
        maximum = std::max(subj[i].name().size(), maximum);
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
    for (int i = 0; i < no_of_subject; i++)
    {
        fmt::print(fmt::bg(fmt::color::light_coral) | fmt::emphasis::underline, "| {0:>5}) | {1:<{2}} | {3:^12} | {4:^14} | {5:^8.2} | {6:^7} |\n", i+1, subj[i].name(), maximum + x, subj[i].full_mark(), subj[i].score(), subj[i].point(), ptog(subj[i].point()));
        total_points =  total_points + subj[i].point();        
    }
    
    fmt::print(fmt::bg(fmt::color::light_coral), "{0: <{1}}\n", " ",size);
    fmt::print(fmt::bg(fmt::color::light_coral), "{0: >{1}}{2: <{1}}\n", "CGPA: ",size/2,(static_cast<float>(total_points/no_of_subject)));
    fmt::print(fmt::bg(fmt::color::light_coral), "{0: <{1}}\n", " ",size);
    return 0;
}