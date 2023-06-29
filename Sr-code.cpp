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

class Node{
public:
    string details1;
    string details2;
    string details3;
    string details4;
    string details5;
    Node* next;
};

Node *head = NULL;

void AddNode(string details1, string details2, string details3, string details4, string details5){
Node *n, *curr;

n = new Node();
    n->details1 = details1;
    n->details2 = details2;
    n->details3 = details3;
    n->details4 = details4;
    n->details5 = details5;
    n->next = NULL;

    if(head==NULL)
    head=n;
    else{
        curr = head;
        head = n;
        head -> next = curr;
    }

}

void displayList(void){
        Node *curr;
        curr = head;
        while (curr!=NULL)
        {
        cout << "SR-CODE: " << curr->details1 << "\t" << "Students Name: " << curr->details2 << endl;
        curr = curr->next;
        }

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
    int temp;

    do {
        system("CLS");
        for (int i = 0; i < numStudents; i++) {
            cout << "Enter Details of Student No. " << i + 1 << endl;
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
            system("CLS");

            details1 = students[i].SRCODE;
            details2 = students[i].name;
            details3 = students[i].Subjects;
            details4 = students[i].Prof;
            details5 = students[i].schedule;
            AddNode(details1, details2, details3, details4, details5);
        }

        displayList();

        string inputSRCODE;
        do {
            cout << "\nEnter the SRCODE to display the details: ";
            cin >> inputSRCODE;

            temp = 0;
            for (int i = 0; i < numStudents; i++) {
                if (inputSRCODE == students[i].SRCODE) {
                    cout << "\nStudents Name: " << students[i].name;
                    cout << "\n\nDetails of Student No. " << i + 1 << ": ";
                    cout << "\n\nSubject: " << students[i].Subjects;
                    cout << "\t\t\tProf: " << students[i].Prof;
                    cout << "\t\t\tSchedule: " << students[i].schedule;
                    temp = 1;
                    break;
                }
            }

            if (temp == 0)
                cout << "\nThe student identified by the given SRCODE does not exist." << endl;

            cout << "\n\nDo you want to continue searching? (Y/N): ";
            char choice;
            cin >> choice;

            while (cin.fail() || (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')) {
                cout << "Invalid input. Please enter 'Y' or 'N': ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> choice;
            }

            if (choice != 'Y' && choice != 'y')
                break;
        } while (true);

        break;
    } while (true);

    delete[] students;

    return 0;
}
