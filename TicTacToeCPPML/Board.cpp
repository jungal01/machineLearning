#include "Board.h"
#include <stdlib.h>

Board::Board() {
    int i;
    
    for (i=0;i<3;i++)
        data.push_back(vector<unsigned char>(3));
}

Board::Board(const Board& orig) {
    data = orig.data;
}

Board::~Board() {
}

unsigned char Board::boardhash() {
    unsigned char hashval = 0;
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[i].size(); j++) {
            hashval += data[i][j] + 1;
        }
    }
    return hashval;
}

unsigned char Board::eval() {

    int i, j;

    unsigned char diag1Sum = 0;
    unsigned char diag2Sum = 0;

    for (i = 0; i < 3; i++) {
       unsigned char rowSum = 0;
       unsigned char colSum = 0;
        diag1Sum += data[i][i];
        diag2Sum += data[i][2 - i];

        for (j = 0; j < 3; j++) {
            rowSum += data[i][j];
            colSum += data[j][i];
        }

        if (abs(rowSum) == 3)
            return rowSum / 3;

        if (abs(colSum) == 3)
            return colSum / 3;
    }

    if (abs(diag1Sum) == 3)
        return diag1Sum / 3;

    if (abs(diag2Sum) == 3)
        return diag2Sum / 3;

    return 0;
}

bool Board::full() {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (data[i][j] == Dummy)
                return false;
        }
    }

    return true;
}