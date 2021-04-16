// AQL Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Student.h"
#include "Cours.h"
#include "Notes.h"
#include <Windows.h>
#include <fstream>

using namespace std;


int main()
{
    
    vector<Student> ListOfStudents;
    vector<Notes> ListOfNotes;
    vector<Cours> ListOfCourses;

    //Teachers menu integers(Tar in variables declaration is for traget)
    int TarStudent;
    char TarChar;
    string TarString;

    int ID;
    string Name;
    string Fname;

    string CourseCode;
    string CourseTitle;
    int CourseID;

    string Identifier;
    float Note;

    bool problem = true;
    bool problem2 = true;

    
    while (problem == true) {
        cout << "Welcome to the primal school management software! If you are a teacher, please enter T. If you are a student and you are willing to register yourself and your courses, please enter S. If you are an administrator, please enter A." << endl;
        cin >> TarChar;
        TarChar = toupper(TarChar);

            /// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            if (TarChar == 'T') {
                cout << "You have now entered the teacher zone. You do not have all the rights in this software.You can either look for students or add notes to students. If you want to add notes for a student, please press the + button. If you want to search for a student, please press L." << endl;

                cin >> TarChar;
                TarChar = toupper(TarChar);

                if (TarChar == 'L') {
                    cout << "Please enter the ID of the student that you are looking for." << endl;
                    cin >> TarStudent;
                    for (auto x : ListOfStudents) {
                        if (x.StudentID == TarStudent)
                        {
                            cout << x;
                            problem2 = false;
                        }
                        else
                        {
                            cout << "The student doesn't exist.";
                            break;
                        }
                    }
                }/*
                else {
                    cout << "Wrong input."<<endl;
                    continue;
                }*/
                
            
                if (TarChar == '+') {
                    cout << "Enter the student's ID: "; cin >> TarStudent; cout << endl;
                    for (auto x:ListOfStudents) {
                        if (x.StudentID == TarStudent)
                        {
                            cout << x << endl;
                            Identifier = x.StudentFName + x.StudentName;
                            break;
                        }
                    }
                    cout << "The course ID: "; cin >> CourseID;
                    cout << "Enter the result that you want to put. "; cin >> Note; cout << endl;
                    Notes note(Identifier, Note, TarStudent, CourseID);
                    ListOfNotes.push_back(note);
                    break;
                }/*
                else
                {
                    cout << "Wrong input." << endl;;
                }*/
            }

        

        /// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        if (TarChar == 'S') {
            cout << "You have entered the student zone. You do not have all the rights in this software. If you want to register yourself, please enter R. If you are aleredy a student and you want to see your courses and notes, please enter C." << endl;
            cin >> TarChar;
            TarChar = toupper(TarChar);
            if (TarChar == 'R')
            {
                cout << "Enter your ID"; cin >> ID; cout << endl;
                cout << "Enter your name"; cin >> Fname; cout << endl;
                cout << "Enter your last name"; cin >> Name; cout << endl;
                Student student(ID, Fname, Name);
                ListOfStudents.push_back(student);
                break;
            }
            else
            {
                cout << "Wrong input." << endl;
                continue;
            }
            if (TarChar == 'C') {
                cout << "Please enter your student ID";
                cin >> TarStudent;
                for (auto x : ListOfStudents) {
                    if (x.StudentID == TarStudent)
                    {
                        cout << x << endl;
                    }
                }
                for (auto x:ListOfNotes) {
                    if (x.StudentID == TarStudent)
                    {
                        cout << x << endl;
                    }
                } 
                break;

            }
            else
            {
                cout << "Wrong input."<<endl;;
                continue;
            }

        }  
        
        /// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       
    
        if (TarChar == 'A') {
        cout << "You have entered the administrator zone. You have all the rights in this software. You can look for students, create students,add notes to students,display all the notes, create courses or display all the courses." << endl;
        cout << "Here are the commands:" << endl << "Student search: STDSRC" << endl << "Student creation: STDCRT" << endl << "Adding notes to student: STDNOT" << endl << "Create course: CRSCRT" << endl << "Display all notes: DSPANT" << endl << "Display all students: DSPSTD" << endl << "Display all courses: DSPCRS" << endl;
        cin >> TarString;
        if (TarString == "STDSRC") {
            cout << "Please enter the ID of the student that you are looking for." << endl;
            cin >> TarStudent;
            for (auto x : ListOfStudents) {
                if (x.StudentID == TarStudent)
                {
                    cout << x;
                }
            }
            break;
        }
        else
        {
            cout << "Wrong input.";
            continue;
        }
        if (TarString == "STDCRT") {
            cout << "Enter the student ID"; cin >> ID; cout << endl;
            cout << "Enter the student's first name"; cin >> Fname; cout << endl;
            cout << "Enter the student last name"; cin >> Name; cout << endl;
            Student student(ID, Fname, Name);
            ListOfStudents.push_back(student);
            break;
        }
        else
        {
            cout << "Wrong input."<<endl;
            continue;
        }

        if (TarString == "STDNOT") {
            cout << "The course ID: "; cin >> CourseID;
            cout << "Enter the result that you want to put. "; cin >> Note; cout << endl;
                Notes note(Identifier, Note, TarStudent, CourseID);
                cout << note;
                ListOfNotes.push_back(note);
                break;
        }
        else
        {
            cout << "Wrong input."<<endl;
            continue;
        }
        if (TarString == "CRSCRT") {
             cout << "Enter the course code" << endl; cin >> CourseCode;
             cout << "Enter the course title" << endl; cin >> CourseTitle;
             cout << "Enter the course ID" << endl; cin >> CourseID;
             Cours cours(CourseID, CourseCode, CourseTitle);
             ListOfCourses.push_back(cours);
             break;
        }
        else
        {
            cout << "Wrong input."<<endl;
            continue;
        }
        if (TarString == "DSPANT") {
            for (auto x : ListOfNotes)
            {
                cout << x << endl;
            } break;
        }
        else {
            cout << "Wrong input."<<endl;
            continue;
        }
        if (TarString == "DSPSTD") {
            for (auto x : ListOfStudents)
            {
                cout << x << endl;
            } break;
        }
        else
        {
            cout << "Wrong input.";
            continue;
        }
        if (TarString == "DSPCRS") {
            for (auto x : ListOfCourses)
            {
                cout << x << endl;
            }
            break;
        }
        else
        {
            cout << "Wrong input.";
            continue;
        }
       }
    }


    cout << "If you want to print the notes of a student, please enter his ID." << endl;
    cin >> TarStudent;
    ofstream outfile("Notes.txt");

    for (auto x : ListOfNotes)
    {
        if (x.StudentID == TarStudent)
        {
            outfile << x << endl;
        }
    }
    outfile.open("Notes.txt");

    return 0;
    }


Student::Student(){}
Cours::Cours(){}
