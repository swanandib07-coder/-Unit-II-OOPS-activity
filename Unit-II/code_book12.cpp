#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Person {
protected:
    string name;

public:
    explicit Person(string personName) : name(move(personName)) {}

    void displayName() const {
        cout << "Name: " << name << '\n';
    }
};

class Student : virtual public Person {
public:
    Student() : Person("Unknown") {}
};

class Employee : virtual public Person {
public:
    Employee() : Person("Unknown") {}
};

class TeachingAssistant : public Student, public Employee {
public:
    explicit TeachingAssistant(string assistantName)
        : Person(move(assistantName)), Student(), Employee() {}
};

int main() {
    TeachingAssistant assistant("Riya");
    assistant.displayName();
    return 0;
}
