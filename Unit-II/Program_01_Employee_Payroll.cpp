#include <iostream>   // Input/output
#include <string>     // String data type
using namespace std;  // Use standard namespace

class Employee
{
protected:
    int empId;             // Employee ID
    string name;           // Employee name
    string department;     // Department

public:
    // Constructor to initialize employee details
    Employee(int id, string n, string dept)
        : empId(id), name(n), department(dept) {}

    // Display basic employee information
    void displayBasicInfo() const
    {
        cout << "ID: " << empId
             << " | Name: " << name
             << " | Department: " << department;
    }

    // Pure virtual function for salary calculation
    virtual double calculateSalary() const = 0;

    // Virtual destructor
    virtual ~Employee() = default;
};


// Full-time employee inherits Employee
class FullTimeemployee : public Employee
{
private:
    double monthlySalary;   // Monthly salary

public:
    // Constructor
    FullTimeemployee(int id, string n, string dept, double salary)
        : Employee(id, n, dept), monthlySalary(salary) {}

    // Override salary calculation
    double calculateSalary() const override
    {
        return monthlySalary;
    }

    // Display full-time employee details
    void display() const
    {
        displayBasicInfo();

        cout << " | Type: Full Time | Salary: Rs. "
             << calculateSalary() << endl;
    }
};


// Part-time employee inherits Employee
class PartTimeEmployee : public Employee
{
private:
    double hourlyRate;    // Payment per hour
    int hoursWorked;      // Hours worked

public:
    // Constructor
    PartTimeEmployee(int id, string n, string dept,
                     double rate, int hours)
        : Employee(id, n, dept),
          hourlyRate(rate),
          hoursWorked(hours) {}

    // Calculate salary using rate × hours
    double calculateSalary() const override
    {
        return hourlyRate * hoursWorked;
    }

    // Display part-time employee details
    void display() const
    {
        displayBasicInfo();

        cout << " | Type: Part Time | Salary: Rs. "
             << calculateSalary() << endl;
    }
};


// Intern inherits Employee
class Intern : public Employee
{
private:
    double stipend;       // Intern stipend

public:
    // Constructor
    Intern(int id, string n, string dept, double stipendAmount)
        : Employee(id, n, dept), stipend(stipendAmount) {}

    // Return intern stipend
    double calculateSalary() const override
    {
        return stipend;
    }

    // Display intern details
    void display() const
    {
        displayBasicInfo();

        cout << " | Type: Intern | Stipend: Rs. "
             << calculateSalary() << endl;
    }
};


int main()
{
    // Create employee objects
    FullTimeemployee f1(101, "Amit", "IT", 65000);
    PartTimeEmployee p1(102, "Sneha", "HR", 250, 120);
    Intern i1(103, "Rohan", "Marketing", 15000);

    // Display payroll heading
    cout << "=== Employee Payroll ===" << endl;

    // Display employee information
    f1.display();
    p1.display();
    i1.display();

    return 0;   // Successful execution
}
