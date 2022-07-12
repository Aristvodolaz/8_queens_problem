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


void PrintHouse(int currentRow, int currentColumn) {
    HorizontPrint(currentRow, currentColumn);
    VerticalPrint(currentRow, currentColumn);
    PrintQue(currentRow, currentColumn);
}

void printStatistics(int row, int col) {
    cout << "row : " << row << endl;
    cout << "col : " << col << endl;
    cout << endl;
}

void QueentDistant(int currentRow, int currentColumn) {
    chessBoard[currentRow][currentColumn] = '1';
    PrintHouse(currentRow, currentColumn);

}

void QueenNinjaAttackWithoutDelay(int currentRow, int currentColumn) {
    chessBoard[currentRow][currentColumn] = '1';
    PrintHouse(currentRow, currentColumn);

}

void firstInitialization(int firstInput) {
    ChassBoardFalse();
    int currentColumn = 0;
    int currentRow = n - firstInput - 1;

}

bool checkAllIsFull(int currentColumn) {
    bool allIsStar = true;
    for (int i = 0, j = currentColumn; i < n; i++) {
        if (chessBoard[i][j] == '*' || chessBoard[i][j] == '1') {
        }
        else {
            allIsStar = false;
        }
    }
    return allIsStar;
}

void resetNextHouses(int col) {
    for (int i = 0; i < n; i++) {
        for (int j = col; j < n; j++) {
            chessBoard[i][j] = '0';
        }
    }
}

void resetStarToZero() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (chessBoard[i][j] == '*') {
                chessBoard[i][j] = '0';
            }
        }
    }
}

void resetQueenNinja() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (chessBoard[i][j] != '1') {
                chessBoard[i][j] = '0';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (chessBoard[i][j] == '1') {
                QueenNinjaAttackWithoutDelay(i, j);
            }
        }
    }
}

bool nQueensComplete() {
    int nQueensCounter = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (chessBoard[i][j] == '1') {
                nQueensCounter++;
            }
        }
    }

    if (nQueensCounter < 8) {
        return false;
    }
    else {
        return true;
    }
}

void moveForward(int currentRow, int currentColumn) {



    if (checkAllIsFull(currentColumn)) {
        resetNextHouses(currentColumn);
        resetStarToZero();
        resetQueenNinja();
    }

    if (chessBoard[currentRow][currentColumn] == '*') {
        return;
    }

    QueentDistant(currentRow, currentColumn);


    if (nQueensComplete()) {
        ChaseBoard(chessBoard, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (chessBoard[j][i] == '1') {

                    cout << " " << n - j - 1;

                }
            }
        }
        cout << endl;
        cout << endl << endl << "------------------------------" << endl << endl;
        spleeping(500);
    }

    for (int row = n - 1; row >= 0 && currentColumn < n - 1; row--) {
        moveForward(row, currentColumn + 1);
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

        firstInitialization(firstInput);
        moveForward(currentRow, currentColumn);
    }

    system("pause");
    return 0;
}