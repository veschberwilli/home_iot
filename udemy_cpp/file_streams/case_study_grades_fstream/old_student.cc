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
	cout << "Please enter the grades (-1 to finish)\n";

	vector<int> grades;                                     // Define vector to store grades
	while (cin >> grade && grade >= 0) {          // Read in grades
		grades.push_back(grade);                      // Add grade to vector
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