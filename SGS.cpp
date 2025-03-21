#include <iostream>
#include <vector>

using namespace std;

// Student class definition
class Student {
private:
    static int idCounter;  // Static variable to generate unique student IDs
    int studentId;
    string name;
    float grade;

public:
    // Default constructor
    Student() {
        studentId = ++idCounter; // Assign unique ID
        name = "Unknown";
        grade = 0.0;
    }

    // Parameterized constructor for input
    Student(string studentName, float studentGrade) {
        studentId = ++idCounter;
        name = studentName;
        grade = studentGrade;
    }

    // Function to display student details
    void display() {
        cout << "Student ID: " << studentId << ", Name: " << name << ", Grade: " << grade << endl;
    }
};

// Initialize static variable
int Student::idCounter = 1000;

int main() {
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    vector<Student> students; // Dynamic array (vector) to store students

    // Taking student details input
    for (int i = 0; i < numStudents; i++) {
        string name;
        float grade;
        cout << "Enter name for student " << (i + 1) << ": ";
        cin >> name;
        cout << "Enter grade for " << name << ": ";
        cin >> grade;

        students.push_back(Student(name, grade));
    }

    // Displaying student details
    cout << "\n--- Student Records ---\n";
    for (Student &s : students) {
        s.display();
    }

    return 0;
}
