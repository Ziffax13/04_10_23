#include <iostream>

using namespace std;

class Person
{
    string name;
    int age;
public:
    Person() = default;
    Person(string, int);
    void Print();
};

class Student : Person
{
    string university;
public:
    Student(string, string, int);
    void Print();
};

class Teacher: Person
{
    string school;
    double salary;
    string* subjects;
    int subcount;
public:
    Teacher(string, int, string, double, initializer_list<string>);
    ~Teacher();
    void Print();
};

class Driver : Person
{
    string registration;
    string serial;
    string license;
public:
    Driver(string, string, string, string, int);
    void Print();
};

class Doctor: Person
{
    string speciality;
    int experience;
    bool isDoctor;
public:
    Doctor(string, int, bool, string, int);
    void Print();
};

int main()
{
    Teacher t1("Walter", 50, "school 1", 545.45, { "math", "chemistry" });
    t1.Print();
}

Person::Person(string n, int a) : name(n), age(a)
{
}

void Person::Print()
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}

Student::Student(string u, string n, int a) : university(u), Person(n, a)
{
}

void Student::Print()
{
    this->Person::Print();
    cout << "University" << endl;
}

Teacher::Teacher(string n, int a, string sch, double sal, initializer_list<string> sub) : school(sch), salary(sal), Person(n, a)
{
    int size = sub.size();
    subjects = new string[size];
    for (const string* x = sub.begin(); x != sub.end(); x++)
    {
        *subjects = *x;
        subjects++;
    }
    subjects -= size;
    subcount = size;
}

Teacher::~Teacher()
{
    delete[] subjects;
}

void Teacher::Print()
{
    this->Person::Print();
    cout << "School: " << school << endl;
    cout << "Salary: " << salary << endl;
    cout << "Subjects: ";
    for (int i = 0; i < subcount; i++)
    {
        cout << subjects[i] << (i == subcount - 1 ? "" : ", ");
    }
    cout << endl;
}

Driver::Driver(string r, string s, string l, string n, int a) : registration(r), serial(s), license(l), Person(n, a)
{
}

void Driver::Print()
{
    this->Person::Print();
    cout << "Registration plate: " << registration << endl;
    cout << "Serial number: " << serial << endl;
    cout << "Driver's license " << license << endl;
}

Doctor::Doctor(string s, int ex, bool isd, string n, int a) : speciality(s), experience(ex), isDoctor(isd), Person(n, a)
{
}

void Doctor::Print()
{
    cout << "Speciality : " << speciality << endl;
    cout << "Experience: " << experience << endl;
    cout << "Is doctor: " << (isDoctor ? "Yes" : "No") << endl;
}