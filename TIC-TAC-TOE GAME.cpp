#include <iostream>
#include <array>

using namespace std;

// Function prototypes
void displayBoard(const array<array<char, 3>, 3>& board);
bool checkWin(const array<array<char, 3>, 3>& board, char player);
bool checkDraw(const array<array<char, 3>, 3>& board);
bool isValidMove(const array<array<char, 3>, 3>& board, int row, int col);
void switchPlayer(char& currentPlayer);

int main() {
    array<array<char, 3>, 3> board = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char currentPlayer = 'X';
    bool gameEnded = false;

    while (!gameEnded) {
        // Display the board
        displayBoard(board);

        // Get player's move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        if (!isValidMove(board, row, col)) {
            cout << "Invalid move! Please try again." << endl;
            continue;
        }

        // Update the board with the player's move
        board[row - 1][col - 1] = currentPlayer;

        // Check for win
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameEnded = true;
        }
        // Check for draw
        else if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            gameEnded = true;
        }
        // Switch players
        else {
            switchPlayer(currentPlayer);
        }
    }

    return 0;
}

// Function to display the Tic-Tac-Toe board
void displayBoard(const array<array<char, 3>, 3>& board) {
    cout << "  1 2 3" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(const array<array<char, 3>, 3>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
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

// Function to check if the game is a draw
bool checkDraw(const array<array<char, 3>, 3>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to check if a move is valid
bool isValidMove(const array<array<char, 3>, 3>& board, int row, int col) {
    if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
        return false;
    }
    return true;
}

// Function to switch players
void switchPlayer(char& currentPlayer) {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}
