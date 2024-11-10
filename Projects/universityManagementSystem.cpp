#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Student {
private:
    string name;
    int id;
    string course;
    int year;
    int semester;
    string branch;

public:
    Student(string name, int id, string course, int year, int semester, string branch)
        : name(name), id(id), course(course), year(year), semester(semester), branch(branch) {}

    string getName() const {
        return name;
    }

    int getId() const {
        return id;
    }

    string getCourse() const {
        return course;
    }

    int getYear() const {
        return year;
    }

    int getSemester() const {
        return semester;
    }

    string getBranch() const {
        return branch;
    }

    void displayInfo() const {
        cout << "Student ID: " << id << ", Name: " << name
             << ", Course: " << course << ", Year: " << year
             << ", Semester: " << semester << ", Branch: " << branch << endl;
    }
};

class Node {
public:
    Student student;
    Node* left;
    Node* right;

    Node(Student student) : student(student), left(NULL), right(NULL) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* addRecursive(Node* current, Student student) {
        if (current == NULL) {
            return new Node(student);
        }

        if (student.getId() < current->student.getId()) {
            current->left = addRecursive(current->left, student);
        } 
        else if (student.getId() > current->student.getId()) {
            current->right = addRecursive(current->right, student);
        }
        return current;
    }

    Node* removeRecursive(Node* current, int id) {
        if (current == NULL) {
            return NULL;
        }

        if (id == current->student.getId()) {
            if (current->left == NULL && current->right == NULL) {
                return NULL;
            }
            if (current->right == NULL) {
                return current->left;
            }
            if (current->left == NULL) {
                return current->right;
            }
            Student smallestStudent = findSmallestStudent(current->right);
            current->student = smallestStudent;
            current->right = removeRecursive(current->right, smallestStudent.getId());
            return current;
        }

        if (id < current->student.getId()) {
            current->left = removeRecursive(current->left, id);
            return current;
        }
        current->right = removeRecursive(current->right, id);
        return current;
    }

    Student findSmallestStudent(Node* root) {
        return root->left == NULL ? root->student : findSmallestStudent(root->left);
    }

    Student* searchRecursive(Node* current, int id) {
        if (current == NULL) {
            return NULL;
        }
        if (id == current->student.getId()) {
            return &current->student;
        }
        return id < current->student.getId() ? searchRecursive(current->left, id) : searchRecursive(current->right, id);
    }

    void inOrderTraversal(Node* node) {
        if (node != NULL) {
            inOrderTraversal(node->left);
            node->student.displayInfo();
            inOrderTraversal(node->right);
        }
    }

public:
    BinarySearchTree() : root(NULL) {}

    void addStudent(Student student) {
        root = addRecursive(root, student);
    }

    bool removeStudent(int id) {
        if (searchStudent(id) != NULL) {
            root = removeRecursive(root, id);
            return true;
        }
        return false;
    }

    Student* searchStudent(int id) {
        return searchRecursive(root, id);
    }

    void displayStudents() {
        inOrderTraversal(root);
    }

    void initializeDefaultStudents() {
        addStudent(Student("Aryan Singh", 1, "Bcom", 2, 4, "CSE"));
        addStudent(Student("Om Tiwari", 2, "Btech", 3, 6, "EEE"));
        addStudent(Student("Khyati Mishra", 3, "BA", 1, 2, "ME"));
        addStudent(Student("Sarthak Gautam", 4, "BSC", 4, 8, "CE"));
    }
};

int main() {
    BinarySearchTree bst;
    bst.initializeDefaultStudents();
    int choice;

    do {
        cout << endl << "University Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Remove Student" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Display Students" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, course, branch;
            int id, year, semester;
            cout << "Enter Student Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Course: ";
            cin.ignore();
            getline(cin, course);
            cout << "Enter Year: ";
            cin >> year;
            cout << "Enter Semester: ";
            cin >> semester;
            cout << "Enter Branch: ";
            cin.ignore();
            getline(cin, branch);
            bst.addStudent(Student(name, id, course, year, semester, branch));
            cout << "Student added successfully!" << endl;
            break;
        }
        case 2: {
            int removeId;
            cout << "Enter Student ID to remove: ";
            cin >> removeId;
            if (bst.removeStudent(removeId)) {
                cout << "Student removed successfully!" << endl;
            } else {
                cout << "Student not found." << endl;
            }
            break;
        }
        case 3: {
            int searchId;
            cout << "Enter Student ID to search: ";
            cin >> searchId;
            Student* foundStudent = bst.searchStudent(searchId);
            if (foundStudent != NULL) {
                foundStudent->displayInfo();
            } else {
                cout << "Student not found." << endl;
            }
            break;
        }
        case 4:
            cout << "Students in the university:" << endl;
            bst.displayStudents();
            break;
        case 5:
            cout << "Exiting." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
