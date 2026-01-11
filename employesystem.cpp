#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


struct Employee {
    int id;
    string name;
    double monthlySalary;
};

int main() {
    
    vector<Employee> employees;


    int number ;
    cout << "Enter number of employees: ";
    cin >> number;
    cin.ignore(); 

    for (int i = 0; i < number; i++) {
        Employee emp;
        cout << " Enter details for employee " << i + 1 << endl;
        cout << "ID: ";
        cin >> emp.id;
        cin.ignore();
        cout << "Name: ";
        getline(cin, emp.name);
        cout << "Monthly Salary: ";
        cin >> emp.monthlySalary;
        cin.ignore();

        employees.push_back(emp);
    }

    //
    double threshold;
    cout << " Enter yearly salary threshold : ";
    cin >> threshold;

    
    ofstream outFile("high_salary.txt");
    if (!outFile) { 
        cout << " Could not open file for writing ";
        return 1;
    }

    for (int i = 0; i < employees.size(); i++) {
        double yearlySalary = employees[i].monthlySalary * 12;
        if (yearlySalary > threshold) {
            outFile << employees[i].id << " " << employees[i].name << " " << yearlySalary << endl;
        }
    }

    outFile.close();
    cout <<endl<< "Filtered employee data has been saved to high_salary.txt"<<endl;

    
    ifstream inFile("high_salary.txt");
    if (!inFile) { 
        cout << endl<<"  Could not open file for reading."<<endl;
        return 1;
    }

    cout << " Employees with yearly salary above threshold: ";
    cout << "ID\tName\tYearly Salary " << endl;

    string id, name, salary;
    while (inFile >> id >> name >> salary) {
        cout << id << "\t" << name << "\t" << salary << endl;
    }

    inFile.close();

    return 0;
}
