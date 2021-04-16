#pragma once
#ifndef NOTES_H
#define NOTES_H

#include<string>
#include <iostream>
#include "Student.h"
#include "Cours.h"
using namespace std;

class Notes : public Cours, public Student
{
    friend istream& operator>>(istream&, Notes&);				
    friend ostream& operator<<(ostream&, const Notes&);			
public:
    string Identifier;
    float Note;
    Cours::CourseID;
    Student::StudentID;

public:Notes(string Ident, float StNotes, int StID, int CrID) {
    Identifier = Ident;
    Note = StNotes;
    CourseID = CrID;
    StudentID = StID;
}
};
#endif
