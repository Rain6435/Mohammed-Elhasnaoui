#include "Student.h"
#include "Cours.h"
#include "Notes.h"


istream& operator>>(istream& istr, Student& r) {
	istr >> r.StudentFName;
	std::cout << endl;
	istr >> r.StudentName;
	std::cout << endl;
	istr >> r.StudentID;
	std::cout << endl;
	return istr;
}

ostream& operator<<(ostream& ostr, const Student& r) {
	ostr << r.StudentFName;
	std::cout << endl;
	ostr << r.StudentName;
	std::cout << endl;
	ostr << r.StudentID;
	std::cout << endl;
	
	return ostr;
}

istream& operator>>(istream& istr, Cours& r) {
	istr >> r.CourseID;
	std::cout << endl;
	istr >> r.CourseCode;
	std::cout << endl;
	istr >> r.CourseTitle;
	std::cout << endl;
	return istr;
}

ostream& operator<<(ostream& ostr, const Cours& r) {
	ostr << r.CourseID;
	std::cout << endl;
	ostr << r.CourseCode;
	std::cout << endl;
	ostr << r.CourseTitle;
	std::cout << endl;

	return ostr;
}


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

ostream& operator<<(ostream& ostr, const Notes& r) {
	ostr << r.Identifier;
	std::cout << endl;
	ostr << r.CourseCode;
	std::cout << endl;
	ostr << r.Note;
	std::cout << endl;
	ostr << r.StudentID;
	std::cout << endl;
	return ostr;
}

