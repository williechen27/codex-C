#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[9];      // 棋盤：0~8 對應 1~9
    int currentPlayer;  // 1 或 2

    void initBoard() {
        for (int i = 0; i < 9; ++i) {
            board[i] = '1' + i; // 初始化為 '1'..'9'
        }
        currentPlayer = 1;      // Player 1 先手
    }

    void printBoard() {
        cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " \n";
        cout << "---+---+---\n";
        cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " \n";
        cout << "---+---+---\n";
        cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
    }

    // 回傳 0: 尚未有人贏, 1: Player1 贏, 2: Player2 贏
    int checkWin() {
        int winLines[8][3] = {
            {0,1,2}, {3,4,5}, {6,7,8}, // rows
            {0,3,6}, {1,4,7}, {2,5,8}, // cols
            {0,4,8}, {2,4,6}           // diags
        };

        for (int i = 0; i < 8; ++i) {
            int a = winLines[i][0];
            int b = winLines[i][1];
            int c = winLines[i][2];
            if (board[a] == board[b] && board[b] == board[c]) {
                if (board[a] == 'X') return 1;
                if (board[a] == 'O') return 2;
            }
        }
        return 0;
    }

    bool isDraw() {
        // 沒有空格(1~9)且沒人贏 -> 平手
        for (int i = 0; i < 9; ++i) {
            if (board[i] != 'X' && board[i] != 'O')
                return false;
        }
        return true;
    }

    bool isValidMove(int pos) {
        if (pos < 1 || pos > 9) return false;
        if (board[pos - 1] == 'X' || board[pos - 1] == 'O') return false;
        return true;
    }

public:
    TicTacToe() {
        initBoard();
    }

    void play() {
        cout << "-- Tic Tac Toe -- CSIE@CGU\n";
        cout << "Player 1 (X) - Player 2 (O)\n";
        printBoard();

        while (true) {
            int move;
            if (currentPlayer == 1) {
                cout << "==> Player 1 (X), enter a number:";
            } else {
                cout << "==> Player 2 (O), enter a number:";
            }

            if (!(cin >> move)) {
                // 讀取失敗就結束（通常不會在測資發生）
                return;
            }

            if (!isValidMove(move)) {
                cout << "==> Invalid value, please enter again\n";
                continue; // 同一玩家重新輸入
            }

            // 落子
            char mark = (currentPlayer == 1) ? 'X' : 'O';
            board[move - 1] = mark;

            // 顯示棋盤
            printBoard();

            // 檢查勝負
            int winner = checkWin();
            if (winner == 1) {
                cout << "==> Player 1 wins!\n";
                break;
            } else if (winner == 2) {
                cout << "==> Player 2 wins!\n";
                break;
            } else if (isDraw()) {
                cout << "==> Game draw\n";
                break;
            }

            // 換人
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}
