#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class TicTacToe {
public:
    TicTacToe() {
        board = vector<vector<char> >(3, vector<char>(3, ' ')); 
        currentPlayer = 'X';
    }

    void displayBoard() {
        cout << "\nCurrent Board:\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << " " << board[i][j] << " ";
                if (j < 2) cout << "|";
            }
            cout << "\n";
            if (i < 2) cout << "---+---+---\n";
        }
        cout << endl;
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin() {
    
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
                return true;
            }
        }
        
        return (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
               (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer);
    }

    bool checkDraw() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') return false;
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void resetBoard() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }
        currentPlayer = 'X';
    }

    char getCurrentPlayer() const {
        return currentPlayer;
    }

private:
    vector<vector<char> > board; 
    char currentPlayer;
};

int main() {
    TicTacToe game;
    char playAgain;

    do {
        game.resetBoard();
        bool gameWon = false;

        while (!gameWon) {
            game.displayBoard();
            int row, col;
            cout << "Player " << game.getCurrentPlayer() << ", enter your move (row and column, 1-3): ";
            cin >> row >> col;

            
            if (cin.fail() || row < 1 || row > 3 || col < 1 || col > 3) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter numbers between 1 and 3.\n";
                continue;
            }

            if (game.makeMove(row - 1, col - 1)) {
                game.displayBoard();

                if (game.checkWin()) {
                    cout << "Player " << game.getCurrentPlayer() << " wins!\n";
                    gameWon = true;
                } else if (game.checkDraw()) {
                    cout << "It's a draw!\n";
                    gameWon = true;
                } else {
                    game.switchPlayer();
                }
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
