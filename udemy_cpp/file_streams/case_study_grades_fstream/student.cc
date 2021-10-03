#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int grade{0};                                  // Variable to hold input grade
	double sum{0.0};                          // Variable to hold running total
	
	vector<int> grades;                                     // Define vector to store grades
	ifstream student_file("student.txt");
	string line;

	while (getline(student_file, line)) {               // Read in each line
		istringstream is(line);
		int grade;
		while (is >> grade) {                         // Read in each grade
			grades.push_back(grade);                  // Add grade to vector
		}
	}

	sort(grades.begin(), grades.end());             // Sort the grades
	size_t output_count{0};

	for (auto grade: grades) {                                // Output the grades, ten on each line
		cout << grade;
		if (output_count != 0 && output_count % 10 == 0) {
			cout << endl;
		}
		else if (output_count != grades.size()) {
			cout << ",";
		}
		sum += grade;                                     // Add this grade to the running total
		++output_count;
	}

	cout << grades.size() << " grades entered" << endl;
	cout << "Average grade is " << sum/grades.size() << endl;
}