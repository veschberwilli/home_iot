#include "student.h"
#include <vector>
#include <algorithm>

using namespace std;

// Equality operator - we compare the ID's
// If we compare names, we could accidentally match
// two different students who have the same name

bool student::operator ==(const student& other) const {
    if (id == other.id) {
               return true;
    }
    return false;
}

bool student::operator !=(const student& other) const {
    return !(*this == other);
}

bool student::operator <(const student& other) const {
	return id < other.id;
}

std::ostream& student::print(std::ostream& os) const {
	os << "(" << name << ", " << id << ")";
	return os;
}

std::ostream& operator << (std::ostream& os, const student& s) {
	return s.print(os);
}

int main() {
	student js1("John Smith", 1297668);
	student js2("John Smith", 2473268);
	cout << "Using equality operator\n";
	cout << js1 << " and " << js2 << " are " << (js1 == js2 ? "" : "not ") << "the same student" << endl;
	cout << "Using inequality operator\n";
	cout << js1 << " and " << js2 << " are " << (js1 != js2 ? "not " : "") << "the same student" << endl;
	student jr("James Raynard", 1048576);
	cout << jr << endl << endl;
	
	cout << js1 << " is " << (js1 < js2 ? "less" : "greater ") << " than " << js2 << endl;
	vector<student> students;
	students.push_back(js1);
	students.push_back(js2);
	students.push_back(jr);
	
	cout << "\nPrinting out all students:\n";
	for (auto s : students) {
		cout << s << endl;
	}
	
	cout << "\nSorting students...:\n";
	sort(students.begin(), students.end());
	
	cout << "\nPrinting out all students:\n";
	for (auto s : students) {
		cout << s << endl;
	}
}