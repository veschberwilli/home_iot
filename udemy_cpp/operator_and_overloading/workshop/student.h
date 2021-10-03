#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class student {
    std::string name;            // Student's name
    int id;                 // Student's ID number - unique to each student
    // Lots of other member data
	//...
public:
	student(const std::string& name, int id) : name(name), id(id) {} // Constructor
	// Accept compiler-generated defaults for copy constructor and assignment operator
	// student(student& other) : name(other.name), id(other.id) {}
	// student& operator=(student&) {name = other.name; id = other.imag;}
	
	// Unary operators are member functions
	bool operator ==(const student& other) const;
	bool operator !=(const student& other) const;
	bool operator <(const student& other) const;
	
	// Lots of other member functions
	// ...
	std::ostream& print(std::ostream& os) const;
};

//Binary operators are non-member functions
std::ostream& operator << (std::ostream&, const student&);

#endif //STUDENT_H