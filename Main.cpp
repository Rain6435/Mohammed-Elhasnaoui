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

    //Création des listes de manière dynamique pour y entreposer les différents étudiants, notes et cours.
    vector<Student> ListOfStudents;
    vector<Notes> ListOfNotes;
    vector<Cours> ListOfCourses;

    //Création des variables qui vont être mis dans les constructeurs pour chaque type d'objet de classe

    //Variables Target, soit qui nous serve à "pointer" un objet de type Student ou qui nous sert pour vérifier le input
    int TarStudent;
    char TarChar;
    string TarString;


    //Variables pour les objets de types Student.
    int ID;
    string Name;
    string Fname;

    //Variables pour les objets de types Cours
    string CourseCode;
    string CourseTitle;
    int CourseID;


    //Variables spécifique aux objets de types Notes 
    string Identifier;
    float Note;


    //Création de la boolean d'infinité, soit qui va nous permettre 
    bool problem = true;

    
    //Boucle d'infinité qui nous permet de run le code à l'infini.
    while (problem == true) {

        //Invitation à l'utilisateur pour qu'il puisse entrer dans différents types de zones, soit celle d'enseignant, d'étudiant ou d'administrateur
        cout << "Welcome to the primal school management software! If you are a teacher, please enter T. If you are a student and you are willing to register yourself and your courses, please enter S. If you are an administrator, please enter A." << endl;
        
        //Commande de saisie
        cin >> TarChar;
        TarChar = toupper(TarChar);

            /////////////////////////////////////////////////////////////////////////////////////////////////Zone enseignant/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            if (TarChar == 'T') {
                //Invitation à l'enseignant de saisir l'action qu'il veut acomplir, soit de chercher un étudiant ou de lui ajouter un note
                cout << "You have now entered the teacher zone. You do not have all the rights in this software.You can either look for students or add notes to students. If you want to add notes for a student, please press the + button. If you want to search for a student, please press L." << endl;

                //Commande de saisie
                cin >> TarChar;
                TarChar = toupper(TarChar);

                //Cas de recehrche d'élève
                if (TarChar == 'L') {
                    //Invitation d'entrer le numéro de l'étudiant qu'il veut chercher 
                    cout << "Please enter the ID of the student that you are looking for." << endl;

                    //Commande de saisie
                    cin >> TarStudent;

                    //Recherche binaire dans la liste d'étudiants
                    for (auto x : ListOfStudents) {

                        //Condition d'existance
                        if (x.StudentID == TarStudent)
                        {
                            cout << x;
                        }
                        else
                        {
                            cout << "The student doesn't exist.";
                            
                        }
                    }
                }
                
                //Case d'ajout de cours
                if (TarChar == '+') {
                    //Invitation d'entrer le numéro de l'étudiant à qui on veut ajouter une note
                    cout << "Enter the student's ID: "; cin >> TarStudent; cout << endl;

                    //Recherche binaire de l'étudiant dans la liste d'étudiants
                    for (auto x:ListOfStudents) {

                        //Condition d'existance et de création de l'identifiant de l'étudiant
                        if (x.StudentID == TarStudent)
                        {
                            cout << x << endl;
                            Identifier = x.StudentFName + x.StudentName;
                            
                        }
                    }

                    //Invitation d'entrer le numéro du cours auquel l'enseignant veut ajouter une note
                    cout << "The course title: ";// 
                    cin >> CourseTitle;

                    //Invitation à définir la valeur du résultat
                    cout << "Enter the result that you want to put. "; 
                    cin >> Note; cout << endl;
                    
                   //Création de l'objet de type notes
                    Notes note(Identifier, Note, TarStudent, CourseTitle); 
                    
                    //Ajout de la note dans le tableu de notes
                    ListOfNotes.push_back(note);

                    //Retour à la case départ
                    break;
                }
            }

        

        ///////////////////////////////////////////////////////////////////////////////////////////////////Zone student////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        if (TarChar == 'S') {
            //Invitation à l'enseignant de saisir l'action qu'il veut acomplir, soit de chercher un étudiant ou de lui ajouter un note
            cout << "You have entered the student zone. You do not have all the rights in this software. If you want to register yourself, please enter R. If you are aleredy a student and you want to see your courses and notes, please enter C." << endl;
            
            //Commande de saisie
            cin >> TarChar;
            TarChar = toupper(TarChar);

            //Cas d'enregistrement
            if (TarChar == 'R')
            {
                //Invitation de saisie du numéro étudiant de l'élève
                cout << "Enter your ID"; cin >> ID; cout << endl;
                //Invitation de saisie du prémom
                cout << "Enter your name"; cin >> Fname; cout << endl;
                //Invitation de saisie du nom de famille
                cout << "Enter your last name"; cin >> Name; cout << endl;

                //Création du student
                Student student(ID, Fname, Name);

                //Placement du student dans la liste
                ListOfStudents.push_back(student);
                break;
            }
            
          
            //Cas de recherche notes
            if (TarChar == 'C') 
            {
                //Invitation de saisie du numéro d'étudiant de l'élève
                cout << "Please enter your student ID:";cin >> TarStudent;

                //Recherche binaire de l'étudiant dans la liste d'étudiant
                for (auto x : ListOfStudents) {

                    //Condition d'existence
                    if (x.StudentID == TarStudent)
                    {
                        cout << x << endl;
                    }
                }

                //Recherche binaire des notes correspondants au ID saisis
                for (auto x:ListOfNotes) {
                    if (x.StudentID == TarStudent)
                    {
                        cout << x << endl;
                    }
                } 
               

            }
           

        }  
        
        /////////////////////////////////////////////////////////////////////////////////////////////Administrator zone///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       
    
        if (TarChar == 'A') {
        //Invitation à l'administrateur d'entrer le code de la commande qu'il veut exécuter
        cout << "You have entered the administrator zone. You have all the rights in this software. You can look for students, create students,add notes to students,display all the notes, create courses or display all the courses." << endl;
        cout << "Here are the commands:" << endl << "Student search: STDSRC" << endl << "Student creation: STDCRT" << endl << "Adding notes to student: STDNOT" << endl << "Create course: CRSCRT" << endl << "Display all notes: DSPANT" << endl << "Display all students: DSPSTD" << endl << "Display all courses: DSPCRS" << endl;
        cin >> TarString;


        if (TarString == "STDSRC") {

            //Demande à l'administrateur d'entrer le numéro étudiant de l'étudiant qu'il cherche
            cout << "Please enter the ID of the student that you are looking for." << endl;

            //Commande de saisie
            cin >> TarStudent;

            //Recherche binaire de l'étudiant dans la liste d'étudiants
            for (auto x : ListOfStudents) {
                if (x.StudentID == TarStudent)
                {
                    cout << x;
                }
            }
            
        }
        
        if (TarString == "STDCRT") {

            //Demande à l'administrateur de saisir le numéro de l'étudiant qu'il souhaite créer
            cout << "Enter the student ID:" << endl;  

            //Commande de saisie 
            cin >> ID; cout << endl;

            cout << "Enter the student's first name:" << endl;
            //Commande de saisie
            cin >> Fname; cout << endl;

            cout << "Enter the student last name:" << endl;
            //Commande de saisie
            cin >> Name; cout << endl;

            //Création de l'étudiant
            Student student(ID, Fname, Name);

            //Ajout de l'étudiant dans la liste d'étudiants
            ListOfStudents.push_back(student);
            
        }
     

        if (TarString == "STDNOT") {
            cout << "The course title:" << endl; cin >> CourseTitle;
            cout << "The student ID:" << endl; cin >> TarStudent;
            cout << "Enter the result that you want to put." << endl; cin >> Note; cout << endl;
            for (auto x : ListOfStudents) {

                //Condition d'existance et de création de l'identifiant de l'étudiant
                if (x.StudentID == TarStudent)
                {
                    cout << x << endl;
                    Identifier = x.StudentFName + x.StudentName;

                }
            }
            Notes note(Identifier, Note, TarStudent, CourseTitle);
            cout << note << endl;
            ListOfNotes.push_back(note);
                
        }
      
        if (TarString == "CRSCRT") {

             cout << "Enter the course code" << endl; cin >> CourseCode;
             cout << "Enter the course title" << endl; cin >> CourseTitle;
             cout << "Enter the course ID" << endl; cin >> CourseID;
             Cours cours(CourseID, CourseCode, CourseTitle);
             ListOfCourses.push_back(cours);
             
        }
        
        if (TarString == "DSPANT") {
            for (auto x : ListOfNotes)
            {
                cout << x << endl;
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

        }
        
        if (TarString == "DSPSTD") {
            for (auto x : ListOfStudents)
            {
                cout << x << endl;
            } 
        }
       
        if (TarString == "DSPCRS") {
            for (auto x : ListOfCourses)
            {
                cout << x << endl;
            }
        
        }
       }
    }

    return 0;
    }


Student::Student(){}
Cours::Cours(){}
