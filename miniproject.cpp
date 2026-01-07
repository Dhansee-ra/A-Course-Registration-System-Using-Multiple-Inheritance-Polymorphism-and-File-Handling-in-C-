#include <iostream>
#include <fstream>
using namespace std;

class Student {
protected:
    int studentId;
    string studentName;

public:
    void getStudentDetails() {
        cout << "Enter Student ID: ";
        cin >> studentId;
        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, studentName);
    }
};

class Course {
protected:
    int courseId;
    string courseName;

public:
    virtual void selectCourse() = 0;  
};

class Registration : public Student, public Course {
public:
    void selectCourse() {
        cout << "\nAvailable Courses:\n";
        cout << "1. C++ Programming\n";
        cout << "2. Data Structures\n";
        cout << "3. Web Development\n";
        cout << "Choose Course ID: ";
        cin >> courseId;

        switch (courseId) {
            case 1:
                courseName = "C++ Programming";
                break;
            case 2:
                courseName = "Data Structures";
                break;
            case 3:
                courseName = "Web Development";
                break;
            default:
                courseName = "Invalid Course";
        }
    }

    void saveToFile() {
        ofstream file("registrations.txt", ios::app);
        if (file.is_open()) {
            file << studentId << " | "
                 << studentName << " | "
                 << courseId << " | "
                 << courseName << endl;
            file.close();
        }
    }

    void display() {
        cout << "\n--- Registration Details ---\n";
        cout << "Student ID: " << studentId << endl;
        cout << "Student Name: " << studentName << endl;
        cout << "Course ID: " << courseId << endl;
        cout << "Course Name: " << courseName << endl;
    }
};

int main() {
    Registration r;
    int choice;

    do {
        cout << "\n===== Course Registration System =====\n";
        cout << "1. Register Student\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            r.getStudentDetails();
            r.selectCourse();
            r.saveToFile();
            r.display();
            cout << "\nRegistration Successful!\n";
        }

    } while (choice != 2);

    cout << "\nThank you for using the system.\n";
    return 0;
}

