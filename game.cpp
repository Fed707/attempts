#include <iostream>
#include <string>
using namespace std;

class player {
    char symbol;
    string name;
public:
    player(char sym = 'X', string n = "Player X") : symbol(sym), name(n) {}
    char getSymbol() const { return symbol; }
    string getname() const { return name; }
};

class Board {
    char grid[3][3];
    int filledcells;
public:
    Board() : filledcells(0) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                grid[i][j] = ' ';
    }
    void drawboard() const {
        cout << "------------------" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "| ";
            for (int j = 0; j < 3; j++)
                cout << grid[i][j] << " | ";
            cout << endl << "------------------" << endl;
        }
    }
    bool isvalidmove(int row, int col) const {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && grid[row][col] == ' ');
    }
    void makemove(int row, int col, char symbol) {
        if (isvalidmove(row, col)) {
            grid[row][col] = symbol;
            filledcells++;
        }
    }
    bool checkwin(char symbol) const {
        for (int i = 0; i < 3; i++) {
            if (grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol)
                return true;
        }
        for (int i = 0; i < 3; i++) {
            if (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol)
                return true;
        }
        if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol)
            return true;
        if (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol)
            return true;
        return false;
    }
    bool isfull() const {
        return filledcells == 9;
    }
};

class tictactoe {
    Board board;
    player players[2];
    int currentplayerindex;
public:
    tictactoe() : currentplayerindex(0) {
        players[0] = player('X', "Player X");
        players[1] = player('O', "Player O");
    }
    player& getCurrentplayer() {
        return players[currentplayerindex];
    }
    void switchturn() {
        currentplayerindex = (currentplayerindex + 1) % 2;
    }
    void play() {
        cout << "Welcome to Tic-Tac-Toe" << endl;
        while (!board.isfull()) {
            board.drawboard();
            cout << getCurrentplayer().getname() << " (" << getCurrentplayer().getSymbol() << "), enter row (1-3) and column (1-3): ";
            int row, col;
            cin >> row >> col;
            row--; col--;
            if (!board.isvalidmove(row, col)) {
                cout << "Invalid move. Try again." << endl;
                continue;
            }
            board.makemove(row, col, getCurrentplayer().getSymbol());
            if (board.checkwin(getCurrentplayer().getSymbol())) {
                board.drawboard();
                cout << getCurrentplayer().getname() << " wins!" << endl;
                return;
            }
            switchturn();
        }
        board.drawboard();
        cout << "It's a draw!" << endl;
    }
};

int main() {
    tictactoe game;
    game.play();
    return 0;
}