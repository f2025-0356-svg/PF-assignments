#include <iostream>
#include <vector>
using namespace std;


struct Employee {
    char name[1000];
    int age;
    vector < vector <char> > skills;
};


void inputEmployee(Employee &emp) {
    int skillCount;

    cout << "Name ( with no spaces): ";
    cin >> emp.name;  

    cout << "Age: ";
    cin >> emp.age;

    cout << "Number of skills: ";
    cin >> skillCount;

    for (int i = 0; i < skillCount; i++) {
        vector<char> skill(1000);
        cout << "Enter skill " << i + 1 << endl;
        cin >> &skill[0];  
        emp.skills.push_back(skill);
    }
}


void displayEmployee(const Employee &emp, int index) {
    cout << "\nEmployee " << index + 1 << endl;
    cout << "Name: " << emp.name << endl;
    cout << "Age: " << emp.age << endl;
    cout << "Skills: ";

    for (int i = 0; i < emp.skills.size(); i++) {
        cout << &emp.skills[i][0] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    vector<Employee> employees;

    for (int i = 0; i < n; i++) {
        Employee emp;
        cout << endl << "Enter details for employee " << i + 1 << endl;
        inputEmployee(emp);
        employees.push_back(emp);
    }

    cout << endl<< "--- Employee Details ---" << endl;

    for (int i = 0; i < employees.size(); i++) {
        displayEmployee(employees[i], i);
    }

    return 0;
}
