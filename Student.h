#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;


//Création de la classe Student
class Student {
    // Ajout des opérateurs d'entrée et de sortie
    friend istream& operator>>(istream&, Student&);				
    friend ostream& operator<<(ostream&, const Student&);		
public:
    //Définition des objets de la classe 
    int StudentID;
    string StudentName;
    string StudentFName;
//Définition du construteur de défaut
public:Student();
//Définition du constructeur paramètré
public:Student(int ID, string Name, string FName) {
    StudentID = ID;
    StudentName = Name;
    StudentFName = FName;
}
};
#endif
