#include <iostream>
#include <cstring>
using namespace std;

class Employee {
protected:
    char *name;
    long int ID;

public:
    Employee() {
        name = "None";
        ID = -9999;
    }

    Employee(Employee &someEmp) {
        name = someEmp.name;
        ID = someEmp.ID;
    }

    virtual void setPerson(char *n, long int id) {
        name = n;
        ID = id;
    }

    virtual void print() = 0;

    virtual ~Employee() {
        cout << "Employee profile deleted" << endl;
    }
};

class Manager : public Employee {
private:
    char *degree;

public:
    Manager() : Employee() {
        degree = "None";
    }

    Manager(char *n, long int id, char *deg) : Employee() {
        name = n;
        ID = id;
        degree = deg;
    }

    Manager(Manager &somemanager) : Employee(somemanager) {
        degree = somemanager.degree;
    }

    void setPerson(char *n, long int id, char *deg) {
        Employee::setPerson(n, id);
        degree = deg;
    }

    void print() override {
        cout << "Manager Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Degree: " << degree << endl;
    }

    ~Manager() {
        cout << "Manager profile deleted" << endl;
    }
};

class Secretary : public Employee {
private:
    bool contract;

public:
    Secretary() : Employee() {
        contract = true;
    }

    Secretary(char *n, long int id, char *contractType) : Employee() {
        name = n;
        ID = id;
        contract = strcmp(contractType, "permanent") == 0;
    }

    Secretary(Secretary &somesecretary) : Employee(somesecretary) {
        contract = somesecretary.contract;
    }

    void setPerson(char *n, long int id, char *contractType) {
        Employee::setPerson(n, id);
        contract = strcmp(contractType, "permanent") == 0;
    }

    void print() override {
        cout << "Secretary Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Contract: " << (contract ? "Permanent" : "Temporary") << endl;
    }

    ~Secretary() {
        cout << "Secretary profile deleted" << endl;
    }
};

int main() {
    // Answer for: Do you see any polymorphic behavior ? What do you learn from this example ?

    // Create a manager object using a base class pointer
    Employee * p = new Manager("Bruce Lee", 234567, "Dr.");

    // Demonstrates polymorphism because we use a base class pointer to call the derived class's print function
    p->print();

    Secretary p2;
    // Using the overloaded setPerson function to set secretary object
    // This calls the derived class version of setPerson() with 3 parameters
    p2.setPerson("Wilma Jones", 341256, "permanent");

    delete p;

    // Demonstrates polymorphism because 'p' is of type Employee*, but it points to a secretary object
    p = & p2;

    // This calls the print function in secretary
    p->print();

    return 0;
}
