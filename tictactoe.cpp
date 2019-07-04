/* Tic-Tac-Toe:
Write a program that allows two players to play a game of tic-tac-toe. Use a two- dimensional char array with three rows and three columns as the game board.
Each element of the array should be initialized with an asterisk (*). The program should run a loop that
• Displays the contents of the board array
• Allows player 1 to select a location on the board for an X. The program should ask the user to enter the row and column number.
• Allows player 2 to select a location on the board for an O. The program should ask the user to enter the row and column number.
• Determines whether a player has won, or a tie has occurred. If a player has won, the program should declare that player the winner and end. 
  If a tie has occurred, the program should say so and end.
Player 1 wins when there are three Xs in a row on the game board. The Xs can appear in a row, in a column, or diagonally across the board. 
A tie occurs when all of the locations on the board are full, but there is no winner. */

#include <iostream>
#include <iomanip>
using namespace std;

char board[3][3] = { {'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'} }; // I used periods instead of asterisks
                                                                          // because I like the look better.
void displayBoard(); // Function prototypes
bool checkWin();
void playerOne();
void playerTwo();

int main() 
{   
    displayBoard(); 
    while (true)
    {
        playerOne(); 
        if (checkWin())
            break;
        playerTwo();
        if (checkWin())
            break;
    }

    return 0;
}

bool checkWin() // Checks for win or tie, and outputs appropriate message
{
    char win = 't';

    for (int count = 0; count < 3; count++) // Checks for horizontal win
    {
        if (board[count][0] == board[count][1] && board[count][1] == board[count][2] && board[count][0] != '.')
            win = board[count][0];
    }

    for (int count = 0; count < 3; count++) // Checks for vertical win
    {
        if (board[0][count] == board[1][count] && board[1][count] == board[2][count] && board[0][count] != '.')
            win = board[0][count];
    }

    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != '.') || // Checks for diagonal win
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != '.'))
            win = board[1][1];

    if (win != 'x' && win != 'o')
    {
        for (int count = 0; count < 3; count++) // Checks for tie
        {
            for (int num = 0; num < 3; num++)
            {
                if (board[count][num] == '.')
                    win = 'n';
            }
        }
    }

    switch (win)
    {
        case 'x': cout << "Player One wins!!!\n\n";
                  return true;
        case 'o': cout << "Player Two wins!!!\n\n";
                  return true;
        case 't': cout << "Tie!!!\n\n";
                  return true;
        case 'n': return false;
    }
}

void displayBoard() // Displays current game board
{
    cout << endl;
    for (int rows = 0; rows < 3; rows++)
    {
        for (int cols = 0; cols < 3; cols++)
            cout << setw(2) << board[rows][cols];
        cout << endl;
    }
    cout << endl;
}

void playerOne() // Player One's turn
{
    int row, col;
    cout << "Player One, please enter the row and column of the space you wish to take, separated by a space: ";
    cin >> row >> col;

    while (row > 3 || row < 1 || col > 3 || col < 1) // Input validation
    {
        cout << "Please enter valid numbers! Try again: ";
        cin >> row >> col;
    }

    while (board[row - 1][col - 1] != '.') // Ensures that the space is free
    {
        cout << "That space is taken! Try again: ";
        cin >> row >> col;
    }

    board[row - 1][col - 1] = 'x';
    displayBoard();
}

void playerTwo() // Player Two's turn
{
    int row, col;
    cout << "Player Two, please enter the row and column of the space you wish to take, separated by a space: ";
    cin >> row >> col;

    while (row > 3 || row < 1 || col > 3 || col < 1) // Input validation
    {
        cout << "Please enter valid numbers! Try again: ";
        cin >> row >> col;
    }

    while (board[row - 1][col - 1] != '.') // Ensures that the space is free
    {
        cout << "That space is taken! Try again: ";
        cin >> row >> col;
    }

    board[row - 1][col - 1] = 'o';
    displayBoard();
}