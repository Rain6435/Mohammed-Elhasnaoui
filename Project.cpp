#include "Student.h"
#include "Cours.h"
#include "Notes.h"


//Flux d'entrée pour les élèments de types Student
istream& operator>>(istream& istr, Student& r) {
	istr >> r.StudentFName;
	std::cout << endl;
	istr >> r.StudentName;
	std::cout << endl;
	istr >> r.StudentID;
	std::cout << endl;
	return istr;
}

//Flux de sortie pour les élèments de types Student
ostream& operator<<(ostream& ostr, const Student& r) {
	ostr << r.StudentFName;
	std::cout << ",";
	ostr << r.StudentName;
	std::cout << ",";
	ostr << r.StudentID;
	std::cout << endl;
	
	return ostr;
}

//Flux d'entrée pour les élèments de types Cours
istream& operator>>(istream& istr, Cours& r) {
	istr >> r.CourseID;
	std::cout << endl;
	istr >> r.CourseCode;
	std::cout << endl;
	istr >> r.CourseTitle;
	std::cout << endl;
	return istr;
}

//Flux de sortie pour les élèments de types Cours
ostream& operator<<(ostream& ostr, const Cours& r) {
	ostr << r.CourseID;
	std::cout << ",";
	ostr << r.CourseCode;
	std::cout << ",";
	ostr << r.CourseTitle;
	std::cout << endl;

	return ostr;
}

//Flux d'entrée pour les élèments de types Notes
istream& operator>>(istream& istr, Notes& r) {
	istr >> r.Identifier;
	std::cout << endl;
	istr >> r.CourseCode;
	std::cout << endl;
	istr >> r.Note;
	std::cout << endl;
	istr >> r.StudentID;
	std::cout << endl;
	return istr;
}

//Flux de sortie pour les élèments de types Notes
ostream& operator<<(ostream& ostr, const Notes& r) {
	ostr << r.Identifier;
	std::cout << ",";
	ostr << r.CourseCode;
	std::cout << ",";
	ostr << r.Note;
	std::cout << ",";
	ostr << r.StudentID;
	std::cout << endl;
	return ostr;
}

