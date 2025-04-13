#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;
    char again;

    do {
        cout << "\n--- Simple Calculator ---\n";

        cout << "Enter first number: ";
        cin >> num1;

        cout << "Pick an operator (+, -, *, /): ";
        cin >> operation;

        cout << "Now enter second number: ";
        cin >> num2;

        // Just doing basic ops
        if (operation == '+') {
            cout << "\nSum is: " << (num1 + num2) << endl;
        } else if (operation == '-') {
            cout << "\nDifference is: " << (num1 - num2) << endl;
        } else if (operation == '*') {
            cout << "\nProduct comes out to: " << (num1 * num2) << endl;
        } else if (operation == '/') {
            if (num2 == 0) {
                cout << "\nOops... can't divide by zero. Try again maybe.\n";
            } else {
                cout << "\nResult after division: " << (num1 / num2) << endl;
            }
        } else {
            cout << "\nHmm!!! not sure what that operator is supposed to do.\n";
        }

        cout << "\nWanna go again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "\nOkay, that's all for now. Bye!\n";
    return 0;
}
