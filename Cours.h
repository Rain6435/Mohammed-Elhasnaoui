#pragma once
#ifndef COURS_H
#define COURS_H


#include <string>
#include <iostream>
using namespace std;


class Cours
{
    friend istream& operator>>(istream&, Cours&);					
    friend ostream& operator<<(ostream&, const Cours&);			
public:
    int CourseID;
    string CourseCode;
    string CourseTitle;

public:Cours();
public:Cours(int CID, string Code, string Title)
{
    CourseID = CID;
    CourseCode = Code;
    CourseTitle = Title;
}
};

#endif
