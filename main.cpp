#include <bits/stdc++.h>
using namespace std;
class Student {
private:
    string name;
    string studentclass;
    int rollnumber;
    float marks;

public:
    Student(string name, string studentclass, int rollnumber, float marks)
        : name(name), studentclass(studentclass), rollnumber(rollnumber), marks(marks) {}

    char calculategrade() const {
        if (marks >= 90){ return 'A';}
        if (marks >= 80){ return 'B';}
        if (marks >= 70){ return 'C';}
        if (marks >= 60){ return 'D';}
        if (marks >= 50){ return 'e';}
        else{return 'F';}
    }

    void displayInfo() const {
        cout << "student name: " << name << endl;
        cout << "class: " << studentclass << endl;
        cout << "roll number: " << rollnumber << endl;
        cout << "marks: " << marks << endl;
        cout << "grade: " << calculategrade() << endl;
    }
};
class Date {
private:
    int day;
    int month;
    int year;

    bool isleapyear(int y) const {
        return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
    }

    bool isvaliddate() const {
        if (year < 1) return false;
        if (month < 1 || month > 12) return false;

        int daysinmonth[] = { 31, (isleapyear(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return (day >= 1 && day <= daysinmonth[month - 1]);
    }

public:
    Date(int day, int month, int year) : day(day), month(month), year(year) {}

    void setdate(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    void getdate(int &d, int &m, int &y) const {
        d = day;
        m = month;
        y = year;
    }

    void displaydate() const {
        if (isvaliddate()) {
            cout << "date: " << day << "/" << month << "/" << year << endl;
        } else {
            cout << "invalid date!" << endl;
        }
    }
};

class Employee {
private:
    string name;
    int employeeid;
    float salary;

public:
    Employee(string name, int id, float salary)
        : name(name), employeeid(id), salary(salary) {}

    void setSalary(float newSalary) {
        salary = newSalary;
    }

    void calculateSalary(float performanceBonus) {
        salary += performanceBonus;
    }

    void displayInfo() const {
        cout << "employee name: " << name << endl;
        cout << "employee id: " << employeeid << endl;
        cout << "salary: " << salary << endl;
    }
};
class Triangle {
private:
    float side1;
    float side2;
    float side3;

public:
    Triangle(float s1, float s2, float s3) : side1(s1), side2(s2), side3(s3) {}

    void determineType() const {
        if (side1 == side2 && side2 == side3) {
            cout << "is equilateral." << endl;
        } else if (side1 == side2 || side2 == side3 || side1 == side3) {
            cout << "is isosceles." << endl;
        } else {
            cout << "is scalene." << endl;
        }
    }
};
class Mother {
public:
    virtual void display() const {
        cout << "this is the mother class." << endl;
    }
};

class Daughter : public Mother {
public:
    void display() const {
        cout << "this is the daughter class." << endl;
    }
};

class Shape {
protected:
    float width;
    float height;

public:
    Shape(float w, float h) : width(w), height(h) {}
    virtual ~Shape() {}

    virtual float area() const = 0;
};

class TriangleShape : public Shape {
public:
    TriangleShape(float w, float h) : Shape(w, h) {}

    float area() const {
        return 0.5f * width * height;
    }
};

class Rectangle : public Shape {
public:
    Rectangle(float w, float h) : Shape(w, h) {}

    float area() const {
        return width * height;
    }
};
int main() {
    Student student("samo", "5th grade", 12345, 85.0f);
    student.displayInfo();
    cout << endl;
    Date date(29, 2, 2024);
    date.displaydate();
    cout << endl;
    Employee employee("ahmed", 6789, 50000.0f);
    employee.calculateSalary(5000.0f);
    employee.displayInfo();
    cout << endl;

    Triangle triangle1(3.0f, 3.0f, 3.0f);
    triangle1.determineType();
    Triangle triangle2(3.0f, 3.0f, 5.0f);
    triangle2.determineType();
    Triangle triangle3(3.0f, 4.0f, 5.0f);
    triangle3.determineType();
    cout << endl;
    Mother* motherPtr = new Daughter();
    motherPtr->display();
    delete motherPtr;
    cout << endl;
    TriangleShape triangle(10.0f, 5.0f);
    Rectangle rectangle(10.0f, 5.0f);

    cout << "Triangle Area: " << triangle.area() << endl;
    cout << "Rectangle Area: " << rectangle.area() << endl;

    return 0;
}
