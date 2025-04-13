#include <iostream>
using namespace std;

char sq[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}}; // board positions 
char player = 'X';
int n;

// prints the current board state
void drawBoard() {
    system("cls"); // windows only
    cout << "\n\n    Tic Tac Toe\n\n";
    
    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    
    cout << "     |     |     " << endl;
    cout << "  " << sq[0][0] << "  |  " << sq[0][1] << "  |  " << sq[0][2] << endl;
    
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    
    cout << "  " << sq[1][0] << "  |  " << sq[1][1] << "  |  " << sq[1][2] << endl;
    
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    
    cout << "  " << sq[2][0] << "  |  " << sq[2][1] << "  |  " << sq[2][2] << endl;
    
    cout << "     |     |     " << endl << endl;
}

// checking of someone has won or not
int checkWin() {
    // For rows
    if (sq[0][0] == sq[0][1] && sq[0][1] == sq[0][2])
        return 1;
    else if (sq[1][0] == sq[1][1] && sq[1][1] == sq[1][2])
        return 1;
    else if (sq[2][0] == sq[2][1] && sq[2][1] == sq[2][2])
        return 1;
    
    // For columns
    else if (sq[0][0] == sq[1][0] && sq[1][0] == sq[2][0])
        return 1;
    else if (sq[0][1] == sq[1][1] && sq[1][1] == sq[2][1])
        return 1;
    else if (sq[0][2] == sq[1][2] && sq[1][2] == sq[2][2])
        return 1;
    
    // For diagonals
    else if (sq[0][0] == sq[1][1] && sq[1][1] == sq[2][2])
        return 1;
    else if (sq[0][2] == sq[1][1] && sq[1][1] == sq[2][0])
        return 1;
    
    // check for game still going
    else if (sq[0][0] != '1' && sq[0][1] != '2' && sq[0][2] != '3' 
             && sq[1][0] != '4' && sq[1][1] != '5' && sq[1][2] != '6' 
             && sq[2][0] != '7' && sq[2][1] != '8' && sq[2][2] != '9')
        return 0;
    else
        return -1;
}

void getRowCol(int pos, int& r, int& c) {
    r = (pos-1)/3;
    c = (pos-1)%3;
}

int main() {
    int gameStatus;
    char restart;
    int choice;
    int row, col;
    
    do {  
        player = 'X';  
        
        // reset the board
        char n = '1';
        for(int i=0; i<3; i++) 
            for(int j=0; j<3; j++)
                sq[i][j] = n++;
        
        do {  
            drawBoard();
            
            // getting input from player
            cout << "Player " << player << ", enter a number: ";
            cin >> choice;
            
            getRowCol(choice, row, col);
            
            // Cheking my move is valid or not 
            if (choice < 1 || choice > 9 || sq[row][col]=='X' || sq[row][col]=='O'){
                cout << "\nInvalid move! Press any key to try again...";
                cin.ignore();
                cin.get();
                continue;
            }
            
            sq[row][col] = player;
            
            gameStatus = checkWin();
            
            player = (player == 'X') ? 'O' : 'X';
                    
        } while(gameStatus == -1);
            
        drawBoard();
                
        if(gameStatus == 1) {
            player = (player == 'X') ? 'O' : 'X';
            cout << "\aPlayer " << player << " wins!\n";
        } else {
            cout << "\aGame draw!\n";
        }
        
        // asking for replay to user 
        cout << "\nPlay again? (y/n): ";
        cin >> restart;
    } while(restart == 'y' || restart == 'Y');
    
    cout << "\nThanks for playing! Bye!\n";
    
    return 0;
}