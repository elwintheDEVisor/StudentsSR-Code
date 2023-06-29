#include <iostream>
#include <limits>
using namespace std;

class Student {
public:
    string name;
    string SRCODE;
    string Subjects;
    string Prof;
    string schedule;
};

class Node {
public:
    string details1;
    string details2;
    string details3;
    string details4;
    string details5;
    Node* next;
};

Node* head = NULL;

void AddNode(string details1, string details2, string details3, string details4, string details5) {
    Node* n, * curr;

    n = new Node();
    n->details1 = details1;
    n->details2 = details2;
    n->details3 = details3;
    n->details4 = details4;
    n->details5 = details5;
    n->next = NULL;

    if (head == NULL)
        head = n;
    else {
        curr = head;
        head = n;
        head->next = curr;
    }
}

void displayList(void) {
    Node* curr;
    curr = head;
    while (curr != NULL) {
        cout << "SR-CODE: " << curr->details1 << "\t" << "Students Name: " << curr->details2 << endl;
        curr = curr->next;
    }
}

bool askToAddAnotherStudent() {
    cout << "\nDo you want to add another student? (Y/N): ";
    char choice;
    cin >> choice;

    while (cin.fail() || (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')) {
        cout << "Invalid input. Please enter 'Y' or 'N': ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;
    }

    return (choice == 'Y' || choice == 'y');
}

void deleteNode(string inputSRCODE) {
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        if (curr->details1 == inputSRCODE) {
            if (prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }

            delete curr;
            cout << "Student with SRCODE " << inputSRCODE << " has been deleted." << endl;
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    cout << "The student with SRCODE " << inputSRCODE << " does not exist." << endl;
}

void displayMenu() {
    cout << "\nMain Menu:" << endl;
    cout << "1. View Existing Details" << endl;
    cout << "2. Delete Existing Details" << endl;
    cout << "3. Add Another Student Details" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int numStudents;
    string details1;
    string details2;
    string details3;
    string details4;
    string details5;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    Student* students = new Student[numStudents];

    for (int i = 0; i < numStudents; i++) {
        system("CLS");
        cout << "Enter Details of Student No. " << i + 1 << " of " << numStudents << endl;
        cout << "Enter SRCODE of Student No. " << i + 1 << ": ";
        cin >> students[i].SRCODE;
        cout << "Enter Name of Student No. " << i + 1 << ": ";
        cin >> students[i].name;
        cout << "Enter Subjects of Student No. " << i + 1 << ": ";
        cin >> students[i].Subjects;
        cout << "Enter Prof of Student No. " << i + 1 << ": ";
        cin >> students[i].Prof;
        cout << "Enter Schedule of Student No. " << i + 1 << ": ";
        cin >> students[i].schedule;
        cout << endl;

        details1 = students[i].SRCODE;
        details2 = students[i].name;
        details3 = students[i].Subjects;
        details4 = students[i].Prof;
        details5 = students[i].schedule;
        AddNode(details1, details2, details3, details4, details5);
    }

    displayList();

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                displayList();
                break;

            case 2: {
                string inputSRCODE;
                cout << "\nEnter the SRCODE to delete the student details (or 'q' to quit): ";
                cin >> inputSRCODE;

                if (inputSRCODE == "q" || inputSRCODE == "Q")
                    break;

                deleteNode(inputSRCODE);
                break;
            }

            case 3: {
                if (!askToAddAnotherStudent())
                    break;

                Student* resizedStudents = new Student[numStudents + 1];
                for (int i = 0; i < numStudents; i++) {
                    resizedStudents[i] = students[i];
                }

                delete[] students;
                students = resizedStudents;

                cout << "Enter Details of Student No. " << numStudents + 1 << endl;
                cout << "Enter SRCODE of Student No. " << numStudents + 1 << ": ";
                cin >> students[numStudents].SRCODE;
                cout << "Enter Name of Student No. " << numStudents + 1 << ": ";
                cin >> students[numStudents].name;
                cout << "Enter Subjects of Student No. " << numStudents + 1 << ": ";
                cin >> students[numStudents].Subjects;
                cout << "Enter Prof of Student No. " << numStudents + 1 << ": ";
                cin >> students[numStudents].Prof;
                cout << "Enter Schedule of Student No. " << numStudents + 1 << ": ";
                cin >> students[numStudents].schedule;
                cout << endl;

                details1 = students[numStudents].SRCODE;
                details2 = students[numStudents].name;
                details3 = students[numStudents].Subjects;
                details4 = students[numStudents].Prof;
                details5 = students[numStudents].schedule;
                AddNode(details1, details2, details3, details4, details5);

                numStudents++;
                break;
            }

            case 4:
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

    } while (choice != 4);

    delete[] students;

    return 0;
}
