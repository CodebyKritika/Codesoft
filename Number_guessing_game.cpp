#include <iostream>
#include <random>

using namespace std;

int main() {
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(1, 100);
    
    int randomNumber = distrib(gen);
    int guess;
    int attempts = 0;
    
    cout << "=== NUMBER GUESSING GAME ===\n" << endl;
    
    cout << "I've selected a number between 1 and 100." << endl;
    
    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;
        
        if (guess < 1 || guess > 100) {
            cout << "Warning!!!! Your guess is not in specified Range, Please enter a number between 1 and 100." << endl;
            continue;
        }
        
        attempts++;

        if (guess < randomNumber) {
            cout << "The guessed number is Too low! Try again." << endl;
        } else if (guess > randomNumber) {
            cout << "Ohh!! Now the guessed number is Too high! Try again." << endl;
        } else {
            cout << "\nCongratulations!! Buddy You guessed the correct number!\n" << endl;
            cout << "You took " << attempts << " attempts to find the number." << endl;
            break;
        }
    }
    
    return 0;
}
