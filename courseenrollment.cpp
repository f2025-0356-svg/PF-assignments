#include <iostream>
#include <vector>
using namespace std;


struct Student {
    string name;  
    int id;
};


struct Course {
    string courseName;  
    string courseCode;  
    vector<Student> students;
};


Student inputStudent() {
    Student s;

    cout << "Student Name (one word only): ";
    cin >> s.name;

    cout << "Student ID: ";
    cin >> s.id;

    return s;
}


Course inputCourse() {
    Course c;
    int numStudents;

    cout << endl << "Course Name (one word only): ";
    cin >> c.courseName;

    cout << "Course Code: ";
    cin >> c.courseCode;

    cout << "Number of students enrolled: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; i++) {
        cout << endl << "Enter details for student " << i + 1 << endl;
        Student s = inputStudent();
        c.students.push_back(s);
    }

    return c;
}


void displayCourses(const vector<Course>& courses) {
    cout <<endl<< " ==== COURSE ENROLLMENT DETAILS ===== " << endl;

    for (int i = 0; i < courses.size(); i++) {
        cout << endl << "Course Name: " << courses[i].courseName << endl;
        cout << "Course Code: " << courses[i].courseCode << endl;
        cout << "Enrolled Students:" << endl;

        for (int j = 0; j < courses[i].students.size(); j++) {
            cout << "  Name: " << courses[i].students[j].name
                 << ", ID: " << courses[i].students[j].id << endl;
        }
    }
}

int main() {
    int numCourses;
    vector<Course> courses;

    cout << "Enter number of courses: ";
    cin >> numCourses;

    for (int i = 0; i < numCourses; i++) {
        cout << endl << "Enter details for course " << i + 1 << endl;
        Course c = inputCourse();
        courses.push_back(c);
    }

    displayCourses(courses);

    return 0;
}
