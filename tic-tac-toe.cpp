#include <iostream>
using namespace std;

char board[3][3];

// Function to initialize the board
void initializeBoard()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = '-';
        }
    }
}

// Function to print the current board state
void printBoard()
{
    cout << "Board:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if the game has been won
bool checkWin(char player)
{
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the game ended in a draw
bool checkDraw()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}

// Function to play the game
void playGame()
{
    char currentPlayer = 'X';
    int row, col;

    initializeBoard();
    printBoard();

    while (true) {
        cout << "Player " << currentPlayer << "'s turn. Enter row and column (1-3): ";
        cin >> row >> col;

        // Convert input to zero-based index
        --row;
        --col;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '-') {
            board[row][col] = currentPlayer;
            printBoard();

            if (checkWin(currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            } else if (checkDraw()) {
                cout << "It's a draw!\n";
                break;
            }

            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }
}

// Main function
int main()
{
    playGame();
    return 0;
}
