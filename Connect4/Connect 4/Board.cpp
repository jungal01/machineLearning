/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Board.h"
#include <stdlib.h>

Board::Board() {
    int i;
    
    for (i=0; i < 6; i++)
        data.push_back(vector<unsigned char>(7));
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

    for (i = 0; i < data.size(); i++) {
       unsigned char rowSum = 0;
       unsigned char colSum = 0;
        diag1Sum += data[i][i];
        diag2Sum += data[i][2 - i];

        for (j = 0; j < data[i].size(); j++) {
            rowSum += data[i][j];
            colSum += data[j][i];
        }

        if (abs(rowSum) == 4)
            return rowSum / 4;

        if (abs(colSum) == 4)
            return colSum / 4;
    }

    if (abs(diag1Sum) == 4)
        return diag1Sum / 4;

    if (abs(diag2Sum) == 4)
        return diag2Sum / 4;

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