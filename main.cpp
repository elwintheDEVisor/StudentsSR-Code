#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct HistoryEntry {
    string equation;
    string answer;
};

int ans;
int add(int num1, int num2);
int difference(int num1, int num2);
int multiply(int num1, int num2);
int divide(int num1, int num2);

const int HISTORY_SIZE = 100;
HistoryEntry history[HISTORY_SIZE];
int indexHistory = 0;

void addToHistory(const string& equation, const string& answer);
void displayHistory();
void searchHistory(const string& searchTerm);

int main() {
    int num1;
    int num2;
    char operation, back;
    int count = 0;

    int numEquations;
    cout << "\t\t\t\t\t\t#CALCULATOR#" << endl;
    cout << endl << endl;

    while (true) {
        cout << "How many equations do you want to input? ";
        if (cin >> numEquations && numEquations > 0) {
            break;
        } else {
            cout << "Invalid input. Please enter a positive integer.\n";
            cout << "Continue[Y/N]: ";
            cin >> back;
            if (back != 'Y' && back != 'y') {
                numEquations = 0;
                break;
            }
            cin.clear();
            cin.ignore(256, '\n');
        }
    }

    while (numEquations > 0) {
        system("CLS");
        cout << "Enter number: \t";

        if (!(cin >> num1)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(256, '\n');
            continue;
        }

        cin >> operation;

        if (!(cin >> num2)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(256, '\n');
            continue;
        }

        string equation = to_string(num1) + " " + operation + " " + to_string(num2);

        switch (operation) {
            case '+':
                ans = add(num1, num2);
                break;
            case '-':
                ans = difference(num1, num2);
                break;
            case '*':
                ans = multiply(num1, num2);
                break;
            case '/':
                ans = divide(num1, num2);
                break;
            default:
                cout << "Invalid operator" << endl;
                cout << "Continue[Y/N]: ";
                cin >> back;
                if (back != 'Y' && back != 'y') {
                    numEquations = 0;
                }
                cin.clear();
                cin.ignore(256, '\n');
                continue;
        }

        string answer = to_string(ans);

        addToHistory(equation, answer);

        cout << "Answer: \t" << ans << endl;

        numEquations--;
        count++;

        if (numEquations > 0) {
            while (true) {
                cout << "Continue to next equation? [Y/N]: ";
                cin >> back;
                if (back == 'Y' || back == 'y' || back == 'N' || back == 'n') {
                    break;
                } else {
                    cout << "Invalid input. Please enter 'Y' or 'N'.\n";
                }
            }

            if (back != 'Y' && back != 'y') {
                break;
            }
        }
    }

    displayHistory();

    string searchTerm;
    cout << "Enter a search term: ";
    cin >> searchTerm;
    searchHistory(searchTerm);

    return 0;
}

int add(int num1, int num2) {
    ans = num1 + num2;
    return ans;
}

int difference(int num1, int num2) {
    ans = num1 - num2;
    return ans;
}

int multiply(int num1, int num2) {
    ans = num1 * num2;
    return ans;
}

int divide(int num1, int num2) {
    if (num2 == 0) {
        cout << "UNDEFINED" << endl;
        return 0;
    } else {
        ans = num1 / num2;
        return ans;
    }
}

void addToHistory(const string& equation, const string& answer) {
    if (indexHistory < HISTORY_SIZE) {
        history[indexHistory].equation = equation;
        history[indexHistory].answer = answer;
        indexHistory++;
    }
}

void displayHistory() {
    cout << "History:" << endl;
    for (int i = 0; i < indexHistory; i++) {
        HistoryEntry* entryPtr = &history[i];
        cout << history[i].equation << " = " << history[i].answer << " --> " << entryPtr << endl;
    }
}

void searchHistory(const string& searchTerm) {
    cout << "Search Results:" << endl;
    bool found = false;
    for (int i = 0; i < indexHistory; i++) {
        if (history[i].equation.find(searchTerm) != string::npos) {
            cout << history[i].equation << " = " << history[i].answer << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No matching equations found." << endl;
    }
}
