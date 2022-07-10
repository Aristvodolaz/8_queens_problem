#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;


const int n = 8;
char chessBoard[n][n];


void spleeping(int milliseconds)
{
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC / 1000;
    while (clock() < time_end) {

    }
}


void ChassBoardFalse() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            chessBoard[i][j] = '0';
        }
    }
}

void ChaseBoard(char myChessBoard[][n], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << myChessBoard[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void HorizontPrint(int currentRow, int currentColumn) {
    for (int i = currentRow, j = 0; j < n; j++) {
        if (chessBoard[i][j] == '1') {
            continue;
        }
        else {
            chessBoard[i][j] = '*';
        }
    }
}

void VerticalPrint(int currentRow, int currentColumn) {
    for (int i = 0, j = currentColumn; i < n; i++) {
        if (chessBoard[i][j] == '1') {
            continue;
        }
        else {
            chessBoard[i][j] = '*';
        }
    }
}

void PrintQue(int currentRow, int currentColumn) {
    for (int i = currentRow, j = currentColumn; i < n && j < n; i++, j++) {
        if (chessBoard[i][j] == '1') {
            continue;
        }
        else {
            chessBoard[i][j] = '*';
        }
    }

    for (int i = currentRow, j = currentColumn; i >= 0 && j >= 0; i--, j--) {
        if (chessBoard[i][j] == '1') {
            continue;
        }
        else {
            chessBoard[i][j] = '*';
        }
    }

    for (int i = currentRow, j = currentColumn; i >= 0 && j < n; i--, j++) {
        if (chessBoard[i][j] == '1') {
            continue;
        }
        else {
            chessBoard[i][j] = '*';
        }
    }

    for (int i = currentRow, j = currentColumn; i < n && j >= 0; i++, j--) {
        if (chessBoard[i][j] == '1') {
            continue;
        }
        else {
            chessBoard[i][j] = '*';
        }
    }
}

int main() {
    int firstInput;
    int currentColumn;
    int currentRow;

    ChassBoardFalse();

    for (int i = 0; i <= 7; i++) {
        firstInput = i;
        currentColumn = 0;
        currentRow = n - firstInput - 1;


    }

    system("pause");
    return 0;
}