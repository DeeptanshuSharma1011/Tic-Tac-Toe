#include <iostream>
using namespace std;

char board[3][3];

void initBoard() {
    char c = '1';
    for (auto &row : board)
        for (char &cell : row)
            cell = c++;
}

void showBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2];
        if (i < 2) cout << "\n-----------\n";
    }
    cout << "\n\n";
}

bool win(char p) {
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == p && board[i][1] == p && board[i][2] == p) ||
            (board[0][i] == p && board[1][i] == p && board[2][i] == p))
            return true;
    return (board[0][0] == p && board[1][1] == p && board[2][2] == p) ||
           (board[0][2] == p && board[1][1] == p && board[2][0] == p);
}

bool draw() {
    for (auto &row : board)
        for (char cell : row)
            if (cell != 'X' && cell != 'O') return false;
    return true;
}

bool move(char p) {
    int pos;
    cout << "Player " << p << ", enter (1-9): ";
    cin >> pos;
    if (pos < 1 || pos > 9) return false;
    int r = (pos - 1) / 3, c = (pos - 1) % 3;
    if (board[r][c] == 'X' || board[r][c] == 'O') return false;
    board[r][c] = p;
    return true;
}

int main() {
    initBoard();
    char player = 'X';

    while (true) {
        showBoard();
        if (!move(player)) {
            cout << "Invalid move. Try again.\n";
            continue;
        }
        if (win(player)) {
            showBoard();
            cout << "Player " << player << " wins!\n";
            break;
        }
        if (draw()) {
            showBoard();
            cout << "It's a draw!\n";
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
    return 0;
}
